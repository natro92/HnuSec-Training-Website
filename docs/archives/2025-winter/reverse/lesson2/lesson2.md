#  花指令与SMC

## 花指令

### X86指令集
X86指令集的长度并不固定，有些指令长度很短，只有1字节，有些则可以达到5字节。因此通过巧妙的构造，可以引导反汇编引擎解析一条错误的指令，最终让反汇编结果出错

### 反汇编算法
+ 线性扫描算法
+ 递归行进算法

#### 常见的反汇编工具所使用的反汇编算法
| 工具名 | 反汇编算法 |
| --- | --- |
| OllyDbg | 线性扫描算法/递归行进算法(Ctrl+A) |
| SoftICE | 线性扫描算法 |
| WinDBG | 线性扫描算法 |
| W32Dasm | 线性扫描算法 |
| IDA Pro | 递归行进算法 |


### 花指令基本要求
<u>保证堆栈平衡</u>

能正常的运行程序，且能让反汇编软件分析出错

即要存在一部分代码，程序不会运行该代码，但反汇编软件需要分析到该代码

### 花指令编写

#### asm

`__asm`关键字用于调用内联汇编程序，并且可在C或C++语句合法时出现。不能单独显示，后面必须跟一个程序集指令、一组括在大括号中的指令，或者至少是一对空大括号。此处的术语"`__asm`块"指任何指令或指令组（无论是否在大括号中）

#### 花指令实现
##### 插入字节
利用汇编里的一个关键指令：`_emit 立即数`

```c
//在C语言中使用内联汇编
__asm{
	__emit 0xE8
}
//代表在这个位置插入一个字节数据0xE8
```

##### 互补条件跳转
原理是构造一个永恒的跳转，通过jz、jnz指令构造一对互补的跳转，保证无论情况如何一定会跳转到Label1处

```c
__asm{
	jmp Label1
	db thunkcode1 ;垃圾数据
	//垃圾数据例如：_emit 0xE8
Label1:
}
```

##### 构造永真跳转
通过设置永真或永假条件，让程序一定执行某一个跳转指令。由于IDA反汇编会优先反汇编false分支，通过这种花指令可以骗过IDA  
下列代码对ebx进行xor之后，再与test进行比较，zf标志位一定为1，则一定会执行`jz Label2`，即中间的`jnz Label1`一定不会被执行，也就是`_emit 0xC7`一定不会被执行

```c
__asm{
	push ebx
	xor ebx, ebx
	test ebx, ebx
	jnz Label1
	jz Label2
Label1:
	__emit 0xC7
	Label2:
	pop ebx
}
```

##### call&ret指令
call指令的本质：`push 函数返回地址`然后`jmp 函数地址`  
ret指令的本质：`pop eip`  
下列代码中的esp存储的是函数返回第地址，对应[esp]+8，正好盖过代码中的函数指令以及垃圾数据

```c
__asm{
	call Label9
	__emit 0x83
Label9:
	add dword ptr ss:[esp], 8
	ret
	__emit 0xF3
}
```

#### 完整示例代码1
```c
#include<stdio.h>

__declspec(naked)
void test() {

    __asm {

        xor eax, eax
        mov eax, 1
        jmp label1
        __emit 0xe9
label1:
        mov ebx, 1
        add eax, ebx
        ret

    }
}

int main(void)
{
    test();
    printf("Hello, world!\n");
    return 0;
}
```

__emit用于直接插入立即数

__emit 0xe9插入0xe9，0xe9是jump指令的首个字，采用线性扫描算法识别到这里时，就会将后面的指令视为jump指令，但程序运行时不会出错，因为前面是一条无条件jump指令，程序永远不会运行到__emit 0xe9这个地方

visual studio反汇编结果：

![](E:\A学习\计算机\逆向\从0开始学逆向_课件\花指令1.png)![](https://cdn.nlark.com/yuque/0/2024/png/47127581/1729171536553-f920b2dc-be4d-4ddd-a326-182338cfe28f.png)

可以看到，visual studio将__emit 0xe9这条指令及其之后的机器码分析为jump指令，后续的指令全部错误

但使用递归行进算法的IDA可以识别出这个花指令，因为IDA识别到jmp指令后，会将jmp指令的目的地址视为起始地址重新开始反编译，从而跳过__emit 0xe9

#### 完整示例代码2
```c
#include<stdio.h>

__declspec(naked)
void test() {

    __asm {

        xor eax, eax
        mov eax, 1
        jz label1
        jnz label1
        __emit 0xe9
label1:
        mov ebx, 1
        add eax, ebx
        ret

    }
}

int main(void)
{
    test();
    printf("Hello, world!\n");
    return 0;
}
```

要骗过IDA，只需要将无条件跳转指令jmp，改成互补的条件跳转指令即可

IDA反汇编结果：![](E:\A学习\计算机\逆向\从0开始学逆向_课件\花指令2.png)![](https://cdn.nlark.com/yuque/0/2024/png/47127581/1729171557442-f4bfba26-4606-4ac1-9991-fcdec7149d2f.png)

由于jz与jnz互补，无论flag为何值，都可以跳转到label1，但由于分析到jnz时，IDA需要分析未跳转的情况，此时会分析到__emit 0xe9这条指令，从而达到花指令的目的

#### 完整示例代码3
```c
#include<stdio.h>

__declspec(naked)
void test() {

    __asm {

        call label1
        __emit 0xe9
label1:
        add dword ptr [esp], 7
        ret
        __emit 0xe9

        add eax, 5
        ret

    }
}

int main(void)
{
    test();
    printf("Hello, world!\n");
    return 0;
}
```

`call label1`执行完成后，将下一条指令的eip入栈，并跳转到label1处执行，`add dword ptr [esp], 7`将esp指向的地址增加7个字节长度，即跳过`add dword ptr [esp], 7`、`ret`与`__emit 0xe9`，直接从`add eax, 5`执行

但反汇编按部就班进行，此时会运行到`__emit 0xe9`，从而达到花指令的效果

反汇编结果：

![](https://cdn.nlark.com/yuque/0/2024/png/47127581/1729171584271-0d8f1fc4-5ff7-420d-a945-d96a6eaa27d6.png)

## 处理花指令
当使用IDA分析到花指令时，右键选择目标地址，点击Undefine(快捷键U)，使其按照数据进行反汇编，再右键点击正确指令的开始地址，点击Code(快捷键C)，按照指令进行解析

但手动操作比较麻烦，如果碰到大量花指令与嵌套花指令，就比较考验耐心了

如果理解花指令操作逻辑，可以在IDA里用IDApython/IDC编写自动化处理花指令的脚本，核心原理就是将这些花指令的机器码替换成0x90(nop指令)，处理后就可以正常解析了；或者在OD调试的时候去掉

### 花指令原理另类利用
在理解花指令原理之后，可以在将花指令中的垃圾数据替换为一些特定的特征码，可以实现“定位”功能，尤其是在SMC中可以运用，例如下段代码中将特征码`hElLowoRld`嵌入到代码中，那么只需要在当前进程中搜索`hElLowoRld`字符串，就可以定位到当前代码位置，然后对后续代码进行SMC自解密

```c
__asm{
    jz Label
    jnz Label
    _emit 'h'
    _emit 'E'
    _emit 'l'
    _emit 'L'
    _emit '0'
    _emit 'e'
    _emit 'w'
    _emit 'o'
    _emit 'R'
    _emit 'l'
    _emit 'D'

    Label:
}
```

## SMC技术
SMC全程Self Modifying Code技术，代码自修改技术，在一段代码执行之前，可以对其进行修改，一般用来加密核心功能逻辑，也是加壳技术的基础

在程序执行时，先执行初始化代码，对加密后的代码执行解密工作，然后就可以成功执行加密后的代码了

![](E:\A学习\计算机\逆向\从0开始学逆向_课件\SMC技术图解.png)![](https://cdn.nlark.com/yuque/0/2024/png/47127581/1729171605496-0f752ada-b99b-4373-90bc-705216c3826b.png)

### 示例代码
```c
// SMCTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

__declspec(naked)
void important_fun() {  //此处代码来源于"远程线程注入.md"
    __asm {

        mov eax, 0x772db730
        push 0
        push 0x6e616e6e
        push 0x696a7579
        mov ebx, esp

        push 0
        push ebx
        push ebx
        push 0
        call eax
        add esp, 0x0C

        ret
    }
}

void important_fun2() {
    printf("hello, world!\n");
}


void encrypt_fun() {
    unsigned char encryped_code[32] = {0};
    unsigned char* ptr = (unsigned char*)important_fun;
    for (int i = 0; i < 31; i++) {
        encryped_code[i] = ptr[i] ^ 0x11;
        printf("0x%02X, ", encryped_code[i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }

    printf("\n======================================\n");

    for (int i = 0; i < 31; i++) {
        printf("0x%02X, ", ptr[i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
}


void decrypt_fun(PVOID address) {
    unsigned char* ptr = (unsigned char*)address;
    for (int i = 0; i < 31; i++) {
        ptr[i] = ptr[i] ^ 0x11;
        printf("0x%02X, ", ptr[i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
}


unsigned char g_code[] = {
    0xA9, 0x21, 0xA6, 0x3C, 0x66, 0x7B, 0x11, 0x79,
    0x7F, 0x7F, 0x70, 0x7F, 0x79, 0x68, 0x64, 0x7B,
    0x78, 0x9A, 0xCD, 0x7B, 0x11, 0x42, 0x42, 0x7B,
    0x11, 0xEE, 0xC1, 0x92, 0xD5, 0x1D, 0xD2,
};


void smc_test() {

    PVOID codePage = VirtualAlloc(NULL, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (codePage) {
        ZeroMemory(codePage, 4096);
        memcpy(codePage, g_code, sizeof(g_code));
        decrypt_fun(codePage);

        __asm {
            call codePage

        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    MessageBoxA(NULL, "start", "start", MB_OK);  //用于显式告诉编译器，此代码使用了MessageBox()函数，需要包含user32.dll
    important_fun();
    encrypt_fun();

    smc_test();

    important_fun2();
    return 0;
}
```

`encrypt_fun()`用于将`important_fun()`的每一个字节与0x11进行异或，并将结果存储在`encryped_code[]`中，在处理完成后将加密后的字节码与原来的字节码都输出到屏幕上

`g_code[]`用于存储加密后的代码

`smc_test()`先分配一块内存，如果分配成功就进行清零，清零后将`g_code[]`拷贝过来，然后对g_code进行解密工作，最后调用这一块内存

上述就是SMC技术的大体展示

### 小问题
为什么需要自己写汇编指令，而不能用普通的C语言函数，再进行加解密呢？

因为如果使用C语言函数，即使是最简单的函数也涉及其他地址的引用，如果直接加密，则其中的一些偏移量都会发生变化，解密后运行大概率会报错，例如`important_fun2()`，可以在visual studio中进行反汇编查看一下汇编代码
