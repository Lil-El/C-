#include <iostream>
#include <utility>
using namespace std;

/*
* decltype：表示表达式的类型
* declval：解决decltype不足
* 
* std::declval是c++11新标准中出现的函数模板，没有函数体（只有声明，没有实现），无法被调用，
	一般用于与decltype，sizeof等关键字配合来进行类型推导、占用内存空间计算等。

template<class _Ty>
add_rvalue_reference_t<_Ty> declval() noexcept;
// add_rvalue_reference_t获取_Ty的右值引用
*/


struct Default { int foo() const { return 1; } };

struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

void declval_main() {
	int a = 10;
	decltype(a) b = 11;
	
	decltype(Default().foo()) n1 = 1;                   // n1 的类型是 int
//  decltype(NonDefault().foo()) n2 = n1;               // 错误：无默认构造函数或者为私有时，是不能通过构造一个对象去调用函数，
														// 此时需要 declval 来转换一个引用类型，然后调用类成员函数。
	decltype(declval<NonDefault>().foo()) n2 = n1;      // n2 的类型是 int

	/*Default d();
	using boost::typeindex::type_id_with_cvr;
	cout << "的返回类型=" << type_id_with_cvr<decltype(d.foo())>().pretty_name() << endl;*/
}