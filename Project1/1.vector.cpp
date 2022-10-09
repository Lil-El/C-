#include<iostream>
#include<vector>

using namespace std;
#define Mino_STL ::std::

void stl_vector_log(const vector<int> &v, const char *str = "vector") {
	cout << "*****begin: " << str << "*****" << endl;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << "vector " << i << ": " << v[i] << endl;
	}
	cout << "*****end: " << str << "*****" << endl << endl;
}

void stl_vector_main() {
	int t = NULL;
	Mino_STL vector<int> a{ 1, 2, 3 };
	std::vector<int> _b = { 1, 2, 3 };
	vector<int> _c = vector<int>(10);
	vector<int> _d(10); // 同上

	_b.clear();
	cout << boolalpha << _b.empty() << endl;
	stl_vector_log(_b, "clear _b");
	_b.push_back(1);
	stl_vector_log(_b, "push _b");
	_b.pop_back();
	stl_vector_log(_b, "pop _b");

	cout << "_c.capacity() return value is: " << _c.capacity() << endl; // vector的容量
	stl_vector_log(_c, "_c");

	stl_vector_log(a, "initial vector a");
	cout << "vector 'at 1' value is: " << a.at(1) << endl;
	cout << "a.back() return value is: " << a.back() << endl;
	// 重新分配size和val
	a.assign(3, 9);
	stl_vector_log(a, "after assign vector a");

}