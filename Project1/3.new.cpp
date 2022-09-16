#include<iostream>
using namespace std;

/*
栈：在函数内部声明的所有变量都将占用栈内存。
堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。
*/

class h_new_Obj {
public:
	h_new_Obj() {
		cout << "constructor" << endl;
	}
	~h_new_Obj() {
		cout << "xg" << endl;
	}
};

void new_main() {
	int *p = nullptr; // NULL
	p = new(int); // new int;
	*p = 99324;
	cout << *p << endl;
	delete p;

	// 二维数组
	int **ip = new int *[2];
	ip[0] = new int[3];
	ip[1] = new int[3];
	delete[]ip[0];
	delete[]ip[1];
	delete[]ip;

	// 数组动态内存分配
	char *cp = NULL;
	cp = new char[20];
	delete[]cp;

	// 对象
	h_new_Obj *op = new h_new_Obj;
	delete op;

	h_new_Obj *arr = new h_new_Obj[4];
	delete[]arr;
}