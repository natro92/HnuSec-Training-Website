# 方向指北 Guidance 4 Weber

> @[Boogipop](https://boogipop.com)，一条正确的入门路线可以让你真正意义上的事半功倍。
> @[Ewoji](https://ewoji.cn/),致敬所有天才！！

## 前言

打开这篇文档的你应该已经准备踏入网络安全和CTF这条路的大门了。不光是 Web 方向，个人认为任何方向，参加 CTF 比赛都是各位入门网络安全最快的途径。
而对于Web方向，它其实是一个传统的老方向，因为他入门起来相较于其他方向是更加简单同时也充满着趣味性、实战性色彩的。但同时它也是我们后续想要深入学习中最难的一个方向，踏上这条路的你做好了准备吗？

## 如何优雅地提问

### 突破魔法屏障

这个大家应该都略有了解，自行搜索。

### 善用浏览器与搜索引擎

突破魔法屏障后的第一步，停止使用原来的2345浏览器、360浏览器、QQ浏览器，善用Google、Bing等搜索引擎。

### 有实在查不到的问题？

可以找我（有时无法及时回复；ID：Boogipop）或者其他 Web 方向的管理员，
在发起提问之前，个人推荐先阅读一遍[提问的智慧](https://how-to-ask.natro92.fun)。虽然看似与直接解决问题无关，但这是十分需要注意的一个点，可能决定了我们解决问题的效率。

## 一些相关的学习路径

### 🔥网页前端基础

零基础的话可以先去[菜鸟教程](https://www.runoob.com)了解了解 HTML 与 JavaScript 编程语言。
更加完整的文档可以参考下面这些：
[使用 HTML 组织网站内容](https://developer.mozilla.org/zh-CN/docs/Learn/HTML)
[现代 JavaScript 教程](https://zh.javascript.info/)
然后，随便打开一个网页，按下 F12 或者 Ctrl+U，对照着打开的文档，尝试去理解那些被尖括号包围着的文字和我们所看到的花花绿绿的网页之间的联系吧。
对于前端语言，前期不用学得特别深入，遇到没见过的 HTML 标签翻文档就行，重点是搞懂 HTML 中的表单，即`<form>`标签。JavaScript 等到接触 XSS 漏洞和后端 JS 时再深入学习也不迟，前期能够理解浏览器中的 JavaScript 与 HTML 分别"是什么"和"它们能做什么"就好。

### 🔥网络协议基础

前期简单了解 HTTP 数据包的结构就好，同样可以去[菜鸟教程](https://www.runoob.com)上搜索 HTTP 相关资料。
更加详细的 HTTP 教程可以参考 [HTTP | MDN](https://developer.mozilla.org/zh-CN/docs/Web/HTTP)

### 🔥编程语言基础

大家应该都有一定的C语言基础了，但是既然方向名称是叫做"Web"，那也就是说和网页程序有关，因此我们需要入手第一门网页编程语言PHP。
[菜鸟教程——PHP](https://www.runoob.com/php/php-tutorial.html)
[PHP 手册](https://www.php.net/manual/zh/)
我们既然要学习PHP，那就少不了PHP环境的搭建了，这里为Windows和Mac选手都提供一款软件。
Windows：

- PhpStudy
- WampServer

Mac：

- MAMP PRO
- PhpStudy

### SQL语言基础

SQL 是用户与数据库进行交互的语言。严格意义上可能不算"编程语言"，最常见的数据库是Mysql，因此我们可以学习一下有关的技术。
[菜鸟教程——SQL](https://www.runoob.com/sql/sql-tutorial.html)
[MySQL 5.7 参考手册](https://dev.mysql.com/doc/refman/5.7/en/)

### 基础漏洞

我们可以先了解常见的 Web 安全问题：
[什么是 OWASP Top 10](https://www.cloudflare-cn.com/learning/security/threats/owasp-top-10/)
本着在实践中学习的原则，我们可以开始边搭环境，边学原理了：

1. SQL 注入漏洞

推荐配合 PHPStudy 在本地搭建 sqli-labs 靶场，就可以在里面学习各种 SQL 注入相关的测试了。
[sqli-labs 本地靶场搭建](https://www.jianshu.com/p/9acc9dd79cc9)
[sqli-labs 通关笔记](https://cloud.tencent.com/developer/article/1982432)

2. 文件上传漏洞

学习文件上传的目的主要是绕过各种过滤，上传 webshell，最终获取网站权限。
[文件上传漏洞靶场 upload-labs 安装 + 第一关教程](https://blog.csdn.net/qq_36711453/article/details/84788215)

3. PHP 文件包含漏洞
4. PHP 反序列化漏洞

> 学习反序列化的时候，需要有PHP语言的面向对象章节的基础。这样才可以继续深入学习。

5. XSS漏洞

全称跨站脚本，XSS 漏洞的发生大都是由于没控制好用户输入，让用户输入的恶意数据被解析为浏览器中合法的 JavaScript 代码并执行，从而造成危险隐患。

6. CSRF

全称跨站请求伪造，其实CSRF和XSS的区别没有那么明显，他们经常配合使用，因此不要过分纠结于这两者的概念。

7. SSRF

全称服务端请求伪造，攻击的目标是服务端，控制服务端以服务端的身份发起请求，读文件，攻击内网应用等。
[SSRF漏洞学习-安全客 - 安全资讯平台](https://www.anquanke.com/post/id/239994)

8. XXE

全称 XML 外部实体注入，听名字就知道又得学新东西了。
[菜鸟教程——XML](https://www.runoob.com/xml/xml-tutorial.html)
[一篇文章带你理解漏洞之 XXE 漏洞](https://www.k0rz3n.com/2018/11/19/%E4%B8%80%E7%AF%87%E6%96%87%E7%AB%A0%E5%B8%A6%E4%BD%A0%E6%B7%B5%E5%85%A5%E7%90%86%E8%A7%A3%20XXE%20%E6%BC%8F%E6%B4%9E/)

9. SSTI

全称模板注入，一般是后台程序参数不当，将用户的输入当做模板语法去渲染，进而造成危险隐患。
[FLask SSTI从零到入门 - 跳跳糖](https://tttang.com/archive/1698/)

### Linux 基础

Linux和Windows是两个操作系统，而Linux是可以没有图形化界面的系统，是一个命令行系统，因此我们需要熟悉一下Linux指令。
[菜鸟教程——Linux 常用命令](https://www.runoob.com/w3cnote/linux-common-command-2.html)

### 好使的工具

"工欲善其事，必先利其器。"
[SwitchyOmega](https://chrome.google.com/webstore/detail/proxy-switchyomega/padekgcemlokbadohgkifijomclgjgif?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，能够增强"魔法道具"切换咏唱模式时的速度（方便切换代理）
[AdBlocker Ultimate](https://chrome.google.com/webstore/detail/adblocker-ultimate/ohahllgiabjaoigichmmfljhkcfikeof?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，和蔼！任何广告，终将绳之以法！
[沉浸式翻译](https://chrome.google.com/webstore/detail/immersive-translate/bpoadfkcbjbfhfodiogcnhhhpibjhbnh?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，一键中英文对照翻译
[ChatGPTBox](https://chrome.google.com/webstore/detail/chatgptbox/eobbhoofkanlmddnplfhnmkfbnlhpbbo?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，将搜索关键字自动发送给 ChatGPT 并集成回答到搜索结果页面
[HackBar](https://chrome.google.com/webstore/detail/hackbar/ginpbkfigcoaokgflihfhhmglmbchinc?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，方便修改与重放 HTTP 数据包
[网课小工具](https://chrome.google.com/webstore/detail/%E7%BD%91%E8%AF%BE%E5%B0%8F%E5%B7%A5%E5%85%B7/kkicgcijebblepmephnfganiiochecfl?utm_source=ext_sidebar&hl=zh-CN) - 浏览器插件，学习通网课自动刷课，并留出时间练习 CTF（确信）
[HackTricks](https://book.hacktricks.xyz/welcome/readme) - 资料库，详细介绍了大量渗透测试与 CTF 技巧，强推
[Command Not Found](https://command-not-found.com/) - 资料库，命令行工具文档
[Cyber Chef](https://gchq.github.io/CyberChef/) - 在线工具，纯 JavaScript 实现的编解码工具，可在本地浏览器离线运行
[Regex101](https://regex101.com/) - 在线工具，调试正则表达式
[Poe](https://poe.com/) - 在线工具，套壳 ChatGPT
[VSCode](https://code.visualstudio.com/) - 插件丰富的多功能编辑器
[010 editor](https://www.sweetscape.com/010editor/) - 优秀的十六进制编辑器，30 天试用，破解找群主@s0rry，鉴定为搞逆向搞的
[中国蚁剑](https://github.com/AntSwordProject/antSword) - 开源的跨平台 websell 管理器，安装和使用参考[手册](https://www.yuque.com/antswordproject/antsword/pgxa1h)
[BurpSuitePro](https://portswigger.net/burp/pro) - 用于攻击 web 应用程序的集成平台，可能是将来一段时间内大家用得最多的工具。后面会在群里发运行环境配置与破解教程，主要是对初学者来说可能有点复杂，这里三言两语讲不清楚。
先写这些吧，之后想到多的会继续往群里放。

## 总结

- 保持好奇的心
- 持续学习的状态
- 谦虚的态度
- 科学上网
- 向学长学姐们请教
- 逛大佬们的博客
  - 比如[Boogipop 的博客](https://boogipop.com)
- 当然也欢迎和我一同进步： [心流](https://natro92.fun)
- **坚持**
- **坚持**
- **坚持** 
