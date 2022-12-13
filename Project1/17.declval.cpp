#include <iostream>
#include <utility>
using namespace std;

/*
* decltype����ʾ���ʽ������
* declval�����decltype����
* 
* std::declval��c++11�±�׼�г��ֵĺ���ģ�壬û�к����壨ֻ��������û��ʵ�֣����޷������ã�
	һ��������decltype��sizeof�ȹؼ�����������������Ƶ���ռ���ڴ�ռ����ȡ�

template<class _Ty>
add_rvalue_reference_t<_Ty> declval() noexcept;
// add_rvalue_reference_t��ȡ_Ty����ֵ����
*/


struct Default { int foo() const { return 1; } };

struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

void declval_main() {
	int a = 10;
	decltype(a) b = 11;
	
	decltype(Default().foo()) n1 = 1;                   // n1 �������� int
//  decltype(NonDefault().foo()) n2 = n1;               // ������Ĭ�Ϲ��캯������Ϊ˽��ʱ���ǲ���ͨ������һ������ȥ���ú�����
														// ��ʱ��Ҫ declval ��ת��һ���������ͣ�Ȼ��������Ա������
	decltype(declval<NonDefault>().foo()) n2 = n1;      // n2 �������� int

	/*Default d();
	using boost::typeindex::type_id_with_cvr;
	cout << "�ķ�������=" << type_id_with_cvr<decltype(d.foo())>().pretty_name() << endl;*/
}