#include "pch.h" // ����pch.h����framework.h������
#pragma comment(lib, "StaticLib1.lib")

void useStatic_main() {
	StaticOne a(1);
	a.sayHello();

	fnStaticLib1();
}
