#include <iostream>
using namespace std;

/*
���⣺
	���̳й�ϵ����ʱ��A����B��C��D�̳�B��C��
	class lve_A {
	public:
		int m_a;
		lve_A(int n) : m_a(n) {};
	};

	class lve_B : virtual public lve_A {
	public:
		int m_b;
		lve_B(int n) : m_b(n), lve_A(2) {};
	};

	class lve_C : virtual public lve_A {
	public:
		int m_c;
		lve_C(int n) : m_c(n), lve_A(2) {};
	};

	class lve_D: public lve_B, public lve_C {
	public:
		int m_d;
		lve_D(int n) : m_d(n), lve_B(3), lve_C(3) {};
	};
	��D��ʵ����ʹ��m_aʱ����������壬��������֪��ʹ��A-B-D��m_a����A-C-D��m_a
�����
	Ϊ�˽���������⣬ʹ����̳С�ΪB��C���virtual��
	- ��̳У���ĳ�����������������������Ļ��ࡣ�����ֻ����£����������a�ڼ̳���ϵ�г����˶��ٴΣ����������ж�ֻ����һ�������ĳ�Ա��
	- ����ͨ�ļ̳й�ϵ�У�������ֻ��ֱ�ӻ���Ĺ��캯������������̳й�ϵ�У�������d���Ե��ü�ӻ���a�Ĺ��캯����ԭ��Ҳ��Ϊ�˱�������ԣ���֪��Aʹ��B�Ļ���C�Ĺ��캯��
	- �ڼ̳й�ϵ�У����캯�����ǰ��մ��ϵ���˳����õģ���̳�ʱ����˳����á�
		A->B->D���̳еĵ���˳��ABD
	    A->BC->D��̳еĵ���˳���ǣ�
			��̳У�class D: public C, public B;     ����˳��A C A B D
			��̳У�class D: public B, public C;     ����˳��A B A C D
			��̳У�class D: public C, public B;     ����˳��A C B D
			��̳У�class D: public B, public C;     ����˳��A B C D

��Ϊ����̳е�������������ֻ������һ�������ĳ�Ա�����Ըó�Ա���Ա�ֱ�ӷ��ʣ�������������ԡ����⣬��������ĳ�Աֻ��һ������·�����ǣ���ô��Ȼ����ֱ�ӷ�����������ǵĳ�Ա����������ó�Ա�����������·�������ˣ��ǾͲ���ֱ�ӷ����ˣ���ʱ����ָ���ó�Ա�����ĸ��ࡣ
���� A ������һ����Ϊ x �ĳ�Ա�������������� D ��ֱ�ӷ��� x ʱ���������ֿ����ԣ�
	��� B �� C �ж�û�� x �Ķ��壬��ô x ��������Ϊ A �ĳ�Ա����ʱ�����ڶ����ԡ�
	��� B �� C ���е�һ���ඨ���� x��Ҳ�����ж����ԣ�������� x �������� x ���ȼ����ߡ�
	��� B �� C �ж������� x����ôֱ�ӷ��� x ���������������⡣
*/

class lve_A {
public:
	int m_a;
	lve_A(int n) : m_a(n) {
		cout << "A" << endl;
	};
};

class lve_B : virtual public lve_A {
public:
	int m_b;
	lve_B(int n) : m_b(n), lve_A(2) {
		cout << "B" << endl;
	};
};

class lve_C : virtual public lve_A {
public:
	int m_c;
	lve_C(int n) : m_c(n), lve_A(2) {
		cout << "C" << endl;
	};
};

class lve_D : public lve_C, public lve_B {
public:
	int m_d;
	lve_D(int n) : m_d(n), lve_C(3), lve_B(3), lve_A(3) {
		cout << "D" << endl;
	};
	// m_a����ȷ����������֪����A - B - D�����̳����Ļ���A - C - D�����̳���������Ҫʹ�÷�Χѡȡ��::
	int getMA() {
		return lve_B::m_a;
	}
};

void learn_virtual_extend_main() {
	lve_D d(3);
	d.getMA();
}