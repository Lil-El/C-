#include <iostream>
#include <string>
using namespace std;

/*
* ָ������ɾ����������ڴ�й©��
* C++ STL�ṩ����������ָ�룺auto_ptr���ѷ�������unique_point��shared_point��weak_point
*/
void smart_point_main() {
#if _HAS_AUTO_PTR_ETC
	auto_ptr<string> p1(new string("auto point is deprected in C++11."));
	auto_ptr<string> p2;
	p2 = p1; // ����ָ�룬�ƽ��ڴ��p2��p1���ٿ��Է����ڴ棬������ָ������
	cout << *p2.get() << endl;
	//cout << *p1.get() << endl; error.
#endif // _HAS_AUTO_PTR_ETC
 
}
