#include<iostream>
using namespace std;

namespace h_3_namespace {
	void log(const char *str) {
		cout << "str: " << str << endl;
	}
	namespace inner_namespace{
		void log2(const char *str) {
			cout << "str2: " << str << endl;
		}
	}
}

namespace std {
	void stdLog() {
		cout << "std log message!" << endl;
	}
}

typedef int my_int;
namespace std {
	using ::my_int;
}

void name_main() {
	stdLog();
	// 1
	h_3_namespace::log("×Ö·û´®");
	using namespace h_3_namespace;
	log("123");

	// 2
	h_3_namespace::inner_namespace::log2("log");
	using namespace h_3_namespace::inner_namespace;
	log2("sds");

	std::my_int a = 1;
}