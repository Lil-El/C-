#include <iostream>
using namespace std;

/*
* �ƶ����캯������ֵ���ã�
* �ƶ����캯���ӹ�Դ���󣬲����������Ŀ�������������Ҫ�����µ��ڴ档���Ч�ʣ���ʡ�ڴ档
*/

class move_cls {
public:
	int* num;
	move_cls(){
		cout << "Ĭ�Ϲ���" << endl;
		this->num = new int(99);
	}
	move_cls(const move_cls& m) {
		cout << "���ƹ���" << endl;
		num = new int(*m.num);
	}
	move_cls(move_cls&& m) noexcept {
		cout << "�ƶ�����" << endl;
		num = m.num;
		m.num = nullptr;
	}
	~move_cls() {
		cout << "����" << endl;
		delete this->num;
	}
};

void move_main() {
	move_cls m; // Ĭ��
	move_cls n(m); // ����
	move_cls(move(m)); // �ƶ�
}