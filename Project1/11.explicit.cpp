#include <iostream>
using namespace std;

/*
	explicit�ؼ���ֻ����������ֻ��һ���������๹�캯��, ���������Ǳ����ù��캯������ʾ��, ������ʽ��, 
	�������Ӧ����һ���ؼ�����implicit, ��˼�����ص�,�๹�캯��Ĭ������¼�����Ϊimplicit(��ʽ).
*/

class know_explicit_class {
public:
	int age;
	explicit know_explicit_class(int a) {
		age = a;
	}
};

void know_explicit_main() {
	know_explicit_class k1(10);
	cout << k1.age << endl;
	// �๹�캯������ʽ�Զ�ת������ʹ��explicit�����������ģ�ʹ���˾ͻ���ʾ����
	/*know_explicit_class k2 = 10;
	cout << k2.age << endl;*/
}
