#include <iostream>
using namespace std;

/*
* __cdecl：C/C++语言默认的调用方式，参数从右向左入栈，MSVC也使用这个
* __stdccall：windows API默认方式，所有参数从右到左依次入栈
* __fastcall：适用于对性能要求较高的场合。从左开始不大于4字节的参数放入CPU的ECX和EDX寄存器，其余参数从右向左入栈。
* 
*   __stdcall：编译后，函数名被修饰为“?functionname@@YG******@Z”。
	__cdecl：编译后，函数名被修饰为“?functionname@@YA******@Z”。
	__fastcall：编译后，函数名被修饰为“?functionname@@YI******@Z”。
*/

void __stdcall stdcall_fn() {
	cout << "stdcall" << endl;
}

void __fastcall fastcall_fn() {
	cout << "fastcall" << endl;
}

void __cdecl cdecl_fn() {
	cout << "cdecl" << endl;
}

void __stdcall call_main() {
	stdcall_fn();
	fastcall_fn();
	cdecl_fn();
}