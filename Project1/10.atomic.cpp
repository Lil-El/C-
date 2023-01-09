#include <iostream>
#include <atomic>
#include <ctime>
using namespace std;

/*
* atomic����ԭ�Ӳ������ڶ��߳�֮��Թ�����Դ����ʱ������ȷ��������ͬһʱ�����Դ���з��ʡ�
* ԭ�Ӳ����ӽ��ײ㣬Ч��Ҳ����
* 
* http://zhuanlan.zhihu.com/p/539229114
*/

void atomic_main() {
	int b = 0;
	atomic<int> a(100);
	a.fetch_add(12);
	a.fetch_sub(11);

	int value = a.load();
	cout << dec << value << endl; // 10����
	cout << oct << value << endl; // 8����
	cout << hex << value << endl; // 16����

	a.store(0);

	cout << "****************" << endl;

	clock_t start = clock();
	for (int i = 0; i < 10000000; i++) {
		a++;
	}
	clock_t end = clock();

	cout << "duration:" << dec << (end - start) << endl;
	cout << start << endl;
}