#include <iostream>
using namespace std;

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

/*
* constexpr������
* �����ķ������ͼ������β����Ͷ�������ֵ����
* ��������ֻ��һ��return ���
*/
constexpr int getNum(int n) {
	return n + 1;
}
consteval int getNum2(int n) {
	return n + 1;
}

/*
* constexpr���κ�������ʾ֧���ڱ�������ֵ���Ƿ�����ڱ�������ֵ����ȷ��������������Щʱ������Ҫ������ڱ�������ֵ��
* constevalֻ�����κ�����Ҫ���������ڱ�������ֵ��
*/
consteval int min(initializer_list<int> array)
{
	int low = numeric_limits<int>::max();
	for (auto& i : array)
	{
		if (i < low)
		{
			low = i;
		}
	}
	return low;
}

const char* GetStringDyn() {
	return "dynamic init";
}
constexpr const char* GetString(bool constInit) {
	return constInit ? "constant init" : GetStringDyn();
}

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

	/*
	* constexpr��constexpr���ʽ��ֵָ����ı䲢���ڱ�����̾Ϳ���ֵ�ı��ʽ��
	* ����Ϊconstexpr�ı���һ��const���������ұ����ó������ʽ��ʼ����
	*/

	// �������ʽ��ֵָ����ı䲢���ڱ�����̾��ܵõ�����ı��ʽ������ֵ���ó������ʽ��ʼ����const����Ҳ�ǳ������ʽ��
	// ����ֵ���ͣ��������͡����ú�ָ�붼��������ֵ���ͣ��Զ����ࡢIO�⣬string��������������ֵ���ͣ����ܱ������constexpr��
	// 1, c1, 2, d + c ���ǳ������ʽ
	const int c1 = 1;
	constexpr int c = c1; // ���c1����const���ᱨ��
	constexpr int d = 2;
	constexpr int e = d + c; 
	constexpr int f = getNum(1); // ����������constexpr��������

	constexpr int* cp = nullptr; // �޶���constexpr����ָ����Ч��ָ�벻�ܸģ�ֵ���Ը�
	constexpr const int* dp = nullptr; // ָ��Ͷ��󶼲��ܸ�

	// constinit���α�������֤�����ڱ����ڳ�ʼ����ֻ��ʹ��constexpr��consteval������ʼ��constinit����
	// thread_local: ����Ĵ洢���߳̿�ʼʱ���䣬�����߳̽���ʱ����䡣ÿ���߳�ӵ��������Ķ���ʵ��
	constinit thread_local int g = getNum(1); // static �� thread_local

	cout << "********" << endl;

	int nn = getNum(100);
	cout << ++nn << endl;
	//int nnn = getNum2(nn); ����-nn���ǳ���
	const int nn1 = getNum(100); // getNum��constexpr�ģ������Ҫ�ڱ�����ֵ����ônn1ҲӦ�ø�Ϊconstexpr�������������ִ����
	int nn2 = getNum2(nn1);
}
