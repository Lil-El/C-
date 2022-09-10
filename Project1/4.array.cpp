#include <iostream>
#include <iomanip>
using namespace std;

int getLastItem(int arr[], int size) {
	int idx = size - 1;
	return arr[idx];
}
int getLastItem2(int *arr, int idx) {
	return *(arr + idx);
}

void array_main() {
	// 数组名是数组的首元素的地址
	double ages[2][3] = { {1, 2, 3}, {4, 5, 6000} };
	// setw设置后面的长度; End前有7个空格
	cout << "Element" << setw(10) << "End" << endl;
	cout << setw(7) << ages[0][0] << setw(10) << ages[0][2] << endl;
	cout << setw(7) << ages[1][0] << setw(10) << ages[1][2] << endl;
	cout << "ages first element address: " << ages << endl;

	int nums[] = { 1, 2, 3, 4, 5 };
	// sizeof 是 20；5个元素，一个是4字节
	cout << "size of nums: " << size(nums) << endl;
	for (int i = 0; i < size(nums); i++) {
		cout << *(nums + i) << endl;
	}
	int last = getLastItem(nums, size(nums));
	cout << "1. last one: " << last << endl;
	int last2 = getLastItem2(nums, (sizeof(nums) / sizeof(nums[0])) - 1);
	cout << "2. last2 one: " << last2 << endl;
}