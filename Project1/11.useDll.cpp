#include <iostream>
#include <windows.h>
using namespace std;

//#pragma comment(lib, "Dll1.lib")
//#include "Dll1.h"
//void staticCall() {
//	CDll1 cd;
//	cd.sayHello();
//	cout << "nDll1: " << nDll1 << endl;
//	cout << "fnDll1(): " << fnDll1() << endl;
//}

void dllCall() {
	typedef int(*FnPoint)();

	HMODULE HD = LoadLibrary("Dll1.dll"); // 或者可以使用path：../../xxx.dll
	if (!HD) {
		cout << "HD is null" << endl;
		return;
	}
	FnPoint FD = (FnPoint)GetProcAddress(HD, "fnDll1");
	int* age = (int*)GetProcAddress(HD, "nDll1");
	if (!FD) {
		cout << "null: " << endl;
		return;
	}
	cout << "age: " << (*age) << endl;
	cout << "fnDll1(): " << FD() << endl;
}

void useDll_main() {
	dllCall();
}
