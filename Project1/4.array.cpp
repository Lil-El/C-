#include <iostream>
#include <iomanip>
using namespace std;

// �������������
// �β�����arr�˻�Ϊָ�룬����arr�޷�ͨ��sizeof�����ȡ��arr����
int getLastItem(int arr[], int size) {
	int idx = size - 1;
	return arr[idx];
}
// �������������
int getLastItem2(int *arr, int idx) {
	return *(arr + idx);
}
// ������������
int *genArray() {
	int arr[]{ 1, 2, 3, 4, 5 };
	return arr;
}

void array_main() {
	// ���������������Ԫ�صĵ�ַ
	double ages[2][3] = { {1, 2, 3}, {4, 5, 6000} };
	// setw���ú���ĳ���; Endǰ��7���ո�
	cout << "Element" << setw(10) << "End" << endl;
	cout << setw(7) << ages[0][0] << setw(10) << ages[0][2] << endl;
	cout << setw(7) << ages[1][0] << setw(10) << ages[1][2] << endl;
	cout << "ages first element address: " << ages << endl;

	int *arr = genArray();
	int nums[]{ 1,2,3,4,5 };
	//sizeof �� 20��5��Ԫ�أ�һ����4�ֽ�
	cout << "size of nums: " << size(nums) << endl;

	int last = getLastItem(nums, size(nums));
	cout << "1. last one: " << last << endl;
	int last2 = getLastItem2(nums, (sizeof(nums) / sizeof(nums[0])) - 1);
	cout << "2. last2 one: " << last2 << endl;
}