#include <iostream>
#include <atomic>
#include <ctime>
using namespace std;

/*
* atomic就是原子操作，在多线程之间对共享资源访问时，可以确保不会再同一时间对资源进行访问。
* 原子操作接近底层，效率也更高
* 
* http://zhuanlan.zhihu.com/p/539229114
*/

void atomic_main() {
	int b = 0;
	atomic<int> a(100);
	a.fetch_add(12);
	a.fetch_sub(11);

	int value = a.load();
	cout << dec << value << endl; // 10进制
	cout << oct << value << endl; // 8进制
	cout << hex << value << endl; // 16进制

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