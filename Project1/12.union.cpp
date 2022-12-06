#include<iostream>
using namespace std;

/*
* union长度是最长的类型的长度。
* 共用同一段内存空间，会相互覆盖
* 
* 
*   1. 长度取最长的(可能存在内存补齐). 且成员起始地址都一样
	2. 当其中一个成员被赋值时, 其他成员的值会被覆盖.
	3. union变量不能作为函数参数和返回值, 不过指向union变量的指针可以
	4. union中不能含构造/析构/拷贝构造/赋值运算符/虚函数

	由于union里面的东西共享内存，所以不能定义静态、引用类型的变量。
	由于在union里也不允许存放带有构造函数、析构函数和复制构造函数等的类的对象，但是可以存放对应的类对象指针。
	编译器无法保证类的构造函数和析构函数得到正确的调用，由此，就可能出现内存泄漏。
*/

class union_class {
public:
	int age = 9;
	union_class() {}
};

union my_union {
	int age;
	char c;
	float af;
	//union_class ua; union不能使用拥有构造、析构等函数的类
	union_class* ua;
};

void union_main() {
	my_union u1;
	u1.age = 100; // u1.c = 'd'; // a97 b98 c99 d100
	cout << "value is: " << u1.age << " " << u1.c << endl;

	// 内存地址都是一样的
	cout << "address is: " << &u1.age << " " << addressof(u1.ua) << endl;

	cout << "size is: " << sizeof(u1) << endl;
}