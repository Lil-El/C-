#include <iostream>
using namespace std;

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

/*
* constexpr函数：
* 函数的返回类型及所有形参类型都是字面值类型
* 函数体中只有一条return 语句
*/
constexpr int getNum(int n) {
	return n + 1;
}
consteval int getNum2(int n) {
	return n + 1;
}

/*
* constexpr修饰函数仅表示支持在编译期求值（是否真的在编译期求值，不确定），但是在有些时候我们要求必须在编译期求值。
* consteval只能修饰函数，要求函数必须在编译期求值。
*/
consteval int min(initializer_list<int> array)
{
	int low = numeric_limits<int>::max();
	for (auto& i : array)
	{
		if (i < low)
		{
			low = i;
		}
	}
	return low;
}

const char* GetStringDyn() {
	return "dynamic init";
}
constexpr const char* GetString(bool constInit) {
	return constInit ? "constant init" : GetStringDyn();
}

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

	/*
	* constexpr：constexpr表达式是指值不会改变并且在编译过程就可求值的表达式。
	* 声明为constexpr的变量一定const变量，而且必须用常量表达式初始化。
	*/

	// 常量表达式：指值不会改变并且在编译过程就能得到结果的表达式；字面值、用常量表达式初始化的const对象也是常量表达式。
	// 字面值类型：算术类型、引用和指针都属于字面值类型，自定义类、IO库，string类型则不属于字面值类型，不能被定义成constexpr；
	// 1, c1, 2, d + c 都是常量表达式
	const int c1 = 1;
	constexpr int c = c1; // 如果c1不是const，会报错
	constexpr int d = 2;
	constexpr int e = d + c; 
	constexpr int f = getNum(1); // 函数必须是constexpr常量函数

	constexpr int* cp = nullptr; // 限定符constexpr仅对指针有效。指针不能改，值可以改
	constexpr const int* dp = nullptr; // 指针和对象都不能改

	// constinit修饰变量，保证变量在编译期初始化。只能使用constexpr或consteval函数初始化constinit变量
	// thread_local: 对象的存储在线程开始时分配，而在线程结束时解分配。每个线程拥有其自身的对象实例
	constinit thread_local int g = getNum(1); // static 或 thread_local

	cout << "********" << endl;

	int nn = getNum(100);
	cout << ++nn << endl;
	//int nnn = getNum2(nn); 报错-nn不是常量
	const int nn1 = getNum(100); // getNum是constexpr的，如果需要在编译求值，那么nn1也应该改为constexpr；否则就是运行执行了
	int nn2 = getNum2(nn1);
}
