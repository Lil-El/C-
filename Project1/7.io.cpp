#include<iostream>

using namespace std;

void io_main() {
	int age;
	cout << "please input age: " << endl;
	cin >> age;
	cout << "age is : " << age << endl;

	char rec1[20]{ 'h', 'e', 'llo' }; // �ַ����� heo
	cout << "rewrite rec1 no space: " << endl;
	cin >> rec1;
	cout << "rec1 is :" << rec1 << endl; // "hello"

	cout << "rewrite rec1 with space: " << endl;
	// cin �޷�����ո��Ʊ�������з�;
	// getlineͨ�����з�ȷ����β���������滻�з�
	cin.get(); // cin.ignore() Ҳ��
	cin.getline(rec1, 70); // Tip: ��д��һ��ʱ�����в�����Ч����Ϊ��һ��������س���ֱ��getline���ȡ�س�ֱ�ӽ���������Ҫ��ignore��get��getlineһ�βſ���
	cout << "rec1 is :" << rec1 << endl; // "hello world"

}