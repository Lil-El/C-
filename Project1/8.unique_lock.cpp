#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
* 互斥量，共包含四种类型：
	std::mutex：最基本的mutex类。
	std::recursive_mutex：递归mutex类，能多次锁定而不死锁。
	std::time_mutex：定时mutex类，可以锁定一定的时间。
	std::recursive_timed_mutex：定时递归mutex类。

另外，还提供了两种锁类型：
	std::lock_guard：方便线程对互斥量上锁。
	std::unique_lock：方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。

以及相关的函数：
	std::try_lock：尝试同时对多个互斥量上锁。
	std::lock：可以同时对多个互斥量上锁。
	std::call_once：如果多个线程需要同时调用某个函数，call_once可以保证多个线程对该函数只调用一次。
*/


// 比lock_guard更灵活，但是效率会第一点，内存的占用也会大一点
mutex m;
/*
* adopt_lock：表示互斥量已经被lock
* try_to_lock：如果被锁住了，它不会在那里阻塞等待，它可以先去执行其他没有被锁的代码。
* defer_lock：表示暂时先不lock，之后手动去lock，但是使用之前也是不允许去lock。一般用来搭配unique_lock的成员函数去使用
*/

/*
* unique_lock所有权：
	std::unique_lock<std::mutex> munique1(m);
	std::unique_lock<std::mutex> munique2(std::move(munique1));
	// 此时munique1失去mlock的权限，并指向空值，munique2获取mlock的权限

	对越unique_lock的对象来说，一个对象只能和一个mutex锁唯一对应，不能存在一对多或者多对一的情况，不然会造成死锁的出现。
	所以如果想要传递两个unique_lock对象对mutex的权限，需要运用到移动语义或者移动构造函数两种方法。
*/

void unique_lock_thread1() {
	unique_lock<mutex> m1(m, defer_lock);
	m1.lock();
	for (int i = 0; i < 10; i++) {
		cout << "i:" << i << endl;
	}
	m1.unlock(); // 这里可以不用unlock，可以通过unique_lock的析构函数unlock
}

void unique_lock_thread2() {
	try
	{
		unique_lock<mutex> m1(m, defer_lock);
		//m1.lock(); // error：lock设置owns为true，try_lock会进行校验，发现owns已经为true了，会抛出异常
		// 尝试锁，锁成功了返回true，否则反之
		if (m1.try_lock()) {
			for (int i = 0; i < 10; i++) {
				cout << "j:" << i << endl;
			}
		}
		else {
			cout << "locking." << endl;
		}
		// 释放m和m1的联系，如果m被锁，需在后面自己手动unlock解锁
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