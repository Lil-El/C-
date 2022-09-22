#include<iostream>
#include<csignal>
using namespace std;

void handler(int signum) {
	cout << "signal num: " << signum << endl;
	exit(signum);
}

void signal_main() {

	// ע���ź�SIGINT���źŴ�����
	signal(SIGINT, handler);

	while (true) {
		cout << "sleep ..." << endl;
	}
}