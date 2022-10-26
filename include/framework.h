#pragma once

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
