#include <iostream>
#include <locale>
#include <tchar.h>
#include <string>
#include <atlstr.h>
using namespace std;
/*
����CStringʹ�õ�ͷ�ļ�˵����
1��ʹ��MFC������£�����ͷ�ļ�cstringt.h
2����ʹ��MFC������atlstr.h   ���� #include <afx.h>
*/

using namespace std;

/*
	wchar_t��C/C++���ַ����ͣ�һ����չ�Ĵ洢��ʽ����Ҫ���ڹ��ʻ������ʵ���У���������ͬ��Unicode���룻Unicode������ַ�һ������wchar_t�ַ��洢��
	char�ַ�����ֻ��8��λ��ֻ�ܰ���256���ַ�������ܶ������ַ�Զ����256���ַ������磺���ġ����ġ����ĵȣ���Щ�ַ���Ҫռ�������ֽڿռ䣬����c++�����˫�ֽ��ַ�����wchar_t(��п��ַ�����)��
	wchar_t���ַ����Ͷ��壺
����	  wchar_t  name[]  =  L"content";
����	  ע��wchar_t�������˫�ֽ����ͣ���ҪL���߱�����contentռ��2�ֽڵĿռ䣬�������������ͱ���
	wchar_t���ַ����������
����	  cout������ֽ�ʮ����������
����	  wcout����� ���ñ������Ժ����������δ�������������������wcout.clear()�����������������
����	  wprintf()������Կ��ַ���ʽ���
����	  wcout��wprintf������ݱ���ʹ��L ���Ρ�
	wchar_t�������ã�
����	  ͷ�ļ���<locale>
����	  setlocale(LC_ALL, "chs");  // ����Ϊ���ĸ�ʽ
*/
void strMain() {
	cout << "**************���� char wchar_t / _T / L***************" << endl;

	char str1[]{ '��', '��', 'l', 'l', 'o', '\0' }; // ����  һ������ռ�����ֽڣ�������һ���ֽڵ�char�����޷��洢����
	char16_t str2[]{ '��', '��', 'l', 'l', 'o', '\0' }; // ����
	const char *cnStr = "����"; // ����

	wchar_t wstr[] = L"���Ĺ�����"; // �ַ�ǰ���L��ʾ���߱�����Ϊ�ַ�����2�ֽڿռ䡣L�Ǳ�ʾ�ַ�����ԴΪUnicode�ġ�
	// TCHARԴ��
	// #define __T(x) L ## x
	// #define _T(x) __T(x)
	// _T �� L ���﷨��
	wchar_t wstr2[] = _T("������"); // ����ͷ�ļ�tchar.h��_T��LЧ����һ���ġ�_T("")��һ����,��������������ĳ���֧��Unicode����
	const wchar_t* wstr3 = L"�����";
	wcout << wstr2 << endl;
	/*
       δ���ñ�������֮ǰ��wcoutֱ���������������
       ��Ҫ�Ȱ���������������wcout�����������
	 */
	wcout.clear();
	setlocale(LC_ALL, "chs");
	cout << "���룺cout:  " << wstr2 << endl;
	wcout << "wcout:  " << wstr2 << endl;
	wcout << "wcout:  " << wstr3 << endl;

	cout << "str1 Length: " << strlen(str1) << endl;
	cout << "wstr Length: " << wcslen(wstr) << endl;
	cout << "wstr2 Length: " << wcslen(wstr2) << endl;

	/*
		1. <locale>��ƽ̨ API��boost.locale��ICU �����԰������ת����
		2. Unicode ����Ӧ��Ϊ�м��ʽ������ı����ַ�����������Ӧ���� Unicode �汾����Դ�ļ�Ӧ�� Unicode ���뱣�棬���������༭����������������ϵͳ�����翽Դ�뵽��Ļ����ϣ��ı������ò�һ�µ������롣
		3. locale ��������Ϊ Unicode ���塣
			std::cout �� char �ı����� UTF-8��
			std::wcout �� char �ı����� UTF-8��
			std::wstring UTF-16
			string ASCII
			wchar_t ������ UTF-16��Windows���� UTF-32������ Unix-like����
			������char8_t & ������/����� reinterpret_cast �� char &���� char16_t & �� char32_t & �е�һ�֣���ƽ̨���������� reinterpret_cast �� wchar_t &��
			string/u8string/u16string/u32string ͬ���á������ܽ�����������
		4. �ȱ𼤶�������ȷ�ķ�����Ȼ���� std::codecvt �ȱ���ת��������ת����
		5. string ���ת�������غõ����������׼����δ�ṩ���������������ӡ�
	*/
	// UTF-X��UniCode�ı�����ʽ
	// char8_t char16_t char32_t ��ʾ���� UTF-x �ַ���ʾ��ʽ
	char16_t str_16 {L'��'};
	wcout << "char16_t: " << (wchar_t)str_16 << endl;
	// TODO: u16string(u"Hello");

	cout << "**************String***************" << endl;
	// string��խ�ַ���ASCII�����ܶ�Windows API�����õ��ǿ��ַ�Unicode
	// wstring���ַ���
	// string ASCII(Ҳ���Ա�ʾUTF-8);  wstring UTF-16
	string str = "���C";
	//wstring wstr = "���C";
	cout << "str: " << str << endl;


	cout << "**************CString***************" << endl;
	// CString�Ƕ�string��wstring�ķ�װ��������MFC��΢��������
	CString cstr("HEllo");
	cout << "cstr: " << cstr << endl;


}
