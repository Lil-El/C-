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
* �洢����thread_local�������߳����ڣ����Ժ�static��extern���ʹ��
* �������thread_local����ôg�������̹߳���
* ����ÿ���̵߳�����һ��g
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
    std::thread t1; // �����߳�
    std::thread t2(f1, n + 1); // ֵ
    std::thread t3(f2, std::ref(n)); // ����
    std::thread t4(std::move(t3)); // t4����f2(),t3������һ��thread
    // join():���̻߳������������߳�ִ�н��������̲߳Ż����ִ��
    // detach():�����̺߳����̷߳��룬��������߳��޷��������̣߳����߳�תΪ��̨�̣߳����߳̽���ϵͳ(����ʱ��)�йܡ�
    // ������̵߳ġ�����ͺ����߳��޹ء����߳̽�������ϵͳ�Զ��ͷ�����Դ�����ػ��̡߳�
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
}