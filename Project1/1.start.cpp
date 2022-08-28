#include <iostream>
using namespace std;

int start_main() {

	// 数据类型
	bool isOk = false; // 1字节
	int age = 25; // 4字节
	char str[] = "A";
	float size = 13.3; // 4字节
	double peopel = 14.44; // 8字节
	// void 
	// wchar_t
	// 枚举
	enum OBJ {
		name,
		age2 = 100,
		sex
	} obj;
	
	// 修饰符
	unsigned int us_age = 10; // 无符号4字节
	signed int si_age = 10; // 有符号4字节
	short int s_age = 10; // 2字节
	long int l_age = 10; // 8字节
	signed long int sli_age = 10; // 8

	cout << "sizeof age is:" << sizeof(age) << endl;

	obj = name;
	cout << obj << endl;
	OBJ obj2 = age2;
	cout << obj2 << endl;
	cout << name << age2 << sex << endl;

	typedef OBJ myEnum;
	myEnum my_enum = sex;
	cout << "my_enum:" << my_enum << endl;

	// 常量 static存储类
	age = 22;
	const static int myAge = 18; // static变量，多个函数直接共享一个值；用于class成员时，所以class对象都共享一个对象

	return 0;
}