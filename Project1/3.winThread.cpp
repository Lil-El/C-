#include <iostream>
#include <windows.h>
using namespace std;

// 屏幕可以看成一个资源，被两个线程公用。当一个线程执行时，输出endl可能会被中断，造成有多个空行产生，使用\n代替；
// 更好的方法是使用mutex进行线程保护

DWORD WINAPI THREAD3_FN(LPVOID lpParamter) {
	for (int i = 0; i < 10; i++) {
		cout << "child:" << i << "\n";
		Sleep(200);
	}
	return 0L;
};

void thread3_main() {
	HANDLE thread = CreateThread(NULL, 0, THREAD3_FN, NULL, 0, NULL);
	WaitForSingleObject(thread, INFINITE); // wait等待子线程执行完毕才向下执行。同步
	CloseHandle(thread);
	for (int i = 0; i < 10; i++) {
		cout << "main:" << i << "\n";
	}
}