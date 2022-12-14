#include <iostream>
using namespace std;

/*
* 编译期间编程：
* 
* SFINAE表示替换失败不是错误( Substitution Failure Is Not An Error)。简单地说，替换就是尝试用提供的类型或值替换模板参数的机制。
* 在某些情况下，如果替换导致无效代码，编译器不应该抛出大量错误，而应该继续尝试其他可用的重载。
* SFINAE概念只是为“健全”的编译器保证这种“健全”的行为。
* 
* C++模板提供了一个SFINAE（subsitate failure is not an error）的机制（模板匹配失败不是错误），
* 当一个模板*展开*失败的时候, 会尝试用其他的重载进行展开, 而不是直接报错,
*	  常见的做法有 enable_if 和 void_t标签分发.
*	  if constexp 为我们的这种代码增加了更多的可读性
*/

/*
* 如果T是一个int类型，那么返回值是bool类型。如果不是int的话，就匹配不到找个实例。
* 使用enable_if的好处是控制函数只接受某些类型的(value==true)的参数，否则编译报错。
*/
template <class T>
typename enable_if<is_integral<T>::value, bool>::type is_odd(T i) { 
	cout << "正常匹配" << endl;
	return bool(i % 2); 
}

template <class...T>
typename bool is_odd(...) {
	cout << "不正常匹配" << endl;
	return false;
}

//////////////////////////////////////////////////////////////////
/*
* void_t分发：就是一个void，没作用。主要作用是利用void_t检验T的合法性
*/
struct hasType {
	using intType = int;
	void fun() {}
};

struct noType {
	void fun() {}
};

// T是必须的，通过T来判断是否包含成员。所以U默认给void
template <typename T, typename U = std::void_t<> > // 连续的 > 之间要有空格
struct hasTypeMem : std::false_type {};

// 在偏特化中的void_t的参数列表中进行命中
template <typename T>
struct hasTypeMem<T, std::void_t<typename T::intType> > : std::true_type {};

//////////////////////////////////////////////////////////////////

template<>
void sfinae_str () {
	if constexpr (true) {
		cout << "sfinae_str 1" << endl;
	} else {
		cout << "sfinae_str 0" << endl;
	}
};

//////////////////////////////////////////////////////////////////

template<typename T>
struct hasHello : true_type {};

//template<typename T>
//struct hasHello<T, enable_if<true, bool>::type> : false_type {};

void sfinae_main() {
	cout << "is_odd: " << is_odd(1) << endl;
	cout << "is_odd: " << is_odd("sdf") << endl;

	cout << hasTypeMem<hasType>::value << endl;
	cout << hasTypeMem<noType>::value << endl;

	sfinae_str();
}