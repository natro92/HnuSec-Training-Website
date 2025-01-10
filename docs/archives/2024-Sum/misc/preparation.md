# 课前准备 Preparation

如果没有很好的准备，培训中的几节课你可能会学的比较迷糊。

## 引言

Misc 是切入 CTF 竞赛领域、培养兴趣的最佳入口。Misc 考察基本知识，对安全技能的各个层面都有不同程度的涉及，可以在很大程度上启发思维。

## 基础

语言的话必须得先学会python（假如不会，可以通过群里的《Python编程：从入门到实践》这本书来入门），python为写解题脚本的基础。当然在日常题目中可能也会出现rust，go等“新语言”。

在misc中经常会出现与其他方向混合出现的情况，因此学习misc不仅仅要学习misc的东西，还有连带web，re，cry等共同学习

## **:wrench:** Misc手的“工具”

MISC是一个对编程能力要求比较高的方向，不过大多数考点的固定衍生出比较多的"轮子"，当然轮子减少手动操作，确实是好东西，但是容易产生一些弊端，因为跳过了手动操作所以不懂原理也能梭题目，可能会导致选手略过本来应该学的原理，手动会做之后再碰到了用工具减少操作是完全没问题的，即便没有这些整合工具，用现成脚本说到底本质也是一样的。

```
使用工具获取便利的同时 请不要忽略对原理的学习！！！！！
```

#### ❆ 基础工具

- **基础语言 | 模块**

| 项目名称 | Usage                      | 项目地址                        | 文档 |
| -------- | -------------------------- | ------------------------------- | ---- |
| Python   | MISC方向中用途最广的语言。 | [官网](https://www.python.org/) | /    |

- **编码 / 解码 / 解密 工具**

| 项目名称      | Usage                                                        | 项目地址                                                     | 文档 |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| CyberChef     | 近乎全能的编码解码工具。                                     | [官网](https://cyberchef.org/)<br />[国内中文镜像站](https://ctf.mzy0.com/CyberChef3/) | /    |
| Ciphey        | 自动化解密工具。                                             | [Github](https://github.com/Ciphey/Ciphey)                   |      |
| CTFCrackTools | 国内首个CTF工具框架,内涵多个主流密码加解密，支持添加支持Python编写的插件。 | [Github](https://github.com/0Chencc/CTFCrackTools)           | /    |

- **文本 / Hex 编辑 | 文件工具**	

| 项目名称   | Usage                                                        | 项目地址                                        | 文档 |
| ---------- | ------------------------------------------------------------ | ----------------------------------------------- | ---- |
| 010 Editor | 专业的文本编辑器和16进制编辑器，可通过加载模块脚本，解析文件结构。 | [官网](http://www.010editor.com/)               | /    |
| lmHex      | 开源的16进制编辑器。                                         | [Github](https://github.com/WerWolv/ImHex)      |      |
| WinHex     | 16 进制编辑器为核心的数据处理软件。                          | [官网](https://www.x-ways.net/winhex/)          | /    |
| Binwalk    | 可识别文件分离提取工具，常用于从文件中提取隐写到其中的其他文件。 | [Github](https://github.com/ReFirmLabs/binwalk) | /    |
| Foremost   | 用于提取一个文件中包含的多个文件。                           | /                                               | /    |

- **隐写工具 | 图像 / 音频**

| 项目名称               | Usage                                                        | 项目地址                                                     | 文档                                                       |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------------------------------- |
| Qrazybox               | 二维码分析和恢复                                             | [Github](https://github.com/Merricx/qrazybox)<br />[Usagepage](https://merri.cx/qrazybox/) |                                                            |
| QR Research            | 专业的二维码扫描识别软件，支持多个纠错等级，掩码选项(已停止维护)。 | /                                                            | /                                                          |
| UleadGIFAnimator       | 高级GIF编辑器                                                | /                                                            | [吾爱论坛](https://www.52pojie.cn/thread-1276299-1-1.html) |
| **-----图像类**        |                                                              |                                                              |                                                            |
| Stegsolve              | 图像分析工具。                                               | [Github](https://github.com/Giotino/stegsolve)               | /                                                          |
| TweakPNG               | 用于检查和修改PNG图像文件 \|类似于010的Png Template功能      | [官网](https://entropymine.com/jason/tweakpng/)              | /                                                          |
| BlindWaterMark(python) | 基于 python 的图像盲水印                                     | [Github](https://github.com/ww23/BlindWatermark)             | /                                                          |
| BlindWatermark(java)   | 基于 java 的图像盲水印                                       | [Github](https://github.com/ww23/BlindWatermark)             | /                                                          |
| WaterMark(隐藏水印)    | 图像隐写工具，在频域添加数字水印                             | /                                                            | [吾爱论坛](https://www.52pojie.cn/thread-709668-1-1.html)  |
| WaterMarkH             | 单图盲水印(频域隐写)工具                                     | /                                                            | /                                                          |
| zsteg                  | PNG 和 BMP 图片隐写                                          | [Github](https://github.com/zed-0xff/zsteg)                  | /                                                          |
| StegoVeritas           | 隐写工具                                                     | [Github](https://github.com/bannsec/stegoVeritas)            | /                                                          |
| Stegdetect             | 检测jpeg图像隐写工具，搭配stegbreak食用更佳                  | [Github](https://github.com/abeluck/stegdetect)              | /                                                          |
| **-----音频类**        |                                                              |                                                              |                                                            |
| Steghide               | 将文件隐藏到**图片或音频**中的工具                           | [官网](https://steghide.sourceforge.net/)                    | /                                                          |
| Audacity               | 多轨音频处理软件。                                           | [Github](https://github.com/audacity/audacity)               | /                                                          |
| Mp3stego               | 音频隐写提取工具                                             | [官网](https://www.petitcolas.net/steganography/mp3stego/)   | /                                                          |
| Silenteye              | 音频/图像隐写工具                                            | [官网](https://achorein.github.io/silenteye/)                | /                                                          |
| DeepSound              | 可以将文件加密保存到一段声音文件中                           | [官网](https://jpinsoft.net/deepsound/documentation.aspx)    | /                                                          |
| Mp3tag                 | 音频文件元资料编辑器                                         | [官网](https://www.mp3tag.de/en/)                            | /                                                          |

- **取证工具**

| 项目名称                | Usage                                                        | 项目地址                                                     | 文档                                                         |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Forensics-Wiki          | 取证综合资料库                                               | [官网](https://www.forensics-wiki.com/)                      | /                                                            |
| **-----密码爆破**       |                                                              |                                                              |                                                              |
| ZipCenOp                | 伪加密加/解密工具                                            | [Github](https://github.com/442048209as/ZipCenOp)            | /                                                            |
| ARCHPR                  | 压缩文件密码暴力破解工具。                                   | /                                                            | /                                                            |
| Ziperello               | zip压缩包密码恢复软件。                                      | /                                                            | /                                                            |
| Aopr                    | Office文件密码暴力破解工具。                                 | /                                                            | /                                                            |
| Passware Kit Forensic   | 十分强大的解密工具，各类文件/磁盘密码爆破，密钥搜索等        | /                                                            | - [依依的汉化包](https://blog.csdn.net/u010418732/article/details/120189354)<br />- [汉化版](https://www.mzy0.com/archives/82/) |
| Hashcat                 | 高性能，GPU/CPU 兼容的本地密码破解，支持多种不同格式         | [Github](https://github.com/hashcat/hashcat)                 | /                                                            |
| John the Ripper         | 简单易用的离线破解                                           | [Github](https://github.com/openwall/john)                   | /                                                            |
| Hydra                   | 远程或在线密码的并行暴力破解。                               | [Github](https://github.com/vanhauser-thc/thc-hydra)         | /                                                            |
| **-----流量分析**       |                                                              |                                                              |                                                              |
| Wireshark               | 流量分析取证软件。 <img src="./img/windows.svg" width="17" height="17" /> <img src="./img/apple.svg" width="17" height="17" /> | [官网](https://www.wireshark.org/)                           | /                                                            |
| **-----内存 磁盘 取证** |                                                              |                                                              |                                                              |
| Volatility              | 内存分析取证软件。 <img src="./img/windows.svg" width="17" height="17" /> <img src="./img/linux.svg" width="17" height="17" /> <img src="./img/apple.svg" width="17" height="17" /> | [官网](https://www.volatilityfoundation.org/)<br />[Github](https://github.com/volatilityfoundation) | /                                                            |
| MemProcFS               | 新型内存取证框架<img src="./img/windows.svg" width="17" height="17" /> | [Github](https://github.com/ufrisk/MemProcFS)                | /                                                            |
| NtfsStreamsEditor       | NTFS流分析<img src="./img/windows.svg" width="17" height="17" /> | [官网](https://www.nirsoft.net/utils/alternate_data_streams.html) | /                                                            |
| R-Studio                | 内存取证tick+磁盘文件恢复分析<img src="./img/windows.svg" width="17" height="17" /> | [官网](https://www.r-studio.com/zhcn/data-recovery-software) | /                                                            |
| AutoPsy                 | 用来分析磁盘映像和恢复文件的开源取证工具<img src="./img/windows.svg" width="17" height="17" /> | [官网](https://www.autopsy.com/)                             | /                                                            |
| RegistryExplorer        | 注册表文件分析器<img src="./img/windows.svg" width="17" height="17" /> | [官网](http://www.regxplor.com/download.html)                | /                                                            |
| PowerToy                | 注册表文件分析器<img src="./img/windows.svg" width="17" height="17" /> | [Github](https://github.com/microsoft/PowerToys)             | /                                                            |

#### ❆ 解题工具

| 项目名称     | Usage                                                    | 相关地址                                         |
| ------------ | -------------------------------------------------------- | ------------------------------------------------ |
| 随波逐流     | 离线加密解密，字符编码进行转换，文件隐写查看等多项功能。 | [官网](http://1o1o.xyz/index.html)               |
| PuzzleSolver | MISC 综合解题工具，由Byxs20开发。                        | [Github](https://github.com/Byxs20/PuzzleSolver) |

#### ❆ 开源脚本

| 项目名称                          | 项目地址                                                     | 项目作者                                         |
| --------------------------------- | ------------------------------------------------------------ | ------------------------------------------------ |
| 自动爆破PNG图片宽高并一键修复工具 | [Github](https://github.com/AabyssZG/Deformed-Image-Restorer) | [AabyssZG (曾哥) )](https://github.com/AabyssZG) |
| 文件反转、倒置、导出工具          | [Github](https://github.com/AabyssZG/FileReverse-Tools)      | [AabyssZG (曾哥) )](https://github.com/AabyssZG) |
| CRC碰撞全自动化脚本               | [Github](https://github.com/AabyssZG/CRC32-Tools)            | [AabyssZG (曾哥) )](https://github.com/AabyssZG) |

## ✒结语



