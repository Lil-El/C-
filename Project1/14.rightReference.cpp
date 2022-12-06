#include <iostream>
using namespace std;

template <class _Ty>
_Ty&& mforward(remove_reference_t<_Ty>& _Arg) { 
	return static_cast<_Ty&&>(_Arg);
}

void rightReferenceForward(int&& arg) {
	cout << "right" << endl;
}
void rightReferenceForward(int& arg) {
	cout << "left" << endl;
}

/*
* 万能引用：
* 编译器有一个规则，如果传入的是左值，则模板类型会被推导成左值引用类型； 传入的是右值，则模板类型就是值的类型
* 
* forward：将左值作为左值或右值进行转发；将右值进行转发
* remove_reference_t: 分离出不带引用符号的类型T
*    
	template <class _Ty>
		_Ty&& forward(remove_reference_t<_Ty>& _Arg) { // forward an lvalue as either an lvalue or an rvalue
		return static_cast<_Ty&&>(_Arg);
	}
* 
* 推导折叠：
*   Base&& && -> Base&&
	Base& &&  -> Base&
	Base&& &  -> Base&
	Base& &   -> Base& 
* 
* 实参：99
* T 是 int&&
* 传给forward<int&&>：_Ty 是 int&&；_Arg是int&& &；_Ty&& 是 int&& &&
* 根据引用折叠，int&& &&会变成int&&
* 
* * 实参：x
* T 是 int&
* 传给forward<int&>：_Ty 是 int&；_Arg是int& &；_Ty&& 是 int& &&
* 根据引用折叠，int& &&会变成int&
*/
template <typename T>
void rightReferenceForward_t(T&& arg) {
	// 在使用过程中，arg自动推导类型T为int&&了。但是后续使用中arg会退化为左值。
	// 但是arg虽然是右值引用，但也是左值。所以 int& x = 右值引用。

	//rightReferenceForward(arg); // error. 无法将T转换为int&&；arg是左值，统一都走了left函数

	// 使用forward（完美转发）处理，arg是左值，但是T分别是int&和int&&
	rightReferenceForward(static_cast<T>(arg)); // 和下面一样
	rightReferenceForward(mforward<T>(arg));  // 和上面一样
}

/*
* 左值是一个内存实体，可以&，可以存在很久
  右值没有内存实体，只是临时的，用一次就不用了
  像函数返回值，10等，都是临时或者将亡值，用一次就不再使用了

* 移动构造函数和移动赋值函数中使用
*/
void rightReference_main() {
	int x = 10; // x是左值，10是右值
	const int& lx = x; // 左值引用
	//int& rx = 10; error. 只能对左值进行引用
	//lx += 1; error. const常量无法修改

	//int&& lx = x; error. 只能对右值进行绑定
	int&& rx = 10; // 右值引用

	/*
	* move强制将左值转为右值
	* _Ty&&表示万能引用，可以传int&、int&&、const、非const，去推到_Ty类型
	* 所以，在模板中不能直接返回_Ty&&，因为他是万能引用，所以通过struct::type，转为右值引用
	*/
	int&& y = move(x);

	/*
	* 右值引用只可以初始为右值
	* 常量右值引用只可以初始为常量右值
	* const左值引用可以初始为左、右值、const、非const
	* 普通左值引用可以初始为普通左值（即非常量左值引用）
	*/
	//int& z = x + x; error. 非常量引用初始值必须是左值
	const int& z = x + x;
	int& z1 = y; // y是右值引用，但也是左值，所以可以使用左值引用
	int&& a = x + z;
	a += 1;

	// static_cast可以显示的将左值转为右值
	int&& rx1 = static_cast<int&&>(x); 

	// remove_reference_t：见名知意是移除引用，int&/int&&都会变成int
	remove_reference_t<int&>&& r1 = 10;
	remove_reference_t<int&&>&& r2 = 10;

	rightReferenceForward_t(x);  // 调用左值函数 left
	rightReferenceForward_t(99); // 调用右值函数 right
}