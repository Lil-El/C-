#include <iostream>
#include <string>
using namespace std;

void test_shared() {
	class A;
	class B;
	// ѭ������
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
	// ����ѭ�����ã���������ʱ������һ����ȻΪ1�����²��������������������ڴ�й©��
	pa->point = pb;
	pb->point = pa;
	//       2                        2
	cout << pa.use_count() << ":" << pb.use_count() << endl;
}

void test_weak() {
	class A;
	class B;
	// ѭ������
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
	// �����Ļ�����ԴB�����ÿ�ʼ��ֻ��1����pb����ʱ��B�ļ�����Ϊ0��B�õ��ͷţ�B�ͷŵ�ͬʱҲ��ʹA�ļ�����1��ͬʱpa����ʱʹA�ļ�����1����ôA�ļ���Ϊ0��A�õ��ͷš�
	pa->point = pb;
	pb->point = pa;
	//       2                        1
	cout << pa.use_count() << ":" << pb.use_count() << endl;

	// weak_ptr������ֱ�ӷ��ʣ�pa->point->print()��
	// ��Ҫ��ת��Ϊshared_ptr��
	if (!pa->point.expired()) {
		shared_ptr<B> ps = pa->point.lock();
		ps->print();
	}
}

/*
* ָ������ɾ����������ڴ�й©��
* C++ STL�ṩ����������ָ�룺auto_ptr���ѷ�������unique_point��shared_point��weak_point
*/
void smart_point_main() {
	/*
	* auto_ptrǱ���ڴ�й©
	*/
#if _HAS_AUTO_PTR_ETC
	auto_ptr<string> p1(new string("auto point is deprected in C++11."));
	auto_ptr<string> p2;
	p2 = p1; // ����ָ�룬�ƽ��ڴ��p2��p1���ٿ��Է����ڴ棬������ָ������
	cout << *p2.get() << endl;
	//cout << *p1.get() << endl; error.
#endif // _HAS_AUTO_PTR_ETC

	/*
	* unique_ptr�����滻auto_ptr����ռ�ڴ档
	* unique_ptr�Ŀ������캯���Ϳ�����ֵ��Ϊdelete��
	* �����໥��ֵ��ֻ����ͨ���ƶ����и�ֵ��
	* �����ڴ�й©
	*/
	cout << "******unique_ptr******" << endl;
	unique_ptr<string> p1(new string("unique_ptr1."));
	unique_ptr<string> p2;
	//p2 = p1; error. ֻ��ͨ���ƶ���ֵ��Ҳ���Ǹ���ֵ��
	p2 = unique_ptr<string>(new string("unique_ptr2."));
	cout << *p2 << endl;
	p2 = move(p1);
	cout << *p2 << endl;

	/*
	* shared_ptr����ȱ��Ϊ�������������໥ʹ��һ��shared_ptr��Ա����ָ��Է��������ѭ�����ã�����ʧЧ���ڴ�й©��������Ϊ0��Զ�����ͷ��ڴ棩��
	* ʹ��weak_ptr����ѭ�����á�
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
	s2.reset(); // s2��Ϊ��ָ��
	//      1                          0                       1
	cout << s1.use_count() << ":" << s2.use_count() << ":" << s3.use_count() << endl;

	test_shared();

	/*
	* weak_ptr:���shared_ptr�໥���õ��������⡣
	*/
	cout << "******weak_ptr******" << endl;
	test_weak();
}
