#include<iostream>
using namespace std;

// 宏
// 定义标识符
#define Mino
// 定义函数宏
#define MAX(a, b) ( a > b ? a : b)
#define getParam(x) #x
#define concat(a, b) a##b

// 条件编译
#ifndef PI
#define PI 3.14
#endif // !PI

#ifndef getPIFunction
#define getPIFunction
float getPI() {
	return PI;
};
#endif // getPIFunction

#ifndef MAIN
#define MAIN
void process_main() {
	// 预定义宏
	cout << "File Name: " << __FILE__ << endl;
	cout << "Date: " << __DATE__ << endl;
	cout << "Time: " << __TIME__ << endl;
#ifdef PI
	cout << PI << endl;
#endif
#ifdef getPIFunction
	cout << (MAX(1, 2)) << endl;
#endif
	cout << __LINE__ << ": " << getParam("Hello") << endl;
	cout << concat("P", "I") << ": " << concat(P, I) << endl;
}
#endif // !PROCESS

