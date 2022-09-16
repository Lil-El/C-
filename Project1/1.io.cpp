#include<iostream>
#include<fstream>

using namespace std;

void h_io_main() {

	// ****************output******************

	/*
		ofstream   创建、写入
		ifstream   读取
		fstream    创建、写入、读取
	*/
	ofstream outfile;
	ifstream infile;
	/*
		ios::app     所有写入都追加到末尾
		ios::ate     打开后定位到末尾
		ios::in      打开用于读取
		ios::out     打开用于写入
		ios::trunc   如果文件已经存在，则设置长度=0，清掉文件内容
	*/
	outfile.open("file.txt", ios::app | ios::out);

	char data[100];
	cout << "Enter word: ";
	//cin >> word;
	cin.getline(data, 100);

	cout << "u input word: " << data << endl;
	outfile << data << endl;
	outfile.close();

	// ****************input******************

	infile.open("file.txt");
	cout << "Reading from the file" << endl;
	// infile.getline(data, 100); 可以getline读取，也可以直接 >> 输入至data中
	infile >> data;
	while (strlen(data)) {
		cout << data << endl;
		infile >> data;
	}

	infile.close();

	// ****************rewrite******************

	fstream ffile;
	ffile.open("file.txt", ios::trunc | ios::out | ios::in);
	cout << "Rewrite the file" << endl;
	cin >> data;
	ffile << data;

	// ****************文件位置指针******************
	ffile.seekg(3, ios::end);
	char temp[] = "abc";
	ffile << temp;
	ffile >> data;
	cout << data;

	ffile.close();
}