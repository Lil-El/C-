#include<iostream>
#include<csignal>
using namespace std;

void handler(int signum) {
	cout << "signal num: " << signum << endl;
	exit(signum);
}

/*
	SIGINT��������ֹ(interrupt)�źţ�
	SIGABRT��������쳣��ֹ������� abort��
	SIGSEGV���Ƿ������ڴ棻
	SIGILL�����Ƿ�ָ�
	SIGFPE��������������㣬����������������Ĳ�����
	SIGTERM�����͵��������ֹ����.
*/
void signal_main() {
	// ע���ź�SIGINT���źŴ�����
	signal(SIGSEGV, handler);  //���յ� SIGSEGV 11���źź�ִ��process
	raise(SIGSEGV); // �����ź�
	// windows��û��alarm����

	while (true) {
		cout << "sleep ..." << endl;
	}
}