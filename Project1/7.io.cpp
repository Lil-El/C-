#include<iostream>

using namespace std;

void io_main() {
	int age;
	cout << "please input age: " << endl;
	cin >> age;
	cout << "age is : " << age << endl;

	char rec1[20]{ 'h', 'e', 'llo' }; // 字符数组 heo
	cout << "rewrite rec1 no space: " << endl;
	cin >> rec1;
	cout << "rec1 is :" << rec1 << endl; // "hello"

	cout << "rewrite rec1 with space: " << endl;
	// cin 无法输入空格、制表符、换行符;
	// getline通过换行符确定行尾，但不保存换行符
	cin.get(); // cin.ignore() 也可
	cin.getline(rec1, 70); // Tip: 不写上一行时，这行不会生效；因为上一行输入过回车，直接getline会读取回车直接结束，所以要先ignore或get或getline一次才可以
	cout << "rec1 is :" << rec1 << endl; // "hello world"

}