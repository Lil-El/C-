#include <iostream>
#include <thread>
/*
#include <chrono>
#include <functional>
#include <atomic>*/
/*
	https://zhuanlan.zhihu.com/p/340201634 
	https://www.runoob.com/w3cnote/cpp-std-thread.html 
*/
/*
* 存储类型thread_local：具有线程周期，可以和static、extern配合使用
* 如果不加thread_local，那么g被所有线程共享
* 否则，每个线程单独有一个g
*/
thread_local int g = 100;

void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing." << g << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing. " << g << std::endl;
        ++n;
        ++g;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void thread_main_81()
{
    g = 9;
    std::cout << "g: " << g << std::endl;

    int n = 0;
    std::thread t1; // 不是线程
    std::thread t2(f1, n + 1); // 值
    std::thread t3(f2, std::ref(n)); // 引用
    std::thread t4(std::move(t3)); // t4运行f2(),t3不再是一个thread
    // join():主线程会阻塞，当子线程执行结束后，主线程才会继续执行
    // detach():将主线程和子线程分离，分离后，主线程无法控制子线程，子线程转为后台线程，子线程将由系统(运行时库)托管。
    // 其后，子线程的“死活”就和主线程无关。子线程结束后，由系统自动释放其资源。即守护线程。
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
}