#include <iostream>
using namespace std;
/*
* 左值是一个内存实体，可以&，可以存在很久
  右值没有内存实体，只是临时的，用一次就不用了

* 移动构造函数和移动赋值函数中使用
*/

void rightReference_main() {
	int x = 10; // x是左值，10是右值
	const int& lx = x; // 左值引用
	//int& rx = 10; error. 只能对左值进行引用
	//lx += 1; error. const常量无法修改

	//int&& lx = x; error. 只能对右值进行绑定
	int&& rx = 10; // 右值引用

	/*
	* move强制将左值转为右值
	* static_cast<remove_reference_t<_Ty>&&>(_Arg)
	*/
	int&& y = move(x);
	/*
	* 右值引用只可以初始为右值（常量）
	* const左值引用可以初始为左、右值
	* 普通左值引用可以初始为普通左值
	*/
	//int& z = x + x; error. 非常量引用初始值必须是左值
	const int& z = x + x;
	int& z1 = y; // y是右值引用，但也是左值，所以可以使用左值引用
	int&& a = x + z;
	a += 1;
}