#include <iostream>
using namespace std;

/*
* fianl����ֹ���̳�
*	���γ�Ա����ʱ��ֻ����virtual����
*/
class Fianl_Parent {
public:
	virtual void getAge() final {
		cout << "age" << endl;
	}
};

class Fianl_Child final : public Fianl_Parent {
public:
	// error. �޷���дfinal���εĺ���
	/*void getAge() {
		cout << "age" << endl;
	}*/
};

// error. ���ܼ̳�final���ε���
//class Final_Son : public Fianl_Child {};

void fianl_main() {
	Fianl_Parent f;
	f.getAge();
}