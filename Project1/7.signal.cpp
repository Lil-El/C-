#include<iostream>
#include<csignal>
using namespace std;

void handler(int signum) {
	cout << "signal num: " << signum << endl;
	exit(signum);
}

/*
	SIGINT：程序终止(interrupt)信号；
	SIGABRT：程序的异常终止，如调用 abort；
	SIGSEGV：非法访问内存；
	SIGILL：检测非法指令；
	SIGFPE：错误的算术运算，比如除以零或导致溢出的操作；
	SIGTERM：发送到程序的终止请求.
*/
void signal_main() {
	// 注册信号SIGINT和信号处理器
	signal(SIGSEGV, handler);  //接收到 SIGSEGV 11的信号后，执行process
	raise(SIGSEGV); // 触发信号
	// windows中没有alarm函数

	while (true) {
		cout << "sleep ..." << endl;
	}
}