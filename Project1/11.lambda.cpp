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
}