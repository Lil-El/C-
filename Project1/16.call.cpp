#include <iostream>
using namespace std;

/*
* __cdecl��C/C++����Ĭ�ϵĵ��÷�ʽ����������������ջ��MSVCҲʹ�����
* __stdccall��windows APIĬ�Ϸ�ʽ�����в������ҵ���������ջ
* __fastcall�������ڶ�����Ҫ��ϸߵĳ��ϡ�����ʼ������4�ֽڵĲ�������CPU��ECX��EDX�Ĵ����������������������ջ��
* 
*   __stdcall������󣬺�����������Ϊ��?functionname@@YG******@Z����
	__cdecl������󣬺�����������Ϊ��?functionname@@YA******@Z����
	__fastcall������󣬺�����������Ϊ��?functionname@@YI******@Z����
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