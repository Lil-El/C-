#include <iostream>
#include <windows.h>
using namespace std;

/*
* ��ͬƽ̨�Ĳ�ͬsleep������
	Windows:
		windows.h -> Sleep(ms)
	Linux:
		unistd.h -> sleep(s)
		unistd.h -> usleep(us)
* 1s = 1000ms
* 1ms = 1000us
* sleep���������߳�
*/

void high_sleep_main() {
	cout << "start" << endl;
	
	Sleep(3 * 1000);

	cout << "end" << endl;
}