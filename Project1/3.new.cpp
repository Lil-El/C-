#include<iostream>
using namespace std;

/*
ջ���ں����ڲ����������б�������ռ��ջ�ڴ档
�ѣ����ǳ�����δʹ�õ��ڴ棬�ڳ�������ʱ�����ڶ�̬�����ڴ档
*/

class h_new_Obj {
public:
	h_new_Obj() {
		cout << "constructor" << endl;
	}
	~h_new_Obj() {
		cout << "xg" << endl;
	}
};

void new_main() {
	int *p = nullptr; // NULL
	p = new(int); // new int;
	*p = 99324;
	cout << *p << endl;
	delete p;

	// ��ά����
	int **ip = new int *[2];
	ip[0] = new int[3];
	ip[1] = new int[3];
	delete[]ip[0];
	delete[]ip[1];
	delete[]ip;

	// ���鶯̬�ڴ����
	char *cp = NULL;
	cp = new char[20];
	delete[]cp;

	// ����
	h_new_Obj *op = new h_new_Obj;
	delete op;

	h_new_Obj *arr = new h_new_Obj[4];
	delete[]arr;
}