# C++

- 相关文章
	- [解释型、编译型区别](https://blog.csdn.net/weixin_58257948/article/details/118033564)

- 相关资料
	- w3c   
	- Book
	- [C语言中文网](http://c.biancheng.net/view/7165.html)
	- [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## GNU C, ANSI C

- GNU C, ANSI C是两个标准，分别通过gcc和vs实现
- GNU C通过gcc（linux）编译
- ANSI C通过vs（windows）编译。
- GNU C从语言层面相对于ANSI C做了一些扩展，所在一段跨平台的程序可以通过gcc编译，也不一定能用vs编译。

## Visual Studio

- “工具”->“选项”->“文本编辑器”->“C/C++”->“代码样式”->“格式设置”->“间距”->“指针/引用对齐方式”->“右对齐”

## 创建项

- 创建时文件名必须为xxxx.cpp；如果没有后缀名，通过F2添加后缀，无法获取到该文件的内容

## using

1. 类型定义，类似于typedef
2. 命名空间，using namespace
3. 父类成员变量修饰 `class: private parent { public: using parent::name};`
4. 父类重载函数 `class : parent {using parent::getName()}`

## 预编译

- #program warning
- #program push/pop
- #define: 定义宏
- #undef: 取消宏定义
https://blog.csdn.net/Poo_Chai/article/details/89350054

## 字符串

- `char str[] { 'h', 'e' };` 可以省略 = ，C++11特性
- `char str[] { 'h', 'e' };` 单引号是字符型, 双引号是字符串型; 使用双引号会报错，应该使用单引号
- 字符串后面没有\0，会输入乱码

## 数组

- 数组名是数组首个元素的地址
- 数组的长度除了size()方法获得外，可以通过sizeof(arr) / sizeof(arr[0])获得；
- 定义数组时无法通过变量指定数组长度：使用vector或者const int length = 10；（只能是数字10，不能是变量）

## 函数

- 重载：参数的类型，个数，顺序不同；不能根据返回类型不同来重载

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

## 类class

- 拷贝构造函数、=赋值重载运算符
	1. 对象未定义赋值(Shape s1 = s;) (Shape s1(s))，调用`拷贝构造函数`；已经定义的赋值，调用`赋值重载`(Shape s(), s1(); s = s1;)
	2. 在对象赋值、形参、返回值时，默认是浅拷贝。对于指针类型的成员，两个对象指向是一样的，会导致在使用或删除时出现问题。所以重写拷贝构造函数，进行深拷贝
	3. 在对象赋值时，使用=或()赋值。需要先将左值清除，然后赋值。默认的指针成员内存不会被释放。所以重载赋值操作符，进行删除指针。

- class和struct

## IO

- TODO: cin/cout/clog/cerr区别-缓冲区

- 模板

template
http://m.biancheng.net/view/320.html
https://blog.csdn.net/vanturman/article/details/81746063
https://blog.csdn.net/qq_45801299/article/details/112298619

## [STL](https://blog.csdn.net/weixin_53332395/article/details/123948946) 

提供一套功能强大的模板类和函数，这些类和函数可以实现算法和数据结构。

- Container：容器
- Algorithms：算法
- iterator：迭代器

## 相关文档

- [new、delete实现原理](https://www.php.cn/blog/detail/31237.html)

## TODO:

- 匿名函数
- 移动构造函数
- const指针相关
- constexpr：https://blog.csdn.net/qq_37766667/article/details/123915233
- union
- 函数float fnName() const {}
- decltype：自动类型推导  auto __cdecl
- explicit：https://blog.csdn.net/qq_24127015/article/details/104412800
- &&...：http://t.zoukankan.com/ishen-p-13771991.html
- <class... x>
- dllimport dllexport