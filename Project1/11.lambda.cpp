#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
* ����������Ҳ��ΪLambda���ʽ��Lambda����
* �ܱ�ݣ��������п��ܻ�ʹ�á�ѭ��չ����������ִ�й���
* 
* []: �ⲿ����
* (): ������û�п���ʡ��
* ->return-type: ����ֵ���ͣ�Ĭ���� ->void ��Ҳ����ʡ��
* {}: ������
* 
* Lambdaʹ���ⲿ�ı�������Щ�����ļ��Ͻ����հ����հ�������[]֮��
* []: ���б�������ʹ�ã�����ȫ�ֱ���
* [=]: ���б�������
* [&]: ���б�������
* [=, &a]: ��ȡ���б���������a������
* [x, &y]: ��ȡx������y������
* [x]: ��ȡx�Ŀ���
* [this]: ��ȡclass�е�thisָ��
*/

// ������Ϊ������1. ʹ�ú���ָ�� 2. typename Lambda 3. function
template<typename T>
void lambda_fn1(const T& fn) {
	fn();
}

// function<int(void)> ��ʾ��������ֵint��������void
void lambda_fn2(const function<void()> &fn) {
	fn();
}

void lambda_main() {
	auto func = []() -> void {
		cout << "lambda." << endl;
	};
	func();

	// for_each
	// for_if

	function<int(int, int)> func1 = [](int a, int b) ->int { return a + b; };
	cout << func1(1, 2) << endl;

	// labmda������һ��const������ʹ��mutableȡ���䳣���ԡ�ʹ��mutableʱ����������()����ʹΪ��Ҳ����ʡ��
	int x = 0;
	int y = 9;
	[&x, y](int a) mutable {
		x = ++y + a;
	}(1);
	cout << x << endl;

	// exception
	[]() noexcept {
		throw 1;
	};

	auto fn = []() -> void {
		cout << "lambda_fn1" << endl;
	};
	lambda_fn1(fn);
	lambda_fn2(fn);
}