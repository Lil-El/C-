#include<iostream>

using namespace std;

void io_main() {
	int age;
	cout << "please input age: " << endl;
	cin >> age;
	cout << "age is : " << age << endl;

	// https://www.cnblogs.com/zwk-coder/articles/10988504.html
	int age1[4]{ 1, 2, 3 };
	char rec1[20]{ 'h', 'e', 'llo' }; // 字符数组 heo
	char rec2[20]{ 'h', 'i', 'k', '\0' }; // 字符数组-字符串
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
	// cin 无法输入空格、制表符、换行符;
	// getline通过换行符确定行尾，但不保存换行符
	cin.get(); // cin.ignore() 也可
	cin.getline(rec1, 70); // Tip: 不写上一行时，这行不会生效；因为上一行输入过回车，直接getline会读取回车直接结束，所以要先ignore或get或getline一次才可以
	cout << "rec1 is :" << rec1 << endl; // "hello world"

	// TODO: 80page get();
}