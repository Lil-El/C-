#pragma once

#ifndef  My_Util
#define  My_Util

#include <iostream>
using namespace std;
// classͨ��������h�ļ��У���Ϊ�������޷�֪����ҪΪclass��������ڴ�

class Shape {
private:
	int width;
	int height;

public:
	Shape(int w, int h) {
		width = w;
		height = h;
	}
	// class�ĳ�Ա�������Զ��������ڲ�������ͨ��"��Χ���������::"���ⲿȥ�����Ա������
	// 1. ʹ���ڲ���������ν��������������
	// 2. ��ͷ�ļ���ͨ��::����ʱ�����ظ�����ͷ�ļ�ʱ�ᱻ��ʾ�ظ����壻����Ҫ��cpp�ļ���ȥ�����Ա����
	int getArea(); 
};

extern int age0; // ����һ��ȫ�ֱ���

// �����ļ������age0��logAge����������ȷ��age0
//void logAge() {
//	cout << age0 << endl;
//};
void logN(int num);

//int agex = 1; // ���ֻ��һ��cpp�ļ������˴�ͷ�ļ����򲻱��������ض���

// cosnt��static���εĲ�Ӱ��
static int age; 
const int age2 = 100;
const static char global_str[20] = "Hello World";

#endif // !My_Util