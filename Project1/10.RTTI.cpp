#include <iostream>
using namespace std;

/*
	RTTI: runtime type identification����ʱ����ʶ��Ϊ���ó���������ʱ�ܸ��ݻ����ָ�����������ø�ָ���������ָ�Ķ����ʵ������
	C++ͨ������ָ��ʵ�ֶ�̬����classVirtual.cpp����
*/

class Human {
public:
	Human() {}
	~Human() {}
	virtual void sex() {
		cout << "Im a human!" << endl;
	};
};

class Man : public Human {
public:
	Man() {}
	~Man() {}
	void sex() {
		cout << "I'm man!" << endl;
	}
	void dd() {
		cout << "man dd" << endl;
	}
};

class Woman : public Human {
public:
	Woman() {}
	~Woman() {}
	void sex() {
		cout << "I'm woman!" << endl;
	}
};

class rtti {

};

void know_rtti_main() {
	Human* human = new Man;
	// �ܶ��д���
	// ����Ҫ��ô֪��humanָ�����˭�أ�
	// RTTI: ����ʶ��
	cout << typeid(*human).name() << endl;
	cout << boolalpha << (typeid(*human) == typeid(Man)) << endl;
	// RTTI: ����ת����
	/*
	* ��������˸�������еĶ�������ʹ�ø���ָ�������������ǺϷ��ġ�
	* ��������ĳ�Ա���������Ǹ���û�еģ�������Ҫdynamic_cast���а�ȫ��Ч������ת�͡�
	*/
	Man man;
	Woman wm;
	Human *hm = &man;
	hm->sex();
	// hm->dd(); // Human��û��Man�ĳ�Ա������������Ҫ����ת����ΪMan����
	Man *m = dynamic_cast<Man*>(hm); // �������m��ָ��nullptr
	m->dd();
}