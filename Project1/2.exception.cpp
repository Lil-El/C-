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

  在C++17中，throw(动态list)被废弃了，throw()没有
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
*/
/*
* https://zyfforlinux.blog.csdn.net/article/details/50410314
	1. 异常抛出的代码块中，对象会被析构，称之为堆栈反解．
		1.1 异常中的资源清理：如果在构造器中报错，那么就会出现内存泄漏。所以避免在构造器出错，如果出错了在构造器中进行捕获异常。
			int main() try {
				throw "main";
			} catch(const char* msg) {
				cout << msg << endl;
				return 1;
			}
			或者
			Base(int data,string str)try:m_int(data),m_string(str)//对初始化列表中可能会出现的异常也会进行捕捉
		   { }catch(const char* msg) {
				cout << "catch a exception" << msg << endl;
		   }
	2. 抛出子类异常，使用父类进行catch
	3. 一直没有catch，就会自动调用unexpected，terminate函数；可以自定义修改set_terminate，set_unexpected函数
	4. C++标准异常：
		logic_error
		runtime_error
		bad_exception：处理无法预期的异常
		out_of_range
		ranger_error
		bad_alloc：该异常通过new抛出
		等
*/
#ifdef _HAS_CXX17
void oneExcepFn() noexcept(false) {
	throw 1;
}
#else
void oneExcepFn() throw() {
	throw 1;
}
#endif

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