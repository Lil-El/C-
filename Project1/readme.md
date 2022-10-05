# C++

- �������
	- [�����͡�����������](https://blog.csdn.net/weixin_58257948/article/details/118033564)

- �������
	- w3c   
	- Book
	- [C����������](http://c.biancheng.net/view/7165.html)
	- [Microsoft](https://docs.microsoft.com/zh-cn/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170)

## Visual Studio

- �����ߡ�->��ѡ�->���ı��༭����->��C/C++��->��������ʽ��->����ʽ���á�->����ࡱ->��ָ��/���ö��뷽ʽ��->���Ҷ��롱

## ������

- ����ʱ�ļ�������Ϊxxxx.cpp�����û�к�׺����ͨ��F2��Ӻ�׺���޷���ȡ�����ļ�������

## using

1. ���Ͷ��壬������typedef
2. �����ռ䣬using namespace
3. �����Ա�������� `class: private parent { public: using parent::name};`
4. �������غ��� `class : parent {using parent::getName()}`

## Ԥ����

- #program warning
- #program push/pop
https://blog.csdn.net/Poo_Chai/article/details/89350054

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
	2. ����һ��ͷ�ļ�����cpp�ļ���includeͷ�ļ�

- class
	1. ��ͷ�ļ��ж��壬���ļ��ж���
	2. ע�⣺Class�޷�ʹ��extern�����鶨����hͷ�ļ��С���Ϊclass���ڴ��С�޷�ȷ��

- basic
	1. �������ݱ������������ļ��ж���ģ�����ͨ��externȥ����ʹ��
	2. Ҳ������ͷ�ļ��ж��壬������static���������ʾ�ظ��������
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

## IO

- TODO: cin/cout/clog/cerr����-������

## [STL](https://blog.csdn.net/weixin_53332395/article/details/123948946) 

## ����ĵ�

- [new��deleteʵ��ԭ��](https://www.php.cn/blog/detail/31237.html)

## TODO:

- ����ת��
- ��������
- �ƶ����캯��
- constָ�����
- constexpr
- union
- explicit
- ����float fnName() const {}