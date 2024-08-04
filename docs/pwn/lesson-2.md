这里是第二节课 “Pwn / Re：汇编和 IDA 的使用” 的相关课件。

# PPT 下载

[点我下载](/pwn/lesson-2-source/lesson_2.pptx)

# 条件跳转

补充一下 PPT 中放不下的条件跳转的知识~

| 命令          | 说明                                                                                   | 标记位           |     |
| ----------- | ------------------------------------------------------------------------------------ | ------------- | --- |
| JZ、JE       | 结果为零则跳转（相等）<br/>jump if zero / jump if equal                                         | ZF=1          |     |
| JNZ、JNE     | 结果不为零则跳转（不相等）                                                                        | ZF=0          |     |
| JS          | 结果为负则跳转<br/>jump if sign                                                             | SF=1          |     |
| JNS         | 结果为非负则跳转                                                                             | SF=0          |     |
| JP、JPE      | 结果中1的个数为偶数则跳转<br/>jump if parity / jump if parity even                               | PF=1          |     |
| JNP、JPO     | 结果中1的个数不为偶数则跳转<br/>jump if not parity / jump if parity odd                           | PF=0          |     |
| JO          | 结果溢出了则跳转                                                                             | OF=1          |     |
| JNO         | 结果没溢出则跳转                                                                             | OF=0          |     |
| JC、JB、JNAE  | 进位则跳转 / 小于则跳转 **（无符号数）**<br/>jump if carry / jump if below / jump if not above equal | CF=1          |     |
| JNC、JNB、JAE | 无进位则跳转 / 不低于则跳转 **（无符号数）**                                                           | CF=0          |     |
| JBE、JNA     | 不高于则跳转 **（无符号数）**<br/>jump if below equal / jump if not above                        | ZF=1 或 CF=1   |     |
| JNBE、JA     | 高于则跳转 **（无符号数）**<br/>jump if not below equal / jump if above                         | ZF=0 或 CF=0   |     |
| JL、JNGE     | 小于则跳转 **（有符号数）**<br/>jump if less / jump if not greater equal                        | SF!=OF        |     |
| JNL、JGE     | 不小于则跳转 **（有符号数）**<br/>jump if not less / jump if greater equal                       | SF=OF         |     |
| JLE、JNG     | 不大于则跳转 **（有符号数）**<br/>jump if less equal / jump if not greater                       | SF!=OF 或 ZF=1 |     |
| JNLE、JG     | 大于则跳转 **（有符号数）**<br/>jump if not less equal /  jump if greater                       | SF=OF 且 ZF=0  |     |
# IDA Pro

## 基础界面介绍
### IDA View
分为图形界面 Graph View 和非图形界面 Non-graph View。用 `空格` 进行界面切换。
#### Graph View
箭头表示程序流程，蓝色是普通箭头，绿色是满足条件的分支箭头，红色是不满足的。

用鼠标拖动，`ctrl + 滚轮` 缩放，`w` 平铺窗口，`1` 设置缩放为100%，`ctrl + ↑ or ↓` 到父母/孩子节点。多选（`shift` 或者 `ctrl + 鼠标` 框选）然后右键 group node，能让多个节点合并成一个。右键 layout node 恢复初始视图。
#### Non-graph View
左侧的箭头表示跳转，实线无条件跳转、虚线是条件跳转。红色表示跳出了当前函数或块的范围。

左边蓝色圆点是断点，在动态调试的时候用。
### Pseudocode
在函数范围内按下 `F5` 打开伪代码窗口，按下 `Tab` 切换回 IDA View。

能够看到函数的调用约定，参数、变量等。鼠标悬停可看到更多提示。
### Hex View
按下 `1` `2` `4` `8` 可以切换字节样式。右键 Synchronize With 可以选择当前光标位置和哪个 View 同步。

`Esc` 返回上一个位置。
### 常用 Subviews
快速打开 subviews `ctrl + 1`

字符串 strings 窗口：`shift + F12`
对象 Names 窗口：`shift + F4`，字符串以 `a` 开头
Functions calls 窗口：函数引用（在伪代码窗口才可使用）

所有 subviews 都可以 `ctrl + F` 或者 `alt + T` 搜索。

拖动标题可以拉出来窗口并且可以并排显示。想合并窗口需要拖动标题下面那个灰色区域。

想保存当前布局，`Windows - Save desktop` 然后再 `Load desktop`，或者在保存时直接勾选default。注意 debug 时的布局设置需要在 debug 过程中保存哦。

如果布局乱了想重置，`Windows - Reset desktop` 就好了。

### 退出
IDA 会询问你是否保存数据库（database）。

如果不保存数据库，则每次加载当前文件都会重新进行分析，dummy names 会随机生成，并且你的所有分析操作需要重新进行。

## 常用设置

`Options - General` 打开设置。
### Disassembly

注意 Graph 和 Non-graph 设置分离，需要切到对应界面去设置。需单独设置的地方会显示（graph）或 （non-graph）。
#### Address representation：地址表示

Function offsets：行号变成函数内部偏移，勾选后会从 `.text:0804925A` 变成 `main+2A` 。具体的地址仍可从 View 底端标题处查看。
#### Display disassembly line parts：显示汇编行内容

Stack pointer：显示函数内部栈偏移，在 debug "sp-analysis failed", "positive sp value has been detected", "call analysis failed" 的时候打开很有用。在 call 处按下 `alt + K` 修复偏移量。

Number of opcode bytes：显示的操作码字节数。按自己喜好设定，如果为 4 则一行最多显示 4 字节，多余的会显示到下一行。0 则不显示。负数则将多余的截断（-4 即一行最多显示 4 字节，多余截断）。
### Cross-references

#### Number of displayed xrefs：显示交叉引用数

Disassembly: 在汇编代码中的显示。non-graph 中为函数处右侧的绿色注释（类似：; CODE XREF: ...+A2↓j）。默认设置为 2，即最多显示 2 条交叉引用信息，多余的省略。

其他的设置大家可以多动手修改试试，找到适合自己的 IDA 配置！
## 快捷键

> 对话框 `ctrl + Enter` 确认，`Esc` 取消。

按住 `Alt` 键，菜单名称下有下划线，按下下划线标记字母（加速键）即可打开菜单，打开菜单后，可以直接输入下划线标记字母来使用标记项。

查看 `Options - Shortcuts`，会显示**当前界面**可用的快捷键，不可用的会被划去。

Linux 或 Mac 上没有显示下划线，但相同的按键序列仍会生效，可以查看 `cfg/idagui.cfg` 文件，其描述了 IDA 的默认菜单布局和所有已分配的加速键（ & 为前缀）。

Mac 用户可以安装 Raycast 的 Navigation 插件。

Command Palette 命令面板 `ctrl + shift + P` 可以查看**当前界面**可以使用的指令。

按下 `G` 可以跳转到指定地址，默认**十六进制**格式（即使不以 0x 开头）。
支持 IDA View 中显示的格式，如 segment : offset 或者 函数 + offset （这个也是十六进制哦）。
支持函数名、变量名和 label 跳转，但是要完全一致才可。
支持 C 表达式运算，但在这个时候数字默认为 10 进制 `logo + 32*4 = logo + 0x80`

按下 `X` 打开选中对象的交叉引用窗口，或者按下 `ctrl + X` 显示当前地址的交叉引用情况。这里是指被谁引用（xfer to）。区分 `ctrl + J`（引用了谁 xfer from，通常用来分析 switch 语句）。

## 数据操作

`alt + L` 开始选择。选中数据可以 `shift + E`  快速导出。按 `*` 创建数组。

字符串可能的乱码问题，在 `Options - General - Strings` 设置默认编码。可以添加自定义编码。选中字符串 `alt + A` 单独设定编码。

更改数据类型：选中对象，按下快捷键，或者查看 `Edit` 中的相关操作。
`C` 将当前内容强制解析为 code ，`D` 将内容解析为 data， `A` 将内容解析为字符串，按 `*` 将内容解析为数组。`U` 将取消内容解析（还原成原始汇编代码）。

汇编语句中操作数的操作参考 `Edit - Operand type`，常用的有 `H` 转换成十六进制和 `R` 转换成字符串等。

## 重命名和注释

按下 `N` 重命名。

在 Pseudocode 界面：按下 `/` 当前行添加注释，按下 `Ins` 在当前行前添加注释。 

在 IDA View： 

按下 `:` 单次注释（仅在注释行出现）

按下 `;` 重复注释（会在所有使用到该对象的位置重复出现，例如识别的字符串，自动注释即为重复注释。函数头部的注释也为重复注释）

`Ins` 前置注释，`shift + Ins` 后置注释。

太多代码？可以手动选择想隐藏的区域，并选择 `View - Hide` 进行隐藏。

# 作业

## 内容

从简单到难，不要求全部完成，量力而行。遇到困难欢迎在群里讨论，或者等待两个星期后的作业答案（届时会在**该页面**更新，请留意）。

题目源码位于 `pwn / lesson-2-source` 文件夹下，请自行编译，推荐使用 Linux 编译成 ELF，更容易分析。也可以尝试编译成 Windows  的 EXE，体验 EXE 和 ELF 的区别。在完成每项作业之前，请先**不要阅读**源码，直接使用可执行文件进行分析。如果分析确实遇到了困难，再查看源码获得提示。

推荐编译指令：`gcc test.c -o test -no-pie -fno-pic` 。32 位程序请参考 PPT 内容。想增加难度可以尝试 `-s` 去除符号表。
### 分析自己写的代码

**学习目的**：熟悉基本编译流程、掌握基础汇编指令

**作业目标**：自行编写 C 语言文件，并使用 IDA 分析程序执行流程（只允许看汇编代码）。

**提交内容**：C 语言文件源码（直接粘贴即可，无需单独提交文件，**不用写太长**），关键函数（main 函数以及自己编写的函数）逐行汇编代码分析。

### 函数分析 ida_func_test

**学习目的**：学会类型转换、了解字符串的小端表示、分析函数运行逻辑
		（进阶）IDA 变量重命名，栈帧分析

**下载链接**：[源码](/pwn/lesson-2-source/ida_func_test.c)

**作业目标**：找到字符串在汇编中的表示形式，了解 IDA 对字符串的操作

（进阶，随缘完成x）优化伪代码，分析 IDA 自动分析不理想的可能原因
![优化伪代码目标](/pwn/lesson-2-source/c36674596076ac6f088f5fcde967dab7_MD5.png)

**提交内容**：在汇编中 `Hi CTFer~` 的对应片段，在 IDA 中还原字符串的操作（汇编界面）
（进阶）优化伪代码的步骤，及对应分析
### 动态调试 ida_secret

**学习目的**：了解 IDA 动态调试基础，熟悉动态调试界面

**下载链接**：[源码](/pwn/lesson-2-source/ida_secret.c)

**作业目标**：请使用 IDA 的动态调试方法，找到 flag 吧。

**提交内容**：分析思路 + 你找到的 flag 值（格式 flag{xxx} ）

**提示**：远程调试时，需要打开 IDA 安装目录下的 `dbgsrv` 文件夹，找到目标文件对应的平台（如使用 Linux 调试则使用 `linux_server` '32位' 或 `linux_server64` '64位'），复制一份到远程机器的可执行文件同目录下。然后运行该 server。

IDA 标题栏 `Debugger` 选择 `Remote Linux Debugger`，并在 `Debugger - Process options` 中设置 `Hostname` （远程机器 IP 地址），`Port` 端口号默认保持不动，即可按下 `F9` 开始调试，`ctrl + F2` 终止当前进程。

调试过程中的快捷键：
+ `F2` 下断点（程序运行到断点位置会自动停止）
+ `F7` 步入。运行一行汇编指令，遇到 `call` 指令会进入到其对应的函数内部继续逐行汇编执行
+ `F8` 步过。运行一条汇编指令，遇到 `call` 指令会直接执行，不进入函数内部
+ `F4` 执行到鼠标位置
+ `ctrl + F7` 执行直到遇到返回（ret）

### 花指令 ida_obfuscation

> 函数内联汇编为 `msvc` 的格式，无法使用 `gcc` 编译。
> 请用 `clang -fasm-blocks -fno-pic -no-pie -m32 ida_obfuscation.c -o ida_obfuscation`(`-g` 生成调试信息)
> 或下载编译好的文件 `ida_obfuscation`(Linux)、`ida_obfuscation.exe`(Windows) 进行调试

**学习目的**：了解基本花指令，学会 IDA 的 patch 操作

**下载链接**：[源码](/pwn/lesson-2-source/ida_obfuscation.c) 、[编译好的Linux32位程序](/pwn/lesson-2-source/ida_obfuscation)、[编译好的Windows32位程序（无调试信息）](/pwn/lesson-2-source/ida_obfuscation.exe)  

**作业目标**：

+ 静态分析：修改汇编代码，移除花指令，让 func1 和 func2 能正常生成伪代码。（都有一行 printf 即可）
+ 动态调试：观察程序运行流程，分析花指令如何不影响程序运行逻辑，但成功干扰了 IDA 的判断。

**提交内容**：操作过程 + 分析。

**提示**：实在没头绪就去看看源码吧。


##  提交方式

将必要的操作步骤截图，所有图片和内容都放在一个 **pdf** 内。

发送至邮箱 `chenjf@nipc.org.cn` ，ddl 8 月 14 日。



