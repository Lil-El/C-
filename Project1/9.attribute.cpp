#include <iostream>
using namespace std;

/*
	��C++11��ʼ������attribute��
	11��[[noreturn]] [[carries_dependency]]
	14: [[deprecated]]   [[deprecated("reason")]]
	C++17�� [[fallthrough]] [[nodiscard]] �� [[nodiscard("reason")]] (C++20) [[maybe_unused]]
	C++20�����׼�� [[likely]] �� [[unlikely]] [[no_unique_address]]
*/

// ������return���
[[noreturn]] void know_noreturn_fn() {
	if (1) {

	}
	else {
		return;
	}
}

[[deprecated("dont use this function!")]] void know_depretcated_fn() {

}

// ����ֵ����ʹ�ã����ܶ���
[[nodiscard("dont discard o��")]] int know_nodiscard_fn() {
	return 1;
}

void know_noreturn_main() {
	know_noreturn_fn();
	know_nodiscard_fn();
}