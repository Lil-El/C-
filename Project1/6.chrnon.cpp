#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

/*
* chrono是c++ 11中的时间库,提供计时,时钟等功能。
*/
void chrono_main() {
	/*
	* 精度：
	*	ratio<60, 1>                      minute
		ratio<1, 1>                       second
		ratio<1, 1000>               microsecond
	*/
	cout << "毫秒精度：" << chrono::milliseconds::period::num << "/" << chrono::milliseconds::period::den << "s" << endl;

	// duration 时间段 -> seconds、minutes等
	chrono::milliseconds ms(1000);
	cout << "1000毫秒等于" << ms.count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den << "s" << endl;

	chrono::seconds s = chrono::duration_cast<chrono::seconds>(ms);
	cout << "1000毫秒等于" << s << endl;

	/* <Clock, Duration>
	 * system_clock: 系统时钟，不稳定，时钟可以调节
	 * 稳定时钟 std::chrono::steady_clock
	 * std::chrono::high_resolution_clock 是标准库中提供的具有最小节拍周期(因此具有最高的精度的时钟)
	 * 
	 * to_time_t() time_point转换成time_t秒
	 * from_time_t() 从time_t转换成time_point
	 * 
	*/
	chrono::time_point<chrono::system_clock, chrono::seconds> tp(chrono::minutes(1));
	cout << tp.time_since_epoch().count() << endl; // time_since_epoch：获取时间原点到时间点的距离
	time_t t = chrono::system_clock::to_time_t(tp);
	char a[50];
	ctime_s(a, sizeof(a), &t);
	cout << a << endl;

	// now
	chrono::time_point<chrono::system_clock, chrono::milliseconds> tp1 = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
	cout << tp1.time_since_epoch() << endl;

	// 时间差
	chrono::system_clock::time_point time1 = chrono::system_clock::now();
	for (int i = 0; i < 10000000; i++) {}
	chrono::system_clock::time_point time2 = chrono::system_clock::now();
	chrono::milliseconds dur1 = chrono::duration_cast<chrono::milliseconds>(time2 - time1);
	cout << "时间差：" << dur1.count() << endl;
}