#include <iostream>
#include <thread>
using namespace std;

/*
* this_thread {
*   get_id
*   yield ��ǰ�̷߳���ִ�У�����ϵͳ������һ�̼߳���ִ�С�
*   sleep_for �߳�����ĳ��ָ����ʱ��Ƭ(time span)�����̲߳ű����»��ѣ����������̵߳��ȵ�ԭ��ʵ������ʱ����ܱ� sleep_duration ����ʾ��ʱ��Ƭ������
*   sleep_until �߳�������ĳ��ָ����ʱ��(time point)�����̲߳ű����»��ѡ�
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
    this_thread::sleep_until(tp); // �ȴ�5s��������ִ��

    std::thread t1(thread5_f1); // ֵ
    cout << boolalpha << "t1 �Ƿ���Ա�join? " << t1.joinable() << endl;
    t1.join();
}