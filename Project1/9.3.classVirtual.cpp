#include <iostream>

/*
	如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类(ABC)。
	ABC不可以被实例化，只能用作接口。
	ACB的子类要实例化必须实现每个虚函数
*/
class Shape_9_3 {

protected:
	float width, height;

public:
	Shape_9_3(float w = 0, float h = 0) : width(w), height(h) {
		std::cout << "shape constructor call" << std::endl;
	}
	/*
		虚函数 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
		在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
	*/
	virtual float getArea() {
		std::cout << "shape call" << std::endl;
		return width * height;
	}
	// 纯虚函数：便于在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
	virtual float getHalfHeight() = 0; // = 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数。
};

/*
	多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
	C++中的多态分为静态多态和动态多态两种，其中：
		1. 静态多态在编译阶段实现，其原理是由函数重载实现，通过不同的实参调用其相应的同名函数。
		2. 动态多态通过虚函数实现，以下着重介绍
			动态多态的两个必要条件：
			必须通过基类的指针或者引用调用
			被调用的必须是虚函数，且在派生类中实现了该虚函数的重写
*/

class Triangle_9_3 : public Shape_9_3 {
public:
	Triangle_9_3(float w, float h) : Shape_9_3(w, h) {}
	float getArea() {
		std::cout << "call triangle" << std::endl;
		return (width * height) / 2;
	}
	float getHalfHeight() {
		return getArea() / 2;
	}
};

class Rectangle_9_3 : public Shape_9_3 {
public:
	Rectangle_9_3(float w, float h) : Shape_9_3(w, h) {}
	float getArea() {
		std::cout << "call rect" << std::endl;
		return width * height;
	}
	float getHalfHeight() {
		return getArea() / 2;
	}
};

void virtual_main() {
	Triangle_9_3  triangle(10, 10);
	Rectangle_9_3 rect = Rectangle_9_3(10, 10);
	std::cout << triangle.getArea() << std::endl;
	std::cout << rect.getArea() << std::endl;

	std::cout << "**********" << std::endl;
	Shape_9_3 *s93;

	/*
		调用函数 getArea() 被编译器设置为基类中的版本，这就是所谓的静态多态，或静态链接
		函数调用在程序执行前就准备好了。有时候这也被称为早绑定，因为 area() 函数在程序编译期间就已经设置好了。
		所以在 Shape 类中，area() 的声明前放置关键字 virtual
	*/

	s93 = &triangle;
	std::cout << s93->getArea() << std::endl;
	s93 = &rect;
	std::cout << s93->getArea() << std::endl;

	std::cout << "**********" << std::endl;
	std::cout << rect.getHalfHeight() << std::endl;
	std::cout << triangle.getHalfHeight() << std::endl;
}