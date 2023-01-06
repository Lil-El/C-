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

/*
构造函数：std::mutex不允许拷贝构造，也不允许move拷贝，最初产生的mutex对象是处于unlocked状态的。
lock()：调用线程将锁住该互斥量，线程调用该函数会发生以下3种情况：
	（1）如果该互斥量当前没有被锁住，则调用线程将该互斥量锁住，直到调用unlock之前，该线程一直拥有该锁。
	（2）如果当前互斥量被其他线程锁住，则当前的调用线程被阻塞住。
	（3）如果当前互斥量被当前调用线程锁住，则会产生死锁,，也就是说同一个线程中不允许锁两次。
unlock()：解锁，释放对互斥量的所有权。
*/

mutex m1;
recursive_mutex m2;

void mutext_thread() {
	/*
	  try_lock()：尝试锁住互斥量，如果互斥量被其他线程占有，则当前线程也不会被阻塞，线程调用该函数会出现下面3种情况：
		（1）如果当前互斥量没有被其他线程占有，则该线程锁住互斥量，直到该线程调用unlock释放互斥量。
		（2）如果当前互斥量被其他线程锁住，则当前调用线程返回false，而并不会被阻塞掉。
		（3）如果当前互斥量被当前调用线程锁住，则会产生死锁。
	*/
	if (m1.try_lock()) {
		//m1.lock(); 多次lock造成死锁
		// throw "err"; 抛出异常，也导致死锁
		for (int i = 0; i < 10; i++) {
			cout << "i:" << i << endl;
		}
		m1.unlock(); // 必须在本线程中解锁，和lock配对。不能再其他线程中解锁mutex
	}
	else {
		cout << "mutex is locked." << endl;
	}
}

void mutext_thread1() {
	if (m2.try_lock()) {
		m2.lock(); // 多次lock也不会死锁，但需要和unlock配对，锁两次就要解两次
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
	* RAII思想
	* lock_guard对象构造时，自动调用mtx.lock()进行上锁
	* lock_guard对象析构时，自动调用mtx.unlock()释放锁
	*/
	lock_guard<mutex> lg(m1); // 第二个参数adopt_lock：已经上锁状态，不需要重复调用lock函数；需要保证第一个参数mutext是上锁状态
	for (int i = 0; i < 10; i++) {
		cout << "k:" << i << endl;
	}
}

void mutext_thread3() {
	/*
	* unique_lock相比于lock_guard，都是基于RAII思想的，也支持std::lock_guard的功能，但是区别在于它提供更多的成员函数，
	* 比如：lock(),unlock()使用更加灵活，并且可以和condiction_variable一起使用控制线程同步。
	* 
	* try_to_lock：不会阻塞等待一个线程执行结束，可以执行其他代码
	*/
	unique_lock<mutex> lg(m1, try_to_lock);
	// true表示可以上锁，当前处于unlock状态
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
	//m1.lock(); // 会阻塞thread函数执行
	thread t1(mutext_thread);
	/*thread t2(mutext_thread1);
	thread t3(mutext_thread2);*/
	thread t4(mutext_thread3);

	t1.join(); // join阻塞主线程，否则t1没执行结束，就return了，导致mutex在lock状态下报错
	//t2.join();
	//t3.join();
	t4.join();
}