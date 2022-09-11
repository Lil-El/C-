#include<iostream>
using namespace std;

void point_main() {
	// 在C中，NULL == ((void *)0); 但是在C++中void*不能隐式转换成其他类型的指针
	// 所以：C++中NULL == 0
	/* if __cplusplus
		#define NULL 0
		else
		#define NULL ((void*)0)
	*/
	// C++NULL==0对于函数重载有影响的(C中没有函数重载)；
	/*
		func(void * i); 1
		func(int i);    2
		func(NULL)  目的让这里执行1，但是执行的是2方法
		func(nullptr)  执行的是1方法
		为了解决这个问题，引入nullptr
	*/
	int *a = 0;
	int *b = NULL; // NULL === 0
	int *c = nullptr; // C++11引入 nullptr
	/*
	* 模拟nullptr的实现
		const class nullptr_t_t
		{
			public:
				template<class T>           operator T*() const {return 0;}
				template<class C, class T>  operator T C::*() const { return 0; }
			private:
				void operator& () const;
		} nullptr_t = {};
		#undef NULL
		#define NULL nullptr_t
	*/
	// T C::*是成员指针，可以用来指向类成员。
	/*
	* 成员指针应用：
		struct C { int foo; int bar; };
		C valc;
		int C::*pmbr=nullptr;
		int x=0;

		pmbr=&C::foo;
		pmbr=&C::bar;
		valc::*pmbr=-1;
		std::swap(valc::*pmbr, x);
	*/
	int arr[5]{ 1,2,3,4,5 }; // arr是一个常量指针，不可以递增，故而也不能给arr重新赋值
	int *arr_point = arr;
	// 指针递增、递减
	arr_point++;
	cout << *(arr_point) << endl;
	// 指针比较
	bool flag = 1 < 0;
	cout << boolalpha; // 加上boolalpha可以输出true false
	cout << flag << endl;
	cout << noboolalpha; // 加上noboolalpha可以输0或1
	cout << (arr < arr_point) << endl;

	// 指针数组
	int a1 = 1;
	int *pa1 = &a1;
	const int *point_arr[] = { pa1 };

	// 指向指针的指针
	int b1 = 1;
	int *pb1 = &b1;
	int **p_pb1 = &pb1;

}