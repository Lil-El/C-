#include <iostream>
using namespace std;

template <class _Ty>
_Ty&& mforward(remove_reference_t<_Ty>& _Arg) { 
	return static_cast<_Ty&&>(_Arg);
}

void rightReferenceForward(int&& arg) {
	cout << "right" << endl;
}
void rightReferenceForward(int& arg) {
	cout << "left" << endl;
}

/*
* �������ã�
* ��������һ������������������ֵ����ģ�����ͻᱻ�Ƶ�����ֵ�������ͣ� ���������ֵ����ģ�����;���ֵ������
* 
* forward������ֵ��Ϊ��ֵ����ֵ����ת��������ֵ����ת��
* remove_reference_t: ������������÷��ŵ�����T
*    
	template <class _Ty>
		_Ty&& forward(remove_reference_t<_Ty>& _Arg) { // forward an lvalue as either an lvalue or an rvalue
		return static_cast<_Ty&&>(_Arg);
	}
* 
* �Ƶ��۵���
*   Base&& && -> Base&&
	Base& &&  -> Base&
	Base&& &  -> Base&
	Base& &   -> Base& 
* 
* ʵ�Σ�99
* T �� int&&
* ����forward<int&&>��_Ty �� int&&��_Arg��int&& &��_Ty&& �� int&& &&
* ���������۵���int&& &&����int&&
* 
* * ʵ�Σ�x
* T �� int&
* ����forward<int&>��_Ty �� int&��_Arg��int& &��_Ty&& �� int& &&
* ���������۵���int& &&����int&
*/
template <typename T>
void rightReferenceForward_t(T&& arg) {
	// ��ʹ�ù����У�arg�Զ��Ƶ�����TΪint&&�ˡ����Ǻ���ʹ����arg���˻�Ϊ��ֵ��
	// ����arg��Ȼ����ֵ���ã���Ҳ����ֵ������ int& x = ��ֵ���á�

	//rightReferenceForward(arg); // error. �޷���Tת��Ϊint&&��arg����ֵ��ͳһ������left����

	// ʹ��forward������ת��������arg����ֵ������T�ֱ���int&��int&&
	rightReferenceForward(static_cast<T>(arg)); // ������һ��
	rightReferenceForward(mforward<T>(arg));  // ������һ��
}

/*
* ��ֵ��һ���ڴ�ʵ�壬����&�����Դ��ںܾ�
  ��ֵû���ڴ�ʵ�壬ֻ����ʱ�ģ���һ�ξͲ�����
  ��������ֵ��10�ȣ�������ʱ���߽���ֵ����һ�ξͲ���ʹ����

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
	* _Ty&&��ʾ�������ã����Դ�int&��int&&��const����const��ȥ�Ƶ�_Ty����
	* ���ԣ���ģ���в���ֱ�ӷ���_Ty&&����Ϊ�����������ã�����ͨ��struct::type��תΪ��ֵ����
	*/
	int&& y = move(x);

	/*
	* ��ֵ����ֻ���Գ�ʼΪ��ֵ
	* ������ֵ����ֻ���Գ�ʼΪ������ֵ
	* const��ֵ���ÿ��Գ�ʼΪ����ֵ��const����const
	* ��ͨ��ֵ���ÿ��Գ�ʼΪ��ͨ��ֵ�����ǳ�����ֵ���ã�
	*/
	//int& z = x + x; error. �ǳ������ó�ʼֵ��������ֵ
	const int& z = x + x;
	int& z1 = y; // y����ֵ���ã���Ҳ����ֵ�����Կ���ʹ����ֵ����
	int&& a = x + z;
	a += 1;

	// static_cast������ʾ�Ľ���ֵתΪ��ֵ
	int&& rx1 = static_cast<int&&>(x); 

	// remove_reference_t������֪�����Ƴ����ã�int&/int&&������int
	remove_reference_t<int&>&& r1 = 10;
	remove_reference_t<int&&>&& r2 = 10;

	rightReferenceForward_t(x);  // ������ֵ���� left
	rightReferenceForward_t(99); // ������ֵ���� right
}