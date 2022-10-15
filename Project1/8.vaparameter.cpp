#include <iostream>
#include <cstdarg>

// �ɱ�����б�
void know_fn(int a, int b, ...) {
	va_list ap; // va_list��ȫ�ֶ��壬stdҲ������
	va_start(ap, a);
	auto z = va_arg(ap, int);
	auto x = va_arg(ap, int);
}

// �ɱ����ģ��1
template<typename... T>
void know_temp_fn(T... args) {
	std::cout << sizeof...(T) << std::endl;
	std::cout << sizeof...(args) << std::endl;
};

// �ɱ����ģ��2
void know_temp_fn2() {};

template <typename T, typename... U>
void know_temp_fn2(T v, U... args)
{
	std::cout << v << std::endl;
	know_temp_fn2(args...);
};

void know_vapara() {
	know_fn(3, 6, 7, 9, 10, 11);
	know_temp_fn(9, 6, 7, 3, 9);
	know_temp_fn2(1, 2, 3);
}