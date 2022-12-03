#include <iostream>
#include <utility>
#include <map>
using namespace std;


struct Atext {
	using type = int;
	using LValue = int&;
	using RValue = int&&;
};

// 参数x是拷贝的，地址不同
//void overloaded(int x) {
//	std::cout << "[value]" << &x << endl;
//}

// 左值、右值的x的地址一致
void overloaded(const int& x) { 
	std::cout << "[lvalue]" << &x << endl; 
}
void overloaded(int&& x) { 
	std::cout << "[rvalue]" << &x << endl;
}

/*
* swap
* make_pair
* move
* forward
*/
void utility_main()
{
	pair<int, int> p;
	p.first = 8;
	p.second = 9;

	pair<Atext::type, Atext::type> p1(1, 2);

	cout << p.first << " " << p.second << endl;
	cout << p1.first << " " << p1.second << endl;
	swap(p.first, p.second); // utility -> std::swap
	cout <<"*********************" << endl;
	cout << p.first << " " << p.second << endl;
	cout << p1.first << " " << p1.second << endl;
	cout << "*********************" << endl;
	p.swap(p1);
	cout << p.first << " " << p.second << endl;
	cout << p1.first << " " << p1.second << endl;
	cout << "*********************" << endl;
	map<int, int> m;
	m.insert(make_pair(1, 2));
	m.insert(map<int, int>::value_type(3, 4));
	map<int, int>::iterator it = m.begin();
	for (; it != m.end(); it++) {
		cout << it->first << endl;
		cout << it->second << endl;
	}
	cout << "*********************" << endl;
	p.first = 99;
	int x = move(p.first);
	cout << addressof(p.first) << ":" << addressof(x) << endl;
	cout << &p.first << ":" << &x << endl;
	cout << "*********************" << endl;
	overloaded(x); // 左值
	overloaded(forward<int>(x)); // 右值
}