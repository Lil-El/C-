#include<iostream>
using namespace std;

/*
* union������������͵ĳ��ȡ�
* ����ͬһ���ڴ�ռ䣬���໥����
* 
* 
*   1. ����ȡ���(���ܴ����ڴ油��). �ҳ�Ա��ʼ��ַ��һ��
	2. ������һ����Ա����ֵʱ, ������Ա��ֵ�ᱻ����.
	3. union����������Ϊ���������ͷ���ֵ, ����ָ��union������ָ�����
	4. union�в��ܺ�����/����/��������/��ֵ�����/�麯��

	����union����Ķ��������ڴ棬���Բ��ܶ��徲̬���������͵ı�����
	������union��Ҳ�������Ŵ��й��캯�������������͸��ƹ��캯���ȵ���Ķ��󣬵��ǿ��Դ�Ŷ�Ӧ�������ָ�롣
	�������޷���֤��Ĺ��캯�������������õ���ȷ�ĵ��ã��ɴˣ��Ϳ��ܳ����ڴ�й©��
*/

class union_class {
public:
	int age = 9;
	union_class() {}
};

union my_union {
	int age;
	char c;
	float af;
	//union_class ua; union����ʹ��ӵ�й��졢�����Ⱥ�������
	union_class* ua;
};

void union_main() {
	my_union u1;
	u1.age = 100; // u1.c = 'd'; // a97 b98 c99 d100
	cout << "value is: " << u1.age << " " << u1.c << endl;

	// �ڴ��ַ����һ����
	cout << "address is: " << &u1.age << " " << addressof(u1.ua) << endl;

	cout << "size is: " << sizeof(u1) << endl;
}