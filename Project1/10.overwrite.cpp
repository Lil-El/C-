#include <iostream>
using namespace std;

/*
overload: ����
	- ��һ��class�У�������һ����������һ�����������������ͣ�

override: ����
	��override �ؼ��֣����Ա�����������������д�麯���Ĵ���
	��1����ͬ�ķ�Χ���ֱ�λ������������ࣩ��
	��2������������ͬ��
	��3��������ͬ��
	��4�����ຯ��������virtual �ؼ��֡�

overwrite: ��д
	��1�����������ĺ��������ĺ���ͬ�������ǲ�����ͬ����ʱ����������virtual�ؼ��֣�����ĺ����������ء�
	��2�����������ĺ��������ĺ���ͬ�������Ҳ���Ҳ��ͬ�����ǻ��ຯ��û��virtual�ؼ��֡���ʱ������ĺ��������أ�ע����븲�ǻ���)
*/

class lo_A {
	// overload����
	void fn(int a) {}
	void fn(int a, int b) {}
	// override����
	virtual void fnR(int a) {}
	// overwrite��д
	void fnW() {}
};

class lo_B : public lo_A {
	void fnR(int a) override {}
	void fnW() {}
};

void learn_over_main() {

}