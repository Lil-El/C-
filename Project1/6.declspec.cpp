#include <iostream>
using namespace std;

/*
	��__declspec����Microsoft c++��ר�õĹؼ��֣��������һЩ���Կ��ԶԱ�׼C++�������䡣
	��Щ�����У�
	align���ֽڶ���
	allocate������#pragma ��code_seg�� const_seg, data_seg,section,init_seg���ʹ��
	deprecated�� �ѷ���
	dllexport��dll����
	dllimport�� dll����
	naked��
	noinline����ȥ��������
	noreturn���޷���ֵ
	nothrow�������״�
	novtable��
	selectany��
	thread��
	property
	uuid��
*/

__declspec(noreturn) void my_exit(int code) {
	exit(code);
}

// ������Ҫ����intֵ�������;�˳��ᱨ������Ϊmy_exit�������noreturn
int know_declspec_main() {
	cout << "Main" << endl;
	my_exit(0);
}