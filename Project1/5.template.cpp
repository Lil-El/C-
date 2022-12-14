#include<iostream>
#include <vector>
using namespace std;

template<typename T>
using tmp_type = T;

// 函数模板
template <typename T>
T h_5_tmp(T a, T b) {
	return a + b;
}

// 类模板
template <class T>
class h_5_tmp_cls {
	T name;
public:
	h_5_tmp_cls() {}
	h_5_tmp_cls(T init) {
		name = init;
	}
	void setName(T n) {
		name = n;
	}
	T getName() {
		return name;
	}
};

/*
* 模板特化：模板参数在某种特定类型下的具体实现
*/
// 模板原型
template<typename T>
T tmp_fn1(T arg) {
	return arg;
}
// 模板全特化
template<>
int tmp_fn1<int>(int arg) {
	return 1;
}
// 函数重载，实现了函数模板特化的功能，避免函数模板的特化失效
int tmp_fn1(int arg) {
	return 1;
}

/*
* 模板偏特化：指定部分模板参数而非全部模板参数，或者指定模板参数的部分特性分而非全部特性
*/
// **************函数**************
template<typename T, typename U>
void tmp_fn2(T arg1, U arg2) {}
// 对部分模板参数进行特化
template<typename T>
void tmp_fn2(int arg1, T arg2) {} // void tmp_fn2<int, T>(int arg1, T arg2) {} Error：报错非法使用显示参数；在class中允许
// 将模板参数特化为指针(模板参数的部分特性)
template<typename T, typename U>
void tmp_fn2(T* arg1, U* arg2) {}
// 将模板参数特化为另一个模板类
template<typename T, typename U> 
void tmp_fn2(vector<T>& arg1, vector<T>& arg2) {}

// **************类**************
template<typename T, typename U>
class tmp_cls2 {};
// 类模板偏特化
template<typename T>
class tmp_cls2<int, T> {};
// 
template<typename T, typename U>
class tmp_cls2<T*, U*> {};

/*
* 调用优先级从高到低进行排序是：全特化类>偏特化类>主版本模板类
*/

/********************Error**********************/

// C++ 不允许同名而参数个数不同的 templates 存在；两个template个数必须一致
template<typename T>
struct tmp_str1{};
/*
* 报错，参数太多
  template<typename T, typename U>
  struct tmp_str1 {};
*/

/********************参数列表**********************/
template<typename... Args>
struct Sum;
//基本定义
template<typename First, typename... Rest>
struct Sum<First, Rest...> //如果没有上面的前置声明，会报错：'Sum' is not a class template
						   //主模板的声明中不允许使用模板参数列表C/C++(840)
{
	enum { value = Sum<First>::value + Sum<Rest...>::value };
};
//递归终止
template<typename Last>
struct Sum<Last>
{
	enum { value = sizeof(Last) };
};

void tmp_main() {
	int result = h_5_tmp<int>(1, 1);
	cout << result << endl;
	int result2 = h_5_tmp(1, 1);
	cout << result2 << endl;

	h_5_tmp_cls<int> ins;
	ins.setName(1);
	cout << ins.getName() << endl;

	h_5_tmp_cls<const char *> inst("mino");
	//inst.setName(1); // Error
	inst.setName("Mino");

	cout << "*********************************************" << endl;

	cout << tmp_fn1(1) << endl;
	cout << tmp_fn1("abc") << endl;

	Sum<int, char> s;
	cout << s.value << endl;
}