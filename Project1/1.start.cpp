#include <iostream>
using namespace std;

int start_main() {

	// ��������
	bool isOk = false; // 1�ֽ�
	int age = 25; // 4�ֽ�
	char str[] = "A";
	float size = 13.3; // 4�ֽ�
	double peopel = 14.44; // 8�ֽ�
	// void 
	// wchar_t
	// ö��
	enum OBJ {
		name,
		age2 = 100,
		sex
	} obj;
	
	// ���η�
	unsigned int us_age = 10; // �޷���4�ֽ�
	signed int si_age = 10; // �з���4�ֽ�
	short int s_age = 10; // 2�ֽ�
	long int l_age = 10; // 8�ֽ�
	signed long int sli_age = 10; // 8

	cout << "sizeof age is:" << sizeof(age) << endl;

	obj = name;
	cout << obj << endl;
	OBJ obj2 = age2;
	cout << obj2 << endl;
	cout << name << age2 << sex << endl;

	typedef OBJ myEnum;
	myEnum my_enum = sex;
	cout << "my_enum:" << my_enum << endl;

	// ���� static�洢��
	age = 22;
	const static int myAge = 18; // static�������������ֱ�ӹ���һ��ֵ������class��Աʱ������class���󶼹���һ������

	return 0;
}