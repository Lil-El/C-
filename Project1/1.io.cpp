#include<iostream>
#include<fstream>

using namespace std;

void h_io_main() {
	/*
		ofstream   创建、写入
		ifstream   读取
		fstream    创建、写入、读取
	*/
	ofstream outfile;
	/*
		ios::app     所有写入都追加到末尾
		ios::ate     打开后定位到末尾
		ios::in      打开用于读取
		ios::out     打开用于写入
		ios::trunc   如果文件已经存在，则设置长度=0，清掉文件内容
	*/
	outfile.open("file.txt", ios::app | ios::out);

	char word[100];
	cout << "Enter word: " << endl;

	//cin >> word;
	cin.getline(word, 100);

	cout << "word: " << word << endl;
	outfile << word;

	outfile.close();
}