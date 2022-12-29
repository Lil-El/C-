#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

/*
* chrono��c++ 11�е�ʱ���,�ṩ��ʱ,ʱ�ӵȹ��ܡ�
*/
void chrono_main() {
	/*
	* ���ȣ�
	*	ratio<60, 1>                      minute
		ratio<1, 1>                       second
		ratio<1, 1000>               microsecond
	*/
	cout << "���뾫�ȣ�" << chrono::milliseconds::period::num << "/" << chrono::milliseconds::period::den << "s" << endl;

	// duration ʱ��� -> seconds��minutes��
	chrono::milliseconds ms(1000);
	cout << "1000�������" << ms.count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den << "s" << endl;

	chrono::seconds s = chrono::duration_cast<chrono::seconds>(ms);
	cout << "1000�������" << s << endl;

	/* <Clock, Duration>
	 * system_clock: ϵͳʱ�ӣ����ȶ���ʱ�ӿ��Ե���
	 * �ȶ�ʱ�� std::chrono::steady_clock
	 * std::chrono::high_resolution_clock �Ǳ�׼�����ṩ�ľ�����С��������(��˾�����ߵľ��ȵ�ʱ��)
	 * 
	 * to_time_t() time_pointת����time_t��
	 * from_time_t() ��time_tת����time_point
	 * 
	*/
	chrono::time_point<chrono::system_clock, chrono::seconds> tp(chrono::minutes(1));
	cout << tp.time_since_epoch().count() << endl; // time_since_epoch����ȡʱ��ԭ�㵽ʱ���ľ���
	time_t t = chrono::system_clock::to_time_t(tp);
	char a[50];
	ctime_s(a, sizeof(a), &t);
	cout << a << endl;

	// now
	chrono::time_point<chrono::system_clock, chrono::milliseconds> tp1 = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
	cout << tp1.time_since_epoch() << endl;

	// ʱ���
	chrono::system_clock::time_point time1 = chrono::system_clock::now();
	for (int i = 0; i < 10000000; i++) {}
	chrono::system_clock::time_point time2 = chrono::system_clock::now();
	chrono::milliseconds dur1 = chrono::duration_cast<chrono::milliseconds>(time2 - time1);
	cout << "ʱ��" << dur1.count() << endl;
}