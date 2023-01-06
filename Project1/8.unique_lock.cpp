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


// ��lock_guard��������Ч�ʻ��һ�㣬�ڴ��ռ��Ҳ���һ��
mutex m;
/*
* adopt_lock����ʾ�������Ѿ���lock
* try_to_lock���������ס�ˣ������������������ȴ�����������ȥִ������û�б����Ĵ��롣
* defer_lock����ʾ��ʱ�Ȳ�lock��֮���ֶ�ȥlock������ʹ��֮ǰҲ�ǲ�����ȥlock��һ����������unique_lock�ĳ�Ա����ȥʹ��
*/

/*
* unique_lock����Ȩ��
	std::unique_lock<std::mutex> munique1(m);
	std::unique_lock<std::mutex> munique2(std::move(munique1));
	// ��ʱmunique1ʧȥmlock��Ȩ�ޣ���ָ���ֵ��munique2��ȡmlock��Ȩ��

	��Խunique_lock�Ķ�����˵��һ������ֻ�ܺ�һ��mutex��Ψһ��Ӧ�����ܴ���һ�Զ���߶��һ���������Ȼ����������ĳ��֡�
	���������Ҫ��������unique_lock�����mutex��Ȩ�ޣ���Ҫ���õ��ƶ���������ƶ����캯�����ַ�����
*/

void unique_lock_thread1() {
	unique_lock<mutex> m1(m, defer_lock);
	m1.lock();
	for (int i = 0; i < 10; i++) {
		cout << "i:" << i << endl;
	}
	m1.unlock(); // ������Բ���unlock������ͨ��unique_lock����������unlock
}

void unique_lock_thread2() {
	try
	{
		unique_lock<mutex> m1(m, defer_lock);
		//m1.lock(); // error��lock����ownsΪtrue��try_lock�����У�飬����owns�Ѿ�Ϊtrue�ˣ����׳��쳣
		// �����������ɹ��˷���true������֮
		if (m1.try_lock()) {
			for (int i = 0; i < 10; i++) {
				cout << "j:" << i << endl;
			}
		}
		else {
			cout << "locking." << endl;
		}
		// �ͷ�m��m1����ϵ�����m���������ں����Լ��ֶ�unlock����
		mutex* mm = m1.release();
		mm->unlock();
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

void unique_lock_main() {
	thread t1(unique_lock_thread1);
	t1.join();
	thread t2(unique_lock_thread2);
	t2.join();
}