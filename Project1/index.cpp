#include <iostream>
#include <cstdarg>
//#include "util.h"
using namespace std;

// 先对函数进行声明，加不加extern都可以，默认就是有的
extern void useDll_main();

int main() {
	useDll_main();
}