#include <iostream>
using namespace std;

/*
* using�÷���
*
1. ���Ͷ��壬������typedef��using mInt = int;
2. �����ռ䣬using namespace
3. �����Ա�������� `class: private parent { public: using parent::name};`
4. �������غ��� `class : parent {using parent::getName()}`
5. using���Զ��庯��ָ�룬��ģ�嶨�����
*/

// classʹ��
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
	using Using_Parent<T>::age; // ������һ�䣬c.age�ͻᱨ����Ϊ�����ĳ�Ա����private��
	using Using_Parent<T>::getAge; // ����һ�䣬c����ʹ������getAge������
};

// usingģ��
template<class T>
using myInt = T;

// struct
struct Using_Struct {
	using mmInt = int;
};

// ����ָ��
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