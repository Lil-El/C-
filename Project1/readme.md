# C++

> w3c   
> Book
> [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## Visual Studio

- “工具”->“选项”->“文本编辑器”->“C/C++”->“代码样式”->“格式设置”->“间距”->“指针/引用对齐方式”->“右对齐”

## 创建项

- 创建时文件名必须为xxxx.cpp；如果没有后缀名，通过F2添加后缀，无法获取到该文件的内容

## using

- TODO: using的4中用法

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

- extern
	1. fileA中定义一个函数，fileB中通过extern引用此函数; 头文件被多次引用会提示重复定义，所以在.h中定义或声明函数等全局变量时，需要添加：
		```
			#ifndef NAME
			#define NAME
			...
			#endif
		```
	2. [extern "C"含义](https://blog.csdn.net/jiqiren007/article/details/5933599)：
		1. C++特有指令，为了支持C/C++混合编程
		2. C和C++的编译规则不同：
			C++比C晚，支持更多的特性，例如C++支持函数重载，C却不行
			定义一个函数`void fn(int a, int b) {};`C编译后是Function(int, int)；但是C++的编译结果是_Z8Functionii(*ii*表示的是参数)。
			场景：
				.h声明函数；在一个.c文件中引入.h并定义函数，该函数使用C方式编译；在Cpp文件中通过extern引入此函数，就会提示函数未定义；(.c定义Function，.cpp引用Functionii)
				如果.cpp引入.h并定义函数，那么两者都是cpp方式编译，就没有问题。
			**编译阶段没报错，是链接的阶段报错了**
			被extern "C"修饰的变量和函数，会通过C的编译方式进行编译。
			extern对应的关键字是static，static表明变量或者函数只能在本模块中使用，因此，被static修饰的变量或者函数不可能被extern C修饰。
		3. 使用：
			```
				#ifndef __INCvxWorksh /*防止该头文件被重复引用*/
				#define __INCvxWorksh

				#ifdef __cplusplus             // 如果是C++就渲染`extern "C"{`;
				extern "C"{
				#endif

				/*…声明或定义变量、函数等…*/ // 如果是C++，这段代码会被extern C包裹，编译器会使用C的方式去编译、链接；否则就正常。

				#ifdef __cplusplus             // 如果是C++就渲染`}`;
				}
				#endif

				#endif /*end of __INCvxWorksh*/
			```

## [STL](https://blog.csdn.net/weixin_53332395/article/details/123948946) 