#include <iostream>

// const修饰变量
extern const int AGE = 99324;

/*
* const修饰函数：
* 不能修饰普通函数，`void xx() const{}` 是错误的
* 只能修饰class成员函数，并且const函数不能修改类中的变量。
*/
class ConstClass {
private:
	int age;
public:
	ConstClass(int num): age(num) {}
	int getAge() const {
		return age;
	}
	void setDefaultAge() {
		age = AGE;
	}
	int setAge(int num) const {
		// age = num;       // error: const修饰的函数不能修改成员变量。
		// setDefaultAge(); // error: 调用了其他非 const 成员函数
	}
};

void const_main() {
	/*
	* const修饰指针：
	* 速记：
	* 很多时候我们分不清const到底是作用于指针本身还是指针所指向的对象，基于此，我们可以通过看const右边是变量名还是数据类型来判别
		举例：
		上面的p1,由于const右边是数据类型int，所以该const作用于指针所指向的对象
		上面的p2,由于const右边是指针p2，所以该const作用于指针本身
	*/
	int a = 1;
	int b = 2;
	const int* ap = &a; // const修饰对象：指针可以修改，但是值不能改
	ap = &b;
	// *ap = 33; error.
	int* const bp = &b; // const修饰指针：指针不可以修改，但是值可以改
	*bp = 99;
	// bp = &a; error.
}