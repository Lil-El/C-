#include<iostream>
#include<map>
#include<string>
using namespace std;

// ��ǰ��ʼ����
template<typename T, typename P>
void stl_map_iterator_front(map<T, P> &m) {
	cout << "*****stl_map_iterator_front begin****" << endl;
	// ��Ϊ����map<T, P>ʱ��ʹ����ģ���ж���Ĳ�������
	// �������޷�֪��iterator�������� ���ͻ��Ǿ�̬�ֶΣ�������Ҫ��֮ǰ����typename
	typename map<T, P>::iterator it = m.begin();
	typename map<T, P>::iterator end = m.end();
	while (it != end) {
		cout << it->first << ": " << it->second << endl;
		it++;
	}
	cout << "*****end****" << endl << endl;
};

// �������
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

// ����: �����������Ϊconst����ô����iteratorʱҪʹ��const_iterator��̬�ֶ�
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
	// ��ʼ��
	map<string, int> a;
	// ��ֵ: Ĭ�ϻ����Key������������sort����
	a["B"] = 1;
	a.insert(pair<string, int>("D", 1));
	a.insert(pair<string, int>("D", 2));
	a.insert(pair<string, int>("A", 1));
	a.insert(map<string, int>::value_type("C", 1));
	stl_map_iterator_back(a);

	a["dd"] = 10;
	stl_map_find(a, static_cast<string>("D")); // ����ת����(string)"D"
	stl_map_iterator_front(a);
	a.erase("dd");
	stl_map_iterator_front(a);

	cout << "a is empty? " << boolalpha << a.empty() << endl;
	a.clear();
	stl_map_iterator_front(a);
}
