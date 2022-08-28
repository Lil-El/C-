#include <iostream>
#include "util.h"
using namespace std;

void logN(int num) {
	cout << "log:" << num << endl;
}

int Shape::getArea() {
	return width * height;
}

Shape shape(2, 3);