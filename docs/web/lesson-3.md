# 类
在编程中我们遇到以西而需要重复利用的属性,可以写成类,可以包含常量变量和方法(即函数)
class:`每个类的定义都以关键字 class 开头，后面跟着类名，后面跟着一对花括号，里面包含有类的属性与方法的定义`,跟C语言一样,类名由数字字母下划线开头
注:php的变量名不能以数字开头
new:实例化一个类,把类实例化之后才能调用类的方法和成员.
当一个方法在类定义内部被调用时，有一个可用的伪变量 $this。$this 是一个到当前对象的引用
```php
class father{
    public $bbb='';
    public function app(){
        $this->bbb='welcom to hnusec!';
    }



}
$father=new father();
$father->app();
echo $father->bbb;
```
## 父类子类
子类能够从父类身上继承一些属性,调用规则是,无论方法还是成员首先在子类中进行匹配,如果子类中存在,优先调用子类中的成员和方法,没有的话就去上一级父类中匹配
## 属性
public 表示全局，类内部外部子类都可以访问
private表示私有的，只有本类内部可以使用
protected表示受保护的，只有本类或子类或父类中可以访问
```php
<?
//父类
class father{
 public function a(){
  echo "function a"; 
 }
 private function b(){
  echo "function b"; 
 }
 protected function c(){
  echo "function c"; 
 }
}
//子类
class child extends father{
  function d(){ 
    parent::a();//调用父类的a方法
  }
  function e(){ 
    parent::c(); //调用父类的c方法
  } 
 function f(){ 
    parent::b(); //调用父类的b方法
  } 
}
$father=new father();
$father->a();
$father->b(); //显示错误 外部无法调用私有的方法 Call to protected method father::b() 
$father->c(); //显示错误 外部无法调用受保护的方法Call to private method father::c() 
$chlid=new child();
$chlid->d();
$chlid->e();
$chlid->f();//显示错误 无法调用父类private的方法 Call to private method father::b() 
?>

```

# 序列化和反序列化
序列化是将对象转换为字符串以便存储传输的一种方式,有利于存储或传递 PHP 的值，同时不丢失其类型和结构
而反序列化恰好就是序列化的逆过程,反序列化会将字符串转换为对象供程序使用。
在PHP中序列化和反序列化对应的函数分别为serialize()和unserialize()
```php
<?php
class father{
    public $aaa='hello';
    public $bbb="welcom to hnusec!";//或者var,跟public一个意思
    public $ccc=1234;
    public function app(){
        $this->bbb='php';
    }

}
$father=new father();
echo (serialize($father));
```
`O:6:"father":3:{s:3:"aaa";s:5:"hello";s:3:"bbb";s:17:"welcom to hnusec!";s:3:"ccc";i:1234;}`
反序列化就是序列化的逆过程,我们可以借此实现对魔术方法的触发以及变量覆盖
# url编码
编码可以防止不可见字符丢失
# 魔术方法

- __construct()

在类被初始化的时候触发,当对象被创建时,实例化的时候触发
```php
<?php
class test{
    public function __construct(){
        print 'hello';
    }

}
$test=new test;//不需要传参的话可以不加括号
serialize($test);
?>
```

- __distruct()析构函数

当对象被销毁时,也就是在整个php代码运行完的时候触发,反序列化以及实例化的时候触发
```php
<?php
class test{
    public function __destruct(){
        print 'hello';
        echo "\n";
    }

}
$test=new test;//不需要传参的话可以不屑括号
//serialize($test);
//unserialize('O:4:"test":0:{}');
只要实例化了类,当代码运行解数的时候都会触发__destruct方法
?>
```

- __call

当对象访问一个不存在的方法,或者不可访问的方法时候触发
```php
<?php
class test{
    private function funny(){
        echo'i am happy!';
    }
    public function __call($a,$b){//两个参数是必须存在的,一个是不存在的方法名,一个是传入的参数
        print 'hello';
    }


}
$test=new test;
$test->aaaa();
$test->funny();
?>
```

- __get

当访问一个私有属性,不存在属性时触发
```php
<?php
class test{
    private $name='xiaoming';
    public $age=20;
    public function __get($a){
        print 'hello';
    }


}
$test=new test;
echo($test->name);
echo "\n";
echo($test->age);
echo "\n";
echo($test->aaa);
?>
```

- __set

对不存在或者不可访问的变量(对象私有属性值)进⾏赋值就⾃动调⽤
```php
<?php
class test{
    private $name='xiaoming';
    public $age=20;
    public function __set($a,$b){
        print 'hello';
    }

}
$test=new test;
//$test->age=99;
$test->name='xiaohong';
echo "\n";
$test->aaa='hahaha';
?>
```

- __unset

在实例外部调用 unset() 函数销毁实例的不可见属性或不存在的属性时会自动调用该方法
```php
<?php
class test{
    public $age=20;
    private $name="xiaoming";
    public function __unset($a){//必须要有字符串的返回值
        print 'hello';
    }

}
$test=new test();
unset($test->age);
//unset($test->aaaa);
//unset($test->name);
?>
```

- __toString

在对象(指实例化类的变量)被当成字符串调用的时候触发//echo
```php
<?php
class test{
    private $name='xiaoming';
    public $age=20;
    public function __toString(){//必须要有字符串的返回值
        return 'hello';
    }

}
$test=new test;
print $test;//echo
?>
```

- __invoke

当一个对象被当成方法(函数)调用的时候触发
```php
<?php
class test{
    private $name='xiaoming';
    public $age=20;
    public function __invoke(){
        print 'hello';
    }

}
$test=new test();
$test();
?>
```

- __sleep()

序列化之前触发
```php
<?php
class test{
    private $name='xiaoming';
    public $age=20;
    public function __sleep(){
        print 'hello';
    }

}
$test=new test();
serialize($test);
?>
```

- __wakeup()

在反序列化之前php会调用
```php
<?php
class test{
    public $age=20;
    public function __wakeup(){
        print 'hello';
    }

}
$test=new test();
echo serialize($test),"\n";
unserialize('O:4:"test":1:{s:3:"age";i:20;}');
//unserialize('O:4:"test":2:{s:3:"age";i:20;}');//绕过方法,修改成员数量,不再触发
?>
```
PHP5 < 5.6.25
PHP7 < 7.0.10
# 字符串逃逸
漏洞成因
先序列化，过滤掉敏感字符，把敏感字符替换成更长或更短的字符，而序列化的格式会严格遵守，一个变量的内容长度不是由内容本身决定，而是由数字决定
![image.png](https://cdn.nlark.com/yuque/0/2024/png/34873733/1723235566985-13e0883d-16fd-4065-905d-31d36ef4349a.png#averageHue=%23302e2d&clientId=u27646e65-cc05-4&from=paste&height=113&id=ud65b8ce6&originHeight=169&originWidth=875&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=24042&status=done&style=none&taskId=u7736c3de-bac9-4bfe-83f0-c73ba24ea8f&title=&width=583.3333333333334)
![image.png](https://cdn.nlark.com/yuque/0/2024/png/34873733/1723235646768-8402fc85-6783-4f54-a84d-62d01389cd4d.png#averageHue=%23302e2d&clientId=u27646e65-cc05-4&from=paste&height=63&id=u2129fd45&originHeight=94&originWidth=839&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=15241&status=done&style=none&taskId=u0ba0767c-5e82-41ec-8cea-7b4cc4a9906&title=&width=559.3333333333334)
## 字符串增多逃逸
```php
<?php
highlight_file(__FILE__);
error_reporting(0);
function filter($name){
    $safe=array("flag","php");
    $name=str_replace($safe,"hack",$name);
    return $name;
}
class test{
    var $user;
    var $pass='daydream';
    function __construct($user){
        $this->user=$user;
    }
}
$param=$_GET['param'];
$param=serialize(new test($param));
$profile=unserialize(filter($param));

if ($profile->pass=='escaping'){
    echo file_get_contents("flag.php");
}
?>
```
```php
O:4:"test":2:{s:4:"user";N;s:4:"pass";s:8:"daydream";} 正常序列化
```
 目的：将";s:4:"pass";s:8:"daydream";}变为注释,前面就是我们想要逃逸进去的内容
## 字符串减少逃逸
```php
<?php
function filter($name){
    $safe=array("flag","php");
    $name=str_replace($safe,"hk",$name);//调用fliter函数把里面含有flag或者php字符串的堵换成hk
    return $name;
}
class test{
    var $user;
    var $pass;
    var $vip = false ;
    function __construct($user,$pass){
        $this->user=$user;
        $this->pass=$pass;
    }
}
$param=$_GET['user'];
$pass=$_GET['pass'];
$param=serialize(new test($param,$pass));
$profile=unserialize(filter($param));

if ($profile->vip){
    echo file_get_contents("flag.php");
}
?>
```
```php
O:4:"test":3:{s:4:"user";s:0:"";s:4:"pass";s:0:"";s:3:"vip";b:0;}//
```
我们的目的是要把";s:4:"pass";s:0:"归到user里面，把";s:3:"vip";b:0;}注释掉，中间就是我们想要逃逸的内容
# pop链
```php
<?php
error_reporting(0);
highlight_file(__FILE__);
class A{
    public $abb;
    public $sanp;

    public function __construct()
    {
        $this->abb->ttl();//3
    }
}

class B{
    public $ao;

    public function __set($a,$b){
        system($this->ao);//1
    }
}

class C{
    public $str1;
    public $str2;
    public $chance;

    public function __call($a,$b){
        if($this->str1==$this->str2){
            $this->chance->hhh=123;//2
        }
    }
}

if(isset($_POST['CTF'])) {
    unserialize($_POST['CTF']);
}
```
A:__construct->C:__call->B__set
```php
<?php
error_reporting(0);
class Hello{
    public $apple;
    public $strawberry;
    public function __construct($a){
        $this -> apple = $a;
    }
    function __destruct()//4
    {
        echo $this -> apple;
    }
}

class NoNo {
    public $peach;
    public function __toString()//3
    {
        $new = $this -> peach;
        return $new();
    }
}

class Banana{
    public $orange;
    public $cherry;
    public $arg1;
    public function __call($arg1,$arg2){
        $function = $this -> orange;
        return $function();
    }
    public function __get($arg1)
    {
        $this -> cherry -> ll2('b2');
    }

}

class UkyoT{
    public $banana;
    public $mangosteen;

    public function __toString()
    {
        $long = @$this -> banana -> add();
        return $long;
    }
}

class E{
    public $e;
    public function __get($arg1){//1
        system ($this->e);
    }
}
class Heraclqs{
    public $grape;
    public $blueberry;
    public function __invoke(){//2
        if($this -> blueberry == 123) {
            return $this -> grape -> hey;
        }
    }
}

class MaiSakatoku{
    public $Carambola;
    private $Kiwifruit;

    public function __set($name, $value)
    {
        $this -> $name = $value;
        if ($this -> Kiwifruit = "hello"){
            strtolower($this-> Carambola);
        }
    }
}

if(isset($_POST['CTF'])) {
    unserialize($_POST['CTF']);
} else {
    highlight_file(__FILE__);
}


```
# 作业
NSSCTF
 [FSCTF 2023]ez_php2//反序列化的题
[SWPUCTF 2022 新生赛]ez_ez_unserialize//wukeup绕过，可以自己去试试
[安洵杯 2019]easy_serialize_php//字符串逃逸的题，会写尽量写，不做硬性要求。
自己再尝试写一下课件里面的题，写wp，不会的可以在web群里面问。
还也可以自己去nssctf上面找题写，相关的wp都可以交
邮箱：2589107567@qq.com
命名格式：学号_姓名_课程3



