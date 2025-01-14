# Pwn方向第一节课-二进制基础与工具使用

## Part0 **PWN**？

### 概述

•破解、利用成功（程序的二进制漏洞）

•攻破（设备、服务器）

•控制（设备、服务器）

### 一次简单的hack

•exploit

•用于攻击的脚本与方案

•payload

•攻击载荷，是目标进程被劫持控制流的数据

•shellcode

•调用攻击目标的shell的代码

## Part1 二进制基础

### 程序的编译与链接

从C源代码到可执行文件的生成过程

•编译：由C语言代码生成汇编代码

•汇编：由汇编代码生成机器码

•链接：将多个机器码的目标文件链接成一个可执行文件

![image-20250114223355978](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223355978.png)

![image-20250114223433740](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223433740.png)

### Linux下的可执行文件格式ELF

#### 什么是可执行文件？

•广义：文件中的数据是可执行代码的文件

•.out、.exe、.sh、.py

•狭义：文件中的数据是机器码的文件

•.out、.exe、.dll、.so

#### 可执行文件的分类

•Windows：PE（Portable Executable）

•可执行程序：.exe

•动态链接库：.dll

•静态链接库：.lib

•Linux：ELF（Executable and Linkable Format）

•可执行程序：.out

•动态链接库：.so

•静态链接库：.a

#### ELF 文件结构

![image-20250114223616715](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223616715.png)

•ELF文件头表（ELF header）：记录了ELF文件的组织结构

•程序头表/段表（Program header table）：告诉系统如何创建进程，生成进程的可执行文件必须拥有此结构：重定位文件不一定需要

•节头表（Section header table）：记录了ELF文件的节区信息，用于链接的目标文件必须拥有此结构，其它类型目标文件不一定需要

![image-20250114223753387](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223753387.png)

#### 磁盘中的ELF（可执行文件）与内存中的ELF（进程内存映像）

![image-20250114223813673](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223813673.png)

![image-20250114223840428](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223840428.png)

### 进程虚拟地址空间

#### ELF文件到虚拟地址空间的映射

![image-20250114223847702](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114223847702.png)

地址以字节编码 1Byte = 8bits

常以16进制表示 0x3c = 0011 1100 

虚拟内存用户空间每个进程一份

虚拟内存内核空间所有进程共享一份

虚拟内存 mmap 段中的动态链接库仅在物理内存中装载一份

![image-20250114224206925](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224206925.png)

![image-20250114224216452](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224216452.png)

#### 段（segment）与节（section）

> •一个 段 包含多个 节
>
> •段视图用于进程的内存区域的 rwx权限划分
>
> •节视图用于ELF文件 编译链接时 与 在磁盘上存储时 的文件结构的组织

**代码段（Text segment）包含了代码与只读数据**

•.text 节

•.rodata 节 

•.hash 节 														

•.dynsym 节 

•.dynstr 节 

•.plt 节

•.rel.got 节 

•……

**数据段（Data segment）包含了可读可写数据**

•.data 节 

•.dynamic 节 

•.got 节 

•.got.plt 节

•.bss 节

•……

**栈段（Stack segment）**

#### 程序数据是如何在内存中组织的

![image-20250114224423196](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224423196.png)

### 程序的装载与进程的执行

#### 大端序与小端序

![image-20250114224441210](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224441210.png)

**小端序**

•低地址存放数据低位、高地址存放数据高位

•我们所主要关注的格式

![image-20250114224459623](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224459623.png)

**大端序**

•低地址存放数据高位、高地址存放数据低位

#### 进程的执行过程

![image-20250114224551909](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224551909.png)

#### 寄存器结构

**amd64寄存器结构**

•rax： 8Bytes

•eax：4Bytes

•ax： 2Bytes

•ah： 1Bytes

•al：  1Bytes

**部分寄存器的功能**

•RIP：存放当前执行的指令的地址

•RSP:存放当前栈帧的栈顶地址

•RB:•存放当前栈帧的栈底地址

•RA:•通用寄存器。存放函数返回值

![image-20250114224805276](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224805276.png)

#### 静态链接的程序的执行过程

![image-20250114224822561](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224822561.png)

#### 动态链接的程序的执行过程

![image-20250114224845326](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114224845326.png)



### x86&amd64汇编简述

#### 常用汇编指令

```asm
•MOV 		JMP 	    XOR/AND

•LEA	    J[Condition]

•ADD/SUB    CALL

•PUSH 		LEAVE

•POP    	RET

•CMP		INC/DEC
```

##### MOV

```asm
MOV DEST, SRC         ; 把源操作数传送给目标

MOV EAX,1234H 		  ; 执行结果（EAX） = 1234H
MOV EBX, EAX 
MOV EAX, [00404011H]  ; [ ] 表示取地址内的值
MOV EAX, [ESI]  
```

##### LEA

```asm
LEA REG, SRC                    ; 把源操作数的有效地址送给指定的寄存器
LEA EBX, ASC                    ; 取 ASC 的地址存放至 EBX 寄存器中
LEA EAX, 6[ESI]                 ; 把 ESI+6 单元的32位地址送给 EAX 
```

##### ADD/SUB

```asm
ADD/SUB DEST, SRC                ;将源操作数的值加/减到目标操作数
ADD AX, 3		 				 ; AX = AX + 3 
ADD AX,[0xdeadbeef]				 ; AX = AX + [0Xdeadbeef]
SUB  AX,3						 ; AX = AX  - 3
```

##### INC/DEC

```asm
INC/DEC REG                    	 ;将指定寄存器的值增加/减少 1
```

##### PUSH/POP

```asm
PUSH VALUE                 	     ; 把目标值压栈，同时SP指针-1字长
PUSH 1234H 
PUSH EAX

POP DEST                     	 ; 将栈顶的值弹出至目的存储位置，同时SP指针+1字长
POP EAX
```

##### LEAVE

```asm
在函数返回时，恢复父函数栈帧的指令
等效于：
MOV ESP, EBP
POP EBP
```

##### RET

```asm
在函数返回时，控制程序执行流返回父函数的指令
等效于：
POP RIP（这条指令实际是不存在的，不能直接向RIP寄存器传送数据）

```

#### 两种汇编格式

![image-20250114225635311](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114225635311.png)

## Part2 **内存保护措施**

### ASLR

ASLR(Address Space Layout Randomization)

```asm
系统的防护措施，程序装载时生效
/proc/sys/kernel/randomize_va_space = 0：没有随机化。即关闭 ASLR
/proc/sys/kernel/randomize_va_space = 1：保留的随机化。共享库、栈、mmap() 以及 VDSO 将被随机化
/proc/sys/kernel/randomize_va_space = 2：完全的随机化。在randomize_va_space = 1的基础上，通过 brk() 分配的内存空间也将被随机化=
```

### PIE

PIE (Position-Independent Executable)

```asm
程序的防护措施，编译时生效
随机化ELF文件的映射地址
开启 ASLR 之后，PIE 才会生效
```

### The NX bits 

The NX bits (the No-eXecute bits)

```asm

程序与操作系统的防护措施，编译时决定是否生效，由操作系统实现
通过在内存页的标识中增加“执行”位, 可以表示该内存页是否可以执行, 若程序代码的 EIP 执行至不可运行的内存页, 则 CPU 将直接拒绝执行“指令”造成程序崩溃
```

![image-20250114225909912](https://raw.githubusercontent.com/iam0range/picgo/main/image-20250114225909912.png)

### Canary

```asm
程序的防护措施，编译时生效
在刚进入函数时，在栈上放置一个标志canary，在函数返回时检测其是否被改变。以达到防护栈溢出的目的
canary长度为1字长，其位置不一定与ebp/rbp存储的位置相邻，具体得看程序的汇编操作
```

### RELRO

RELRO (RELocate Read-Only)

```asm
程序的防护措施，编译时生效
部分 RELRO: 在程序装入后, 将其中一些段(如.dynamic)标记为只读, 防止程序的一些重定位信息被修改
完全 RELRO: 在部分 RELRO 的基础上, 在程序装入时, 直接解析完所有符号并填入对应的值, 此时所有的 GOT 表项都已初始化, 且不装入link_map与_dl_runtime_resolve的地址
```

## Part3 PWN Tools

```asm
IDA Pro
pwntools
pwndbg
checksec
ROPgadget
one_gadget
LibcSearcher
main_arena_offset
```

