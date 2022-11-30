#include <iostream>

// const���α���
extern const int AGE = 99324;

/*
* const���κ�����
* ����������ͨ������`void xx() const{}` �Ǵ����
* ֻ������class��Ա����������const���������޸����еı�����
*/
class ConstClass {
private:
	int age;
public:
	ConstClass(int num): age(num) {}
	int getAge() const {
		return age;
	}
	void setDefaultAge() {
		age = AGE;
	}
	int setAge(int num) const {
		// age = num;       // error: const���εĺ��������޸ĳ�Ա������
		// setDefaultAge(); // error: ������������ const ��Ա����
	}
};

void const_main() {
	/*
	* const����ָ�룺
	* �ټǣ�
	* �ܶ�ʱ�����Ƿֲ���const������������ָ�뱾����ָ����ָ��Ķ��󣬻��ڴˣ����ǿ���ͨ����const�ұ��Ǳ��������������������б�
		������
		�����p1,����const�ұ�����������int�����Ը�const������ָ����ָ��Ķ���
		�����p2,����const�ұ���ָ��p2�����Ը�const������ָ�뱾��
	*/
	int a = 1;
	int b = 2;
	const int* ap = &a; // const���ζ���ָ������޸ģ�����ֵ���ܸ�
	ap = &b;
	// *ap = 33; error.
	int* const bp = &b; // const����ָ�룺ָ�벻�����޸ģ�����ֵ���Ը�
	*bp = 99;
	// bp = &a; error.
}