# 课前准备
1. 下载好Burp Suite（社区版或pro均可
2. 准备好富文本笔记软件（语雀、Obsidian、Typaro等），支撑后续学习
3. 一个好用的可以访问全球互联网的浏览器


# 基础知识

## B/S结构
 - Browser/Server，浏览器/服务器模式
![caabad6bd1afc44fb9692b18d54b63e6_MD5](https://orxiain-1316625240.cos.ap-guangzhou.myqcloud.com/undefined202408012146830.jpeg?imageSlim)

[简述网站、B/S架构与C/S架构 - 田冬雪 - 博客园 (cnblogs.com)](https://www.cnblogs.com/tdxl/p/10984604.html)
## URL

**URL**（Uniform Resource Locator，统一资源定位符）是用于定位互联网上资源的地址
它指定了资源的位置以及浏览器用于获取资源的方法
这里举个小栗子
### URL例子

http://www.example.com/index.html

**URL包含以下几个部分：**
- 协议：`http://`指定了访问资源所使用的协议类型。这里的协议类型为`HTTP`，除此之外还有`HTTPS`，`FTP`，`file`和`sms`等等，当然第三方应用也可以拥有私有协议。
- 主机名（Host）：`example.com`就是这里的域名（domain name）或者直接是IP，一般域名在DNS解析后也是IP地址
- 端口号（port）：用于指定服务器监听的端口号，当你不指定端口时，网页会默认访问80端口（也就是http请求）或者443端口（也就是https请求）。带着端口号的长这样： `http://www.aaa.com:11451`
- 路径：也就是这里的`/index.html`
- 查询字符串：像是 https://www.google.com/search?q=abc  这里的`q`就是我们给服务器传递的参数，这里通过在url直接对q进行传递的方式是通过GET方法实现的
- 片段标识符（Fragment Identifier）：像是 https://fynch3r.github.io/Context琐事/#搞搞StandardContext  这里的`#搞搞StandardContext`就是片段标识符

**HTTP与HTTPS的区别**
除了访问时的默认端口不同
- HTTP不对数据进行任何加密
- HTTPS在HTTP的基础上加入了**SSL/TLS**加密，防止了数据在传输过程中被接获和被修改
# 抓包
## 请求包
```
GET / HTTP/1.1
Host: node4.anna.nssctf.cn:28998
Accept-Encoding: gzip, deflate
Upgrade-Insecure-Requests: 1
Priority: u=0, i
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:128.0) Gecko/20100101 Firefox/128.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
```
### GET和POST的区别
POST理论没有传输上限
GET会有URL长度限制
```
POST / HTTP/1.1
Host: node5.anna.nssctf.cn:26613
Upgrade-Insecure-Requests: 1
Priority: u=0, i
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:128.0) Gecko/20100101 Firefox/128.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded

moe=flag
```
1. 请求行：`GET / HTTP/1.1`   
2. 请求头：提供关于请求、响应或者其他的辅助信息
3. 空行：请求头与请求体之间有空行 
4. 请求体：当请求方法为POST时会有请求体
>- HTTP协议中有一个OPTIONS方法，可以用来查询服务器支持哪些HTTP方法。客户端发送一个OPTIONS请求到服务器，服务器会在响应中包含一个名为“Allow”的头字段，列出它支持的方法。
>- `Allow: GET, POST, HEAD, OPTIONS`

**Cookie：**
是网站为了辨别用户身份、进行会话跟踪而存储在用户本地终端上的数据

**XFF (X-Forwarded-For)**：
它用于识别通过HTTP代理或负载均衡器传递的请求的原始IP地址

**Via:**
当HTTP请求或响应通过代理或网关时，Via字段会被添加，用以记录中间的传输节点
如果一个HTTP请求经过了一个代理服务器，该代理服务器可能会在请求头中添加一个“Via”字段
`Via: 1.1 proxyserver.example.com`
## 响应包
```
HTTP/1.1 200 OK
Content-Type: text/html; charset=UTF-8
Content-Length: 1250

<!DOCTYPE html>
<html>
<head>
    <title>Example Page</title>
</head>
<body>
    <h1>Welcome to Example.com</h1>
    <p>This is a sample response from the server.</p>
</body>
</html>
```
- 状态行：HTTP版本、状态码、状态消息(OK)
- 响应头：包含了关于响应的元数据，比如响应的内容类型、长度、服务器信息、缓存指令等
- 响应体：包含服务器返回的资源或数据

### 服务器返回状态码
**1xx - 信息性状态码**：这类状态码表示临时的响应。例如：
    
    - `100 Continue`：服务器已经接收到请求头，客户端应该继续发送请求体。
    - `101 Switching Protocols`：服务器正根据客户端的请求切换协议。
**2xx - 成功状态码**：表示请求被成功接收、理解和接受。例如：
    
    - `200 OK`：请求成功，响应体中包含请求的结果。
    - `201 Created`：请求已成功处理，并创建了新的资源。
    - `204 No Content`：请求成功，但响应体为空。
**3xx - 重定向状态码**：表示需要客户端采取进一步的操作才能完成请求。例如：
    
    - `301 Moved Permanently`：请求的资源已永久移动到新的URI。
    - `302 Found`：请求的资源临时从不同的URI响应请求。
    - `304 Not Modified`：客户端发送的附带条件请求未满足，资源未修改。
**4xx - 客户端错误状态码**：表示客户端可能发生了错误，妨碍了服务器的处理。例如：
    
    - `400 Bad Request`：服务器无法理解请求的格式。
    - `401 Unauthorized`：请求需要用户认证。
    - `404 Not Found`：服务器找不到请求的资源。
**5xx - 服务器错误状态码**：表示服务器在处理请求时发生了错误。例如：
    
    - `500 Internal Server Error`：服务器遇到了一个未曾预料的状况，无法完成请求。
    - `502 Bad Gateway`：作为网关或代理的服务器从上游服务器收到了无效的响应。
    - `503 Service Unavailable`：服务器目前无法使用（过载或维护）。


一般抓包有两种方式：**F12**、**BurpSuite（Yakit）**
## F12
插件推荐`HackBar V2`，`Max HacKBar`(一个坏了就用另一个😇)
## BurpSuite
### BURP
Burp Suite是一款集成化的渗透测试工具，包含了很多功能，可以帮助我们高效地完成对Web应用程序的渗透测试和攻击,由Java语言编写
**抓包、改包的工具**
配合burp的插件推荐`FoxyProxy`
### CA证书安装
访问 http://burp

### 模块功能

1. **Proxy（代理）**：Proxy模块是一个拦截HTTP/S请求和响应的代理服务器。它允许测试人员查看、修改在客户端和服务器之间传递的数据。
2. **Scanner（扫描器）**：Scanner模块自动地发现Web应用程序中的安全漏洞。它分析Proxy模块捕获的数据，执行各种攻击来识别潜在的安全问题。
3. **Intruder（入侵者）**：Intruder模块用于自动化定制化的攻击，如枚举标识符、收集有用的数据、利用漏洞等。它通过修改HTTP请求的参数，向服务器发送大量请求来测试系统的弱点。
5. **Repeater（中继器）**：Repeater模块用于手动修改和重放浏览器和服务器之间的HTTP请求。这有助于测试人员分析应用程序对特定请求的响应。
6. **Sequencer（序列器）**：Seqencer模块用于测试Web应用程序中会话令牌或其他重要数据项的随机性和预测性。
7. **Decoder（解码器）**：Decoder模块是一个用于解码和编码数据的工具，支持多种编码格式，如URLu编码、HTML实体编码等。
8. **Comparer（比较器）**：Comparer模块用于比较两个或多个数据片段，以发现它们之间的差异，这对于分析应用程序的响应差异很有帮助。
9. **Extender（扩展器）**：Extender模块允许用户加载和运行自定义插件，以扩展Burp Suite的功能。


# Links
非常好Burp教程[Burp Suite指南](https://t0data.gitbooks.io/burpsuite/content/)

[[LitCTF 2023]Follow me and hack me | NSSCTF](https://www.nssctf.cn/problem/3864)

[ctf.show](https://ctf.show/challenges)

非常好burp视频[【【5号黯区】BurpSuite/Burp Suite 2021最新系列渗透视频】](https://www.bilibili.com/video/BV1aq4y1X7oE)

CTFweb指南[MoeCTF_2023/Challenges/Web/Web入门指北/web入门指北.md at main · XDSEC/MoeCTF_2023 (github.com)](https://github.com/XDSEC/MoeCTF_2023/blob/main/Challenges/Web/Web%E5%85%A5%E9%97%A8%E6%8C%87%E5%8C%97/web%E5%85%A5%E9%97%A8%E6%8C%87%E5%8C%97.md)

刷题 https://ctf.bugku.com/ https://www.nssctf.cn/

安装Burp需要java环境：[Index of java-local/jdk (huaweicloud.com)](https://repo.huaweicloud.com/java/jdk/)

主播同款Burp 下载（ https://drive.google.com/file/d/1PxxAGdfmfTn1yb-dcc3xPtPytyH--zHW/view?usp=sharing

感谢各位的聆听，这里只是对web学习进行了一个基础知识的讲解，希望大家共同学习进步

（￣︶￣）↗　

# 作业
使用语雀、Obsidian、Typora等笔记软件，作业内容：
1. 怎么安装Burp Suite的

2. 做以下题目并写出WriteUp（题解）：

3. [GET - Bugku CTF](https://ctf.bugku.com/challenges/detail/id/70.html) （用hackbar或burp抓包都行）

4. [POST - Bugku CTF](https://ctf.bugku.com/challenges/detail/id/71.html)（用hackbar或burp抓包都行）

5. [本地管理员 - Bugku CTF](https://ctf.bugku.com/challenges/detail/id/79.html)

6. [bp - Bugku CTF](https://ctf.bugku.com/challenges/detail/id/314.html)

7. 其它题，可以自己找点来练


在ddl前，作业（PDF）提交到 http://ctf.miaoaixuan.cn/ 的web作业提交处（只交本次作业）

有问题在答疑群里问

**ddl:** 8月14日提交