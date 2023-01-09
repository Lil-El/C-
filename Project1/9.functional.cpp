#include <iostream>
#include <functional>
using namespace std;

int functional_fn(int& a, int b, int c) {
	int result = a++ + b + c;
	cout << "functional bind." << result << endl;
	return result;
}

class functional_struct {
public:
	static void fn() {
		cout << "fn." << endl;
	}
};

struct functional_str {
	static void fn() {
		cout << "ff." << endl;
	}
};

void functional_main() {
	int a = 1;
	function<void()> fn = bind(functional_fn, ref(a), 2, 3);
	fn();
	cout << "a is: " << a << endl;

	function<void()> fn2 = []() {
		cout << "lambda." << endl;
	};
	fn2();

	// ±ØÐëÊÇ¾²Ì¬µÄ
	auto fn3 = bind(functional_struct::fn); // &functional_struct
	fn3();
}