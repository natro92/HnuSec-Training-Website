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
    - ![image](https://cdn.nlark.com/yuque/__latex/77261a872e2c854182780bf700311ee4.svg)<font style="color:rgb(6, 6, 7);">。</font>
    - <font style="color:rgb(6, 6, 7);">因此，3 模 7的逆元是 5</font>
2. 求 2 模 9 的逆元：
    - <font style="color:rgb(6, 6, 7);">我们需要找到一个整数 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/3a6c35e749a8f73185fe9dfc062687a5.svg)<font style="color:rgb(6, 6, 7);">。</font>
    - ![image](https://cdn.nlark.com/yuque/__latex/c2e9f6082fcebeda5722b60127a68db4.svg)
    - <font style="color:rgb(6, 6, 7);">因此，2 模 9的逆元是 5。</font>

### 逆元的性质
1. **<font style="color:rgb(6, 6, 7);">唯一性</font>**<font style="color:rgb(6, 6, 7);">：如果 a 模 m</font><font style="color:rgb(6, 6, 7);">的逆元存在，那么它是唯一的。</font>
2. **<font style="color:rgb(6, 6, 7);">存在性</font>**<font style="color:rgb(6, 6, 7);">：a</font>模 m 的逆元存在当且仅当 a和 m互质，即 ![image](https://cdn.nlark.com/yuque/__latex/0de6b207ef67ec4f9f28e4edf808664e.svg)<font style="color:rgb(6, 6, 7);">。</font>
3. **<font style="color:rgb(6, 6, 7);">逆元的逆元</font>**<font style="color:rgb(6, 6, 7);">：如果 b是 a模 m的逆元，那么 a是 b模 m</font><font style="color:rgb(6, 6, 7);">的逆元。</font>



## 4.欧拉函数
### <font style="color:rgb(6, 6, 7);">定义</font>
<font style="color:rgb(6, 6, 7);">在数论中，欧拉函数 </font>![image](https://cdn.nlark.com/yuque/__latex/c31aeefc86524dd0d9dac6776444f2e0.svg)<font style="color:rgb(6, 6, 7);"> 表示小于或等于 </font>![image](https://cdn.nlark.com/yuque/__latex/df378375e7693bdcf9535661c023c02e.svg)<font style="color:rgb(6, 6, 7);">的正整数中与</font>![image](https://cdn.nlark.com/yuque/__latex/58e9ef90f745f513253970379e805547.svg)<font style="color:rgb(6, 6, 7);">互质的数的个数。</font>

### <font style="color:rgb(6, 6, 7);">性质</font>
1. **<font style="color:rgb(6, 6, 7);">积性函数</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">和 </font>![image](https://cdn.nlark.com/yuque/__latex/d29c2e5f4926e5b0e9a95305650f6e54.svg)<font style="color:rgb(6, 6, 7);"> 互质，即 </font>![image](https://cdn.nlark.com/yuque/__latex/db05e7ce0b3ad2ec981933bfb37d7ac2.svg)<font style="color:rgb(6, 6, 7);">那么 </font>![image](https://cdn.nlark.com/yuque/__latex/d822f3f64ea69b8149ad425f145e8dd4.svg)
2. ![image](https://cdn.nlark.com/yuque/__latex/66b220dff6aa2cd9008dff837ee5a624.svg)<font style="color:rgb(6, 6, 7);">：显然，1 与任何数互质。</font>
3. **<font style="color:rgb(6, 6, 7);">质数的欧拉函数</font>**<font style="color:rgb(6, 6, 7);">：对于质数</font>![image](https://cdn.nlark.com/yuque/__latex/8983e984a87e8e997172b9b33901f9d7.svg)
4. **<font style="color:rgb(6, 6, 7);">质数幂的欧拉函数</font>**：对于质数的幂 ![image](https://cdn.nlark.com/yuque/__latex/880df6ab7591dfc4fdcf39a2f8fa1791.svg)
5. **<font style="color:rgb(6, 6, 7);">一般计算公式</font>**<font style="color:rgb(6, 6, 7);">：如果 </font>![image](https://cdn.nlark.com/yuque/__latex/01820e8427fa04ca458d78d4335c8eaa.svg)<font style="color:rgb(6, 6, 7);">，其中 </font>![image](https://cdn.nlark.com/yuque/__latex/39c69fbad0041c1d5caa9acf313cb0e6.svg)<font style="color:rgb(6, 6, 7);">是质数，</font>![image](https://cdn.nlark.com/yuque/__latex/26e255f82b8cc1651e50a820c5a16dc8.svg)<font style="color:rgb(6, 6, 7);">为正整数，那么 </font>![image](https://cdn.nlark.com/yuque/__latex/89d8b560573bec343121592776b86a4a.svg)

### <font style="color:rgb(6, 6, 7);">例子</font>
1. **<font style="color:rgb(6, 6, 7);">计算 ϕ(10)</font>**<font style="color:rgb(6, 6, 7);">：</font>
    - <font style="color:rgb(6, 6, 7);">小于或等于 10 的正整数中与 10 互质的数有：1, 3, 7, 9。</font>
    - ϕ(10)=4。
2. **<font style="color:rgb(6, 6, 7);">计算 ϕ(12)</font>**
    - <font style="color:rgb(6, 6, 7);">小于或等于 12 的正整数中与 12 互质的数有：1, 5, 7, 11。</font>
    - ϕ(12)=4
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

### <font style="color:rgb(6, 6, 7);">费马小定理的应用</font>
费马小定理在数论、密码学、计算机科学等领域有广泛的应用。例如，在RSA 加密算法中，费马小定理被用来简化模幂运算。此外，费马小定理还可以用于素性测试，即判断一个数是否为质数。

## <font style="color:rgb(6, 6, 7);">7.群</font>
<font style="color:rgb(6, 6, 7);">群是一个集合</font>![image](https://cdn.nlark.com/yuque/__latex/3dc9388c2579b8de16250f7593bacb32.svg)<font style="color:rgb(6, 6, 7);">，配备了一个二元运算 </font>![image](https://cdn.nlark.com/yuque/__latex/8e6e13634f4a22100629f406cd3c5945.svg)<font style="color:rgb(6, 6, 7);">，满足以下四个公理：</font>

1. **<font style="color:rgb(6, 6, 7);">封闭性</font>**<font style="color:rgb(6, 6, 7);">：对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/6e7ed7bd42c35827225892535efa46e1.svg)<font style="color:rgb(6, 6, 7);">，运算 </font>![image](https://cdn.nlark.com/yuque/__latex/6e7ed7bd42c35827225892535efa46e1.svg)<font style="color:rgb(6, 6, 7);">的结果也在</font>![image](https://cdn.nlark.com/yuque/__latex/3dc9388c2579b8de16250f7593bacb32.svg)<font style="color:rgb(6, 6, 7);">中。</font>
2. **<font style="color:rgb(6, 6, 7);">结合律</font>**<font style="color:rgb(6, 6, 7);">：对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/c85bdf3001ec60645f6a51c8d5a1091a.svg)<font style="color:rgb(6, 6, 7);">，有 </font>![image](https://cdn.nlark.com/yuque/__latex/5788d9f3db450de28f4d1b726bf9804d.svg)
3. **<font style="color:rgb(6, 6, 7);">单位元</font>**<font style="color:rgb(6, 6, 7);">：存在一个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/3fc553dce5a73fc29d2d57d695b71324.svg)<font style="color:rgb(6, 6, 7);">，使得对于所有 </font>![image](https://cdn.nlark.com/yuque/__latex/3fc553dce5a73fc29d2d57d695b71324.svg)<font style="color:rgb(6, 6, 7);">，有</font>![image](https://cdn.nlark.com/yuque/__latex/5a563cbfecddd5021dc61cd055862e9e.svg)
4. **<font style="color:rgb(6, 6, 7);">逆元</font>**<font style="color:rgb(6, 6, 7);">：对于每个 </font>![image](https://cdn.nlark.com/yuque/__latex/bc8c4ff0e741ca5dcc480e210fdc3799.svg)<font style="color:rgb(6, 6, 7);">，存在一个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/bde57c80be07cb7130a8248f19702704.svg)<font style="color:rgb(6, 6, 7);">，使得 </font>![image](https://cdn.nlark.com/yuque/__latex/606a0a8746439c2718c3b4217b4a3a7b.svg)

**<font style="color:rgb(6, 6, 7);">例子</font>**<font style="color:rgb(6, 6, 7);">：</font>

+ <font style="color:rgb(6, 6, 7);">整数集合</font>![image](https://cdn.nlark.com/yuque/__latex/61027f5f8c931b1232d321ecd254c694.svg)<font style="color:rgb(6, 6, 7);">在加法运算下构成一个群，单位元是 0，每个元素</font>![image](https://cdn.nlark.com/yuque/__latex/f1dec9e916c9b93c26bd11ac86a4b8f0.svg)<font style="color:rgb(6, 6, 7);">逆元是</font>![image](https://cdn.nlark.com/yuque/__latex/a1083fe6ac5f99c5a9a9484fecb452e8.svg)
+ <font style="color:rgb(6, 6, 7);">非零有理数集合 </font>![image](https://cdn.nlark.com/yuque/__latex/c36d15b34a7bc81ef4adabcd0efb3735.svg)<font style="color:rgb(6, 6, 7);"> 在乘法运算下构成一个群，单位元是 1，每个元素 </font>![image](https://cdn.nlark.com/yuque/__latex/26fdbf8e53cb0e48da5f4ddd4aaf5a5c.svg)<font style="color:rgb(6, 6, 7);">的逆元是 </font>![image](https://cdn.nlark.com/yuque/__latex/51886a2cd9de9aadc3acbafafb4de29f.svg)

# RSA

## 密钥生成

RSA密钥生成包括以下步骤：
①选择两个大质数p和q	
②计算n=pq	
③欧拉公式φ(n)=(p-1)(q-1)	
④选择一个整数e，使得1<e<φ(n)，且e和φ(n)互质	
⑤计算e关于φ(n)的模逆元d，即ed≡1(mod φ(n))	
此时就能得到公钥pk=(e, n)，私钥sk=(d, n)

## RSA加密和解密

给定明文M，加密过程如下：

- 计算C≡M**e (mod n)，得到的C就是密文。

给定密文C，解密过程如下：

- 计算M≡C**d (mod n)，得到的M就是解密后的明文。

# 对称密码

## 一、基础知识

### （一）异或

运算规则：同为0，异为1

| 0⊕0=0 | 1⊕1=0 |
| ----- | ----- |
| 0⊕1=1 | 1⊕0=1 |

### （二）常见三种运算符

1. **^** ，异或计算
2. **|** ，有1则1，全0才0 （析取）
3. **&** ，有0则0，全1才1（合取）

### （三）奇偶校验

奇偶校验是一种校验代码传输正确性的方法。根据被传输的一组二进制代码的数位中“1”的个数是奇数或偶数来进行校验。

采用奇数的称为奇校验，反之，称为偶校验。采用何种校验是**事先规定好**的。通常专门设置一个奇偶校验位，用它使这组代码中“1”的个数为奇数或偶数。

用奇校验，则当接收端收到这组代码时，校验“1”的个数是否为奇数，从而确定传输代码的正确性。

### （四）有限域

有限域是包括有限个元素、能进行加减乘除运算的集合

- 单位元：任何元素与单位元做运算，得到的都是该元素，单位元是唯一的。
- 逆元：A与B做运算，得到的结果是单位元，则A和B互为该运算下的逆元
- 封闭性：运算元素和结果都在域中有对应元素
- 结合律
- 交换律
- 分配律
- 无零因子

用处：将四则运算精简为二则运算加和乘

##### 有限域$GF(p)$

p一定为素数，运算是模p的运算，域中有p个元素，p为素数保证每个元素都有加法和乘法逆元

例：$GF(p)$，其中 p = 7

- 加：$(a\oplus b)(mod\ 7)=(a+b)(mod\ 7)$
- 减：$(a\ominus b)(mod\ 7)=(a+(-b))(mod\ 7)$，-b为 b 的加法逆元
- 乘：$(a\otimes b)(mod\ 7)=(a\times b)(mod\ 7)$
- 除：$(a\oslash b)(mod\ 7)=(a/ b)(mod\ 7)=(a\times(b^{-1}))(mod\ 7)$，$b^{-1}$是 b 的乘法逆元

	在这里，已知$5\otimes 3=1$，所以$6\oslash5=6\otimes3=4$，除法运算要求在有限域$GF(7)$内，满足封闭性

##### 符合二进制的域$GF(2^m)$

**$GF(2)$**：只有0和1元素，01相加减都需要模2，符合异或运算

**扩展域：** 如果有限域的阶不是素数，则在这个有限域内加法和乘法操作就不能模p，$ m>1 $ 的域称为扩展域。扩展域的元素可以用多项式表示，且扩展域内的计算也可以通过多项式运算得到。

**扩展域$GF(2^m)$：** 在AES中包含256个元素的有限域可以用$GF(2^8)$。该域的每一个元素都可以用一个字节表示。

每个元素 $ A\in GF(2^8) $ 都可以表示为：$ A(x)=b_7x^7+……+b_1x+b_0, b_i\in GF(2)={0,1} $

简单举例：$ 1=1,2=x,3=1+x,4=x^2,5=1+x^2,6=x+x^2,…… $

##### 运算

**加法：** 异或

例：$57+66=01010111+01100110=00110001=31$，这里的57、66和31均为16进制

**乘法：** 先乘再加，最后模，这里的模多项式采用$m(x)=x^8+x^4+x^3+x+1$
$$
57\times 66=01010111\times 01100110\\
=(x^6+x^4+x^2+x+1)\times (x^6+x^5+x^2+x)\\
=x^{12}+x^{10}+x^8+x^7+x^6+x^{11}+x^9+x^7+x^6+x^5\\
+x^8+x^6+x^4+x^3+x^2+x^7+x^5+x^3+x^2+x\\
=x^{12}+x^{11}+x^{10}+x^9+x^7+x^6+x^4+x(mod\ x^8+x^4+x^3+x+1)\\
=x^7+x^5+x^4+x^3+x+1
$$

## 二、分组密码

定义：将明文消息分割成固定长度的数据块，并使用相同的密钥和算法对每个数据块进行加密

例：加密FOUR_AND_FOUR利用分组密码可以先加密FOUR，再加密\_AND\_ ，最后加密FOUR，即一次加密明文中一个字符块

### （一）分组模式

分为ECB（电子密码本）、CBC（密码块链接）、CFB（密码反馈），OFB（输出反馈），前两种模式使用分组密码，后两种模式将分组密码当作流密码使用，另外常见还有CTR（计数器），是OFB的变种

1. **ECB**

   一般给定密钥后，相同的明文块会有相同的密文块，如果明文块反复出现，对应的密文块也会多次出现，会为破解密文提供线索

   **加密：**

   ![img](https://camo.githubusercontent.com/db3ee3a2ca4d39b5a3dcf80d6bd8e60d35403badab54942396068723633bb90b/68747470733a2f2f6374662d77696b692e6f72672f63727970746f2f626c6f636b6369706865722f6d6f64652f6669677572652f6563625f656e6372797074696f6e2e706e67)

   电子密码本仅适合加密短消息，明文重复少，破解几率低

   **解密：**

   ![img](https://camo.githubusercontent.com/77c3f6a5af70e314a78d22b713e5533f6c7e3f802f02d7a87c35bb4dc85595b1/68747470733a2f2f6374662d77696b692e6f72672f63727970746f2f626c6f636b6369706865722f6d6f64652f6669677572652f6563625f64656372797074696f6e2e706e67)

2. **CBC**

   在块密码中增加反馈机制链接，即用每个块来修饰下一个块的加密

   **加密：**

   ![img](https://camo.githubusercontent.com/6c6bf60c3edb52e40c461c6b482c809892d38f1ee04cdbdd40b2be4d47f4c0db/68747470733a2f2f6374662d77696b692e6f72672f63727970746f2f626c6f636b6369706865722f6d6f64652f6669677572652f6362635f656e6372797074696f6e2e706e67)

   (1) 如图所示，第1步有两个输入：第1个明文块和一个随机文本块。随机文本块是初始化向量（IV），没有特殊含义，只是为了使每个消息独特。将第1个明文块和IV异或再用密钥加密，生成密文块1

   (2) 将密文块1跟明文块2异或后再用密钥加密得出密文块2，依次类推

   注：IV仅在第1个明文块中使用，但用相同的密钥加密

   **解密：**

   ![img](https://camo.githubusercontent.com/d2335d4710a9d497c9f2865c588441726d022352e0c16779f118ad00909f2600/68747470733a2f2f6374662d77696b692e6f72672f63727970746f2f626c6f636b6369706865722f6d6f64652f6669677572652f6362635f64656372797074696f6e2e706e67)

关于填充，一般情况下明文长度是不符合分块要求的，需要对此进行填充。

常见填充方式如下：

1. **ISO 10126：** 规定应在最后一个块的末尾用随机字节进行填充，填充边界应由最后一个字节指定。

   这种填充方式中，填充字符串的最后一个字节为填充字节的长度，其他为随机字节

   例如：现在有3bytes，块大小为8bytes，需要填充5bytes，则最后一个为 05，其他全部为 00

   原数据：66 6F 72

   填充后的数据：66 6F 72 81 A3 00 23 05

2. **PKCS7：** 假设需要填充n (n>0) 个字节才对齐，填充n个字节，每个字节都是n ；如果数据本身就已经对齐了，则填充一块长度为块大小的数据，每个字节都是块大小；PKCS7填充字节的范围在 **1-255 **之间 ，填充方式为上面的 填充数据为填充字节的长度，填充如下：

   ```
   01
   02 02
   03 03 03
   04 04 04 04
   05 05 05 05 05
   06 06 06 06 06 06
   ```
   
当且仅当N小于256时才有用。
   
原数据：66 6F 72
   
填充后的数据：66 6F 72 05 05 05 05 05
   
3. **PKCS5：** 将数据填充到8的倍数，填充数据计算公式是，假如原数据长度为len，利用该方法填充后的长度是 len + (8 - (len % 8)), 填充的数据长度为 8 - (len % 8)，块大小固定为8字节，和PKCS7的区别在于，5的填充块大小为8bytes，而7的填充块大小可以在1-255bytes之间。

4. **ISO/IEC 7816-4：** 第一个字节是值为 '80' （十六进制） 的强制字节，如果需要，后跟 0 到 *N* − 1 个设置为 '00' 的字节，直到到达块的末尾

   例如：66 6F 72 80 00 00 00 00

5. **Zero padding：** 所有需要填充的字节都用零填充。比如66 6F 72 00 00 00 00 00。它通常应用于二进制编码的字符串(以null 结尾的字符串)，因为null字符通常可以作为空格被剥离。

### （二）DES

DES使用56位的密钥和64位的明文块进行加密，初始密钥实际上也是64位，但在开始之前，丢弃了密钥的每个第8位，得到56位密钥。丢弃之前可进行奇偶校验，以确保密钥不包含任何错误。

![img](https://camo.githubusercontent.com/343e3d318e524c54821152dfef30ec10c5f1643dc34fd24559877d8c3d750495/68747470733a2f2f692d626c6f672e6373646e696d672e636e2f626c6f675f6d6967726174652f31333035376663613864326165393361383762626365623535393734363833322e706e67)

#### (1)初始置换

初始置换只发生一次，且只发生在第一轮之前，例如，初始置换指定要将原始明文块的第1位替换成原始明文块的第58位，第2位替换成第50位等。

完成初始置换后，生成的64位置换明文块被分为两半，各32位，左半块是左明文(L0)，右半块是右明文(R0)，对这两块执行16轮操作

<img src="https://www.nssctf.cn//files/2023/5/5/faaaf1f97e.png" alt="img" style="zoom:80%;" />

#### (2)获取子密钥

在进入第一轮之前，还需要对密钥进行处理生成子密钥，每一轮将使用不同的子密钥参与运算。DES加密算法的密钥长度为56位，一般表示为`64`位(每个第`8`位用于奇偶校验)，将用户提供的`64`位初始密钥经过一系列的处理得到K1,K2,…,K16，分别作为1~16轮运算的16个子密钥。

1. 将64位密钥去掉8个校验位，用密钥置换`PC-1`置换剩下的56位密钥。

   `PC-1`置换表如下

   ![图 3](https://www.nssctf.cn//files/2023/5/5/190d319ce5.png)

2. 将56位分成前28位C0和后28位D0。

3. 根据轮数，这两部分分别循环左移1位或2位

   ![图 4](https://www.nssctf.cn//files/2023/5/5/574f070ad3.png)

4. 移动后，将两部分合并成56位后通过压缩置换`PC-2`后得到48位子密钥。

   `PC-2`置换表如下

   ![图5](https://www.nssctf.cn//files/2023/5/5/458f8126c3.png)

#### (3)轮函数f

轮函数F的作用是将输入的32比特数据和48比特子密钥进行加密输出32比特

扩展置换E：将数据的右半部分`Ri`从32位扩展为48位。位选择函数(也称E盒)。

异或：扩展后的48位输出`E(Ri)`与压缩后的48位密钥Ki作异或运算；

S盒替换：将异或得到的48位结果分成八个6位的块，每一块通过对应的一个S盒产生一个4位的输出。（8个不同s盒压缩处理）

|  \   |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |  13  |  14  |  15  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  0   |  14  |  4   |  13  |  1   |  2   |  15  |  11  |  8   |  3   |  10  |  6   |  12  |  5   |  9   |  0   |  7   |
|  1   |  0   |  15  |  7   |  4   |  14  |  2   |  13  |  1   |  10  |  6   |  12  |  11  |  9   |  5   |  3   |  8   |
|  2   |  4   |  1   |  14  |  8   |  13  |  6   |  2   |  11  |  15  |  12  |  9   |  7   |  3   |  10  |  5   |  0   |
|  3   |  15  |  12  |  8   |  2   |  4   |  9   |  1   |  7   |  5   |  11  |  3   |  14  |  10  |  0   |  6   |  13  |

例如输入`101010`到S1中。S1会将这六位的第一位和第六位拿出来`10`作为S1的行，中间四位`0101`拿出来作为S1的列。我们转换成十进制，此时映射到这个S盒的位置就是`(2,5)`对应S盒的**第3行第6列**（索引都从0开始数）。

![img](https://i-blog.csdnimg.cn/blog_migrate/77c447f7c19980ee161f0f207aa6a61a.png)

P盒置换：将S盒得到的输出再和P盒进行置换操作。

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/ab90e6a45ca4374fcd9ac80fa5046eee.png)

#### (4)逆置换

也叫最终置换，DES加密过程最后的逆置换IP−1，是初始置换的逆过程。经过16次迭代运算后，进行逆置换，即得到密文输出。逆置换正好是初始置的逆运算。例如，第1位经过初始置换后，处于第40位，而通过逆置换，又将第40位换回到第1位。置换表如下：

![图7](https://www.nssctf.cn/files/2023/5/5/a3a3fe5a5f.png)

### （三）AES

#### 1. 加密

![aes_struct](https://i-blog.csdnimg.cn/blog_migrate/574604ab6bf5f632f275528b95a4d8a2.png)

**秘钥扩展 **
示例秘钥key = “abcdefghijklmnop”={0x61, 0x62,…,0x6F,0x70}。
AES128中原始秘钥key为16字节，运算中需要11个矩阵大小的秘钥，每一列所包含的32位记为一个uint32_t W，所以秘钥扩展一共需要生产44个列W，即uint32_t W[44]。![秘钥扩展](https://i-blog.csdnimg.cn/blog_migrate/461a595346442c2681be7d491f78c116.png)



W[0-3]为直接复制的原始秘钥。

W[0] = 0x61626364.
W[1] = 0x65666768.
W[2] = 0x696A6B6C.
W[3] = 0x6D6E6F70.
W[4-43]为扩展的秘钥。

![image-20250722170312471](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722170312471.png)

Mix(x)=SubWord(RotWord(x))

RotWord()为循环左移一位

SubWord()为字节替换

rcon为轮常量异或，常量数组为：

![image-20250722170426489](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722170426489.png)

下面举个例子：
设初始的128位密钥为：
3C A1 0B 21 57 F0 19 16 90 2E 13 80 AC C1 07 BD
那么4个初始值为：
W[0] = 3C A1 0B 21
W[1] = 57 F0 19 16
W[2] = 90 2E 13 80
W[3] = AC C1 07 BD
下面求扩展的第1轮的子密钥(W[4],W[5],W[6],W[7])。
由于4是4的倍数，所以：
W[4] = W[0] ⨁ T(W[3])
T(W[3])的计算步骤如下：

循环地将W[3]的元素移位：AC C1 07 BD变成C1 07 BD AC;
将 C1 07 BD AC 作为S盒的输入，输出为78 C5 7A 91;
将78 C5 7A 91与第一轮轮常量Rcon[1]进行异或运算，将得到79 C5 7A 91，因此，T(W[3])=79 C5 7A 91，故
W[4] = 3C A1 0B 21 ⨁ 79 C5 7A 91 = 45 64 71 B0
其余的3个子密钥段的计算如下：
W[5] = W[1] ⨁ W[4] = 57 F0 19 16 ⨁ 45 64 71 B0 = 12 94 68 A6
W[6] = W[2] ⨁ W[5] =90 2E 13 80 ⨁ 12 94 68 A6 = 82 BA 7B 26
W[7] = W[3] ⨁ W[6] = AC C1 07 BD ⨁ 82 BA 7B 26 = 2E 7B 7C 9B
所以，第一轮的密钥为 45 64 71 B0 12 94 68 A6 82 BA 7B 26 2E 7B 7C 9B。

**轮密钥加：** 明文矩阵P，子密钥矩阵K，轮密钥加的结果就是两个矩阵对应元素异或

**字节替换：** 将字节看作$GF(2^8)$上的元素，根据s盒做映射，然后对字节做如下的（$GF(2)$上可逆的）仿射变换

**行移位：** 第一行不变，第二行左移1，第三行左移2，第四行左移3

**列混淆：** 列混合通过矩阵相乘来实现，经过移位后的矩阵左乘一个固定的矩阵，得到混淆后的矩阵，如下公式所示

![image-20250722170914016](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722170914016.png)

上述矩阵相乘可以化简为如下表达式：

![image-20250722170933235](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722170933235.png)

其中矩阵的乘法和加法并不是通常意义上的乘法和加法，而是定义在伽罗华域上的二元运算，且使用的不可约多项式为P ( x ) = x 8 + x 4 + x 3 + x + 1 。其加法为模二加法，相当于异或运算，其乘法可以使用GMul表示，则上式运算可以表示为

![image-20250722171020927](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722171020927.png)

解密时**逆列混合**操作和列混合一样，只是左乘的矩阵使用如下矩阵。可以验证此矩阵B是列混合使用矩阵A的逆矩阵，两者乘积为单位矩阵，即AB=BA=E

![image-20250722171055512](C:/Users/mingtian/AppData/Roaming/Typora/typora-user-images/image-20250722171055512.png)

#### 2. 解密

- 交换逆向行移位和逆向字节代替并不影响结果
- 交换轮密钥加和逆向列混淆并不影响结果，关键在于首先可以把异或看成域上的多项式加法，然后多项式中乘法对加法具有分配律

**加解密全图**

<img src="https://ctf-wiki.org/crypto/blockcipher/figure/aes_enc_dec.png" style="zoom:80%;" />

## 三、流密码

定义：流密码是加密和解密双方使用相同伪随机加密数据流作为密钥，明文数据每次与密钥数据流顺次对应加密，得到密文数据流。实践中数据通常是一个位（bit）并用异或（XOR）操作加密 可以理解成明⽂ ⊕ 密钥，但是密钥是由⼀个伪随机数⽣成器⽣成的

### PRG/PRNG伪随机数生成器

伪随机序列：如果一个序列能够和等长的随机序列不可区分的话，那么它就是伪随机序列，即可以以假乱真的序列

#### LCG线性同余生成器

LCG的原理是通过一个递归公式生成下一个随机数，包含一个乘法因子、一个加法常数和一个模数。
$$
X_{n+1}=AX_n+B(mod\ m)\\
其中乘法因子0<A<m，加法常数0≤B<m，模数m>0\\
A=13,B=17,m=22,X_n=8\\
X_{n+1}=(13\times 8+17)mod\ 22\ =121\ mod\ 22=11
$$
python：

```python
import time
seed = int(time.time())
a=13
b=17
m=22
def generate_random(seed):
    while True:
        seed = (a * seed + b ) % m
        yield seed

random_generator=generate_random(seed)

for i in range(20):
    random_number = next(random_generator)
    print(random_number)
```


