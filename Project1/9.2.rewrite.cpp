#include<iostream>
using namespace std;

class Shape {
private:
	char type[10];
protected:
	float width;
	float height;

public:
	Shape() {}

	Shape(float w, float h) : width(w), height(h) {}

	Shape(const Shape &s) {
		width = s.width;
		height = s.height;
	}

	void setWidth(float w) {
		width = w;
	}
	void setHeigth(float h) {
		height = h;
	}
	float getWidth() {
		return width;
	}
	float getHeight() {
		return height;
	}

	// һԪ����� - !��
	Shape operator-() {
		width = -this->width;
		height = -height;
		// return �µ�ʵ���Ļ�����ֵʱ��Ч�����磺return Shape shape(); Shape s = -rect1;
		return *this; // return Shape()
	}
	// ��Ԫ����� + - * /
	Shape operator+(const Shape &s) {
		Shape shape;
		shape.setWidth(this->width + s.width);
		shape.setHeigth(this->height + s.height);
		return shape;
	}
	// ��ϵ����� < > <= ==��
	bool operator==(const Shape &s) {
		if (s.width == this->width && s.height == height) return true;
		return false;
	}
	// ǰ׺���������++
	Shape operator++(int) {
		width = width + 1;
		height = height + 1;
		return *this; // �����µ�
	}
	// ��׺���������++
	Shape operator++() {
		Shape shape(width, height);
		width = width + 1;
		height = height + 1;
		return shape; // ���ؾɵ�
	}
	/*
		����/������������
		��ֵ���������
		������������� () ����
		�±������ [] ����
		���Ա��������� -> ����
	*/
};

// ���ش󲿷� C++ ���õ������
void rewrite_main() {
	Shape rect1, rect2, rect3;
	// r1
	rect1.setWidth(10);
	rect1.setHeigth(10);
	// r2
	rect2 = rect1;
	cout << boolalpha << (rect1 == rect2) << endl;
	//r3
	rect3 = rect1 + rect2;
	// output
	cout << rect3.getWidth() << endl;
	cout << rect3.getHeight() << endl;

	-rect1;
	cout << rect1.getWidth() << endl;
	cout << rect1.getHeight() << endl;

	Shape s1 = Shape(99, 33);
	cout << s1.getWidth() << endl;
	cout << Shape(14, 15).getHeight() << endl;

	s1++;
	cout << s1.getWidth() << endl;
}
