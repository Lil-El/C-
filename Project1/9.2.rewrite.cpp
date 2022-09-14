#include<iostream>
using namespace std;

class Shape {

protected:
	float width;
	float height;

public:
	Shape() {}

	Shape(float w, float h) : width(w), height(h) {}

	Shape(const Shape &s) {
		cout << "����" << endl;
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

	friend class SmartPoint;

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
	// ��ֵ����� =
	void operator=(const Shape &s) {
		cout << "��ֵ�����" << endl;
		width = s.width;
		height = s.height;
	}
	// ������������� () ����
	Shape operator()(int x) {
		width = width + x;
		height = height + x;
		return *this;
	}
	float operator()() {
		return width;
	}
	//�±������ [] ����
	float operator[](int x) {
		float arr[2]{ width, height };
		return arr[x];
	}
	// ����/������������
	/*
		��Ϊcout������������������thisָ������ռ��һ��������λ�ã����ԣ�û�а취��operator<<���س���ĳ�Ա������
		thisָ��Ĭ���ǵ�һ��������Ҳ�����������������ʵ��ʹ����cout��Ҫ���ǵ�һ���βζ��󣬲�������ʹ��
		��������Ҫ��operator<<���س�ȫ�ֺ�����Ϊ����������Է��ʳ�Ա������Ҫ��Ԫ����������ˡ�
	*/
	friend ostream &operator<<(ostream &out, Shape &s) {
		//out << "width: " << s.width << "; height: " << s.height << endl;
		return out;
	}
	friend istream &operator>>(istream &in, Shape &s) {
		//in >> s.width >> s.height;
		return in;
	}
};

class SmartPoint {
private:
	Shape *shape;
public:
	static int count;
	SmartPoint(Shape *s) {
		shape = s;
	}
	// sp++ ����sp.operator++()
	void operator++(int) {
		count++;
	}
	/*
		�������ͱ�����ָ���������Ķ���
		����� -> ͨ����ָ����������� * ���ʹ�ã�����ʵ��"����ָ��"�Ĺ��ܡ�
	*/
	// sp->getWidth()  ����(sp.operator->())->getWidth()
	Shape *operator->() {
		operator++(1);
		return shape;
	}
};

int SmartPoint::count = 0;

// ���ش󲿷� C++ ���õ������
// �����βΡ�����ֵ���õ��ǿ������캯��������=���ø�ֵ����
void rewrite_main() {
	Shape rect1, rect2, rect3;
	// r1
	rect1.setWidth(10);
	rect1.setHeigth(10);
	// r2
	// =
	rect2 = rect1;
	cout << boolalpha << (rect1 == rect2) << endl;
	//r3
	// +
	rect3 = rect1 + rect2;
	// output
	cout << rect3.getWidth() << endl;
	cout << rect3.getHeight() << endl;
	// -
	-rect1;
	cout << rect1.getWidth() << endl;
	cout << rect1.getHeight() << endl;

	Shape s1 = Shape(99, 33);
	cout << s1.getWidth() << endl;
	cout << Shape(14, 15).getHeight() << endl;
	// ++
	s1++;
	cout << s1.getWidth() << endl;
	cout << s1.getHeight() << endl;
	// ()
	s1(10);
	cout << s1.getWidth() << endl;
	cout << s1.getHeight() << endl;
	cout << s1() << endl;
	// []
	cout << s1[0] << " " << s1[1] << endl;
	// ->
	cout << "**********************" << endl;
	Shape *sptr = &s1;
	cout << sptr->getWidth() << endl;

	cin >> s1;
	cout << s1;

	cout << "**********************" << endl;
	SmartPoint sp(&s1);
	cout << "sp: " << sp->getWidth() << endl;
	cout << "sp count: " << sp.count << endl;
	cout << "sp: " << sp->getHeight() << endl;
	cout << "sp count: " << sp.count << endl;
	sp++;
	cout << "sp count: " << sp.count << endl;
}
