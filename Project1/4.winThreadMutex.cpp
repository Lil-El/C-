#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hMutex;

DWORD WINAPI THREAD4_FN(LPVOID lpParamter) {
	for (int i = 0; i < 10; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "child:" << i << "\n";
		ReleaseMutex(hMutex);
	}
	return 0L;
};

void thread4_main() {
	// 创建互斥量
	hMutex = CreateMutex(0, FALSE, (LPCWSTR)"screen");
	HANDLE thread = CreateThread(NULL, 0, THREAD4_FN, NULL, 0, NULL);
	CloseHandle(thread);
	for (int i = 0; i < 10; i++) {
		/*
		* dwMilliseconds：超时的间隔，以毫秒为单位；
		* 如果dwMilliseconds为非0，则等待直到dwMilliseconds时间间隔用完或对象变为非占用的状态，
		* 如果dwMilliseconds 为INFINITE则表示无限等待，直到等待的对象处于非占用的状态。
		*/
		WaitForSingleObject(hMutex, INFINITE); // 互斥锁
		cout << "main:" << i << "\n";
		ReleaseMutex(hMutex); // 释放锁
	}
}