#include<iostream>
using namespace std;

class Shape_9_1 {
private:
	char type[10];
protected:
	float width;
	float height;

public:
	Shape_9_1() {}

	void setWidth(float w) {
		width = w;
	};
	void setHeigth(float h) {
		height = h;
	};
};

/*
	ͬһ�����У����Է���public��private��protected��Ա
	���࣬���Է��ʸ����public��protected��Ա
	�ⲿ�࣬���Է���public
*/
/*
�̳з�ʽ��
	public�������public���������public��protected���������protected��private���ܷ���
	protected�������public��protected��Ա�������protected��Ա
	private�������public��protected��Ա�������private��Ա
*/
// �̳в���̳и���Ĺ��캯�����������캯������Ԫ���������������
// ��̳У�clss Rectangle_9_1: public Shape_9_1, public classB, protected classC {}
class Rectangle_9_1 : public Shape_9_1 {
public:
	float getArea() {
		return width * height;
	}
};

class : public Shape_9_1 {
public:
	float getArea() {
		return width * height;
	}
} circle;

void extend_main() {
	Rectangle_9_1 rect;
	rect.setWidth(10);
	rect.setHeigth(10);
	cout << "Area is: " << rect.getArea() << endl;
	cout << "circle Area is: " << circle.getArea() << endl;
}