# <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">CTF-Misc</font>
<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">CTF中的Misc（杂项）方向是涵盖范围极广、综合性很强的题目类型，常被称为CTF的“万金油”方向。它不像Web或Pwn那样有明确的技术边界，而是融合了编码、隐写、取证、数据分析等多种技能，题目形式灵活多变，可能涉及图片、音频、视频、压缩包甚至网络流量中的隐藏信息。解题时往往需要快速判断题目类型，灵活运用各种工具（如Stegsolve、Binwalk、CyberChef等）进行分析，有时还需要结合逻辑推理或脑洞猜测。Misc题目既适合新手入门（比如简单的Base64解码或图片隐写），也能设计得非常复杂（如多层隐写+流量分析+取证综合题），因此既是CTF比赛的“得分大户”，也是考验选手综合能力的试金石。</font>

## <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">常见题型</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">隐写术</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：在图片、音频、视频中隐藏信息，如LSB隐写、盲水印等。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">文件分析</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：修复损坏的压缩包、文件头，提取隐藏数据</font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">编码转换</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：Base64、Hex等编码的识别与解码</font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">网络与流量分析</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：解析pcap文件，提取关键信息</font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">数字取证</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：内存取证、日志分析、EXIF信息提取等。</font>

## 常用的工具
1. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">隐写分析：Stegsolve、Steghide、zsteg。</font>
2. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">文件处理：010 Editor、WinHex、binwalk。</font>
3. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">编码转换：CyberChef、Python</font>

## Base系列编码介绍
### <font style="color:rgba(0, 0, 0, 0.87);">base16</font>
<font style="color:rgba(0, 0, 0, 0.87);">使用所有数字和大写字母A-F，其实就是Hex</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079120566-049a437c-8db8-4475-853b-c1bef69d50b4.png)

### <font style="color:rgba(0, 0, 0, 0.87);">base32</font>
<font style="color:rgba(0, 0, 0, 0.87);">只使用数字2-7和所有大写字母，末尾补位的'='：0~6个</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079150253-3a395426-4ee0-409f-bde0-510e648f23da.png)

### <font style="color:rgba(0, 0, 0, 0.87);">base58</font>
<font style="color:rgba(0, 0, 0, 0.87);">没有0，O，小写L，大写i，+和/，不使用‘=’补位</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079169388-41894cf5-2da3-461d-83cc-ecbcf6e9f415.png)

### <font style="color:rgba(0, 0, 0, 0.87);">BASE 62</font>
<font style="color:rgba(0, 0, 0, 0.87);">使用所有字母和数字</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079186631-0d30359a-9d02-4727-a95c-18ead67bd6d8.png)

### <font style="color:rgba(0, 0, 0, 0.87);">BASE 64</font>
<font style="color:rgba(0, 0, 0, 0.87);">使用所有字母和数字，及’+‘和’/‘，末尾会使用最多两个‘=’进行补位</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079202613-13e1e7bc-ad0d-42e6-adcf-1287f2ae6167.png)

### <font style="color:rgba(0, 0, 0, 0.87);">BASE 85</font>
<font style="color:rgba(0, 0, 0, 0.87);">使用所有字母和数字，以及 !#$%&()*+-;<=>?@^_`{|}~</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079221573-abbf14bf-e2d7-49ab-bf2a-e92afa69c489.png)

### <font style="color:rgba(0, 0, 0, 0.87);">BASE 100</font>
<font style="color:rgba(0, 0, 0, 0.87);">全都是emoji</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079278183-78ac531d-4c94-4639-b6e9-02dfe818ba8d.png)



## 其他编码
### <font style="color:rgba(0, 0, 0, 0.87);">brainfuck</font>[<font style="color:rgba(0, 0, 0, 0.32);">¶</font>](https://hnusec-training.natro92.fun/misc/lesson-1/#brainfuck)
<font style="color:rgba(0, 0, 0, 0.87);">一种计算机语言，只有八种符号，<>+-.,[]</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079376242-8304b172-39cf-4097-9c4c-2a2172772431.png)

### <font style="color:rgba(0, 0, 0, 0.87);">Ook</font>
<font style="color:rgba(0, 0, 0, 0.87);">全篇都是Ook加上.!字符</font>

  
 ![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079422564-746851e2-3f73-4d8d-b160-ea9170924ecc.png)  
 

### <font style="color:rgba(0, 0, 0, 0.87);">敲击码</font>
<font style="color:rgba(0, 0, 0, 0.87);">密文的特征为1-5的两位一组的数字，编码的范围是A-Z字母字符集，字母不区分大小写。</font>  
 ![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079487726-35a5fdeb-871f-42e4-9add-adbd3079a010.png)![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079512871-5f5cbfcb-a345-4148-93f7-e8402e577c63.png)

### <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">中文电码</font>
四位数一组编码<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">  
</font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">   
</font>![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753079598452-46f462bc-2258-4b1c-bf53-bd3919fcd799.png)

### <font style="color:rgba(0, 0, 0, 0.87);">键盘相关编码</font>
比如：

（1）外形

<font style="color:rgba(0, 0, 0, 0.87);">EWAZX RTY TGB IJN IO KL</font>

<font style="color:rgba(0, 0, 0, 0.87);">在键盘上的形状是CTF</font>

<font style="color:rgba(0, 0, 0, 0.87);">（2）缺失</font>

<font style="color:rgba(0, 0, 0, 0.87);">asdghjkl asdfghjk sdfghjkl asdfhjkl</font>

<font style="color:rgba(0, 0, 0, 0.87);">对应键盘一行缺失的字母是flag</font>

### <font style="color:rgba(0, 0, 0, 0.87);">其他各种奇形怪状的编码</font>
<font style="color:rgba(0, 0, 0, 0.87);">核心价值观编码、阴阳怪气编码、八卦编码等等...</font>

<font style="color:rgba(0, 0, 0, 0.87);"></font>

## <font style="color:rgba(0, 0, 0, 0.87);">offic文件</font>
### word
<font style="color:rgba(0, 0, 0, 0.87);">最简单的情况：只是把文字颜色改成了白色</font>

<font style="color:rgba(0, 0, 0, 0.87);">或者是空格和tab的交替使用，这种情况下有的通过查找替换成1和0就能解决，有的则是snow隐写</font>

<font style="color:rgba(0, 0, 0, 0.87);">如果什么都没有：查看是否显示隐藏文字</font>

### <font style="color:rgba(0, 0, 0, 0.87);">PDF</font>
简单情况下：使用PDF编辑器把图片移开就是flag

或者把pdf reverse了，我们需要把其复原打开

或者<font style="color:rgba(0, 0, 0, 0.87);">PS打开看有没有多图层</font>

## <font style="color:rgba(0, 0, 0, 0.87);">文件结构</font>
<font style="color:rgba(0, 0, 0, 0.87);">用010editor打开查看，看有无多余信息，通常在末尾，可以搜索文本flag或者其他常见关键词。用binwalk分离文件，也可以手动。有时文件头可能会被修改，比如小写改大写等。</font>

```plain
zip 文件头：50 4B 03 04 14 00 08 00 
rar 文件头：52 61 72 21 (Rar!)               文件尾：C4 3D 7B 00 40 07 00
7z  文件头：37 7A BC AF 27 1C
png 文件头：89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52   文件尾：49 45 4E 44 AE 42 60 82
jpg 文件头：FF D8 FF E0 00 10 4A 46 49 46 00 01
gif 文件头：47 49 46 38 39 61（GIF89A）或 47 49 46 38 37 61（GIF87A）    文件尾：00 3B
```

<font style="color:rgba(0, 0, 0, 0.87);">  
</font><font style="color:rgba(0, 0, 0, 0.87);"> </font>

## <font style="color:rgba(0, 0, 0, 0.87);">ZIP</font>
<font style="color:rgb(76, 73, 72);">zip有密码先看是不是伪加密，再看能不能爆破出来，要不要明文攻击，有没有注释等等</font>

### <font style="color:rgba(0, 0, 0, 0.87);">伪加密</font>
<font style="color:rgba(0, 0, 0, 0.87);">全局方式位标记 偶数无加密，奇数有加密。比如06 00有加密，00 00或14 00无加密</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753080470204-78d3bfde-378d-4660-bb59-a4944e21da21.png)

<font style="color:rgb(51, 51, 51);">文件头--解压文件要的版本--全局标记是否加密--压缩方式--修改文件时间和日期--crc32--压缩后尺寸和未压缩尺寸--文件名长度--扩展长度</font>

## <font style="color:rgba(0, 0, 0, 0.87);">图片</font>
<font style="color:rgba(0, 0, 0, 0.87);">（1）图片后面藏东西比较多先010editor打开看有没有；</font>

<font style="color:rgba(0, 0, 0, 0.87);">（2）JPG比较常见的图片题改宽高，把flag藏在直接打开可见范围外。可以盲猜改回去也可以CRC爆破。</font>

<font style="color:rgba(0, 0, 0, 0.87);">（3）LSB隐写：修改RGB颜色分量的最低二进制位也就是最低有效位（LSB），而人类的眼睛不会注意到这前后的变化，每个像数可以携带3比特的信息。常用工具：stegsolve</font>

<font style="color:rgba(0, 0, 0, 0.87);">（4）对于gif图，用PS打开时间轴看每帧图片GIF分帧，或者用随波逐流也可打开查看每一帧。</font>

<font style="color:rgba(0, 0, 0, 0.87);">（5）其他工具隐写：oursecret隐写、</font><font style="color:rgb(51, 51, 51);">silenteye等等比较多，可以慢慢做题积累</font>

### <font style="color:rgba(0, 0, 0, 0.87);">二维码</font>
<font style="color:rgba(0, 0, 0, 0.87);">常见的二维码是QR码，题里有切成碎块，缺失定位点，图片反相等简单加工，善用PS即可。</font>

<font style="color:rgba(0, 0, 0, 0.87);">还有很多其他类型，手机扫码无法识别的二维码，比如：</font>

<font style="color:rgba(0, 0, 0, 0.87);">Aztec码、Data Matrix码等等，还有其他的，大家可以自行去探索</font>

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753080907216-1f7e269f-d78c-4127-b6b7-7e145cc2485b.png)![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753080974767-8cf3a8ac-d5c2-4ebb-8bd1-d84de5169177.png)![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753081010115-33d4780e-4313-45f0-9d8e-bd4291370ff6.png)

## <font style="color:rgba(0, 0, 0, 0.87);">音频</font>
#### <font style="color:rgba(0, 0, 0, 0.87);">摩斯电码</font>
<font style="color:rgba(0, 0, 0, 0.87);">自己听有点精神折磨，可以AU打开看频谱图，或者找在线识别的网站，有的准确率还可以。</font>

[莫斯解码](https://morsecodemagic.com/zh/%E6%91%A9%E5%B0%94%E6%96%AF%E7%94%B5%E7%A0%81%E9%9F%B3%E9%A2%91%E8%A7%A3%E7%A0%81%E5%99%A8/)

#### <font style="color:rgba(0, 0, 0, 0.87);">DTMF电话音</font>
<font style="color:rgba(0, 0, 0, 0.87);">听起来就像拨号，网上有识别工具，对于简单的可以识别，复杂的可能要靠手工提取了</font>

### <font style="color:rgb(31, 45, 61);">deepsound</font>
<font style="color:rgb(76, 73, 72);">如果把音频拖进deepsound解密要密码的话一般就是deepsound隐写，密码看有没有其他地方得到</font>

<font style="color:rgb(76, 73, 72);"></font>

<font style="color:rgb(76, 73, 72);"></font>

## <font style="color:rgb(76, 73, 72);">TXT文本隐写</font>
### <font style="color:rgb(31, 45, 61);">snow加密</font>
<font style="color:rgb(76, 73, 72);">这个是空白字符隐写，解密需要密码，当然也可以无密码解密</font>

```plain
snow.exe -p password -C encoded.txt

```

## <font style="color:rgb(31, 45, 61);">零宽字符</font>
<font style="color:rgb(76, 73, 72);">零宽度字符是一些</font>**<font style="color:rgb(76, 73, 72);">不可见的，不可打印的</font>**<font style="color:rgb(76, 73, 72);">字符。它们存在于页面中主要用于</font>**<font style="color:rgb(76, 73, 72);">调整字符的显示格式</font>**<font style="color:rgb(76, 73, 72);">。它们在文本中占有位置却不显示，解密网站： </font>[<font style="color:rgb(73, 177, 245);">Unicode Steganography with Zero-Width Characters</font>](https://330k.github.io/misc_tools/unicode_steganography.html)

例子如下：其特征就是用肉眼看只有十几字符左右，但实际上却有四十多字符

![](https://cdn.nlark.com/yuque/0/2025/png/49967934/1753081395229-dfb98b31-a4a8-4a0e-9f9d-4571b51f2c79.png)



## <font style="color:rgb(31, 45, 61);">空格-Tab隐写</font>
<font style="color:rgb(76, 73, 72);">一个txt全选会发现有很多空白内容，sunblime/notepad++打开会发现有很多空格和Tab，这种一般是莫斯密码、01二进制，手敲一下然后转化就行。</font>

