#include <iostream>
using namespace std;

/*
* 移动构造函数：右值引用；
* 移动构造函数接管源对象，不会产生额外的拷贝开销，不需要开辟新的内存。提高效率，节省内存。
*/

class move_cls {
public:
	int* num;
	move_cls(){
		cout << "默认构造" << endl;
		this->num = new int(99);
	}
	move_cls(const move_cls& m) {
		cout << "复制构造" << endl;
		num = new int(*m.num);
	}
	move_cls(move_cls&& m) noexcept {
		cout << "移动构造" << endl;
		num = m.num;
		m.num = nullptr;
	}
	~move_cls() {
		cout << "析构" << endl;
		delete this->num;
	}
};

void move_main() {
	move_cls m; // 默认
	move_cls n(m); // 复制
	move_cls(move(m)); // 移动
}