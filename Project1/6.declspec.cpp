#include <iostream>
using namespace std;

/*
	“__declspec”是Microsoft c++中专用的关键字，它配合着一些属性可以对标准C++进行扩充。
	这些属性有：
	align、字节对齐
	allocate、它和#pragma 的code_seg， const_seg, data_seg,section,init_seg配合使用
	deprecated、 已废弃
	dllexport、dll导出
	dllimport、 dll导入
	naked、
	noinline、不去内联函数
	noreturn、无返回值
	nothrow、不会抛错
	novtable、
	selectany、
	thread、
	property
	uuid。
*/

__declspec(noreturn) void my_exit(int code) {
	exit(code);
}

// 函数需要返回int值，如果中途退出会报错；所以为my_exit函数添加noreturn
int know_declspec_main() {
	cout << "Main" << endl;
	my_exit(0);
}