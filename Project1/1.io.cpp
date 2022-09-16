#include<iostream>
#include<fstream>

using namespace std;

void h_io_main() {

	// ****************output******************

	/*
		ofstream   ������д��
		ifstream   ��ȡ
		fstream    ������д�롢��ȡ
	*/
	ofstream outfile;
	ifstream infile;
	/*
		ios::app     ����д�붼׷�ӵ�ĩβ
		ios::ate     �򿪺�λ��ĩβ
		ios::in      �����ڶ�ȡ
		ios::out     ������д��
		ios::trunc   ����ļ��Ѿ����ڣ������ó���=0������ļ�����
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
	// infile.getline(data, 100); ����getline��ȡ��Ҳ����ֱ�� >> ������data��
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

	// ****************�ļ�λ��ָ��******************
	ffile.seekg(3, ios::end);
	char temp[] = "abc";
	ffile << temp;
	ffile >> data;
	cout << data;

	ffile.close();
}