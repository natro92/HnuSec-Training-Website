# 常见隐写

注：课后作业在最后面。

## 工具

### 010Editor（展现文件的16进制编码）

下载链接：https://download.sweetscape.com/010EditorWin32Installer11.0.1.exe

补充信息——各类型文件的文件头
PNG (png)，⽂件头：89504E47 
GIF (gif)，⽂件头：47494638 
TIFF (tif)，⽂件头：49492A00 
Windows Bitmap (bmp)，⽂件头：424DC001 
CAD (dwg)，⽂件头：41433130 
Adobe Photoshop (psd)，⽂件头：38425053 
Rich Text Format (rtf)，⽂件头：7B5C727466 
XML (xml)，⽂件头：3C3F786D6C 
HTML (html)，⽂件头：68746D6C3E 
Email [thorough only] (eml)，⽂件头：44656C69766572792D646174653A 
Outlook Express (dbx)，⽂件头：CFAD12FEC5FD746F 
Outlook (pst)，⽂件头：2142444E 
旧版office MS Word/Excel (xls.or.doc or.ppt)，⽂件头：D0CF11E0 
MS Access (mdb)，⽂件头：5374616E64617264204A 
WordPerfect (wpd)，⽂件头：FF575043 
Adobe Acrobat (pdf)，⽂件头：255044462D312E 
Quicken (qdf)，⽂件头：AC9EBD8F 
ZIP Archive (zip)，⽂件头：504B0304 
RAR Archive (rar)，⽂件头：52617221 
Wave (wav)，⽂件头：57415645 
JPEG (jpg)，⽂件头：FFD8FFE1 
<.img 
src= “data:image…” 
alt= “Base64 encoded image ” /> ⽣成图⽚（常⽤于base64隐写图⽚） 

### Stegsolve⼯具

下载安装参考：https://blog.csdn.net/wzk4869/article/details/132635923

File Format:文件格式 
Data Extract:数据提取 
Steregram Solve:立体试图 可以左右控制偏移 
Frame Browser:帧浏览器 
Image Combiner:拼图，图片拼接 

### VMware Workstation

这个的下载安装可以去B站参考学习，也是有很多的资源视频的。
这个里面就可以开很多虚拟机。
所谓虚拟机就是可以理解为在你的电脑上又开了一个新的系统，比如说win7（这个需要资源，得去下载   这个是我从网上买的，大家可以自己去探索一下）。

其他工具和参考做题网站可以参考群文件 Misc第一节相关工具及第二节预备工具.pdf

## 常见隐写题

在CTF（Capture The Flag）比赛中，隐写术（Steganography）是一种重要的解题手段。隐写术是将信息隐藏在看似普通的数据中，以达到不被察觉的目的。

### 对两个16进制文件进行拼接

一些解题思路：
1.简单的签到题（考察你有没有下载010Editor等）：直接拉到最下面，看有没有flag
2.Ctrl+F搜索text文本
3.分离文件
（1）改文件后缀（两个拼在一起）
（2）用010Editor，手动分离出来，新建hex file，另存查看（根据模板的不同颜色）
（3）虚拟机kali binwalk文件分离，口令：binwalk -e+文件名

base加解密（乱码，由大小写字母、等号、数字组成的）→base加解密
Base64是一种用64个字符表示任意二进制数据的编码方法。
用CyberChef网站（to加密 from解密）

LSB隐写
LSB隐写技术通过修改图像、音频等文件中像素或样本的最低有效位（Least Significant Bit）来隐藏信息。由于最低有效位的变化对整体数据的影响非常小，因此这种隐写方式很难被察觉。
使用StegSolve工具

### Word隐写

①字体颜色被设置为纯白色
②隐藏文字（字体→隐藏文字）
③用压缩文件（如Bandizip）打开之后：word→media

### 音频隐写

音频隐写技术将信息隐藏在音频文件的波形数据中，通过修改音频样本的细微变化来隐藏信息。
①放到Adobe Audition直接出flag→演示
②藏了一段→听或者分析 去在线摩斯密码解密 详细过程大家可以自己去做题体会、参考学习。

### PDF隐写

单独考就是图片编辑→拖开

### gif隐写

用Frame Browser（帧浏览器，因为.gif是一个动图，有很多帧，用这个可以一帧一帧地看）

## 结语

隐写术在CTF比赛中扮演着重要的角色，它要求参赛者具备逆向思维、加密解密能力和细致的观察力。通过学习和实践隐写术的相关知识，我们可以更好地理解和掌握计算机安全领域中的一种重要技术。同时，在实际应用中也要注意遵守法律法规，不得用于非法用途。

## 课后作业

https://buuoj.cn/challenges BUUCTF网站，先注册登录，然后进行以下操作。
练习场→题目列表→Misc里的以下题目（也可这样：进到题目列表以后，在搜索框里直接搜索题目名称）：
1.二维码  提示：本题需要压缩包暴力破解，可使用ARCHPR工具
2.基础破解  提示：本题仍需要压缩包暴力破解
3.文件中的秘密  提示：根据题目所给提示想想别的思路
4.qr
大家把flag和简单的解题过程于2024年8月14日前以pdf的形式发到邮箱：18562196602@163.com。

另：金三胖、你竟然赶我走、LSB、隐藏的钥匙是本节课讲过的题目，可温习一遍。

大家课后要多学习多做题。
