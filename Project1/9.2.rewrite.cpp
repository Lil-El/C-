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
		cout << "拷贝" << endl;
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
	// 赋值运算符 =
	void operator=(const Shape &s) {
		cout << "赋值运算符" << endl;
		width = s.width;
		height = s.height;
	}
	// 函数调用运算符 () 重载
	Shape operator()(int x) {
		width = width + x;
		height = height + x;
		return *this;
	}
	float operator()() {
		return width;
	}
	//下标运算符 [] 重载
	float operator[](int x) {
		float arr[2]{ width, height };
		return arr[x];
	}
	// 输入/输出运算符重载
	/*
		因为cout的输出流对象和隐含的this指针在抢占第一个参数的位置，所以，没有办法将operator<<重载成类的成员函数。
		this指针默认是第一个参数，也就是左操作数，但在实际使用中cout需要的是第一个形参对象，才能正常使用
		所以我们要将operator<<重载成全局函数，为了让类外可以访问成员，就需要友元函数来解决了。
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
	// sp++ 即：sp.operator++()
	void operator++(int) {
		count++;
	}
	/*
		返回类型必须是指针或者是类的对象。
		运算符 -> 通常与指针引用运算符 * 结合使用，用于实现"智能指针"的功能。
	*/
	// sp->getWidth()  即：(sp.operator->())->getWidth()
	Shape *operator->() {
		operator++(1);
		return shape;
	}
};

int SmartPoint::count = 0;

// 重载大部分 C++ 内置的运算符
// 对于形参、返回值调用的是拷贝构造函数；对于=调用赋值重载
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
