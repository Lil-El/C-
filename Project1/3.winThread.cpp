#include <iostream>
#include <windows.h>
using namespace std;

// ��Ļ���Կ���һ����Դ���������̹߳��á���һ���߳�ִ��ʱ�����endl���ܻᱻ�жϣ�����ж�����в�����ʹ��\n���棻
// ���õķ�����ʹ��mutex�����̱߳���

DWORD WINAPI THREAD3_FN(LPVOID lpParamter) {
	for (int i = 0; i < 10; i++) {
		cout << "child:" << i << "\n";
		Sleep(200);
	}
	return 0L;
};

void thread3_main() {
	HANDLE thread = CreateThread(NULL, 0, THREAD3_FN, NULL, 0, NULL);
	WaitForSingleObject(thread, INFINITE); // wait�ȴ����߳�ִ����ϲ�����ִ�С�ͬ��
	CloseHandle(thread);
	for (int i = 0; i < 10; i++) {
		cout << "main:" << i << "\n";
	}
}