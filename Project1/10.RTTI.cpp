#include <iostream>
using namespace std;

/*
	RTTI: runtime type identification运行时类型识别：为了让程序在运行时能根据基类的指针或引用来获得该指针或引用所指的对象的实际类型
	C++通过父类指针实现多态（见classVirtual.cpp），
*/

class Human {
public:
	Human() {}
	~Human() {}
	virtual void sex() {
		cout << "Im a human!" << endl;
	};
};

class Man : public Human {
public:
	Man() {}
	~Man() {}
	void sex() {
		cout << "I'm man!" << endl;
	}
	void dd() {
		cout << "man dd" << endl;
	}
};

class Woman : public Human {
public:
	Woman() {}
	~Woman() {}
	void sex() {
		cout << "I'm woman!" << endl;
	}
};

class rtti {

};

void know_rtti_main() {
	Human* human = new Man;
	// 很多行代码
	// 这里要怎么知道human指向的是谁呢？
	// RTTI: 类型识别
	cout << typeid(*human).name() << endl;
	cout << boolalpha << (typeid(*human) == typeid(Man)) << endl;
	// RTTI: 类型转换；
	/*
	* 子类包含了父类的所有的对象，所以使用父类指针操作子类对象是合法的。
	* 但是子类的成员函数可能是父类没有的，所以需要dynamic_cast进行安全有效的向下转型。
	*/
	Man man;
	Woman wm;
	Human *hm = &man;
	hm->sex();
	// hm->dd(); // Human并没有Man的成员函数，所以需要进行转换，为Man类型
	Man *m = dynamic_cast<Man*>(hm); // 如果出错，m将指向nullptr
	m->dd();
}