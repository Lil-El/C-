# C++

- 相关文章
	- [解释型、编译型区别](https://blog.csdn.net/weixin_58257948/article/details/118033564)

- 相关资料
	- w3c   
	- Book
	- [C语言中文网](http://c.biancheng.net/view/7165.html)
	- [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## 编译器

- GNU C, ANSI C是两个标准，分别通过gcc和vs实现
- GNU C通过gcc（linux）编译
- ANSI C通过vs（windows）编译。
- GNU C从语言层面相对于ANSI C做了一些扩展，所在一段跨平台的程序可以通过gcc编译，也不一定能用vs编译。
- MSVC：微软的VC编译器
- gcc、g++：C语言编译器和C++编译器
- MinGW：Gnu和Windows包的集合，可以在linux、windows中运行而不需要引入其他C库

## Visual Studio

- “工具”->“选项”->“文本编辑器”->“C/C++”->“代码样式”->“格式设置”->“间距”->“指针/引用对齐方式”->“左对齐”

## 创建项

- 创建时文件名必须为xxxx.cpp；如果没有后缀名，通过F2添加后缀，无法获取到该文件的内容

## using

1. 类型定义，类似于typedef；using mInt = int;
2. 命名空间，using namespace
3. 父类成员变量修饰 `class: private parent { public: using parent::name};`
4. 父类重载函数 `class : parent {using parent::getName()}`

## typename

- 用于标识是一个类型名称；using myInt = typename struct1::type;

## 预编译

- #program warning
- #program push/pop
- #define: 定义宏
- #undef: 取消宏定义
- #if defined(char8_t) && _HAS_CXX20
https://blog.csdn.net/Poo_Chai/article/details/89350054

## 数据类型

- _t: 表示使用typedef定义的类型
- wchar_t: 表示 unsigned char 类型

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
		- 如：在a.cpp中定义function a(){}，在b.cpp中使用（extern默认就有）function a();
	2. 定义一个头文件，在cpp文件中include头文件

- class
	1. 在头文件中定义，或本文件中定义
	2. 注意：Class无法使用extern，建议定义在h头文件中。因为class的内存大小无法确定

- basic
	1. 基础数据变量，在其他cpp文件中定义的，可以通过extern去引入使用（定义和引入都要添加extern关键字）
		- 如：在a.cpp定义extern int a = 1; 在b.cpp使用extern int a; cout << a;
	2. 也可以在头文件中定义，添加const或者static，否则会提示重复定义错误
		- 在头文件中只声明，不要定义，否则多次include头文件，会提示重复定义。需要使用ifndef进行头文件保护。
			把a.cpp和b.cpp单独链接成a.o和b.o之后不会报错，到最后编译链接成项目名.exe就会出现全局变量重定义
		- 头文件保护：
			每个头文件加上这个是个好习惯，但是不会对头文件中的定义生效，如int a = 1; void fn() {};
			如果不加可能会出现以下场景:
				有A.h，里面定义了一些方法。
				有B.h，里面#include了A.h，也定义了一些方法。
				现在main.cpp同时#include了A.h和B.h，就要报错了，字符串替换后包含了两次A.h，如果加了上头文件保护符，再导入A.h会不用执行，就避免了这种情况。
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
- is_base_of, typeid判断继承关系
- typeid().name()可以获取指针的class对象

## IO

- TODO: cin/cout/clog/cerr区别-缓冲区

- 模板

template
http://m.biancheng.net/view/320.html
https://blog.csdn.net/vanturman/article/details/81746063
https://blog.csdn.net/qq_45801299/article/details/112298619

## 其他

- static_assert：静态断言 C++11，在编译时检测，不通过会报错
- assert：断言，不影响编译，失败也可以通过，在运行时检测；
- 性能：
	static_assert: 所包含的代码不会生成目标代码，不会影响程序性能；
	assert: 会影响程序性能，常用于调试阶段，正式释放软件时通常关闭assert功能
- = default: 自动生成函数体；例如在class A中定义默认构造函数，A() = default;

## [STL](https://blog.csdn.net/weixin_53332395/article/details/123948946) 

提供一套功能强大的模板类和函数，这些类和函数可以实现算法和数据结构。

- Container：容器
- Algorithms：算法
- iterator：迭代器

## 相关文档

- [new、delete实现原理](https://www.php.cn/blog/detail/31237.html)

## Blog:

- 万能引用、右值引用：https://www.cnblogs.com/ht1947/p/10617821.html http://t.zoukankan.com/ishen-p-13771991.html

## TODO:

- 移动构造函数
- 智能指针
- decltype：自动类型推导  auto __cdecl
- stdcall cdecl
- declval
- mutex
- thread
	https://blog.csdn.net/zzhongcy/article/details/91372329
	https://zhuanlan.zhihu.com/p/340201634 
	https://www.runoob.com/w3cnote/cpp-std-thread.html 
	https://zhuanlan.zhihu.com/p/450087085
	https://blog.csdn.net/qq_20853741/article/details/114093265
- 函数参数是Lambda表达式：void swap(_Ty (&)[_Size], _Ty (&)[_Size]);
- C++11标准库 chrono functional atomic
