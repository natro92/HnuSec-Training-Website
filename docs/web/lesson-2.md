# 课前准备

1.安装好Linux系统（vm虚拟机或者wsl都可）

2.配置好php语言环境（Windows和Linux都有最好）

3.了解一下正则表达式

# 基础知识

## Linux系统需要的一些认识

- Linux是开源操作系统，可以更改源代码，而Windows是商业操作系统，没有访问源代码的权限。

- Linux运行速度更快，Windows在旧硬件上运行较慢。

- Linux提供更好的定制化和灵活性，Windows提供更友好的用户界面和更广泛的软件兼容性。

- Linux适用于程序设计和服务器工作且一般没有图形化界面，Windows适用于日常任务和桌面环境。

## Linux系统的基本命令操作

Linux系统一切皆文件，我们要懂得对文件的基本操作

### 查看当前目录存在的文件和文件夹

- ls

### 切换文件夹

- cd xxx进入指定目录
- cd .. 返回上一级目录

### 查看文件

- cat
- tail

### 创建文件
- touch

### 移动复制删除文件
- cp /e1.txt /e2.txt 复制
- mv /1.txt /go/1.txt 移动
- rm 1.txt 删除

### 编辑文件
- vim 1.txt

以上命令只是能能够让你快速上手linux并进行简单的操作，随着更深入的学习，命令会变得更复杂

# RCE

## 什么是RCE

rce是Remote Command Execute的缩写

即远程执行命令，它可以是一种漏洞，也可以看作渗透测试的最后一环

如果能成功rce，意味着你离成功不远了

## 如何RCE

RCE基本要满足如下条件

**存在危险函数且危险函数的参数可控**

以php为例，有且不只这些危险函数

```
执行系统命令的函数:
有回显:
system(),passthur()
无回显:
exec()
shell_exec()

执行php代码的函数:
eval()
```

通过这些危险函数，我们传入想执行的命令作为参数运行即可执行命令

### 实例

在早期一些提供ping功能的地方可能会存在rce漏洞，如下

```php
if($_POST['ip']){
    $ip = $_POST['ip'];
    system("ping ".$ip);
}
```

危险函数system()存在且$ip参数可控

我们只需给ip赋值为"1&whoami"即可执行同时执行ping 1 和 whoami两条命令

## 为什么要RCE

### 在CTF中

flag往往藏在网站根目录，所以我们要通过命令去读取flag

### 在实战中

1.发现rce漏洞往往是高危漏洞

2.通过rce控制主机有助于更深入的渗透

## RCE在CTF中的基础考察方式

通过上面实例我们知道，我们的漏洞利用过程为

阅读源码-->发现漏洞-->利用漏洞

那么对于新手而言往往注重考察如何利用漏洞，而不是阅读源码挖掘漏洞（因为这需要很深的代码功底）

所以题目一般会很直接明了的给出哪里存在危险函数，且什么参数可控

ctfshow-web29:

```php
error_reporting(0);
if(isset($_GET['c'])){
    $c = $_GET['c'];
    if(!preg_match("/flag/i", $c)){
        eval($c);
    }
    
}else{
    highlight_file(__FILE__);
}
```

ctfshow-web34:

```php
error_reporting(0);
if(isset($_GET['c'])){
    $c = $_GET['c'];
    if(!preg_match("/flag|system|php|cat|sort|shell|\.| |\'|\`|echo|\;|\(|\:|\"/i", $c)){
        eval($c);
    }
    
}else{
    highlight_file(__FILE__);
}
```

可见考察重点一般是放在ban关键词，绕关键词上，所以主要考察我们的绕过技巧

## 关于绕过

绕过的方式千奇百怪，但最重要的思想还是替代，下面仅介绍一些基础的替代

### 查看类命令的替代

cat

tail--看文件末尾，对一些比较长的文件才有显著效果

sort--排序并输出内容

tac

head

nl

more

less

od（od -t d1 tmp flag）

rev（rev flag | rev）

## flag字段的替代

f*:匹配所有f开头的文件

fla?:匹配所有flax，x代表任意字符

fla[f-h]:匹配flaf，flag，flah

fla{f,g.h}:匹配flaf，flag，flah

f''lag = f""lag = flag

以上的方法仅仅是让你明白何为“绕过”，当你明白“绕过”的概念后，可以将思维发散，多在网上收集资料，刷题，你会碰见很多千奇百怪的绕过

## 你需要了解的一些linux命令行中的特殊字符

[linux特殊符号大全 - balaamwe - 博客园 (cnblogs.com)](https://www.cnblogs.com/balaamwe/archive/2012/03/15/2397998.html)

## 关于正则表达式

对于关键词的禁用往往是通过正则表达式的形式书写的

对于没有系统学习正则表达式的人来说看懂一些简单的过滤应该也问题不大

但是认真学习正则表达式且会书写和利用它来做一些事情我认为还是很有帮助的

# 课后作业

- 速通正则表达式https://regexlearn.com/zh-cn（附完成截图）

- 思考一下当我们使用exec()而不是system()来执行命令时，我们该如何去得到回显结果（tip：反弹shell）（附成功反弹shell截图）
- 通过做题简单整理并收集一下自己的绕过词典，学习新的绕过方式

推荐做题平台https://buuoj.cn/，[诺赛斯 (nssctf.cn)](https://www.nssctf.cn/index)

课后作业最好为pdf或者md格式（若为md格式有图片必须一起打包）

如果学有余力可以自己搭建一下题目环境，不用提交

发送到邮箱1060089371@qq.com(8.14号前)

