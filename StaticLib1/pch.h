#pragma once

/*
	pch表示预编译头文件Pre-compiled Header。
	对于比较大型的工程，往往编译时间会很久，通过使用PCH，把那些不经常发生改动的头文件都预先编译出来，就可以大大节省实际使用时候的编译时间
	应在此处包含任何稳定的标头文件，例如标准库标头（如 <vector>）
*/

#ifndef STATIC_LIB
#define STATIC_LIB

#include <iostream>
using namespace std;

void fnStaticLib1();

class StaticOne {
	int age;
public:
	StaticOne() {};
	StaticOne(int a);
	void sayHello();
};

#endif // !STATIC_LIB
