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
	// ����������
	hMutex = CreateMutex(0, FALSE, (LPCWSTR)"screen");
	HANDLE thread = CreateThread(NULL, 0, THREAD4_FN, NULL, 0, NULL);
	CloseHandle(thread);
	for (int i = 0; i < 10; i++) {
		/*
		* dwMilliseconds����ʱ�ļ�����Ժ���Ϊ��λ��
		* ���dwMillisecondsΪ��0����ȴ�ֱ��dwMillisecondsʱ�������������Ϊ��ռ�õ�״̬��
		* ���dwMilliseconds ΪINFINITE���ʾ���޵ȴ���ֱ���ȴ��Ķ����ڷ�ռ�õ�״̬��
		*/
		WaitForSingleObject(hMutex, INFINITE); // ������
		cout << "main:" << i << "\n";
		ReleaseMutex(hMutex); // �ͷ���
	}
}