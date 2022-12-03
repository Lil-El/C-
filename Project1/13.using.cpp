#include <iostream>
using namespace std;

/*
* using用法：
*
1. 类型定义，类似于typedef；using mInt = int;
2. 命名空间，using namespace
3. 父类成员变量修饰 `class: private parent { public: using parent::name};`
4. 父类重载函数 `class : parent {using parent::getName()}`
5. using可以定义函数指针，给模板定义别名
*/

// class使用
template <typename T>
class Using_Parent {
public:
	using mInt = T;
	Using_Parent() : age(24) {};
	int age;
	constexpr int getAge() noexcept {
		return age;
	}
	constexpr int getAge(int a) noexcept {
		return age;
	}
};

template<class T>
class Using_Child : private Using_Parent<T> {
public:
	using Using_Parent<T>::age; // 不加这一句，c.age就会报错；因为父级的成员都是private的
	using Using_Parent<T>::getAge; // 加这一句，c可以使用所有getAge的重载
};

// using模板
template<class T>
using myInt = T;

// struct
struct Using_Struct {
	using mmInt = int;
};

// 函数指针
template<typename T>
using funcType = T(*)(T, T);

template <typename T>
struct STFunc {
	typedef T(*type)(T, T);
};

typedef int(*func)(int a, int b);
using func1 = int(*)(int a, int b);

// add
int add(int l, int r) {
	return (l)+(r);
}

void using_main() {
	Using_Parent<myInt<int>> p; // int
	cout << p.getAge() << endl;
	Using_Child<Using_Struct::mmInt> c; // int
	cout << c.age << endl;
	cout << c.getAge() << endl;
	cout << c.getAge(1) << endl;

	cout << "*************" << endl;

	STFunc<int>::type fn1 = add;
	funcType<int> fn2 = add;
	func fn3 = add;
	func1 fn4 = add;
	cout << fn1(1, 2) << endl;
	cout << fn2(1, 2) << endl;
	cout << fn3(1, 2) << endl;
	cout << fn4(1, 2) << endl;
}