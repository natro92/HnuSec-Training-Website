# ctf——Crypto
CTF（Capture The Flag）是信息安全领域中一种极具挑战性和趣味性的竞赛形式，参赛者通过破解各种加密、解密、编程和逆向工程等任务来获得“旗帜”（Flag）。在CTF竞赛中，密码学方向的任务主要涉及各种加密算法、解密技巧和密码破解的应用。具体来说，CTF密码学方向的任务通常包括经典密码破解（如凯撒密码、维吉尼亚密码等）、现代加密算法的攻击、密钥恢复、哈希碰撞以及密码协议的漏洞分析等。

需要运用对密码学知识的理解和实际操作技能，解决与加密算法、密文分析、数据泄露、漏洞利用等相关的问题。这考验了选手对密码学理论的掌握，还要求具备一定的编程能力、逆向思维以及创新性的解决问题的能力。CTF密码学方向的任务既可以是理论性的，如对传统密码学算法的分析，也可以是实践性的，如模拟现代加密算法的攻击。  

## Crypto方向题目类型：
### 1. **经典加密算法破解**
+ **对称加密（如AES、DES）**：这些题目通常会给出加密文本和一些已知信息（比如密钥、明文等），考察选手如何通过分析和算法攻击破解加密数据。
+ **非对称加密（如RSA、ECC）**：RSA是CTF比赛中最常见的加密方式之一，题目可能包括公钥加密、私钥泄漏、密钥恢复、数字签名等，一般需要利用数学知识（如素因数分解、扩展欧几里得算法）破解这些加密。
+ **哈希函数（如MD5、SHA）**：这些题目一般会给出某个哈希值，要求选手找出原始数据，或是利用碰撞攻击、字典攻击等方法破解哈希值。

### 2. **编码和加密算法的组合**
+ 很多Crypto题目涉及到某种加密算法与编码方式（如Base64、Hex、URL编码等）结合，需要首先解码，再进行加密破解或逆向解密。

### 3. **流密码与分组密码**
+ **流密码（如RC4）**：流密码生成的加密文本可能与某种特定的结构有关，需要通过分析密文流来恢复密钥。
+ **分组密码（如DES、AES）**：这类题目中，密文可能采用了某种模式（如ECB、CBC），破解时需要注意模式的特性，并利用它们的弱点进行攻击。

### 4. **密码学漏洞利用**
+ 这些题目通常会涉及到加密算法的漏洞或设计缺陷，选手需要找到漏洞并利用它进行破解。常见的漏洞包括**时间攻击**、**侧信道攻击**、**重放攻击**、**密钥恢复**等。
+ 例如，某些加密算法可能使用不安全的随机数生成器，或者密钥长度不够，攻击者可以利用这些弱点进行攻击。

### 5. **数学问题**
+ 密码学问题往往需要一定的数学基础，特别是数论、代数、概率论等。常见的数学题目包括**素数分解**、**离散对数问题**、**欧几里得算法**等。
+ 例如，RSA加密的安全性基于大数分解的困难性，所以如果你能利用某些优化算法对大数分解进行攻击，就能破解RSA。

### 6.古典密码
<font style="color:rgb(51, 51, 51);background-color:rgb(245, 246, 248);">古典密码（Classical Cryptography）是指在现代计算机技术普及之前使用的加密技术，通常是通过简单的数学或逻辑方法来对信息进行加密和解密。常见的有凯撒密码、单表替换密码、栅栏密码、维吉尼亚密码、摩尔斯密码等等。</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(245, 246, 248);"></font>

# <font style="color:rgb(51, 51, 51);background-color:rgb(245, 246, 248);">古典密码</font>
### 1.凯撒密码
凯撒密码是最早的代换密码，使用单表代换。其基本思想是：通过把字母移动一定的位数来实现加密和解密。明文中的所有字母都在字母表上向后(或向前)按照一个固定数目进行偏移后被替换成密文。例如，当偏移量是3的时候，所有的字母A将被替换成D，B变成E，以此类推X将变成A，Y变成B，Z变成C。位数就是凯撒密码加密和解密的密钥。

例子如下：

![](https://cdn.nlark.com/yuque/0/2025/png/42552926/1736738168030-37840c54-3053-4be8-8f74-5110910c2eb9.png)



### 2.维吉尼亚密码
在凯撒密码中，字母表中的每一字母都会作一定的偏移。  
例如当偏移量为3时，A就转换为了D、B转换为了E……因为凯撒密码中所有字母的偏移量是一样的，因此容易受到字母频率攻击分析，攻击者可以根据密文中出现字母的频率来猜测是由明文中那个字母经过偏移得到的。

<font style="color:rgb(180, 180, 180) !important;background-color:rgb(36, 36, 41);"></font>【**维吉尼亚密码**】则是由一些偏移量不同的恺撒密码组成。

为了生成密码，需要使用**表格法**。

这一表格包括了26行字母表，每一行都由前一行向左偏移一位得到。具体使用哪一行字母表进行编译是基于密钥进行的，在过程中会不断地变换。

下图是用来加解密的维吉尼亚表格：

![](https://cdn.nlark.com/yuque/0/2025/png/42552926/1736738804729-551d0987-42a8-44e9-b731-28e55469d8cb.png)

例如，假设明文为：HEETIAN

  然后选择某一关键词并重复而得到密钥，如关键词为LAB时，密钥为：LABLABL

  对于明文的第一个字母H，对应密钥的第一个字母L，于是使用表格中L行字母表进行加密，得到密文第一个字母S。  类似地，明文第二个字母为E，在表格中使用对应的A行进行加密，得到密文第二个字母E。以此类推，可以得到：

  明文：HEETIAN

  密钥：LABLABL

  密文：SEFEIBY

  解密的过程则与加密相反。

  例如：根据密钥第一个字母L所对应的L行字母表，发现密文第一个字母S位于H列，因而明文第一个字母为H。

  密钥第二个字母A对应A行字母表，而密文第二个字母E位于此行E列，因而明文第二个字母为E。以此类推便可得到明文。



### 3.栅栏密码
栅栏密码属于古典密码中最经典的**移项式密码**

我们以2栏栅栏密码为例来讲解它的加密和解密过程。

加密过程：明文：THERE_IS_A_CIPHER_

 两个一组，得到：(TH) (ER) (E_) (IS) (_A) (_C) (IP) (HE) (R_)

 先每组中取出第一个字母：TEEI__IHR

 再从每组中取出第二个字母：HR_SACPE_

 连在一起得到密文：TEEI__IHRHR_SACPE_

  解密过程：

  而解密的时候，我们先把密文从中间分开，变为两行：

 TEEI__IHR

 HR_SACPE_

 再按上下上下的顺序组合起来：

 THERE_IS_A_CIPHER_



  **那么如何将2栏密码扩展到多栏呢？**在之前的明文中，CIPHER这个单词之后加了一个下划线，

  目的就是为了让明文字符串的长度是2的倍数，

  栅栏密码的分栏的一个前提就是分的栏数需是明文长度的因数，这样才会使得分出来的每个栏长度都一样。

  对于多栏，我们还是用上面的例子来讲解。

  上面的明文字符串（THERE_IS_A_CIPHER_）的长度是18 

  所以我们可以把它分为2，3，4，6，9栏，这里我们以6栏为例。

  以每个元素相隔6个字符分割出栅栏。

        第一栏：TII

        第二栏：HSP

        第三栏：E_H

        第四栏：RAE

        第五栏：E_R

        第六栏：_C_

  连接在一起得到密文：TIIHSPE_HRAEE_R_C_



### 4. 置换密码（Transposition Cipher）  
**置换密码**是一种通过重新排列明文字母顺序来加密的密码方法。它不改变字母本身，而是改变它们的位置。

#### 1. **选择明文**
明文：HELLO WORLD

#### 2. **选择密钥**
密钥可以是一个数字序列，表示重新排列的顺序。例如，选择密钥：`3 1 4 5 2`。

#### 3. **按密钥长度分组**
根据密钥长度（5），将明文分组：

```plain

H E L L O   W O R L D
```

补齐不足的字符（如果最后一组不足 5 个字符），可以用占位符（如 X）填充：

```plain

H E L L O
W O R L D
X
```

#### 4. **重新排列字母**
按照密钥顺序 `3 1 4 5 2`，重新排列每组字母：

+ 第一组：`H E L L O` → `L H L O E`
+ 第二组：`W O R L D` → `R W L D O`
+ 第三组：`X` → 补齐 `X X X X X` → `X X X X X`

#### 5. **生成密文**
将重新排列后的字母按组拼接：

```plain

密文：LHL OER WLD OX XXXXXX
```

### 6.base64编码
<font style="color:rgb(6, 6, 7);">编码（Encoding）是将信息从一种形式或格式转换为另一种形式的过程。在计算机科学和信息处理中，编码通常用于将数据转换为适合存储、传输或处理的格式。编码可以是简单的字符转换，也可以是复杂的算法处理，具体取决于应用的需求。</font>

<font style="color:rgb(6, 6, 7);"></font>

Base64编码是一种将二进制数据转换为文本编码的方法，通常用于在文本协议中传输二进制数据，如电子邮件附件或在URL中传递数据。

原理：

准备要编码的二进制数据： 将要编码的二进制数据准备好，通常是字节的形式。

分组： 将二进制数据分成固定大小的组，每组通常为3字节（24位）。如果最后一组不足3字节，通常需要进行填充，以便每组都有3字节。

将每个组的二进制数据转换为十进制： 将每个3字节的二进制数据视为一个8bit*3=24bit位的二进制整数，再转化为一个十进制整数。

Base64编码： 将每个十进制整数编码为Base64字符。

Base64字符集通常包括64个字符，通常是大写字母A到Z、小写字母a到z、数字0到9以及两个额外的字符（通常是"+"和"/"）。

以24位整数为例，将它分成4组，每组6位。这4组6位整数将被编码为4个Base64字符。

每个6位整数对应一个Base64字符，根据其在Base64字符集中的位置来选择。

如果原始数据不足3字节，会添加一个或两个额外的0位，以确保每个6位整数都有6位。

Base64编码的结果是一个文本字符串，其中包含一系列Base64字符，每4个字符分为一组，每组表示一个24位整数。

填充（可选）： 如果原始数据的长度不是3的倍数，可以使用一个或两个填充字符“=”来补全Base64编码，以确保编码长度是4的倍数。

最终，Base64编码的结果就是表示输入二进制数据的文本字符串。在解码时，可以根据相同的算法将Base64编码的文本字符串还原为原始的二进制数据。

Base64编码是一种常见的数据表示方式，用于在各种情境中传输和存储二进制数据，因为它可以将二进制数据转换为纯文本，并且广泛支持各种编程语言和应用程序。

编码示例：base64编码 Man

![](https://cdn.nlark.com/yuque/0/2025/png/42552926/1736783088811-74b6bcc1-805c-4784-81ab-b38e3ffa79b7.png)

<font style="color:rgb(77, 77, 77);">编码示例：Base64的末尾补足</font>

![](https://cdn.nlark.com/yuque/0/2025/png/42552926/1736783132463-1d2bbfca-5152-4760-83be-23e6f059a7d9.png)  
 <font style="color:rgb(77, 77, 77);">base64索引表：</font>

|  Index  |  Character  |  Index  |  Character  |  Index  |  Character  |  Index  |  Character  |

|:-------:|:-----------:|:-------:|:-----------:|:-------:|:-----------:|:-------:|:-----------:|

|    0    |      A      |   16    |      Q      |   32    |      g      |   48    |      w      |

|    1    |      B      |   17    |      R      |   33    |      h      |   49    |      x      |

|    2    |      C      |   18    |      S      |   34    |      i      |   50    |      y      |

|    3    |      D      |   19    |      T      |   35    |      j      |   51    |      z      |

|    4    |      E      |   20    |      U      |   36    |      k      |   52    |      0      |

|    5    |      F      |   21    |      V      |   37    |      l      |   53    |      1      |

|    6    |      G      |   22    |      W      |   38    |      m      |   54    |      2      |

|    7    |      H      |   23    |      X      |   39    |      n      |   55    |      3      |

|    8    |      I      |   24    |      Y      |   40    |      o      |   56    |      4      |

|    9    |      J      |   25    |      Z      |   41    |      p      |   57    |      5      |

|   10    |      K      |   26    |      a      |   42    |      q      |   58    |      6      |

|   11    |      L      |   27    |      b      |   43    |      r      |   59    |      7      |

|   12    |      M      |   28    |      c      |   44    |      s      |   60    |      8      |

|   13    |      N      |   29    |      d      |   45    |      t      |   61    |      9      |

|   14    |      O      |   30    |      e      |   46    |      u      |   62    |      +      |

|   15    |      P      |   31    |      f      |   47    |      v      |   63    |      /      |

****

**古典密码的类型还有很多，例如 阿特巴什密码（Atbash Cipher）   希尔密码（Hill Cipher）   普莱费尔密码（Playfair Cipher）   培根密码（Bacon's Cipher）等，  课后同学们可以自行进行了解。**

# 数论基础
## 1.整除
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">设 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 和</font>![image](https://cdn.nlark.com/yuque/__latex/b19c6a394a363cf710008217809cdc76.svg)<font style="color:rgb(6, 6, 7);">是两个整数，且</font>![image](https://cdn.nlark.com/yuque/__latex/7daa78f3f4b676ec593b3d8ebd3e19f5.svg)<font style="color:rgb(6, 6, 7);">。如果存在一个整数 </font>![image](https://cdn.nlark.com/yuque/__latex/df976ff7fcf17d60490267d18a1e3996.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/0aed57cd8b273e522fd97f4115c8fa06.svg)<font style="color:rgb(6, 6, 7);">，则称 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);"> 整除 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">，记作 </font>![image](https://cdn.nlark.com/yuque/__latex/8c7826531fe28427883a34564ea5068d.svg)<font style="color:rgb(6, 6, 7);">。</font>

### <font style="color:rgb(6, 6, 7);">例子</font>
![image](https://cdn.nlark.com/yuque/__latex/cb898bd142677f65dbdc9141f890b67f.svg)

### <font style="color:rgb(6, 6, 7);">整除的性质</font>
1. **<font style="color:rgb(6, 6, 7);">自反性</font>**<font style="color:rgb(6, 6, 7);">：对于任何整数 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">，都有</font>![image](https://cdn.nlark.com/yuque/__latex/8a89e94443a30998f62642677a6c593a.svg)<font style="color:rgb(6, 6, 7);">。</font>
2. **<font style="color:rgb(6, 6, 7);">传递性</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/8bd3fc864bbd1a002f0666b8c4d55235.svg)<font style="color:rgb(6, 6, 7);"> 且 </font>![image](https://cdn.nlark.com/yuque/__latex/05d8f99aeaa0e1b8b1f4639eb3d76b27.svg)<font style="color:rgb(6, 6, 7);">，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/16e50ea111710649cf8ce6ef39506257.svg)<font style="color:rgb(6, 6, 7);">。</font>
3. **<font style="color:rgb(6, 6, 7);">线性组合</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/8bd3fc864bbd1a002f0666b8c4d55235.svg)<font style="color:rgb(6, 6, 7);">且 </font>![image](https://cdn.nlark.com/yuque/__latex/16e50ea111710649cf8ce6ef39506257.svg)<font style="color:rgb(6, 6, 7);">，那么对于任何整数 </font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">和 </font>![image](https://cdn.nlark.com/yuque/__latex/df378375e7693bdcf9535661c023c02e.svg)<font style="color:rgb(6, 6, 7);">，都有 </font>![image](https://cdn.nlark.com/yuque/__latex/5f0784276b82b07dcb48f9bb5f9c833a.svg)<font style="color:rgb(6, 6, 7);">。</font>
4. **<font style="color:rgb(6, 6, 7);">倍数性质</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/8bd3fc864bbd1a002f0666b8c4d55235.svg)<font style="color:rgb(6, 6, 7);">，那么对于任何整数</font>![image](https://cdn.nlark.com/yuque/__latex/14cb784d07a4234356ce44d06a5b8a3c.svg)<font style="color:rgb(6, 6, 7);">，都有</font>![image](https://cdn.nlark.com/yuque/__latex/a43a1ad4303160763c2e8d1d44a8195f.svg)<font style="color:rgb(6, 6, 7);">。</font>
5. **<font style="color:rgb(6, 6, 7);">因数性质</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/8bd3fc864bbd1a002f0666b8c4d55235.svg)<font style="color:rgb(6, 6, 7);">且 </font>![image](https://cdn.nlark.com/yuque/__latex/ccbd958ac21eeece7b4e9af664181d09.svg)<font style="color:rgb(6, 6, 7);">，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/f9c92b78a8aec1db1fb85e8d22fe343c.svg)<font style="color:rgb(6, 6, 7);">。</font>
6. **<font style="color:rgb(6, 6, 7);">唯一性</font>**<font style="color:rgb(6, 6, 7);">：如果</font>![image](https://cdn.nlark.com/yuque/__latex/7ca2de59d533961b35af0834f1f772df.svg)<font style="color:rgb(6, 6, 7);">且</font>![image](https://cdn.nlark.com/yuque/__latex/7814bbaee87084e5c695250747e37687.svg)<font style="color:rgb(6, 6, 7);">，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/49705465b20bfa30c40d087c5c3ae6da.svg)<font style="color:rgb(6, 6, 7);">。</font>



## 2.同余
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">设 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 和</font>![image](https://cdn.nlark.com/yuque/__latex/b19c6a394a363cf710008217809cdc76.svg)<font style="color:rgb(6, 6, 7);"> 是两个整数，</font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">是一个正整数。如果</font>![image](https://cdn.nlark.com/yuque/__latex/f1dec9e916c9b93c26bd11ac86a4b8f0.svg)<font style="color:rgb(6, 6, 7);">和</font>![image](https://cdn.nlark.com/yuque/__latex/b19c6a394a363cf710008217809cdc76.svg)<font style="color:rgb(6, 6, 7);"> 除以 </font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">的余数相同，即 </font>![image](https://cdn.nlark.com/yuque/__latex/704e7821287df2b5057717a6bc68cefb.svg)<font style="color:rgb(6, 6, 7);">，那么我们称 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">和</font>![image](https://cdn.nlark.com/yuque/__latex/b19c6a394a363cf710008217809cdc76.svg)<font style="color:rgb(6, 6, 7);">模 </font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">同余，记作</font>![image](https://cdn.nlark.com/yuque/__latex/3902b20e7239b15f5b62a30eb835c5e6.svg)<font style="color:rgb(6, 6, 7);">。</font>

### <font style="color:rgb(6, 6, 7);">例子</font>
![image](https://cdn.nlark.com/yuque/__latex/129e8cc1421167ce86826fcf00ba9cff.svg)

### <font style="color:rgb(6, 6, 7);">同余的性质</font>
1. **<font style="color:rgb(6, 6, 7);">自反性</font>**<font style="color:rgb(6, 6, 7);">：对于任何整数 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 和正整数</font>![image](https://cdn.nlark.com/yuque/__latex/01a0b33465cb6a9a84504f60af049255.svg)<font style="color:rgb(6, 6, 7);">，都有 </font>![image](https://cdn.nlark.com/yuque/__latex/11cd28b82771bf339db21de8d8830b11.svg)<font style="color:rgb(6, 6, 7);">。</font>
2. **<font style="color:rgb(6, 6, 7);">对称性</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/4ea54d17639c118bb703bcac5969d9a5.svg)<font style="color:rgb(6, 6, 7);">，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/0a29ebb93ed83b52656aaf794986f59c.svg)<font style="color:rgb(6, 6, 7);">。</font>
3. **<font style="color:rgb(6, 6, 7);">传递性</font>**<font style="color:rgb(6, 6, 7);">：如果</font>![image](https://cdn.nlark.com/yuque/__latex/3902b20e7239b15f5b62a30eb835c5e6.svg)<font style="color:rgb(6, 6, 7);">且</font>![image](https://cdn.nlark.com/yuque/__latex/688925603bb93edaa81d548973e4e35f.svg)<font style="color:rgb(6, 6, 7);">，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/bb1a691e0076f650d8560fb6eec24a10.svg)<font style="color:rgb(6, 6, 7);">。</font>
4. **<font style="color:rgb(6, 6, 7);">线性组合</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/4ea54d17639c118bb703bcac5969d9a5.svg)<font style="color:rgb(6, 6, 7);">且</font>![image](https://cdn.nlark.com/yuque/__latex/95435a22ebd107b2deadf4ca9fb1815e.svg)<font style="color:rgb(6, 6, 7);">，那么对于任何整数</font>![image](https://cdn.nlark.com/yuque/__latex/14cb784d07a4234356ce44d06a5b8a3c.svg)<font style="color:rgb(6, 6, 7);">和</font>![image](https://cdn.nlark.com/yuque/__latex/2086b3e9a86ae9cf4579cb1fa00957f2.svg)<font style="color:rgb(6, 6, 7);">，都有 </font>![image](https://cdn.nlark.com/yuque/__latex/38e12afdadfb24801ad94feb85bc7f23.svg)
5. **<font style="color:rgb(6, 6, 7);">乘法性质</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/4ea54d17639c118bb703bcac5969d9a5.svg)<font style="color:rgb(6, 6, 7);">，那么对于任何整数</font>![image](https://cdn.nlark.com/yuque/__latex/14cb784d07a4234356ce44d06a5b8a3c.svg)<font style="color:rgb(6, 6, 7);">，都有 </font>![image](https://cdn.nlark.com/yuque/__latex/9f24c4f4eb6297fd1d4e524742b0d10f.svg)<font style="color:rgb(6, 6, 7);">。</font>
6. **<font style="color:rgb(6, 6, 7);">除法性质</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/4ea54d17639c118bb703bcac5969d9a5.svg)<font style="color:rgb(6, 6, 7);">且</font>![image](https://cdn.nlark.com/yuque/__latex/14cb784d07a4234356ce44d06a5b8a3c.svg)<font style="color:rgb(6, 6, 7);">是 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">和</font>![image](https://cdn.nlark.com/yuque/__latex/b19c6a394a363cf710008217809cdc76.svg)<font style="color:rgb(6, 6, 7);">的公因数，</font>



## 3.逆元
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">在数论中，逆元通常指的是模</font>![image](https://cdn.nlark.com/yuque/__latex/01a0b33465cb6a9a84504f60af049255.svg)<font style="color:rgb(6, 6, 7);">的逆元。设 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 是一个整数，</font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">是一个正整数，如果存在一个整数</font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/5036396b69b66bc1845bee05ad06842c.svg)<font style="color:rgb(6, 6, 7);">，那么我们称 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);"> 是 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">模 </font>![image](https://cdn.nlark.com/yuque/__latex/4760e2f007e23d820825ba241c47ce3b.svg)<font style="color:rgb(6, 6, 7);">的逆元，记作 </font>![image](https://cdn.nlark.com/yuque/__latex/2236310b74e749fafbcecac8224b8309.svg)

此外，逆元的范围属于1 ~（m-1）

### <font style="color:rgb(6, 6, 7);">例子</font>
1. <font style="color:rgb(6, 6, 7);">求 3模 7 的逆元：</font>
    - <font style="color:rgb(6, 6, 7);">我们需要找到一个整数 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);">，使得</font>![image](https://cdn.nlark.com/yuque/__latex/a207b1350f5132e1fc3e8365741bb8bb.svg)<font style="color:rgb(6, 6, 7);">。</font>
    - <font style="color:rgb(6, 6, 7);"></font>![image](https://cdn.nlark.com/yuque/__latex/77261a872e2c854182780bf700311ee4.svg)<font style="color:rgb(6, 6, 7);">。</font>
    - <font style="color:rgb(6, 6, 7);">因此，3 模 7的逆元是 5</font>
2. <font style="color:rgb(6, 6, 7);">求 2 模 9 的逆元：</font>
    - <font style="color:rgb(6, 6, 7);">我们需要找到一个整数 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/3a6c35e749a8f73185fe9dfc062687a5.svg)<font style="color:rgb(6, 6, 7);">。</font>
    - <font style="color:rgb(6, 6, 7);"></font>![image](https://cdn.nlark.com/yuque/__latex/c2e9f6082fcebeda5722b60127a68db4.svg)
    - <font style="color:rgb(6, 6, 7);">因此，2 模 9的逆元是 5。</font>

### <font style="color:rgb(6, 6, 7);">逆元的性质</font>
1. **<font style="color:rgb(6, 6, 7);">唯一性</font>**<font style="color:rgb(6, 6, 7);">：如果 a 模 m</font>_<font style="color:rgb(6, 6, 7);"></font>_<font style="color:rgb(6, 6, 7);">的逆元存在，那么它是唯一的。</font>
2. **<font style="color:rgb(6, 6, 7);">存在性</font>**<font style="color:rgb(6, 6, 7);">：a</font>_<font style="color:rgb(6, 6, 7);"></font>_<font style="color:rgb(6, 6, 7);">模 m 的逆元存在当且仅当 a和 m互质，即 </font>![image](https://cdn.nlark.com/yuque/__latex/0de6b207ef67ec4f9f28e4edf808664e.svg)<font style="color:rgb(6, 6, 7);">。</font>
3. **<font style="color:rgb(6, 6, 7);">逆元的逆元</font>**<font style="color:rgb(6, 6, 7);">：如果 b是 a模 m的逆元，那么 a是 b模 m</font><font style="color:rgb(6, 6, 7);">的逆元。</font>



## 4.欧拉函数
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">在数论中，欧拉函数 </font>![image](https://cdn.nlark.com/yuque/__latex/c31aeefc86524dd0d9dac6776444f2e0.svg)<font style="color:rgb(6, 6, 7);"> 表示小于或等于 </font>![image](https://cdn.nlark.com/yuque/__latex/df378375e7693bdcf9535661c023c02e.svg)<font style="color:rgb(6, 6, 7);">的正整数中与</font>![image](https://cdn.nlark.com/yuque/__latex/58e9ef90f745f513253970379e805547.svg)<font style="color:rgb(6, 6, 7);">互质的数的个数。</font>

### <font style="color:rgb(6, 6, 7);">性质</font>
1. **<font style="color:rgb(6, 6, 7);">积性函数</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">和 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);"> 互质，即 </font>![image](https://cdn.nlark.com/yuque/__latex/db05e7ce0b3ad2ec981933bfb37d7ac2.svg)<font style="color:rgb(6, 6, 7);">那么 </font>![image](https://cdn.nlark.com/yuque/__latex/d822f3f64ea69b8149ad425f145e8dd4.svg)
2. **<font style="color:rgb(6, 6, 7);"></font>**![image](https://cdn.nlark.com/yuque/__latex/66b220dff6aa2cd9008dff837ee5a624.svg)<font style="color:rgb(6, 6, 7);">：显然，1 与任何数互质。</font>
3. **<font style="color:rgb(6, 6, 7);">质数的欧拉函数</font>**<font style="color:rgb(6, 6, 7);">：对于质数</font>![image](https://cdn.nlark.com/yuque/__latex/8983e984a87e8e997172b9b33901f9d7.svg)
4. **<font style="color:rgb(6, 6, 7);">质数幂的欧拉函数</font>**<font style="color:rgb(6, 6, 7);">：对于质数的幂 </font>![image](https://cdn.nlark.com/yuque/__latex/880df6ab7591dfc4fdcf39a2f8fa1791.svg)
5. **<font style="color:rgb(6, 6, 7);">一般计算公式</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/01820e8427fa04ca458d78d4335c8eaa.svg)<font style="color:rgb(6, 6, 7);">，其中 </font>![image](https://cdn.nlark.com/yuque/__latex/39c69fbad0041c1d5caa9acf313cb0e6.svg)<font style="color:rgb(6, 6, 7);">是质数，</font>![image](https://cdn.nlark.com/yuque/__latex/26e255f82b8cc1651e50a820c5a16dc8.svg)<font style="color:rgb(6, 6, 7);">为正整数，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/89d8b560573bec343121592776b86a4a.svg)

### <font style="color:rgb(6, 6, 7);">例子</font>
1. **<font style="color:rgb(6, 6, 7);">计算 ϕ(10)</font>**_**<font style="color:rgb(6, 6, 7);"></font>**_<font style="color:rgb(6, 6, 7);">：</font>
    - <font style="color:rgb(6, 6, 7);">小于或等于 10 的正整数中与 10 互质的数有：1, 3, 7, 9。</font>
    - <font style="color:rgb(6, 6, 7);">ϕ(10)=4。</font>
2. **<font style="color:rgb(6, 6, 7);">计算 ϕ(12)</font>**_**<font style="color:rgb(6, 6, 7);"></font>**_<font style="color:rgb(6, 6, 7);">：</font>
    - <font style="color:rgb(6, 6, 7);">小于或等于 12 的正整数中与 12 互质的数有：1, 5, 7, 11。</font>
    - <font style="color:rgb(6, 6, 7);">ϕ(12)=4</font>
    - ![image](https://cdn.nlark.com/yuque/__latex/90e91eea656775222190781361e2afdb.svg)



## 5.欧拉定理
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">欧拉定理（Euler's Theorem）是数论中的一个重要定理，它描述了模运算中的一些性质。具体来说，对于任意整数 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 和正整数 </font>![image](https://cdn.nlark.com/yuque/__latex/df378375e7693bdcf9535661c023c02e.svg)<font style="color:rgb(6, 6, 7);">，如果 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);"> 和 </font>![image](https://cdn.nlark.com/yuque/__latex/df378375e7693bdcf9535661c023c02e.svg)<font style="color:rgb(6, 6, 7);"> 互质（即 </font>![image](https://cdn.nlark.com/yuque/__latex/e408699418f72f5c7f2a1fc7392f9c45.svg)<font style="color:rgb(6, 6, 7);">），那么有： </font>![image](https://cdn.nlark.com/yuque/__latex/41e9c1e75d0164f49028736bdf07cc1d.svg)<font style="color:rgb(6, 6, 7);"> 其中</font>![image](https://cdn.nlark.com/yuque/__latex/c31aeefc86524dd0d9dac6776444f2e0.svg)<font style="color:rgb(6, 6, 7);">是欧拉函数，表示小于或等于n的正整数中与 n互质的数的个数。</font>

### <font style="color:rgb(6, 6, 7);">例子</font>
1. **<font style="color:rgb(6, 6, 7);">计算</font>**![image](https://cdn.nlark.com/yuque/__latex/e37f501d288a41f211352a98dffdbbbf.svg)**<font style="color:rgb(6, 6, 7);">的最后两位数</font>**<font style="color:rgb(6, 6, 7);">：</font>
    - <font style="color:rgb(6, 6, 7);">首先，我们需要计算 </font>![image](https://cdn.nlark.com/yuque/__latex/a2f7a0ce0c474616c2db63bdc6a871c8.svg)<font style="color:rgb(6, 6, 7);">。因为 </font>![image](https://cdn.nlark.com/yuque/__latex/469b7a5d01d8936f879ca03c8ddc586c.svg)<font style="color:rgb(6, 6, 7);">，所以：</font>![image](https://cdn.nlark.com/yuque/__latex/813fe36ab68d1fc18b8443b715f26953.svg)
    - <font style="color:rgb(6, 6, 7);">由于</font>![image](https://cdn.nlark.com/yuque/__latex/7616e5d0714a3908623864a18477945d.svg)<font style="color:rgb(6, 6, 7);">，根据欧拉定理，我们有：</font>![image](https://cdn.nlark.com/yuque/__latex/67ac13d582cc08847abd006c583f0e73.svg)
    - <font style="color:rgb(6, 6, 7);">因此：</font>![image](https://cdn.nlark.com/yuque/__latex/53c4f749c14bd661250ae73aa6db96f2.svg)
    - <font style="color:rgb(6, 6, 7);">最后两位数是 27。</font>



## 6.费马小定理
<font style="color:rgb(6, 6, 7);">费马小定理（Fermat's Little Theorem）是数论中的一个基本定理。具体来说，如果</font>![image](https://cdn.nlark.com/yuque/__latex/3bb10f1d5025cd88d0887f887470953a.svg)<font style="color:rgb(6, 6, 7);">是一个质数，且 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">是一个不被</font>![image](https://cdn.nlark.com/yuque/__latex/4a0b1494d8b014da3f2bbe68b94ed5cb.svg)<font style="color:rgb(6, 6, 7);">整除的整数（即</font>![image](https://cdn.nlark.com/yuque/__latex/2f45afd3fbf50cef828a3fdd5b52bbee.svg)<font style="color:rgb(6, 6, 7);">，那么有：</font>![image](https://cdn.nlark.com/yuque/__latex/92993db1cef4737e361014170a49dfdc.svg)

### <font style="color:rgb(6, 6, 7);">例子</font>
**<font style="color:rgb(6, 6, 7);">计算 </font>**<font style="color:rgb(6, 6, 7);">：</font>![image](https://cdn.nlark.com/yuque/__latex/51bb5d4de34ddb82861126333d0c7157.svg)

    - <font style="color:rgb(6, 6, 7);">根据费马小定理，因为 11 是质数且</font>![image](https://cdn.nlark.com/yuque/__latex/4a501d4a187b9106d7b2a51ee86a3278.svg)<font style="color:rgb(6, 6, 7);">，所以</font>![image](https://cdn.nlark.com/yuque/__latex/c2985d125279ff516a2d5b0e1bbab998.svg)

### <font style="color:rgb(6, 6, 7);">费马小定理的应用</font>
<font style="color:rgb(6, 6, 7);">费马小定理在数论、密码学、计算机科学等领域有广泛的应用。例如，在RSA 加密算法中，费马小定理被用来简化模幂运算。此外，费马小定理还可以用于素性测试，即判断一个数是否为质数。</font>

<font style="color:rgb(6, 6, 7);"></font>

## <font style="color:rgb(6, 6, 7);">7.群</font>
<font style="color:rgb(6, 6, 7);">群是一个集合</font>![image](https://cdn.nlark.com/yuque/__latex/3dc9388c2579b8de16250f7593bacb32.svg)<font style="color:rgb(6, 6, 7);">，配备了一个二元运算 </font>![image](https://cdn.nlark.com/yuque/__latex/8e6e13634f4a22100629f406cd3c5945.svg)<font style="color:rgb(6, 6, 7);">，满足以下四个公理：</font>

1. **<font style="color:rgb(6, 6, 7);">封闭性</font>**<font style="color:rgb(6, 6, 7);">：对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/6e7ed7bd42c35827225892535efa46e1.svg)<font style="color:rgb(6, 6, 7);">，运算 </font>![image](https://cdn.nlark.com/yuque/__latex/6e7ed7bd42c35827225892535efa46e1.svg)<font style="color:rgb(6, 6, 7);">的结果也在</font>![image](https://cdn.nlark.com/yuque/__latex/3dc9388c2579b8de16250f7593bacb32.svg)<font style="color:rgb(6, 6, 7);">中。</font>
2. **<font style="color:rgb(6, 6, 7);">结合律</font>**<font style="color:rgb(6, 6, 7);">：对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/c85bdf3001ec60645f6a51c8d5a1091a.svg)<font style="color:rgb(6, 6, 7);">，有 </font>![image](https://cdn.nlark.com/yuque/__latex/5788d9f3db450de28f4d1b726bf9804d.svg)
3. **<font style="color:rgb(6, 6, 7);">单位元</font>**<font style="color:rgb(6, 6, 7);">：存在一个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/3fc553dce5a73fc29d2d57d695b71324.svg)<font style="color:rgb(6, 6, 7);">，使得对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/3fc553dce5a73fc29d2d57d695b71324.svg)<font style="color:rgb(6, 6, 7);">，有</font>![image](https://cdn.nlark.com/yuque/__latex/5a563cbfecddd5021dc61cd055862e9e.svg)
4. **<font style="color:rgb(6, 6, 7);">逆元</font>**<font style="color:rgb(6, 6, 7);">：对于每个 </font>![image](https://cdn.nlark.com/yuque/__latex/bc8c4ff0e741ca5dcc480e210fdc3799.svg)<font style="color:rgb(6, 6, 7);">，存在一个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/bde57c80be07cb7130a8248f19702704.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/606a0a8746439c2718c3b4217b4a3a7b.svg)

**<font style="color:rgb(6, 6, 7);">例子</font>**<font style="color:rgb(6, 6, 7);">：</font>

+ <font style="color:rgb(6, 6, 7);">整数集合</font>![image](https://cdn.nlark.com/yuque/__latex/61027f5f8c931b1232d321ecd254c694.svg)<font style="color:rgb(6, 6, 7);">在加法运算下构成一个群，单位元是 0，每个元素</font>![image](https://cdn.nlark.com/yuque/__latex/f1dec9e916c9b93c26bd11ac86a4b8f0.svg)<font style="color:rgb(6, 6, 7);">逆元是</font>![image](https://cdn.nlark.com/yuque/__latex/a1083fe6ac5f99c5a9a9484fecb452e8.svg)
+ <font style="color:rgb(6, 6, 7);">非零有理数集合 </font>![image](https://cdn.nlark.com/yuque/__latex/c36d15b34a7bc81ef4adabcd0efb3735.svg)<font style="color:rgb(6, 6, 7);"> 在乘法运算下构成一个群，单位元是 1，每个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">的逆元是 </font>![image](https://cdn.nlark.com/yuque/__latex/51886a2cd9de9aadc3acbafafb4de29f.svg)

<font style="color:rgb(6, 6, 7);"></font>

<font style="color:rgb(6, 6, 7);">大家课程结束后，还可以自行了解环、域的相关内容，都是抽象代数部分的知识</font>

<font style="color:rgb(6, 6, 7);"></font>

## <font style="color:rgb(6, 6, 7);">课后作业</font>
1.复习今天上课所学内容（古典密码的相关类型，数论基础）

2.完成[https://www.nssctf.cn/problem/5829](https://www.nssctf.cn/problem/5829)（<font style="color:rgb(0, 0, 0);">密码学？类魂？</font>）、[https://ctf.bugku.com/challenges/detail/id/60.html](https://ctf.bugku.com/challenges/detail/id/60.html)（贝斯家族）、

[https://ctf.bugku.com/challenges/detail/id/54.html](https://ctf.bugku.com/challenges/detail/id/54.html)（.!?）三道题目并保存好完整的wp

