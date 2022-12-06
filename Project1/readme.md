# C++

- �������
	- [�����͡�����������](https://blog.csdn.net/weixin_58257948/article/details/118033564)

- �������
	- w3c   
	- Book
	- [C����������](http://c.biancheng.net/view/7165.html)
	- [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## ������

- GNU C, ANSI C��������׼���ֱ�ͨ��gcc��vsʵ��
- GNU Cͨ��gcc��linux������
- ANSI Cͨ��vs��windows�����롣
- GNU C�����Բ��������ANSI C����һЩ��չ������һ�ο�ƽ̨�ĳ������ͨ��gcc���룬Ҳ��һ������vs���롣
- MSVC��΢���VC������
- gcc��g++��C���Ա�������C++������
- MinGW��Gnu��Windows���ļ��ϣ�������linux��windows�����ж�����Ҫ��������C��

## Visual Studio

- �����ߡ�->��ѡ�->���ı��༭����->��C/C++��->��������ʽ��->����ʽ���á�->����ࡱ->��ָ��/���ö��뷽ʽ��->������롱

## ������

- ����ʱ�ļ�������Ϊxxxx.cpp�����û�к�׺����ͨ��F2��Ӻ�׺���޷���ȡ�����ļ�������

## using

1. ���Ͷ��壬������typedef��using mInt = int;
2. �����ռ䣬using namespace
3. �����Ա�������� `class: private parent { public: using parent::name};`
4. �������غ��� `class : parent {using parent::getName()}`

## typename

- ���ڱ�ʶ��һ���������ƣ�using myInt = typename struct1::type;

## Ԥ����

- #program warning
- #program push/pop
- #define: �����
- #undef: ȡ���궨��
- #if defined(char8_t) && _HAS_CXX20
https://blog.csdn.net/Poo_Chai/article/details/89350054

## ��������

- _t: ��ʾʹ��typedef���������
- wchar_t: ��ʾ unsigned char ����

## �ַ���

- `char str[] { 'h', 'e' };` ����ʡ�� = ��C++11����
- `char str[] { 'h', 'e' };` ���������ַ���, ˫�������ַ�����; ʹ��˫���Żᱨ��Ӧ��ʹ�õ�����
- �ַ�������û��\0������������

## ����

- �������������׸�Ԫ�صĵ�ַ
- ����ĳ��ȳ���size()��������⣬����ͨ��sizeof(arr) / sizeof(arr[0])��ã�
- ��������ʱ�޷�ͨ������ָ�����鳤�ȣ�ʹ��vector����const int length = 10����ֻ��������10�������Ǳ�����

## ����

- ���أ����������ͣ�������˳��ͬ�����ܸ��ݷ������Ͳ�ͬ������

## ȫ�ֱ���

- function
	1. ����cpp�ļ�������һ��ȫ�ֺ�����������ļ��п���ͨ��externȥʹ��
		- �磺��a.cpp�ж���function a(){}����b.cpp��ʹ�ã�externĬ�Ͼ��У�function a();
	2. ����һ��ͷ�ļ�����cpp�ļ���includeͷ�ļ�

- class
	1. ��ͷ�ļ��ж��壬���ļ��ж���
	2. ע�⣺Class�޷�ʹ��extern�����鶨����hͷ�ļ��С���Ϊclass���ڴ��С�޷�ȷ��

- basic
	1. �������ݱ�����������cpp�ļ��ж���ģ�����ͨ��externȥ����ʹ�ã���������붼Ҫ���extern�ؼ��֣�
		- �磺��a.cpp����extern int a = 1; ��b.cppʹ��extern int a; cout << a;
	2. Ҳ������ͷ�ļ��ж��壬���const����static���������ʾ�ظ��������
		- ��ͷ�ļ���ֻ��������Ҫ���壬������includeͷ�ļ�������ʾ�ظ����塣��Ҫʹ��ifndef����ͷ�ļ�������
			��a.cpp��b.cpp�������ӳ�a.o��b.o֮�󲻻ᱨ�������������ӳ���Ŀ��.exe�ͻ����ȫ�ֱ����ض���
		- ͷ�ļ�������
			ÿ��ͷ�ļ���������Ǹ���ϰ�ߣ����ǲ����ͷ�ļ��еĶ�����Ч����int a = 1; void fn() {};
			������ӿ��ܻ�������³���:
				��A.h�����涨����һЩ������
				��B.h������#include��A.h��Ҳ������һЩ������
				����main.cppͬʱ#include��A.h��B.h����Ҫ�����ˣ��ַ����滻�����������A.h�����������ͷ�ļ����������ٵ���A.h�᲻��ִ�У��ͱ��������������
	3. Tips:
		1. cpp�ж����static�ı������޷��������ļ���extern��ʹ�õģ�
		2. h�ж����static��������������ظ���������
		3. ���ģ����Է��ʱ��������ǲ����޸ģ�������ü���const���η�

- extern
	1. fileA�ж���һ��������fileB��ͨ��extern���ô˺���; ͷ�ļ���������û���ʾ�ظ����壬������.h�ж��������������ȫ�ֱ���ʱ����Ҫ��ӣ�
		```
			#ifndef NAME
			#define NAME
			...
			#endif
		```
	2. [extern "C"����](https://blog.csdn.net/jiqiren007/article/details/5933599)��
		1. C++����ָ�Ϊ��֧��C/C++��ϱ��
		2. C��C++�ı������ͬ��
			C++��C��֧�ָ�������ԣ�����C++֧�ֺ������أ�Cȴ����
			����һ������`void fn(int a, int b) {};`C�������Function(int, int)������C++�ı�������_Z8Functionii(*ii*��ʾ���ǲ���)��
			������
				.h������������һ��.c�ļ�������.h�����庯�����ú���ʹ��C��ʽ���룻��Cpp�ļ���ͨ��extern����˺������ͻ���ʾ����δ���壻(.c����Function��.cpp����Functionii)
				���.cpp����.h�����庯������ô���߶���cpp��ʽ���룬��û�����⡣
			**����׶�û���������ӵĽ׶α�����**
			��extern "C"���εı����ͺ�������ͨ��C�ı��뷽ʽ���б��롣
			extern��Ӧ�Ĺؼ�����static��static�����������ߺ���ֻ���ڱ�ģ����ʹ�ã���ˣ���static���εı������ߺ��������ܱ�extern C���Ρ�
		3. ʹ�ã�
			```
				#ifndef __INCvxWorksh /*��ֹ��ͷ�ļ����ظ�����*/
				#define __INCvxWorksh

				#ifdef __cplusplus             // �����C++����Ⱦ`extern "C"{`;
				extern "C"{
				#endif

				/*��������������������ȡ�*/ // �����C++����δ���ᱻextern C��������������ʹ��C�ķ�ʽȥ���롢���ӣ������������

				#ifdef __cplusplus             // �����C++����Ⱦ`}`;
				}
				#endif

				#endif /*end of __INCvxWorksh*/
			```

## ��class

- �������캯����=��ֵ���������
	1. ����δ���帳ֵ(Shape s1 = s;) (Shape s1(s))������`�������캯��`���Ѿ�����ĸ�ֵ������`��ֵ����`(Shape s(), s1(); s = s1;)
	2. �ڶ���ֵ���βΡ�����ֵʱ��Ĭ����ǳ����������ָ�����͵ĳ�Ա����������ָ����һ���ģ��ᵼ����ʹ�û�ɾ��ʱ�������⡣������д�������캯�����������
	3. �ڶ���ֵʱ��ʹ��=��()��ֵ����Ҫ�Ƚ���ֵ�����Ȼ��ֵ��Ĭ�ϵ�ָ���Ա�ڴ治�ᱻ�ͷš��������ظ�ֵ������������ɾ��ָ�롣

- class��struct
- is_base_of, typeid�жϼ̳й�ϵ
- typeid().name()���Ի�ȡָ���class����

## IO

- TODO: cin/cout/clog/cerr����-������

- ģ��

template
http://m.biancheng.net/view/320.html
https://blog.csdn.net/vanturman/article/details/81746063
https://blog.csdn.net/qq_45801299/article/details/112298619

## ����

- static_assert����̬���� C++11���ڱ���ʱ��⣬��ͨ���ᱨ��
- assert�����ԣ���Ӱ����룬ʧ��Ҳ����ͨ����������ʱ��⣻
- ���ܣ�
	static_assert: �������Ĵ��벻������Ŀ����룬����Ӱ��������ܣ�
	assert: ��Ӱ��������ܣ������ڵ��Խ׶Σ���ʽ�ͷ����ʱͨ���ر�assert����
- = default: �Զ����ɺ����壻������class A�ж���Ĭ�Ϲ��캯����A() = default;

## [STL](https://blog.csdn.net/weixin_53332395/article/details/123948946) 

�ṩһ�׹���ǿ���ģ����ͺ�������Щ��ͺ�������ʵ���㷨�����ݽṹ��

- Container������
- Algorithms���㷨
- iterator��������

## ����ĵ�

- [new��deleteʵ��ԭ��](https://www.php.cn/blog/detail/31237.html)

## Blog:

- �������á���ֵ���ã�https://www.cnblogs.com/ht1947/p/10617821.html http://t.zoukankan.com/ishen-p-13771991.html

## TODO:

- �ƶ����캯��
- ����ָ��
- decltype���Զ������Ƶ�  auto __cdecl
- stdcall cdecl
- declval
- mutex
- thread
	https://blog.csdn.net/zzhongcy/article/details/91372329
	https://zhuanlan.zhihu.com/p/340201634 
	https://www.runoob.com/w3cnote/cpp-std-thread.html 
	https://zhuanlan.zhihu.com/p/450087085
	https://blog.csdn.net/qq_20853741/article/details/114093265
- ����������Lambda���ʽ��void swap(_Ty (&)[_Size], _Ty (&)[_Size]);
- C++11��׼�� chrono functional atomic
