#include <iostream>
#include <cstdarg>
#include <initializer_list>

// �ɱ�����б�
void know_fn(int a, int b, ...) {
	va_list ap; // va_list��ȫ�ֶ��壬stdҲ������
	va_start(ap, a);
	auto z = va_arg(ap, int);
	auto x = va_arg(ap, int);
	va_end(ap); // �ͷ�
}

// �ɱ����ģ��1
template<typename... T>
void know_temp_fn(T... args) {
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(T) << std::endl;
};

// �ɱ����ģ��2��ģ��ͨ�����õݹ鷽ʽչ��
void know_temp_fn2() {};

template <typename T, typename... U>
void know_temp_fn2(T v, const U&... args)
{
	std::cout << v << std::endl;
	know_temp_fn2(args...);
};

void know_temp_fn3(std::initializer_list<int> li) {
	for (std::initializer_list<int>::iterator beg = li.begin(); beg != li.end(); ++beg)
		std::cout << *beg << " ";
	std::cout << std::endl;
}

void know_vapara_main() {
	know_fn(3, 6, 7, 9, 10, 11);
	know_temp_fn(9, 6, 7, 3, 9);
	know_temp_fn2(1, 2, 3);
	know_temp_fn3({ 1, 2, 3 });
}