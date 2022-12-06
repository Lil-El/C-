#include <iostream>
#include <functional>
using namespace std;

void ref_add(int& a, int& b) {
	a += 1;
	b += 1;
}

// reference_wrapper原理是将，参数的引用的地址保存在reference_wrapper的指针里
class reference_wrapper1 {
public:
	int* a;
	reference_wrapper1(int& arg) {
		a = addressof(arg);
	}
};

/*
* ref/reference_wrapper 将一个引用包装成一个可拷贝的，可分配的对象
* 标准容器无法存储引用，需要将引用进行包装
*/
void ref_main() {
	int a(1);
	reference_wrapper ra = ref(a);
	ra++; // 2

	int b{1};

	// bind参数是对值的拷贝，所以修改b不生效，传入引用时使用ref进行处理
	// thread中也一样
	function<void()> fn = bind(ref_add, ra, b);
	fn();
	cout << a << " " << b << endl;
}