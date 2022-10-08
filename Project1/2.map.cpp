#include<iostream>
#include<map>
#include<string>
using namespace std;

// 从前开始遍历
template<typename T, typename P>
void stl_map_iterator_front(map<T, P> &m) {
	cout << "*****stl_map_iterator_front begin****" << endl;
	// 因为定义map<T, P>时，使用了模板中定义的参数名称
	// 编译器无法知道iterator的类型是 类型还是静态字段；所以需要在之前加上typename
	typename map<T, P>::iterator it = m.begin();
	typename map<T, P>::iterator end = m.end();
	while (it != end) {
		cout << it->first << ": " << it->second << endl;
		it++;
	}
	cout << "*****end****" << endl << endl;
};

// 反向遍历
template<typename T, typename P>
void stl_map_iterator_back(map<T, P> &m) {
	cout << "*****stl_map_iterator_back begin****" << endl;
	typename map<T, P>::reverse_iterator it = m.rbegin();
	typename map<T, P>::reverse_iterator end = m.rend();
	while (it != end) {
		cout << it->first << ": " << it->second << endl;
		it++;
	}
	cout << "*****end****" << endl << endl;
};

// 查找: 如果参数设置为const，那么定义iterator时要使用const_iterator静态字段
template<typename T, typename P>
void stl_map_find(const map<T, P> &m, const T key) {
	cout << "*****stl_map_find begin****" << endl;
	typename map<T, P>::const_iterator it = m.find(key);
	typename map<T, P>::const_iterator end = m.end();
	if (it == end) {
		cout << "Not found!" << endl;
	}
	else {
		cout << it->first << ": " << it->second << endl;
	}
	cout << "*****end****" << endl << endl;
};

void stl_map_main() {
	// 初始化
	map<string, int> a;
	// 插值: 默认会根据Key升序排序，所以sort无用
	a["B"] = 1;
	a.insert(pair<string, int>("D", 1));
	a.insert(pair<string, int>("D", 2));
	a.insert(pair<string, int>("A", 1));
	a.insert(map<string, int>::value_type("C", 1));
	stl_map_iterator_back(a);

	a["dd"] = 10;
	stl_map_find(a, static_cast<string>("D")); // 类型转换：(string)"D"
	stl_map_iterator_front(a);
	a.erase("dd");
	stl_map_iterator_front(a);

	cout << "a is empty? " << boolalpha << a.empty() << endl;
	a.clear();
	stl_map_iterator_front(a);
}
