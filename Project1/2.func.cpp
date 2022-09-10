#include <iostream>
using namespace std;

// 创建引用 &a = num1; 结果：a = 2
void my_swap2(int &a, int &b) {
	cout << "a address: " << &a << endl;
	int temp = a;
	a = b;
	b = temp;
}
// 函数声明并定义
// 传递指针参数; 创建指针a = &num1; 结果：a=地址, *a=100
void my_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

// C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
int *genArr() {
	static int newArr[5];
	for (int i = 0; i < 5; i++) {
		newArr[i] = i + 3;
	}
	return newArr;
}

void start_func() {
	int num1 = 100;
	int num2 = 2;
	cout << "num1 address: " << &num1 << endl;

	//定义指针
	int *p1 = &num1; // p1是num1的地址；*p1 === 100
	int *p2 = &num2;
	// C++17内置了swap函数
	my_swap(p1, p2);
	cout << "num1: " << num1 << endl; // 2
	cout << "num2: " << num2 << endl; // 100

	int &r1 = num1;
	int &r2 = num2;
	my_swap2(r1, r2);
	cout << "num1: " << num1 << endl; // 100
	cout << "num2: " << num2 << endl; // 2

	int *arr = genArr();
	cout << "arr: " << *(arr + 0) << endl;
	cout << "arr: " << arr[1] << endl;
}
