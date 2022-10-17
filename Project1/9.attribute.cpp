#include <iostream>
using namespace std;

/*
	从C++11开始引入了attribute；
	11：[[noreturn]] [[carries_dependency]]
	14: [[deprecated]]   [[deprecated("reason")]]
	C++17： [[fallthrough]] [[nodiscard]] 和 [[nodiscard("reason")]] (C++20) [[maybe_unused]]
	C++20引入标准： [[likely]] 和 [[unlikely]] [[no_unique_address]]
*/

// 不能有return语句
[[noreturn]] void know_noreturn_fn() {
	if (1) {

	}
	else {
		return;
	}
}

[[deprecated("dont use this function!")]] void know_depretcated_fn() {

}

// 返回值必须使用，不能丢弃
[[nodiscard("dont discard o！")]] int know_nodiscard_fn() {
	return 1;
}

void know_noreturn_main() {
	know_noreturn_fn();
	know_nodiscard_fn();
}