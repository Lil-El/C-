#include <iostream>
#include <windows.h>
using namespace std;

/*
* 不同平台的不同sleep函数：
	Windows:
		windows.h -> Sleep(ms)
	Linux:
		unistd.h -> sleep(s)
		unistd.h -> usleep(us)
* 1s = 1000ms
* 1ms = 1000us
* sleep会阻塞主线程
*/

void high_sleep_main() {
	cout << "start" << endl;
	
	Sleep(3 * 1000);

	cout << "end" << endl;
}