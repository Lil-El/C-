#include <iostream>
using namespace std;

/*
* �����ڼ��̣�
* 
* SFINAE��ʾ�滻ʧ�ܲ��Ǵ���( Substitution Failure Is Not An Error)���򵥵�˵���滻���ǳ������ṩ�����ͻ�ֵ�滻ģ������Ļ��ơ�
* ��ĳЩ����£�����滻������Ч���룬��������Ӧ���׳��������󣬶�Ӧ�ü��������������õ����ء�
* SFINAE����ֻ��Ϊ����ȫ���ı�������֤���֡���ȫ������Ϊ��
* 
* C++ģ���ṩ��һ��SFINAE��subsitate failure is not an error���Ļ��ƣ�ģ��ƥ��ʧ�ܲ��Ǵ��󣩣�
* ��һ��ģ��*չ��*ʧ�ܵ�ʱ��, �᳢�������������ؽ���չ��, ������ֱ�ӱ���,
*	  ������������ enable_if �� void_t��ǩ�ַ�.
*	  if constexp Ϊ���ǵ����ִ��������˸���Ŀɶ���
*/

/*
* ���T��һ��int���ͣ���ô����ֵ��bool���͡��������int�Ļ�����ƥ�䲻���Ҹ�ʵ����
* ʹ��enable_if�ĺô��ǿ��ƺ���ֻ����ĳЩ���͵�(value==true)�Ĳ�����������뱨��
*/
template <class T>
typename enable_if<is_integral<T>::value, bool>::type is_odd(T i) { 
	cout << "����ƥ��" << endl;
	return bool(i % 2); 
}

template <class...T>
typename bool is_odd(...) {
	cout << "������ƥ��" << endl;
	return false;
}

//////////////////////////////////////////////////////////////////
/*
* void_t�ַ�������һ��void��û���á���Ҫ����������void_t����T�ĺϷ���
*/
struct hasType {
	using intType = int;
	void fun() {}
};

struct noType {
	void fun() {}
};

// T�Ǳ���ģ�ͨ��T���ж��Ƿ������Ա������UĬ�ϸ�void
template <typename T, typename U = std::void_t<> > // ������ > ֮��Ҫ�пո�
struct hasTypeMem : std::false_type {};

// ��ƫ�ػ��е�void_t�Ĳ����б��н�������
template <typename T>
struct hasTypeMem<T, std::void_t<typename T::intType> > : std::true_type {};

//////////////////////////////////////////////////////////////////

template<>
void sfinae_str () {
	if constexpr (true) {
		cout << "sfinae_str 1" << endl;
	} else {
		cout << "sfinae_str 0" << endl;
	}
};

//////////////////////////////////////////////////////////////////

template<typename T>
struct hasHello : true_type {};

//template<typename T>
//struct hasHello<T, enable_if<true, bool>::type> : false_type {};

void sfinae_main() {
	cout << "is_odd: " << is_odd(1) << endl;
	cout << "is_odd: " << is_odd("sdf") << endl;

	cout << hasTypeMem<hasType>::value << endl;
	cout << hasTypeMem<noType>::value << endl;

	sfinae_str();
}