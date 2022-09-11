#include<iostream>
using namespace std;

void point_main() {
	// ��C�У�NULL == ((void *)0); ������C++��void*������ʽת�����������͵�ָ��
	// ���ԣ�C++��NULL == 0
	/* if __cplusplus
		#define NULL 0
		else
		#define NULL ((void*)0)
	*/
	// C++NULL==0���ں���������Ӱ���(C��û�к�������)��
	/*
		func(void * i); 1
		func(int i);    2
		func(NULL)  Ŀ��������ִ��1������ִ�е���2����
		func(nullptr)  ִ�е���1����
		Ϊ�˽��������⣬����nullptr
	*/
	int *a = 0;
	int *b = NULL; // NULL === 0
	int *c = nullptr; // C++11���� nullptr
	/*
	* ģ��nullptr��ʵ��
		const class nullptr_t_t
		{
			public:
				template<class T>           operator T*() const {return 0;}
				template<class C, class T>  operator T C::*() const { return 0; }
			private:
				void operator& () const;
		} nullptr_t = {};
		#undef NULL
		#define NULL nullptr_t
	*/
	// T C::*�ǳ�Աָ�룬��������ָ�����Ա��
	/*
	* ��Աָ��Ӧ�ã�
		struct C { int foo; int bar; };
		C valc;
		int C::*pmbr=nullptr;
		int x=0;

		pmbr=&C::foo;
		pmbr=&C::bar;
		valc::*pmbr=-1;
		std::swap(valc::*pmbr, x);
	*/
	int arr[5]{ 1,2,3,4,5 }; // arr��һ������ָ�룬�����Ե������ʶ�Ҳ���ܸ�arr���¸�ֵ
	int *arr_point = arr;
	// ָ��������ݼ�
	arr_point++;
	cout << *(arr_point) << endl;
	// ָ��Ƚ�
	bool flag = 1 < 0;
	cout << boolalpha; // ����boolalpha�������true false
	cout << flag << endl;
	cout << noboolalpha; // ����noboolalpha������0��1
	cout << (arr < arr_point) << endl;

	// ָ������
	int a1 = 1;
	int *pa1 = &a1;
	const int *point_arr[] = { pa1 };

	// ָ��ָ���ָ��
	int b1 = 1;
	int *pb1 = &b1;
	int **p_pb1 = &pb1;

}