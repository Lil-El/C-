#include <iostream>
#include <string>
using namespace std;

void test_shared() {
	class A;
	class B;
	// 循环引用
	class A {
	public:
		shared_ptr<B> point;
		~A() {
			cout << "A delete." << endl;
		}
	};
	class B {
	public:
		shared_ptr<A> point;
		~B() {
			cout << "B delete." << endl;
		}
	};
	shared_ptr<A> pa(new A());
	shared_ptr<B> pb(new B());
	//       1                        1
	cout << pa.use_count() << ":" << pb.use_count() << endl;
	// 由于循环引用，函数结束时计数减一，仍然为1，导致不会调用析构函数，造成内存泄漏。
	pa->point = pb;
	pb->point = pa;
	//       2                        2
	cout << pa.use_count() << ":" << pb.use_count() << endl;
}

void test_weak() {
	class A;
	class B;
	// 循环引用
	class A {
	public:
		weak_ptr<B> point;
		void print() {
			cout << "It's A." << endl;
		}
		~A() {
			cout << "A delete." << endl;
		}
	};
	class B {
	public:
		shared_ptr<A> point;
		void print() {
			cout << "It's B." << endl;
		}
		~B() {
			cout << "B delete." << endl;
		}
	};
	shared_ptr<A> pa(new A());
	shared_ptr<B> pb(new B());
	//       1                        1
	cout << pa.use_count() << ":" << pb.use_count() << endl;
	// 这样的话，资源B的引用开始就只有1，当pb析构时，B的计数变为0，B得到释放，B释放的同时也会使A的计数减1，同时pa析构时使A的计数减1，那么A的计数为0，A得到释放。
	pa->point = pb;
	pb->point = pa;
	//       2                        1
	cout << pa.use_count() << ":" << pb.use_count() << endl;

	// weak_ptr不可以直接访问，pa->point->print()；
	// 需要先转换为shared_ptr，
	if (!pa->point.expired()) {
		shared_ptr<B> ps = pa->point.lock();
		ps->print();
	}
}

/*
* 指针忘记删除，会造成内存泄漏。
* C++ STL提供了四种智能指针：auto_ptr（已废弃）、unique_point、shared_point、weak_point
*/
void smart_point_main() {
	/*
	* auto_ptr潜在内存泄漏
	*/
#if _HAS_AUTO_PTR_ETC
	auto_ptr<string> p1(new string("auto point is deprected in C++11."));
	auto_ptr<string> p2;
	p2 = p1; // 智能指针，移交内存给p2，p1不再可以访问内存，避免了指针悬挂
	cout << *p2.get() << endl;
	//cout << *p1.get() << endl; error.
#endif // _HAS_AUTO_PTR_ETC

	/*
	* unique_ptr用于替换auto_ptr，独占内存。
	* unique_ptr的拷贝构造函数和拷贝赋值均为delete；
	* 避免相互赋值，只可以通过移动进行赋值。
	* 避免内存泄漏
	*/
	cout << "******unique_ptr******" << endl;
	unique_ptr<string> p1(new string("unique_ptr1."));
	unique_ptr<string> p2;
	//p2 = p1; error. 只能通过移动赋值，也就是赋右值。
	p2 = unique_ptr<string>(new string("unique_ptr2."));
	cout << *p2 << endl;
	p2 = move(p1);
	cout << *p2 << endl;

	/*
	* shared_ptr共享，缺点为：当两个对象相互使用一个shared_ptr成员变量指向对方，会造成循环引用，计数失效，内存泄漏（计数不为0永远不会释放内存）。
	* 使用weak_ptr避免循环引用。
	*/
	cout << "******shared_ptr******" << endl;
	string *str = new string("string.");
	shared_ptr<string> s1(str);
	shared_ptr<string> s2(str);
	//          1                         1
	cout << s1.use_count() << ":" << s2.use_count() << endl;
	shared_ptr<string> s3 = s1;
	//       2                         1                       2
	cout << s1.use_count() << ":" << s2.use_count() << ":" << s3.use_count() << endl;
	s3.swap(s2);
	//      2                          2                       1
	cout << s1.use_count() << ":" << s2.use_count() << ":" << s3.use_count() << endl;
	s2.reset(); // s2变为空指针
	//      1                          0                       1
	cout << s1.use_count() << ":" << s2.use_count() << ":" << s3.use_count() << endl;

	test_shared();

	/*
	* weak_ptr:解决shared_ptr相互引用的死锁问题。
	*/
	cout << "******weak_ptr******" << endl;
	test_weak();
}
