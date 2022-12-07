#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
* 匿名函数，也称为Lambda表达式、Lambda函数
* 很便捷，编译器有可能会使用“循环展开”，加速执行过程
* 
* []: 外部变量
* (): 参数，没有可以省略
* ->return-type: 返回值类型，默认是 ->void ，也可以省略
* {}: 函数体
* 
* Lambda使用外部的变量，这些变量的集合叫做闭包。闭包定义在[]之内
* []: 所有变量不能使用，除非全局变量
* [=]: 所有变量拷贝
* [&]: 所有变量引用
* [=, &a]: 获取所有变量拷贝，a是引用
* [x, &y]: 获取x拷贝，y的引用
* [x]: 获取x的拷贝
* [this]: 获取class中的this指针
*/

// 函数作为参数：1. 使用函数指针 2. typename Lambda 3. function
template<typename T>
void lambda_fn1(const T& fn) {
	fn();
}

// function<int(void)> 表示函数返回值int，参数是void
void lambda_fn2(const function<void()> &fn) {
	fn();
}

void lambda_main() {
	auto func = []() -> void {
		cout << "lambda." << endl;
	};
	func();

	// for_each
	// for_if

	function<int(int, int)> func1 = [](int a, int b) ->int { return a + b; };
	cout << func1(1, 2) << endl;

	// labmda函数是一个const函数，使用mutable取消其常量性。使用mutable时，参数括号()，即使为空也不能省略
	int x = 0;
	int y = 9;
	[&x, y](int a) mutable {
		x = ++y + a;
	}(1);
	cout << x << endl;

	// exception
	[]() noexcept {
		throw 1;
	};

	auto fn = []() -> void {
		cout << "lambda_fn1" << endl;
	};
	lambda_fn1(fn);
	lambda_fn2(fn);
}