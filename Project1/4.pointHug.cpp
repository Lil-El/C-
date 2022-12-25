#include<iostream>
using namespace std;

/*
* 指针悬挂：
* 两个指针指向同一块内存，如果其中一个指针删除了内存，这时候就形成了“指针悬挂”。
* 使用拷贝构造函数时，不要随便浅拷贝。
*/

class point_hug {
	int* age;
public:
	point_hug() {
		age = new int(993);
	}
	point_hug(const point_hug &p) {
		age = p.age; // 浅拷贝
	}
	~point_hug() {
		delete age;
	}
};

void point_hug_main() {
	point_hug p;
	point_hug p1(p);
	cout << "程序结束，age会被删除两次，形成指针悬挂，程序崩溃。" << endl;
}
