#include <iostream>
#include <locale>
using namespace std;

void dataType_main() {

	// ��������
	bool isOk = false; // 1�ֽ�
	int age = 25; // 4�ֽ� ʹ��=����
	int age1(25); // ʹ��()����
	int age1_1{ 25 }; // ʹ��{}����
	int num11[]{ 1997, 11 }; // C++11���ԣ�����ʡ��=��
	float size = 13.3; // 4�ֽ�
	double peopel = 14.44; // 8�ֽ�
	__int8 i8 = 12;
	cout << i8 << endl; // TODO: 

	// ''���������ַ���""˫�������ַ���
	char str[] = "ABB";
	char rec[9] = "hello";

	// ���������ַ����飬ֻ�еڶ������ַ���; �ڲ���������ʱ���Կ������ߵ�����string.cpp��
	char rec1[9]{ 'h', 'i', 'k' }; // �ַ�����
	char rec2[9]{ 'h', 'i', 'k', '\0' }; // �ַ�����-�ַ���
	wchar_t wc = L'��'; // _T() ͬ���� L (string.cpp)  ���������ַ�
	setlocale(LC_ALL, "chs");

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
	unsigned long long ll_age = 10;
	signed long int sli_age = 10; // 8
	float f_age = (float)age; // ǿ������ת��
	float f_age1 = float(age); // ǿ������ת�� C11: Ϊ������һ��

	cout << "sizeof ll_age is:" << sizeof(ll_age) << endl;

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

	return ;
}