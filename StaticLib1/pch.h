#pragma once

/*
	pch��ʾԤ����ͷ�ļ�Pre-compiled Header��
	���ڱȽϴ��͵Ĺ��̣���������ʱ���ܾã�ͨ��ʹ��PCH������Щ�����������Ķ���ͷ�ļ���Ԥ�ȱ���������Ϳ��Դ���ʡʵ��ʹ��ʱ��ı���ʱ��
	Ӧ�ڴ˴������κ��ȶ��ı�ͷ�ļ��������׼���ͷ���� <vector>��
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
