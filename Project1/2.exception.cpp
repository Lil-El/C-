#include<iostream>
#include<exception>
using namespace std;

/*
* 
* void fn() throw() {}
* 在函数后接throw()表示：
	throw(type) 表示可能会抛出type类型的异常
	throw()     表示不会抛出异常
	throw(...)  表示可能抛出任何异常


  在C++11中，使用noexcept代替，异常返回false，否则是true
  void fn() noexcept {}

  在C++17中，throw()被废弃了
*/

// 通过继承、重载exception来实现自己的异常，exception有一个公共函数what，可以获取异常产生原因
struct MyException : public exception {
	const char *what() const throw() {
		return "It's my error!";
	}
};

/*
* 该关键字告诉编译器，函数中不会发生异常,这有利于编译器对程序做更多的优化。
如果在运行时，noexecpt函数向外抛出了异常（如果函数内部捕捉了异常并完成处理，这种情况不算抛出异常），程序会直接终止
https://blog.csdn.net/u011942101/article/details/123940489
https://blog.csdn.net/qq_24127015/article/details/104412800
*/
void oneExcepFn() throw() {
	throw 1;
}

void excp_main() {
	try {
		throw MyException();
		//throw "Division by zero condition!";
	}
	catch (const char *msg) {
		cout << msg;
	}
	catch (MyException &err) {
		cout << err.what();
	}
	catch (const exception &e) {
		cout << e.what();
	}
}