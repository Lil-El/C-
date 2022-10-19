#include <iostream>
using namespace std;

/*
问题：
	当继承关系如下时：A派生B、C。D继承B，C。
	class lve_A {
	public:
		int m_a;
		lve_A(int n) : m_a(n) {};
	};

	class lve_B : virtual public lve_A {
	public:
		int m_b;
		lve_B(int n) : m_b(n), lve_A(2) {};
	};

	class lve_C : virtual public lve_A {
	public:
		int m_c;
		lve_C(int n) : m_c(n), lve_A(2) {};
	};

	class lve_D: public lve_B, public lve_C {
	public:
		int m_d;
		lve_D(int n) : m_d(n), lve_B(3), lve_C(3) {};
	};
	在D的实例中使用m_a时，会产生歧义，编译器不知道使用A-B-D的m_a还是A-C-D的m_a
解决：
	为了解决上面问题，使用虚继承。为B、C添加virtual。
	- 虚继承：让某个类做出声明，并共享它的基类。在这种机制下，不论虚基类a在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。
	- 在普通的继承关系中，派生类只能直接基类的构造函数，但是在虚继承关系中，派生类d可以调用间接基类a的构造函数。原因也是为了避免二义性，不知道A使用B的还是C的构造函数
	- 在继承关系中，构造函数都是按照从上到下顺序调用的，多继承时按照顺序调用。
		A->B->D单继承的调用顺序：ABD
	    A->BC->D多继承的调用顺序是：
			多继承：class D: public C, public B;     调用顺序A C A B D
			多继承：class D: public B, public C;     调用顺序A B A C D
			虚继承：class D: public C, public B;     调用顺序A C B D
			虚继承：class D: public B, public C;     调用顺序A B C D

因为在虚继承的最终派生类中只保留了一份虚基类的成员，所以该成员可以被直接访问，不会产生二义性。此外，如果虚基类的成员只被一条派生路径覆盖，那么仍然可以直接访问这个被覆盖的成员。但是如果该成员被两条或多条路径覆盖了，那就不能直接访问了，此时必须指明该成员属于哪个类。
假设 A 定义了一个名为 x 的成员变量，当我们在 D 中直接访问 x 时，会有三种可能性：
	如果 B 和 C 中都没有 x 的定义，那么 x 将被解析为 A 的成员，此时不存在二义性。
	如果 B 或 C 其中的一个类定义了 x，也不会有二义性，派生类的 x 比虚基类的 x 优先级更高。
	如果 B 和 C 中都定义了 x，那么直接访问 x 将产生二义性问题。
*/

class lve_A {
public:
	int m_a;
	lve_A(int n) : m_a(n) {
		cout << "A" << endl;
	};
};

class lve_B : virtual public lve_A {
public:
	int m_b;
	lve_B(int n) : m_b(n), lve_A(2) {
		cout << "B" << endl;
	};
};

class lve_C : virtual public lve_A {
public:
	int m_c;
	lve_C(int n) : m_c(n), lve_A(2) {
		cout << "C" << endl;
	};
};

class lve_D : public lve_C, public lve_B {
public:
	int m_d;
	lve_D(int n) : m_d(n), lve_C(3), lve_B(3), lve_A(3) {
		cout << "D" << endl;
	};
	// m_a不明确，编译器不知道是A - B - D这条继承链的还是A - C - D这条继承链，所以要使用范围选取符::
	int getMA() {
		return lve_B::m_a;
	}
};

void learn_virtual_extend_main() {
	lve_D d(3);
	d.getMA();
}