#include <iostream>
using namespace std;

/*
* �����Զ��Ƶ�����Ӧ���ڱ�����������ģ���
*/

template<typename T>
auto auto_fn(int n, auto b) {
	auto a = T::get();
	cout << "T::get()��" << a << endl;
	if (n < 2) {
		return true;
	}
	return false;
}

struct auto_struct {
	static bool get() {
		cout << "get" << endl;
		return true;
	}
	//auto name = 1; error��struct�в�����ʹ��auto��Ϊ��Ա����
};

void auto_main() {
	//auto n1; error������ָ��ֵ
	//auto n1[100]; ��������Ϊ����

	auto num = 3; // auto - int
	//num = "sd"; error������ȷ���ˣ��������¸���Ϊ�������͵�ֵ
	auto p = new auto_struct; // auto - auto_struct*
	cout << boolalpha << auto_fn<auto_struct>(num, 1) << endl;

	for (auto i = 0; i < 3; i++) {

	}
}