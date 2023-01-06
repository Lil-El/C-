#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
* ���������������������ͣ�
	std::mutex���������mutex�ࡣ
	std::recursive_mutex���ݹ�mutex�࣬�ܶ����������������
	std::time_mutex����ʱmutex�࣬��������һ����ʱ�䡣
	std::recursive_timed_mutex����ʱ�ݹ�mutex�ࡣ

���⣬���ṩ�����������ͣ�
	std::lock_guard�������̶߳Ի�����������
	std::unique_lock�������̶߳Ի��������������ṩ�˸��õ������ͽ������ơ�

�Լ���صĺ�����
	std::try_lock������ͬʱ�Զ��������������
	std::lock������ͬʱ�Զ��������������
	std::call_once���������߳���Ҫͬʱ����ĳ��������call_once���Ա�֤����̶߳Ըú���ֻ����һ�Ρ�
*/

/*
���캯����std::mutex�����������죬Ҳ������move���������������mutex�����Ǵ���unlocked״̬�ġ�
lock()�������߳̽���ס�û��������̵߳��øú����ᷢ������3�������
	��1������û�������ǰû�б���ס��������߳̽��û�������ס��ֱ������unlock֮ǰ�����߳�һֱӵ�и�����
	��2�������ǰ�������������߳���ס����ǰ�ĵ����̱߳�����ס��
	��3�������ǰ����������ǰ�����߳���ס������������,��Ҳ����˵ͬһ���߳��в����������Ρ�
unlock()���������ͷŶԻ�����������Ȩ��
*/

mutex m1;
recursive_mutex m2;

void mutext_thread() {
	/*
	  try_lock()��������ס������������������������߳�ռ�У���ǰ�߳�Ҳ���ᱻ�������̵߳��øú������������3�������
		��1�������ǰ������û�б������߳�ռ�У�����߳���ס��������ֱ�����̵߳���unlock�ͷŻ�������
		��2�������ǰ�������������߳���ס����ǰ�����̷߳���false���������ᱻ��������
		��3�������ǰ����������ǰ�����߳���ס��������������
	*/
	if (m1.try_lock()) {
		//m1.lock(); ���lock�������
		// throw "err"; �׳��쳣��Ҳ��������
		for (int i = 0; i < 10; i++) {
			cout << "i:" << i << endl;
		}
		m1.unlock(); // �����ڱ��߳��н�������lock��ԡ������������߳��н���mutex
	}
	else {
		cout << "mutex is locked." << endl;
	}
}

void mutext_thread1() {
	if (m2.try_lock()) {
		m2.lock(); // ���lockҲ��������������Ҫ��unlock��ԣ������ξ�Ҫ������
		for (int i = 0; i < 10; i++) {
			cout << "j:" << i << endl;
		}
		cout << "unlock" << endl;
		m2.unlock();
		m2.unlock();
	}
	else {
		cout << "mutex is locked." << endl;
	}
}

void mutext_thread2() {
	/*
	* RAII˼��
	* lock_guard������ʱ���Զ�����mtx.lock()��������
	* lock_guard��������ʱ���Զ�����mtx.unlock()�ͷ���
	*/
	lock_guard<mutex> lg(m1); // �ڶ�������adopt_lock���Ѿ�����״̬������Ҫ�ظ�����lock��������Ҫ��֤��һ������mutext������״̬
	for (int i = 0; i < 10; i++) {
		cout << "k:" << i << endl;
	}
}

void mutext_thread3() {
	/*
	* unique_lock�����lock_guard�����ǻ���RAII˼��ģ�Ҳ֧��std::lock_guard�Ĺ��ܣ����������������ṩ����ĳ�Ա������
	* ���磺lock(),unlock()ʹ�ø��������ҿ��Ժ�condiction_variableһ��ʹ�ÿ����߳�ͬ����
	* 
	* try_to_lock�����������ȴ�һ���߳�ִ�н���������ִ����������
	*/
	unique_lock<mutex> lg(m1, try_to_lock);
	// true��ʾ������������ǰ����unlock״̬
	if (lg.owns_lock()) {
		for (int i = 0; i < 10; i++) {
			cout << "l:" << i << endl;
		}
	}
	else {
		cout << "lock ing." << endl;
	}
}
void mutex_main() {
	//m1.lock(); // ������thread����ִ��
	thread t1(mutext_thread);
	/*thread t2(mutext_thread1);
	thread t3(mutext_thread2);*/
	thread t4(mutext_thread3);

	t1.join(); // join�������̣߳�����t1ûִ�н�������return�ˣ�����mutex��lock״̬�±���
	//t2.join();
	//t3.join();
	t4.join();
}