#include <iostream>
using namespace std;
/*
* ��ֵ��һ���ڴ�ʵ�壬����&�����Դ��ںܾ�
  ��ֵû���ڴ�ʵ�壬ֻ����ʱ�ģ���һ�ξͲ�����

* �ƶ����캯�����ƶ���ֵ������ʹ��
*/

void rightReference_main() {
	int x = 10; // x����ֵ��10����ֵ
	const int& lx = x; // ��ֵ����
	//int& rx = 10; error. ֻ�ܶ���ֵ��������
	//lx += 1; error. const�����޷��޸�

	//int&& lx = x; error. ֻ�ܶ���ֵ���а�
	int&& rx = 10; // ��ֵ����

	/*
	* moveǿ�ƽ���ֵתΪ��ֵ
	* static_cast<remove_reference_t<_Ty>&&>(_Arg)
	*/
	int&& y = move(x);
	/*
	* ��ֵ����ֻ���Գ�ʼΪ��ֵ��������
	* const��ֵ���ÿ��Գ�ʼΪ����ֵ
	* ��ͨ��ֵ���ÿ��Գ�ʼΪ��ͨ��ֵ
	*/
	//int& z = x + x; error. �ǳ������ó�ʼֵ��������ֵ
	const int& z = x + x;
	int& z1 = y; // y����ֵ���ã���Ҳ����ֵ�����Կ���ʹ����ֵ����
	int&& a = x + z;
	a += 1;
}