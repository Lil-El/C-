#include <iostream>
#include <string>
using namespace std;

/*
* 指针忘记删除，会造成内存泄漏。
* C++ STL提供了四种智能指针：auto_ptr（已废弃）、unique_point、shared_point、weak_point
*/
void smart_point_main() {
#if _HAS_AUTO_PTR_ETC
	auto_ptr<string> p1(new string("auto point is deprected in C++11."));
	auto_ptr<string> p2;
	p2 = p1; // 智能指针，移交内存给p2，p1不再可以访问内存，避免了指针悬挂
	cout << *p2.get() << endl;
	//cout << *p1.get() << endl; error.
#endif // _HAS_AUTO_PTR_ETC
 
}
