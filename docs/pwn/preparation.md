# 课前准备 Preparation

如果没有很好的准备，培训中的几节课你可能会学的比较迷糊。

## :grey_question: pwn是什么？

pwn代指二进制漏洞挖掘与利用，以较底层的应用程序代码漏洞的利用为主。

在ctf中，极大部分pwn提供的可执行文件为由c语言编译的，x86架构下ubuntu系统的elf可执行文件。且利用方式围绕栈溢出，堆利用，格式化字符串漏洞等知识点。而我们的目的也很简单，拿到系统的shell，然后拿到flag。

主要的利用方式也很简单，就是跟程序交互。我们接受程序输出，然后给出能让我们利用的输入，再接收，再输入，以此循环，直到拿到系统shell。只不过交互的内容与平时有所不同，常常需要输入不可见字符，且可能需要根据输出而改变我们的输入，这时候人工输入显然不太方便，所以需要我们写一个脚本，也就是exp来代替我们人工操作。

## 语言基础

相较于其他方向，pwn需要的基础知识比较庞大。

- C语言：大部分逆向程序给的伪代码语法是c语言，再者pwn中对地址的各种调用十分频繁。因此掌握C语言是必不可少的，尤其需要熟练掌握C语言的指针相关内容。
- Linux：elf文件只能运行在linux上，所以linux的使用是逃不开的。当然，不需要掌握太多，只要会增删编辑运行文件，还有安装软件等基础操作即可。
- python：exp的书写一般用python完成。然后需要安装pwntools包，该包提供了上述所说的接收输出、发送输入等功能。虽然网上有人还在使用python2，但为了更好的兼容性和便捷性，建议直接用python3噢。
- 汇编：这里的汇编指x86的intel汇编，对应刚刚所说的常见的x86架构的elf。需要大家理解汇编中寄存器的概念，栈的概念，以及函数调用过程中传参和返回的相关步骤。因为有些时候伪代码难以理解，这时候就需要靠直接阅读汇编了。

## :wrench: 神奇妙妙工具

PWN要配置的工具有点多，准备这些软件，磨刀不误砍柴功：

- [VMware Workstation Pro](https://www.vmware.com/content/vmware/vmware-published-sites/cn/products/workstation-pro/workstation-pro-evaluation.html.html.html): 用于在PC中运行虚拟机。推荐安装ubuntu最新版。

- [Python3](https://www.python.org/): 虚拟机linux中一定要装，主机随意。

- [pwntools](https://github.com/Gallopsled/pwntools): 依然是需要装在虚拟机中。除了用于python脚本中构建exp，该包还提供了ROPgadget，checksec等工具。

- [one_gadget](https://github.com/david942j/one_gadget): linux中，用于获取可以无需传参直接getshell的地址。在堆利用时会使用到。

- [LibcSearcher](https://github.com/lieanu/LibcSearcher): linux中，用于根据泄露的地址查询对应libc的版本。有多种版本，包括在线查询、离线查询等，但一般较少使用到，因为大部分题目都会提供libc文件。

- IDA Pro: 逆向工具，装在主机上即可。

:stop_sign: 如果你某些软件并没有找到或者不能访问，那可能你的搜索能力还需要再多加进步了。

## 最后

入门有两道坎，一是环境的配置，二是基础知识的学习。如果你能成功坚持到做出第一道pwn题，那么你就已经赢了别人一大步了，后面的路也一定不会难倒你。

我们仅仅对各个方向的基础知识做了入门引导，也给大家提供了一些后续学习方向。

但是更重要的是保持自身对知识的渴求，锻炼自己使用搜索引擎来自己解决问题。
