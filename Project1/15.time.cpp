#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

void ctime_main() {
	time_t t1 = time(NULL); // ��ǰʱ���
	clock_t c1 = clock(); // ��ʱ
	tm tm1; // ����ʱ������ڵ�struct

	localtime_s(&tm1, &t1);
	cout << 1900 + tm1.tm_year << "/" << tm1.tm_mon + 1 << "/" <<tm1.tm_mday << endl;

	char buffer[100];
	ctime_s(buffer, sizeof(buffer), &t1);
	cout << buffer << endl;

	time_t t2, t3;
	time(&t2);
	Sleep(1000);
	time(&t3);
	cout << t3 - t2 << "��" << endl;
	cout << difftime(t3, t2) << "��" << endl;

}