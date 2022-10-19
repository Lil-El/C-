#include <iostream>
using namespace std;

/*
overload: 重载
	- 在一个class中，函数名一样，参数不一样（个数，参数类型）

override: 覆盖
	加override 关键字，可以避免派生类中忘记重写虚函数的错误
	（1）不同的范围（分别位于派生类与基类）；
	（2）函数名字相同；
	（3）参数相同；
	（4）基类函数必须有virtual 关键字。

overwrite: 重写
	（1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏。
	（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆)
*/

class lo_A {
	// overload重载
	void fn(int a) {}
	void fn(int a, int b) {}
	// override覆盖
	virtual void fnR(int a) {}
	// overwrite重写
	void fnW() {}
};

class lo_B : public lo_A {
	void fnR(int a) override {}
	void fnW() {}
};

void learn_over_main() {

}