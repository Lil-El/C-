#include<iostream>

using namespace std;

void io_main() {
	int age;
	cout << "please input age: " << endl;
	cin >> age;
	cout << "age is : " << age << endl;

	// https://www.cnblogs.com/zwk-coder/articles/10988504.html
	int age1[4]{ 1, 2, 3 };
	char rec1[20]{ 'h', 'e', 'llo' }; // �ַ����� heo
	char rec2[20]{ 'h', 'i', 'k', '\0' }; // �ַ�����-�ַ���
	char rec3[40];
	cout << "age1 is :" << age1 << endl;
	cout << "rec1 is :" << rec1 << endl;
	cout << "rec2 is :" << rec2 << endl;

	cout << "rec1 length: " << strlen(rec1) << endl;
	strcpy_s(rec2, rec1);
	cout << "rec1 is :" << rec1 << endl; // heo
	cout << "rec2 is :" << rec2 << endl; // heo

	strcat_s(rec1, rec2);
	cout << "rec1 is :" << rec1 << endl; // heoheo
	cout << "rec2 is :" << rec2 << endl; // heo

	cout << "rewrite rec1 no space: " << endl;
	cin >> rec1;
	cout << "rec1 is :" << rec1 << endl; // "hello"

	cout << "rewrite rec1 with space: " << endl;
	// cin �޷�����ո��Ʊ�������з�;
	// getlineͨ�����з�ȷ����β���������滻�з�
	cin.get(); // cin.ignore() Ҳ��
	cin.getline(rec1, 70); // Tip: ��д��һ��ʱ�����в�����Ч����Ϊ��һ��������س���ֱ��getline���ȡ�س�ֱ�ӽ���������Ҫ��ignore��get��getlineһ�βſ���
	cout << "rec1 is :" << rec1 << endl; // "hello world"

	// TODO: 80page get();
}