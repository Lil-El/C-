#include <iostream>
using namespace std;

/*
	__attribute__��һ��������ָ���ʵ�� GNU C ��һ�ֻ��ƣ�������һ����������ָ��.
	��������ʱ������ṩһЩ���ԣ��ڱ���׶������ã������������Ĵ�����͸߼��Ż���

	��Linux�����¿���ʹ�á�

	���α��������������ͣ��ṹ�塢�����塢ö�ٵȣ�

	__attribute__֧�ֵ����ͣ�
		��������(Function Attribute)	��������(Type Attributes)	��������(Variable Attribute)	Clang���е�
		noreturn	                    aligned						alias							availability
		noinline						packed						at(address)						overloadable
		always_inline					bitband						aligned
		flatten														deprecated
		pure														noinline
		const														packed
		constructor													weak
		destructor													weakref(��target��)
		sentinel													section(��name��)
		format														unused
		format_arg													used
		section														visibility(��visibility_type��)
		used														zero_init
		unused
		deprecated
		weak
		malloc
		alias
		warn_unused_result
		nonnull

	noreturn��������Ը��߱������������᷵�أ�������������ƹ���δ�ﵽ����·���Ĵ��� C�⺯��abort������exit������ʹ�ô���������
	aligned�������ֽڶ���
	pure�����庯��Ϊ������
	const��������ֻ�����ڴ�����ֵ���Ͳ����ĺ����ϡ����ظ����ô�����ֵ�����ĺ���ʱ�����ڷ���ֵ����ͬ�ģ����Դ�ʱ���������Խ����Ż���������һ����Ҫ�����⣬����ֻ��Ҫ���ص�һ�εĽ���Ϳ����ˣ������������Ч�ʡ���������Ҫ������û�о�̬״̬(static state)�͸����õ�һЩ���������ҷ���ֵ������������Ĳ�����
	deprecated�����߱������Ѿ���ʱ
*/
// attribute��GNU C�ģ���MSVC����ʹ�� _declspec(align())

// ������Ҫ����intֵ�������;�˳��ᱨ������Ϊmy_exit�������noreturn
void know_attr_main() {
	return;
}