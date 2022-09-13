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

	// 一元运算符 - !等
	Shape operator-() {
		width = -this->width;
		height = -height;
		// return 新的实例的话，赋值时生效。例如：return Shape shape(); Shape s = -rect1;
		return *this; // return Shape()
	}
	// 二元运算符 + - * /
	Shape operator+(const Shape &s) {
		Shape shape;
		shape.setWidth(this->width + s.width);
		shape.setHeigth(this->height + s.height);
		return shape;
	}
	// 关系运算符 < > <= ==等
	bool operator==(const Shape &s) {
		if (s.width == this->width && s.height == height) return true;
		return false;
	}
	// 前缀递增运算符++
	Shape operator++(int) {
		width = width + 1;
		height = height + 1;
		return *this; // 返回新的
	}
	// 后缀递增运算符++
	Shape operator++() {
		Shape shape(width, height);
		width = width + 1;
		height = height + 1;
		return shape; // 返回旧的
	}
	/*
		输入/输出运算符重载
		赋值运算符重载
		函数调用运算符 () 重载
		下标运算符 [] 重载
		类成员访问运算符 -> 重载
	*/
};

// 重载大部分 C++ 内置的运算符
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
