<?php
session_start();
$a=isset($_GET['username'])?$_GET['username']:'none';
$b=isset($_GET['password'])?$_GET['password']:'none';
if($a=='none' || $b=='none'){
$a=isset($_POST['username'])?$_POST['username']:'none';
$b=isset($_POST['password'])?$_POST['password']:'none';
if($a=='none' || $b=='none'){
exit("<h1>Please Login First.</h1>");
}
}
if($a=='admin'&&$b=='123456'){
$_SESSION['login']=True;
header("location:welcome.php");
}
exit("<h1>Invalid Username/Password.</h1>");
?>