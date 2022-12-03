#include <iostream>
#include <thread>
/*
#include <chrono>
#include <functional>
#include <atomic>*/

/*
* 存储类型thread_local：具有线程周期，可以和static、extern配合使用
* 如果不加thread_local，那么g被所有线程共享
* 否则，每个线程单独有一个g
*/
thread_local int g = 100;

void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing." << std::endl;
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
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
}