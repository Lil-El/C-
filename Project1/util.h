#pragma once

#ifndef  A
#define  A

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

void logN(int num);
const static char global_str[20] = "Hello World";

#endif