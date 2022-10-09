#include<iostream>
using namespace std;

// 类型转换
void know_type_transform() {
	// 普通方式类型转换
	double age = 23.3;
	int age_t = (int)age; // C风格的类型转换
	int age_t_2 = int(age);
	cout << boolalpha << (age_t == age_t_2) << endl; // 23

	// 四种方式转换
	/*
	static_case:
		1. 主要用于内置数据类型之间的相互转换。
		2. static_cast只能在有相互联系（继承）的类型间进行转换，且不一定包含虚函数。
		3. 将void指针转换为指定类型的指针
	*/
	double age2 = 23.4;
	int age2_t = static_cast<int>(age2);

	int a = 12;
	int *a_p = &a;
	void *v_p = static_cast<void *>(a_p); // 万能指针void*
	double *d_p = static_cast<double *>(v_p);

	/*
		const_cast: 
			可以去除const关键字，只针对与指针、引用
			const类型不可以直接设置指针
			类中的const成员函数中的成员变量是不可以被改变的，const_cast也可以利用于去掉常成员函数中变量的const限制，使得它可以被修改。
	*/
	const int name = 12.3;
	int *n_p = const_cast<int *>(&name);
	int &n_y = const_cast<int &>(name);

	/*
		dynamic_cast: 用于虚函数父类于子类之间的指针或引用的转换，使用的前提就是必须要有虚函数。有额外开销，非必要不适用。
		转换失败时等于nullptr
	*/

	//reinterpret_cast: 类似于C语言显示强制转换，不存在检查，在编译阶段直接转换、强制赋值。但未知是否出错，且后果自负，慎重使用。
	int n = 1;
	int *p = reinterpret_cast<int *>(n);
	char *pCh = reinterpret_cast<char *>(p);

}