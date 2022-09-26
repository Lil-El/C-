#include<iostream>
#include<vector>

/*
	yvals_core.h: ºê¶¨Òå¿â
	#define _STD ::std::
*/
#undef _STD
#define _Mino std::
#define _Validate_TRUE_BEGIN if(true) {
#define _Validate_TRUE_END }

void stl_vector_main() {
	_Mino vector<int> arr { 1, 2, 3, 3, 4 };
	_Validate_TRUE_BEGIN
		_STD cout << arr[0] << ::std::endl;
	_Validate_TRUE_END

}