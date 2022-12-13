#include <iostream>
using namespace std;

/*
* SFINAE��ʾ�滻ʧ�ܲ��Ǵ���( Substitution Failure Is Not An Error)���򵥵�˵���滻���ǳ������ṩ�����ͻ�ֵ�滻ģ������Ļ��ơ�
* ��ĳЩ����£�����滻������Ч���룬��������Ӧ���׳��������󣬶�Ӧ�ü��������������õ����ء�
* SFINAE����ֻ��Ϊ����ȫ���ı�������֤���֡���ȫ������Ϊ��
* 
* C++ģ���ṩ��һ��SFINAE��subsitate failure is not an error���Ļ��ƣ�ģ��ƥ��ʧ�ܲ��Ǵ��󣩣�
* ����ģ������һ���ǳ�����˼�����ԣ�
* ����������ƿ��Լ��һ���ṹ���Ƿ����ĳ����Ա�Ȳ�����
*/

/*
* ���T��һ��int���ͣ���ô����ֵ��bool���͡��������int�Ļ�����ƥ�䲻���Ҹ�ʵ����
* ʹ��enable_if�ĺô��ǿ��ƺ���ֻ����ĳЩ���͵�(value==true)�Ĳ�����������뱨��
*/
template <class T>
typename enable_if<is_integral<T>::value, bool>::type is_odd(T i) { return bool(i % 2); }

/*
* ��� T û�� foo, ��û�� sfinae ��ʱ��, �ͻ�ֱ�ӱ������, ��Ϊչ���Ľ�����Ϸ�, 
* ������Ϊ������ sfinae ��һ��չ�����ֲ��Ϸ��˲������̱������, ���ǻ᳢�Ա������չ��.
*/
template <typename T>
void sfinae_foo(typename T::foo) {}

template <typename T>
void sfinae_foo(T) {}

void sfinae_main() {
	cout << "is_odd: " << is_odd(2) << endl;
//https://www.modb.pro/db/150467
}