#include <iostream>
#include <windows.h>
using namespace std;

/*
	ʹ�þ�̬����ʱ��dllʹ��extern�����Ϳ��ԣ���̬����ʱ�ͱ���ʹ��extern "C"�أ�
	��Ϊ����C++���б��룬dll�ĺ������������ˣ���̬����ʱҲ�������ˣ����Կ������ӹ�ȥ���е��ú�����
	���Ƕ�̬����ʱ�����������ֶ������ַ�������ʽ����GetProcAddress�У�����������ֺ�������֮��Ĳ�һ�£�������Ҫʹ��extrn "C"
*/

//#include "Dll1.h" ���£�
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

	//// L�������޸�����-�ַ���Ϊ�����ֽ��ַ�����
	//HMODULE HD = LoadLibrary(L"Dll1.dll"); // ���߿���ʹ��path��../../xxx.dll
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
