#include <iostream>
#include "util.h"
using namespace std;

// 头文件声明age0，cpp进行定义
int age0 = 521;

// 其他文件调用logAge也可以输入521

void logN(int num) {
	age = 99;
	cout << "util's age: " << age << endl;
	cout << "util's age2: " << age2 << endl;
	cout << "util's age0: " << age0 << endl;
	cout << "log:" << num << endl;
}

int Shape::getArea() {
	return width * height;
}

Shape shape(2, 3);