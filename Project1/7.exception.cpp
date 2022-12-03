#include <iostream>
using namespace std;

// 指定noexcept后，发生异常会提示；否则异常也不提示
// noexcept(true)和 noexcept和__declspec(nothrow)和throw()一样，表示不会抛出异常
/*
* 加了noexcept或者noexcept(true)时表示不会抛出异常，这时抛出异常是无法捕获throw内容；
* 如果是noexcept(false)表示可能抛出异常，此时抛出异常可以捕获
* 
	throw()和noexcept相比，noexcept会直接中断程序。
	因为throw()不知道是什么异常，会在当前函数的catch匹配，没有则回退调用栈的上一层去处理异常，一直找不到就执行unexpected；一系列操作反而会影响程序。
		使用第三方的库时，你都不知道catch什么错误。
		如果fn() throw(int, double)，fn中throw其他类型的错误，编译是可以通过的，也没有警告。
		知道“会抛什么异常”没什么意义，但是知道“是否会抛异常”可以有不同的优化
	所以直接使用noexcept直接terminate退出程序

	http://www.wjhsh.net/5iedu-p-11270922.html
*/
int know_key_fn(bool flag) noexcept(false) /* throw() */ {
	if (flag) {
		return 99;
	}
	else {
		throw true; //  "MM"; // 500
	}
}

[[noreturn]] void know_key_main(void) {
	//int a = know_key_fn(false);
	try
	{
		int b = know_key_fn(false);
	}
	catch (const int& err) {
		cout << err << endl;
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...) // 捕获全部类型异常
	{
		cout << "catch unknown error" << endl;
	}
	// return; // 因为是noreturn，所以即使写了return;也会提示错误
}