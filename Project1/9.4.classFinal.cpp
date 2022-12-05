#include <iostream>
using namespace std;

/*
* fianl：禁止被继承
*	修饰成员函数时，只能是virtual函数
*/
class Fianl_Parent {
public:
	virtual void getAge() final {
		cout << "age" << endl;
	}
};

class Fianl_Child final : public Fianl_Parent {
public:
	// error. 无法重写final修饰的函数
	/*void getAge() {
		cout << "age" << endl;
	}*/
};

// error. 不能继承final修饰的类
//class Final_Son : public Fianl_Child {};

void fianl_main() {
	Fianl_Parent f;
	f.getAge();
}