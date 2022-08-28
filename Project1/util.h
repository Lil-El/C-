#pragma once

#ifndef  A
#define  A

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

void logN(int num);
const static char global_str[20] = "Hello World";

#endif