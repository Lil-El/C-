#include <iostream>
using namespace std;

/*
	explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 
	跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).
*/

class know_explicit_class {
public:
	int age;
	explicit know_explicit_class(int a) {
		age = a;
	}
};

void know_explicit_main() {
	know_explicit_class k1(10);
	cout << k1.age << endl;
	// 类构造函数的隐式自动转换，不使用explicit下面是正常的；使用了就会提示错误
	/*know_explicit_class k2 = 10;
	cout << k2.age << endl;*/
}
