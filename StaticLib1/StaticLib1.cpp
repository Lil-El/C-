#include <iostream>
#include "pch.h"

// 在项目右键属性中可以修改项目属性是lib还是dll
// 并且可以设置选择是否使用预编译头，选择之后每个源文件都应该使用预编译头，否则就会报错

// 这是一个库函数示例
void fnStaticLib1()
{
    int someIdentifier = 42;
    std::cout << "Some Identifier: " << someIdentifier << std::endl;
}

// StaticOne在.h文件中定义，在.cpp文件中就不能再写class StaticOne{...}了，会重复定义。
StaticOne::StaticOne(int a) : age(a) {};
void StaticOne::sayHello() {
    std::cout << "Hello， it's class of StaticOne." << std::endl;
};