#include <iostream>
#include <locale>

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
	char str1[]{ '你', '好', 'l', 'l', 'o', '\0' }; // Bug: 乱码  一个汉字占两个字节，所以用一个字节的char类型无法存储中文
	char16_t str2[]{ '你', '好', 'l', 'l', 'o', '\0' }; // Bug: 乱码
	const char *cnStr = "中文"; // 正常

	wchar_t wstr[] = L"中文哈哈哈"; // 字符前添加L表示告诉编译器为字符分配2字节空间
	wcout << wstr << endl;
	/*
       未设置本地语言之前，wcout直接输出导致流错误，
       需要先把流错误清除，后边wcout才能正常输出
	 */
	wcout.clear();
	setlocale(LC_ALL, "chs");
	cout << wstr << endl;
	wcout << wstr << endl;
}
