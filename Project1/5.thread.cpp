#include <iostream>
#include <thread>
using namespace std;

/*
* this_thread {
*   get_id
*   yield 当前线程放弃执行，操作系统调度另一线程继续执行。
*   sleep_for 线程休眠某个指定的时间片(time span)，该线程才被重新唤醒，不过由于线程调度等原因，实际休眠时间可能比 sleep_duration 所表示的时间片更长。
*   sleep_until 线程休眠至某个指定的时刻(time point)，该线程才被重新唤醒。
* }
*/
void thread5_f1()
{
    thread::id id = this_thread::get_id();
    cout << "fn1 id: " << id << endl;
    for (int i = 0; i < 10; ++i) {
        if (i > 6) {
            this_thread::yield();
        }
        cout << "fn1: " << i << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void thread5_main()
{
    chrono::seconds wait_seconds(5);
    chrono::time_point now = chrono::high_resolution_clock::now();
    chrono::duration after_duration = now.time_since_epoch() + wait_seconds;
    chrono::time_point<chrono::high_resolution_clock, chrono::seconds> tp(chrono::duration_cast<chrono::seconds>(after_duration));
    this_thread::sleep_until(tp); // 等待5s继续向下执行

    std::thread t1(thread5_f1); // 值
    cout << boolalpha << "t1 是否可以被join? " << t1.joinable() << endl;
    t1.join();
}