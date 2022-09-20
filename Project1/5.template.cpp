#include<iostream>
using namespace std;

// 函数模板
template <typename T>
T h_5_tmp(T a, T b) {
	return a + b;
}

// 类模板
template <class T>
class h_5_tmp_cls {
	T name;
public:
	h_5_tmp_cls() {}
	h_5_tmp_cls(T init) {
		name = init;
	}
	void setName(T n) {
		name = n;
	}
	T getName() {
		return name;
	}
};

void tmp_main() {
	int result = h_5_tmp<int>(1, 1);
	cout << result << endl;
	int result2 = h_5_tmp(1, 1);
	cout << result2 << endl;

	h_5_tmp_cls<int> ins;
	ins.setName(1);
	cout << ins.getName() << endl;

	h_5_tmp_cls<const char *> inst("mino");
	//inst.setName(1); // Error
	inst.setName("Mino");
}