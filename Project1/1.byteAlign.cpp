/*
* struct��class�ֽڶ��룺
* #program pack(1,2,4,8,16)�������ֽڶ���
*  _declspec(align(1,2,4,8,16))�����ֽڶ���
*/
#include<iostream>
#include<iomanip>
using namespace std;

/*
	sizeof(ByteAlignStruct) != sizeof(a) + b + ...; ����ȵ�ԭ�������Ϊ�ֽڶ���
	��ַƫ��1����ʾռ1���ֽ�

	�ֽڶ��룺
		����ƽ̨���ڴ洦��ͬ��Ϊ�˱�֤����ƽ̨�϶�������ȷ���棬��Ҫʹ�ֽڶ��뱣��һ�£�
		ͬʱ���Ч�ʣ�32λϵͳһ�ζ�ȡ4�ֽڣ�һ��intֵ����0-4��ַ����һ�ζ�ȡ���������������2-6����ô����Ҫ������

	Ҫ�ж�һ���ṹ����ռ�Ŀռ��С��������˵�������ߣ�
	1.��ȷ��ʵ�ʶ��뵥λ�����������������ؾ�
		1> CPU����
			WIN  vs  qt  Ĭ��8�ֽڶ���
			Linux 32λ Ĭ��4�ֽڶ��룬64λĬ��8�ֽڶ���
		2> �ṹ������Ա(�����������ͱ���)
		3> Ԥ����ָ��#pragma pack(n)�ֶ�����     n--ֻ����1 2 4 8 16
			��������ȡ��С��,����ʵ�ʶ��뵥λ(����ġ�ʵ�ʶ��뵥λ������Ϊ�˷����������ȡ�ĸ���)
	2.���ṹ��ĵ�һ����Ա�⣬�������еĳ�Ա�ĵ�ַ����ڽṹ���ַ(�����׸���Ա�ĵ�ַ)��ƫ��������Ϊʵ�ʶ��뵥λ�������С��������(ȡ������С���Ǹ�)
	3.�ṹ��������С����Ϊʵ�ʶ��뵥λ����������

	��struct {
		char a,
		int b,
		char c,
		int d
	}
	windowsĬ���ֽڶ�����8
	a���������ֵ��1��ָ������ֵ��8��1 < 8��������Ч����ֵ��1����ַ0x0001��1��������������ռһ���ֽ�
	b���������ֵ��4��ָ����������8��4 < 8��������Ч��������4����ַ0x0002����4����������0x0004����������0x002-0x003�Զ������ֽ���䣬����b����0x0004-7��λ�ã�ռ4�ֽ�
	c��ͬ����0x0008λ�ã�ռ1�ֽ�
	d��ͬ����0x0009λ�ã�ռ1�ֽ�
	���ڽṹ��������С������Ա��ռ�ֽڵ���������4������������ǰ��9��������Ҫ��9֮�����3���ֽ���0x0012������sizeof == 12
*/
// ���Ͷ���
//#pragma pack(4)
typedef struct ByteAlignStruct {
	char a;
	int b;
	char c;
	char d;
} ST;

// ����struct��ͬʱʵ����struct = instance
struct {
	char a;
	int b;
	char c;
	char d;
} instance;

void byteAlign_main() {
	instance.a = '1';
	instance.b = 1;
	instance.c = '2';
	instance.d = '3';

	cout << sizeof(instance) << endl;
	cout << "instance: " << &instance << endl;
	cout << "instance.a: " << &instance.a << endl;
	cout << "instance.b: " << &instance.b << endl;
	cout << "instance.c: " << &instance.c << endl;
	cout << "instance.d: " << &instance.d << endl;
}