#include<iostream>
using namespace std;

/*
* ָ�����ң�
* ����ָ��ָ��ͬһ���ڴ棬�������һ��ָ��ɾ�����ڴ棬��ʱ����γ��ˡ�ָ�����ҡ���
* ʹ�ÿ������캯��ʱ����Ҫ���ǳ������
*/

class point_hug {
	int* age;
public:
	point_hug() {
		age = new int(993);
	}
	point_hug(const point_hug &p) {
		age = p.age; // ǳ����
	}
	~point_hug() {
		delete age;
	}
};

void point_hug_main() {
	point_hug p;
	point_hug p1(p);
	cout << "���������age�ᱻɾ�����Σ��γ�ָ�����ң����������" << endl;
}
