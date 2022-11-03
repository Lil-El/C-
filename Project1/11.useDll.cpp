#include <iostream>
#include <windows.h>
using namespace std;

/*
	使用静态调用时，dll使用extern导出就可以，动态调用时就必须使用extern "C"呢？
	因为代码C++进行编译，dll的函数被重命名了，静态调用时也重命名了，所以可以链接过去进行调用函数；
	但是动态调用时，函数的名字都是以字符串的形式传在GetProcAddress中，所以这个名字和重命名之后的不一致，所以需要使用extrn "C"
*/

//#include "Dll1.h" 如下：
extern "C" {
	__declspec(dllimport) int nDll1;
}
#pragma comment(lib, "Dll1.lib")
void staticCall() {
	/*CDll1 cd;
	cd.sayHello();*/
	cout << "nDll1: " << nDll1 << endl;
	//cout << "fnDll1(): " << fnDll1() << endl;
}

void dllCall() {
	//typedef int(*FnPoint)();

	//// L或者是修改属性-字符集为”多字节字符集“
	//HMODULE HD = LoadLibrary(L"Dll1.dll"); // 或者可以使用path：../../xxx.dll
	//if (!HD) {
	//	cout << "HD is null." << endl;
	//	return;
	//}
	//FnPoint FD = (FnPoint)GetProcAddress(HD, "fnDll1");
	//int* age = (int*)GetProcAddress(HD, "nDll1");
	//if (!FD) {
	//	cout << "FD is null." << endl;
	//	return;
	//}
	//cout << "age: " << (*age) << endl;
	//cout << "fnDll1(): " << FD() << endl;
}

void useDll_main() {
	staticCall();
}
