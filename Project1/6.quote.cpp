#include<iostream>
using namespace std;

// ��������
void set100(int &a) {
	a = 100;
}

// ��������ֵ
int &getQuote() {
	static int a = 99;
	int &aa = a;
	return aa;
}

void quote_main() {
	int a = 1;
	int &qa = a;
	qa = 2;
	a = 3;
	cout << (a == qa) << endl;

	set100(a);
	cout << a << endl;

	getQuote() = 993;
	cout << getQuote() << endl;
}