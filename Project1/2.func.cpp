#include <iostream>
#include <iomanip>
using namespace std;

// ��������
int calc(int a = 0, int b = 0);
void my_swap2(int &a, int &b);
// ��������������
// ����ָ�����; ����ָ��a = &num1; �����a=��ַ, *a=100
void my_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int getLastItem(int arr[], int size) {
	int idx = size - 1;
	return arr[idx];
}
int getLastItem2(int *arr, int idx) {
	return *(arr + idx);
}

// C++ ��֧���ں����ⷵ�ؾֲ������ĵ�ַ�����Ƕ���ֲ�����Ϊ static ����
int *genArr() {
	static int newArr[5];
	for (int i = 0; i < 5; i++) {
		newArr[i] = i + 3;
	}
	return newArr;
}

void start_func() {
	int result = calc();
	cout << "result: " << result << endl;

	int num1 = 100;
	int num2 = 2;
	cout << "num1 address: " << &num1 << endl;
	cout << "num2 address: " << &num2 << endl;
	//����ָ��
	int *p1 = &num1; // p1��num1�ĵ�ַ��*p1 === 100
	int *p2 = &num2;
	// C++17������swap����
	my_swap(p1, p2);
	cout << "num1: " << num1 << endl; // 2
	cout << "num2: " << num2 << endl; // 100

	int &r1 = num1;
	int &r2 = num2;
	my_swap2(r1, r2);
	cout << "num1: " << num1 << endl; // 100
	cout << "num2: " << num2 << endl; // 2

	// ���������������Ԫ�صĵ�ַ
	double ages[2][3] = { {1, 2, 3}, {4, 5, 6000} };
	// setw���ú���ĳ���; Endǰ��7���ո�
	cout << "Element" << setw(10) << "End" << endl;
	cout << setw(7) << ages[0][0] << setw(10) << ages[0][2] << endl;
	cout << setw(7) << ages[1][0] << setw(10) << ages[1][2] << endl;
	cout << "ages first element address: " << ages << endl;

	int nums[] = { 1, 2, 3, 4, 5 };
	// sizeof �� 20��5��Ԫ�أ�һ����4�ֽ�
	cout << "size of nums: " << size(nums) << endl;
	for (int i = 0; i < size(nums); i++) {
		cout << *(nums + i) << endl;
	}

	int last = getLastItem(nums, size(nums));
	cout << "1. last one: " << last << endl;
	int last2 = getLastItem2(nums, (sizeof(nums) / sizeof(nums[0])) - 1);
	cout << "2. last2 one: " << last2 << endl;

	int *arr = genArr();
	cout << "arr: " << *(arr + 0) << endl;
	cout << "arr: " << arr[1] << endl;
	cout << "arr: " << arr[2] << endl;
	cout << "arr: " << arr[3] << endl;

}

// ��������
int calc(int a, int b) {
	return a + b;
}

// �������� &a = num1; �����a = 2
void my_swap2(int &a, int &b) {
	cout << "a address: " << &a << endl;
	int temp = a;
	a = b;
	b = temp;
}