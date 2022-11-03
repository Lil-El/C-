// Dll1.cpp : 定义 DLL 的导出函数。

#include "Dll1.h"
#include <iostream>
using namespace std;

// 这是导出变量的一个示例
// cpp中DLL_API不写也可以
extern int nDll1 = 99;

// 这是导出函数的一个示例。
int fnDll1()
{
#ifdef DLL1_EXPORTS
	cout << "DLL export" << endl;
#else
	cout << "DLL import" << endl;
#endif
	cout << "fnDll1 run" << endl;
	return 100;
}

// 这是已导出类的构造函数。
 CDll1::CDll1()
{

}

 void CDll1::sayHello()
{
	cout << "Hello DLL" << endl;
}

