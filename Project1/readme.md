# C++

> w3c   
> Book
> [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## Visual Studio

- “工具”->“选项”->“文本编辑器”->“C/C++”->“代码样式”->“格式设置”->“间距”->“指针/引用对齐方式”->“右对齐”

## 创建项

- 创建时文件名必须为xxxx.cpp；如果没有后缀名，通过F2添加后缀，无法获取到该文件的内容

## 字符串

- `char str[] { 'h', 'e' };` 可以省略 = ，C++11特性
- `char str[] { 'h', 'e' };` 单引号是字符型, 双引号是字符串型; 使用双引号会报错，应该使用单引号
- 字符串后面没有\0，会输入乱码

## 数组

- 数组名是数组首个元素的地址
- 数组的长度除了size()方法获得外，可以通过sizeof(arr) / sizeof(arr[0])获得；
- 定义数组时无法通过变量指定数组长度：使用vector或者const int length = 10；（只能是数字10，不能是变量）

## 全局变量

- function
	1. 两个cpp文件，定义一个全局函数，在另个文件中可以通过extern去使用
	2. 定义一个头文件，在cpp文件中include头文件

- class
	1. 在头文件中定义，或本文件中定义
	2. 注意：Class无法使用extern，建议定义在h头文件中。因为class的内存大小无法确定

- basic
	1. 基础数据变量，在其他文件中定义的，可以通过extern去引入使用
	2. 也可以在头文件中定义，最好添加static，否则会提示重复定义错误
	3. Tips:
		1. cpp中定义的static的变量，无法在其他文件中extern并使用的；
		2. h中定义的static变量，不会产生重复定义问题
		3. 多个模块可以访问变量，但是不能修改，所以最好加上const修饰符