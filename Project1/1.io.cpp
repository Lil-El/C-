#include<iostream>
#include<fstream>

using namespace std;

void h_io_main() {
	/*
		ofstream   ������д��
		ifstream   ��ȡ
		fstream    ������д�롢��ȡ
	*/
	ofstream outfile;
	/*
		ios::app     ����д�붼׷�ӵ�ĩβ
		ios::ate     �򿪺�λ��ĩβ
		ios::in      �����ڶ�ȡ
		ios::out     ������д��
		ios::trunc   ����ļ��Ѿ����ڣ������ó���=0������ļ�����
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