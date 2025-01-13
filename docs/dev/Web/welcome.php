<?php
session_start();
if(!isset($_SESSION['login'])||$_SESSION['login']!=True){
	exit("<meta charset=\"utf-8\">您似乎还未登录，3s后跳转至登录界面<script>setInterval(function(){location.href='login.php'},3000)</script>");
}
exit("Login Success!<h1>Welcome to HnuSec!</h1>");
?>