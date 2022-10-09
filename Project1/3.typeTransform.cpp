#include<iostream>
using namespace std;

// ����ת��
void know_type_transform() {
	// ��ͨ��ʽ����ת��
	double age = 23.3;
	int age_t = (int)age; // C��������ת��
	int age_t_2 = int(age);
	cout << boolalpha << (age_t == age_t_2) << endl; // 23

	// ���ַ�ʽת��
	/*
	static_case:
		1. ��Ҫ����������������֮����໥ת����
		2. static_castֻ�������໥��ϵ���̳У������ͼ����ת�����Ҳ�һ�������麯����
		3. ��voidָ��ת��Ϊָ�����͵�ָ��
	*/
	double age2 = 23.4;
	int age2_t = static_cast<int>(age2);

	int a = 12;
	int *a_p = &a;
	void *v_p = static_cast<void *>(a_p); // ����ָ��void*
	double *d_p = static_cast<double *>(v_p);

	/*
		const_cast: 
			����ȥ��const�ؼ��֣�ֻ�����ָ�롢����
			const���Ͳ�����ֱ������ָ��
			���е�const��Ա�����еĳ�Ա�����ǲ����Ա��ı�ģ�const_castҲ����������ȥ������Ա�����б�����const���ƣ�ʹ�������Ա��޸ġ�
	*/
	const int name = 12.3;
	int *n_p = const_cast<int *>(&name);
	int &n_y = const_cast<int &>(name);

	/*
		dynamic_cast: �����麯������������֮���ָ������õ�ת����ʹ�õ�ǰ����Ǳ���Ҫ���麯�����ж��⿪�����Ǳ�Ҫ�����á�
		ת��ʧ��ʱ����nullptr
	*/

	//reinterpret_cast: ������C������ʾǿ��ת���������ڼ�飬�ڱ���׶�ֱ��ת����ǿ�Ƹ�ֵ����δ֪�Ƿ�����Һ���Ը�������ʹ�á�
	int n = 1;
	int *p = reinterpret_cast<int *>(n);
	char *pCh = reinterpret_cast<char *>(p);

}