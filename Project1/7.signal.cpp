#include<iostream>
#include<csignal>
using namespace std;

void handler(int signum) {
	cout << "signal num: " << signum << endl;
	exit(signum);
}

void signal_main() {

	// 注册信号SIGINT和信号处理器
	signal(SIGINT, handler);

	while (true) {
		cout << "sleep ..." << endl;
	}
}