#include <iostream>

/*
	�������������һ������������Ϊ���麯�������������ǳ�����(ABC)��
	ABC�����Ա�ʵ������ֻ�������ӿڡ�
	ACB������Ҫʵ��������ʵ��ÿ���麯��
*/
class Shape_9_3 {

protected:
	float width, height;

public:
	Shape_9_3(float w = 0, float h = 0) : width(w), height(h) {
		std::cout << "shape constructor call" << std::endl;
	}
	/*
		�麯�� ���ڻ�����ʹ�ùؼ��� virtual �����ĺ������������������¶�������ж�����麯��ʱ������߱�������Ҫ��̬���ӵ��ú�����
		�ڳ������������Ը��������õĶ���������ѡ����õĺ��������ֲ�������Ϊ��̬���ӣ�����ڰ󶨡�
	*/
	virtual float getArea() {
		std::cout << "shape call" << std::endl;
		return width * height;
	}
	// ���麯���������������������¶���ú������õ������ڶ��󣬵������ڻ������ֲ��ܶ��麯�������������ʵ�֣����ʱ��ͻ��õ����麯����
	virtual float getHalfHeight() = 0; // = 0 ���߱�����������û�����壬������麯���Ǵ��麯����
};

/*
	��̬��ζ�ŵ��ó�Ա����ʱ������ݵ��ú����Ķ����������ִ�в�ͬ�ĺ�����
	C++�еĶ�̬��Ϊ��̬��̬�Ͷ�̬��̬���֣����У�
		1. ��̬��̬�ڱ���׶�ʵ�֣���ԭ�����ɺ�������ʵ�֣�ͨ����ͬ��ʵ�ε�������Ӧ��ͬ��������
		2. ��̬��̬ͨ���麯��ʵ�֣��������ؽ���
			��̬��̬��������Ҫ������
			����ͨ�������ָ��������õ���
			�����õı������麯����������������ʵ���˸��麯������д
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
		���ú��� getArea() ������������Ϊ�����еİ汾���������ν�ľ�̬��̬����̬����
		���������ڳ���ִ��ǰ��׼�����ˡ���ʱ����Ҳ����Ϊ��󶨣���Ϊ area() �����ڳ�������ڼ���Ѿ����ú��ˡ�
		������ Shape ���У�area() ������ǰ���ùؼ��� virtual
	*/

	s93 = &triangle;
	std::cout << s93->getArea() << std::endl;
	s93 = &rect;
	std::cout << s93->getArea() << std::endl;

	std::cout << "**********" << std::endl;
	std::cout << rect.getHalfHeight() << std::endl;
	std::cout << triangle.getHalfHeight() << std::endl;
}