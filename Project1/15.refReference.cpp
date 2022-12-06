#include <iostream>
#include <functional>
using namespace std;

void ref_add(int& a, int& b) {
	a += 1;
	b += 1;
}

// reference_wrapperԭ���ǽ������������õĵ�ַ������reference_wrapper��ָ����
class reference_wrapper1 {
public:
	int* a;
	reference_wrapper1(int& arg) {
		a = addressof(arg);
	}
};

/*
* ref/reference_wrapper ��һ�����ð�װ��һ���ɿ����ģ��ɷ���Ķ���
* ��׼�����޷��洢���ã���Ҫ�����ý��а�װ
*/
void ref_main() {
	int a(1);
	reference_wrapper ra = ref(a);
	ra++; // 2

	int b{1};

	// bind�����Ƕ�ֵ�Ŀ����������޸�b����Ч����������ʱʹ��ref���д���
	// thread��Ҳһ��
	function<void()> fn = bind(ref_add, ra, b);
	fn();
	cout << a << " " << b << endl;
}