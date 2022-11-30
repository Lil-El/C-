#pragma once

#ifndef  My_Util
#define  My_Util

#include <iostream>
using namespace std;
// class通常定义在h文件中；因为编译器无法知道需要为class分配多少内存

class Shape {
private:
	int width;
	int height;

public:
	Shape(int w, int h) {
		width = w;
		height = h;
	}
	// class的成员函数可以定义在类内部；或者通过"范围解析运算符::"在外部去定义成员函数；
	// 1. 使用内部定义无所谓，可以正常运行
	// 2. 在头文件中通过::定义时，在重复引用头文件时会被提示重复定义；所以要在cpp文件中去定义成员函数
	int getArea(); 
};

extern int age0; // 定义一个全局变量

// 其他文件定义此age0，logAge可以输入正确的age0
//void logAge() {
//	cout << age0 << endl;
//};
void logN(int num);

//int agex = 1; // 如果只有一个cpp文件包含了此头文件，则不报错，否则重定义

// cosnt、static修饰的不影响
static int age; 
const int age2 = 100;
const static char global_str[20] = "Hello World";

#endif // !My_Util