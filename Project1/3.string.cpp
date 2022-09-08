#include <iostream>
#include <locale>
#include <tchar.h>
#include <string>
#include <atlstr.h>
using namespace std;
/*
关于CString使用的头文件说明：
1、使用MFC的情况下，包含头文件cstringt.h
2、不使用MFC：包含atlstr.h   或者 #include <afx.h>
*/

using namespace std;

/*
	wchar_t是C/C++的字符类型，一种扩展的存储方式，主要用在国际化程序的实现中，但它不等同与Unicode编码；Unicode编码的字符一般是以wchar_t字符存储。
	char字符类型只有8个位，只能包含256个字符，而像很多外文字符远超过256个字符，例如：中文、日文、韩文等，这些字符需要占用两个字节空间，所以c++提出了双字节字符类型wchar_t(或叫宽字符类型)。
	wchar_t宽字符类型定义：
　　	  wchar_t  name[]  =  L"content";
　　	  注：wchar_t定义的是双字节类型，需要L告诉编译器content占用2字节的空间，否则编译产生类型报错。
	wchar_t宽字符类型输出：
　　	  cout输出：字节十六进制数据
　　	  wcout输出： 设置本地语言后，正常输出，未设置则发生流错误，需调用wcout.clear()清除错误后方能正常输出
　　	  wprintf()输出：以宽字符形式输出
　　	  wcout、wprintf输出内容必须使用L 修饰。
	wchar_t环境设置：
　　	  头文件：<locale>
　　	  setlocale(LC_ALL, "chs");  // 设置为中文格式
*/
void strMain() {
	cout << "**************中文 char wchar_t / _T / L***************" << endl;

	char str1[]{ '你', '好', 'l', 'l', 'o', '\0' }; // 乱码  一个汉字占两个字节，所以用一个字节的char类型无法存储中文
	char16_t str2[]{ '你', '好', 'l', 'l', 'o', '\0' }; // 乱码
	const char *cnStr = "中文"; // 正常

	wchar_t wstr[] = L"中文哈哈哈"; // 字符前添加L表示告诉编译器为字符分配2字节空间。L是表示字符串资源为Unicode的。
	// TCHAR源码
	// #define __T(x) L ## x
	// #define _T(x) __T(x)
	// _T 是 L 的语法糖
	wchar_t wstr2[] = _T("嘻嘻嘻"); // 引入头文件tchar.h；_T和L效果是一样的。_T("")是一个宏,他的作用是让你的程序支持Unicode编码
	const wchar_t* wstr3 = L"额恩恩";
	wcout << wstr2 << endl;
	/*
       未设置本地语言之前，wcout直接输出导致流错误，
       需要先把流错误清除，后边wcout才能正常输出
	 */
	wcout.clear();
	setlocale(LC_ALL, "chs");
	cout << "输入：cout:  " << wstr2 << endl;
	wcout << "wcout:  " << wstr2 << endl;
	wcout << "wcout:  " << wstr3 << endl;

	cout << "str1 Length: " << strlen(str1) << endl;
	cout << "wstr Length: " << wcslen(wstr) << endl;
	cout << "wstr2 Length: " << wcslen(wstr2) << endl;

	/*
		1. <locale>、平台 API、boost.locale、ICU 都可以帮你编码转换。
		2. Unicode 编码应作为中间格式。表达文本的字符串的字面量应当用 Unicode 版本，且源文件应以 Unicode 编码保存，否则可能因编辑器、编译器、其它系统（例如拷源码到别的机器上）的编码设置不一致导致乱码。
		3. locale 可以设置为 Unicode 变体。
			std::cout 的 char 的编码是 UTF-8。
			std::wcout 的 char 的编码是 UTF-8。
			std::wstring UTF-16
			string ASCII
			wchar_t 编码是 UTF-16（Windows）或 UTF-32（多数 Unix-like）。
			这样，char8_t & 在输入/输出能 reinterpret_cast 成 char &，而 char16_t & 或 char32_t & 中的一种（视平台而定）可以 reinterpret_cast 成 wchar_t &。
			string/u8string/u16string/u32string 同理处置。这样能解决大多数需求。
		4. 先别激动。更正确的方法当然是用 std::codecvt 等编码转换功能来转换。
		5. string 间的转换和重载好的运算符，标准库虽未提供，但你可以自行添加。
	*/
	// UTF-X是UniCode的表现形式
	// char8_t char16_t char32_t 表示用于 UTF-x 字符表示形式
	char16_t str_16 {L'马'};
	wcout << "char16_t: " << (wchar_t)str_16 << endl;
	// TODO: u16string(u"Hello");

	cout << "**************String***************" << endl;
	// string是窄字符串ASCII，而很多Windows API函数用的是宽字符Unicode
	// wstring宽字符串
	// string ASCII(也可以表示UTF-8);  wstring UTF-16
	string str = "你好C";
	//wstring wstr = "你好C";
	cout << "str: " << str << endl;


	cout << "**************CString***************" << endl;
	// CString是对string和wstring的封装，常用于MFC：微软基础类库
	CString cstr("HEllo");
	cout << "cstr: " << cstr << endl;


}
