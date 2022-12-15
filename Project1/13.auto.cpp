#include <iostream>
using namespace std;

/*
* 类型自动推导：可应用在变量、函数、模板等
*/

template<typename T>
auto auto_fn(int n, auto b) {
	auto a = T::get();
	cout << "T::get()：" << a << endl;
	if (n < 2) {
		return true;
	}
	return false;
}

struct auto_struct {
	static bool get() {
		cout << "get" << endl;
		return true;
	}
	//auto name = 1; error：struct中不允许使用auto作为成员变量
};

void auto_main() {
	//auto n1; error：必须指定值
	//auto n1[100]; 不能设置为数组

	auto num = 3; // auto - int
	//num = "sd"; error：类型确定了，不能重新更改为其他类型的值
	auto p = new auto_struct; // auto - auto_struct*
	cout << boolalpha << auto_fn<auto_struct>(num, 1) << endl;

	for (auto i = 0; i < 3; i++) {

	}
}