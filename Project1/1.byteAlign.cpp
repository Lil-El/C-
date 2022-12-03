/*
* struct、class字节对齐：
* #program pack(1,2,4,8,16)等设置字节对齐
*  _declspec(align(1,2,4,8,16))设置字节对齐
*/
#include<iostream>
#include<iomanip>
using namespace std;

/*
	sizeof(ByteAlignStruct) != sizeof(a) + b + ...; 不相等的原因就是因为字节对齐
	地址偏移1个表示占1个字节

	字节对齐：
		各个平台对内存处理不同，为了保证所有平台上都可以正确读存，需要使字节对齐保持一致；
		同时提高效率，32位系统一次读取4字节，一个int值放在0-4地址可以一次读取出来，如果放在了2-6，那么就需要读两次

	要判断一个结构体所占的空间大小，大体来说分三步走：
	1.先确定实际对齐单位，其由以下三个因素决
		1> CPU周期
			WIN  vs  qt  默认8字节对齐
			Linux 32位 默认4字节对齐，64位默认8字节对齐
		2> 结构体最大成员(基本数据类型变量)
		3> 预编译指令#pragma pack(n)手动设置     n--只能填1 2 4 8 16
			上面三者取最小的,就是实际对齐单位(这里的“实际对齐单位”是我为了方便区分随便取的概念)
	2.除结构体的第一个成员外，其他所有的成员的地址相对于结构体地址(即它首个成员的地址)的偏移量必须为实际对齐单位或自身大小的整数倍(取两者中小的那个)
	3.结构体的整体大小必须为实际对齐单位的整数倍。

	设struct {
		char a,
		int b,
		char c,
		int d
	}
	windows默认字节对齐是8
	a：自身对齐值是1，指定对齐值是8，1 < 8，所以有效对齐值是1；地址0x0001是1的整数倍，所以占一个字节
	b：自身对齐值是4，指定对其置是8，4 < 8，所以有效对其置是4；地址0x0002不是4的整数倍，0x0004是整数倍，0x002-0x003自动进行字节填充，所以b存在0x0004-7的位置，占4字节
	c：同上在0x0008位置，占1字节
	d：同上在0x0009位置，占1字节
	由于结构体的整体大小是最大成员所占字节的整数倍，4的整数倍，当前是9，所以需要在9之后填充3个字节至0x0012，所以sizeof == 12
*/
// 类型定义
//#pragma pack(4)
typedef struct ByteAlignStruct {
	char a;
	int b;
	char c;
	char d;
} ST;

// 匿名struct；同时实例化struct = instance
struct {
	char a;
	int b;
	char c;
	char d;
} instance;

void byteAlign_main() {
	instance.a = '1';
	instance.b = 1;
	instance.c = '2';
	instance.d = '3';

	cout << sizeof(instance) << endl;
	cout << "instance: " << &instance << endl;
	cout << "instance.a: " << &instance.a << endl;
	cout << "instance.b: " << &instance.b << endl;
	cout << "instance.c: " << &instance.c << endl;
	cout << "instance.d: " << &instance.d << endl;
}