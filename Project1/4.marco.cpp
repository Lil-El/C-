#include <iostream>
using namespace std;
/*
	#include<>��ʾʹ��ϵͳ�ļ�
	#include""��ʾʹ���Լ����ļ�
	����.h�Ǿ�д��
	�µı�׼ʹ��ͷ�ļ����Բ���.h��
*/

/*
	��C�����У������ú�������ִ��Ч�ʡ�����뱾���Ǻ�������ʹ������������
	Ԥ�������ø��ƺ����ķ�ʽ���溯�����ã�ʡȥ�˲���ѹջ�����ɻ�����Ե�CALL���á�����������ִ��return�ȹ���.�Զ�������ٶȡ�(���⺯����˼, ��߳���Ч��)
*/

// #define�����
#define Mino_Marco

// �պ꣬ûʲô����
#define ABC(args, ...)

void know_marco_main() {
	// __has_include���ж��Ƿ���include iostream������
	#if __has_include(<iostream>)
	#include <iostream>
		using namespace std;
		#define _MINO_STD ::std::
	#else
		cout << "error" << endl;
	#endif

	// defined()�ж��Ƿ����˺�
	#if defined(Mino_Marco) && ABC
		cout << "Mino" << _MINO_STD endl;
	#endif
}