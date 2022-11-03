// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DLL1_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DLL1_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的

#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif

//

/*
extern   "C "只是表示这个能够被C语言调用，除了这个以外，没有什么更多含义。
由于C语言的编译器和C++的不一样，C++的会有个叫作函数名打散的机制，好比函数：int   add(int   a,int   b)在C＋＋里面编译以后，就不是int   add(int   a,int   b)，而是相似：int   add@WEROIUERH(int   a,int   b)的函数名，并且是随机的，若是不用extern   "C "，C语言根本无法调用，而在C＋＋里面能够经过@的顺序来调用。函数

__declspec   (dllexport)输出函数的时候，用loadlibrary又有何不可？
关键是你要知道输出符号的名字。
由于c＋＋中有函数重载，经过函数名并不能惟一肯定一个函数，因此使用c＋＋方式编译函数时系统会在目标码中的内部修饰符中加入参数信息和返回值信息等， 这时候你能估算出正确的名称吗？
若是加了extern   "C "则是用c的方式编译，函数在目标码中的内部修饰符就是_函数名,只要用函数名就能够调用编译器

因为C++里面有函数重载，因此在编译的时候，编译器会在你写的，也就是你但愿导出的函数
后面加上一些关于参数的信息，也就是真正导出的函数名字和你想要的不同。
又因为C语言没有函数重载，因此用EXTERN "C"的意思就是告诉编译器不要按照C++那样修改函数
名称。

建议用模块定义文件 .def文件来写DLL，这样能够保证导出函数的纯净
在  链接器-输入-模块定义文件中定义def文件的名称
LIBRARY "Dll1"

;这是一个注释

EXPORTS
nDll1      @1
fnDll1     @2
;VARDLL    =nDll1     @1
;FNDLL     =fnDll1    @2
*/

// 要导出的必须在h文件中写dll_export；在h中对于extern需要给变量加上，函数可以不加。cpp中不写extern 和 dll_export也没事
// 静态调用时：但是在使用Dll加载时会报错。
//extern DLL1_API int nDll1;
//DLL1_API int fnDll1();

// 使用LoadLibrary时，必须使用extern "C"，可以兼容静态、动态的调用。
// extern “C” {...} 或者 extern "C" int a;

#ifdef __cplusplus  // 如果是C++就渲染`extern "C"{`;
extern "C" {
#endif // __cplusplus

	extern DLL1_API int nDll1;
	DLL1_API int fnDll1();

	// 编译器会忽略class前的extern "C"；extern C只对变量和函数起作用
	class DLL1_API CDll1 {
	public:
		CDll1();
		void sayHello();
	};

#ifdef __cplusplus
}
#endif // __cplusplus

