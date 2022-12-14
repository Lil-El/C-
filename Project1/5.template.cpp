#include<iostream>
#include <vector>
using namespace std;

template<typename T>
using tmp_type = T;

// ����ģ��
template <typename T>
T h_5_tmp(T a, T b) {
	return a + b;
}

// ��ģ��
template <class T>
class h_5_tmp_cls {
	T name;
public:
	h_5_tmp_cls() {}
	h_5_tmp_cls(T init) {
		name = init;
	}
	void setName(T n) {
		name = n;
	}
	T getName() {
		return name;
	}
};

/*
* ģ���ػ���ģ�������ĳ���ض������µľ���ʵ��
*/
// ģ��ԭ��
template<typename T>
T tmp_fn1(T arg) {
	return arg;
}
// ģ��ȫ�ػ�
template<>
int tmp_fn1<int>(int arg) {
	return 1;
}
// �������أ�ʵ���˺���ģ���ػ��Ĺ��ܣ����⺯��ģ����ػ�ʧЧ
int tmp_fn1(int arg) {
	return 1;
}

/*
* ģ��ƫ�ػ���ָ������ģ���������ȫ��ģ�����������ָ��ģ������Ĳ������Էֶ���ȫ������
*/
// **************����**************
template<typename T, typename U>
void tmp_fn2(T arg1, U arg2) {}
// �Բ���ģ����������ػ�
template<typename T>
void tmp_fn2(int arg1, T arg2) {} // void tmp_fn2<int, T>(int arg1, T arg2) {} Error������Ƿ�ʹ����ʾ��������class������
// ��ģ������ػ�Ϊָ��(ģ������Ĳ�������)
template<typename T, typename U>
void tmp_fn2(T* arg1, U* arg2) {}
// ��ģ������ػ�Ϊ��һ��ģ����
template<typename T, typename U> 
void tmp_fn2(vector<T>& arg1, vector<T>& arg2) {}

// **************��**************
template<typename T, typename U>
class tmp_cls2 {};
// ��ģ��ƫ�ػ�
template<typename T>
class tmp_cls2<int, T> {};
// 
template<typename T, typename U>
class tmp_cls2<T*, U*> {};

/*
* �������ȼ��Ӹߵ��ͽ��������ǣ�ȫ�ػ���>ƫ�ػ���>���汾ģ����
*/

/********************Error**********************/

// C++ ������ͬ��������������ͬ�� templates ���ڣ�����template��������һ��
template<typename T>
struct tmp_str1{};
/*
* ��������̫��
  template<typename T, typename U>
  struct tmp_str1 {};
*/

/********************�����б�**********************/
template<typename... Args>
struct Sum;
//��������
template<typename First, typename... Rest>
struct Sum<First, Rest...> //���û�������ǰ���������ᱨ��'Sum' is not a class template
						   //��ģ��������в�����ʹ��ģ������б�C/C++(840)
{
	enum { value = Sum<First>::value + Sum<Rest...>::value };
};
//�ݹ���ֹ
template<typename Last>
struct Sum<Last>
{
	enum { value = sizeof(Last) };
};

void tmp_main() {
	int result = h_5_tmp<int>(1, 1);
	cout << result << endl;
	int result2 = h_5_tmp(1, 1);
	cout << result2 << endl;

	h_5_tmp_cls<int> ins;
	ins.setName(1);
	cout << ins.getName() << endl;

	h_5_tmp_cls<const char *> inst("mino");
	//inst.setName(1); // Error
	inst.setName("Mino");

	cout << "*********************************************" << endl;

	cout << tmp_fn1(1) << endl;
	cout << tmp_fn1("abc") << endl;

	Sum<int, char> s;
	cout << s.value << endl;
}