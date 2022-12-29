#include <windows.h>
#include <iostream>
using namespace std;

/*
* C++语言本身并没有提供多线程机制（当然目前C++ 11新特性中，已经可以使用std::thread来创建线程了）
* 但Windows系统为我们提供了相关API，我们可以使用他们来进行多线程编程。
*/

#define MAX 100   //数组空间最大值

int arr[MAX];   //待排序的数组

typedef struct param {    //作为线程参数传入的结构体
	int *array;
	int start, end;
}param;

void swap(int *a, int *b)   //选择排序中用到的交换函数
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
* 线程函数，必须以如下格式进行定义。
* DWORD WINAPI xxx(){}
*/
DWORD WINAPI ThreadProc(LPVOID lpParameter)   //线程的回调函数
{   //进行选择排序
	cout << "子进程" << endl;
	param *p;
	p = (param *)lpParameter;  //将线程参数强制转化为所需类型
	int l = p->start, r = p->end;
	if (l >= r) return NULL;

	for (int i = l; i < r; i++)
	{
		int min = i;
		for (int j = i + 1; j <= r; j++)
			if (p->array[j] < p->array[min])
				min = j;
		swap(&p->array[min], &p->array[i]);
	}
	return 0L; // 0
}

void thread_main()
{
	int n;
	//处理输入、初始化
	cout << "please enter the length of the array:";
	cin >> n;
	cout << "please enter the element of the array:";
	for (int i = 0; i < n; i++) cin >> arr[i];

	HANDLE sortq, sorth;

	int mid = (0 + n - 1) >> 1;

	//sortq
	param paramq;
	paramq.array = arr;
	paramq.start = 0;             //[
	paramq.end = mid;             //]
	/*
		HANDLE CreateThread(
			LPSECURITY_ATTRIBUTES lpThreadAttributes,//SD：线程安全相关的属性，常置为NULL
			SIZE_T dwStackSize,//initialstacksize：新线程的初始化栈的大小，可设置为0
			LPTHREAD_START_ROUTINE lpStartAddress,//threadfunction：被线程执行的回调函数，也称为线程函数
			LPVOID lpParameter,//threadargument：传入线程函数的参数，不需传递参数时为NULL
			DWORD dwCreationFlags,//creationoption：控制线程创建的标志
					（1）CREATE_SUSPENDED(0x00000004)：创建一个挂起的线程（就绪状态），直到线程被唤醒时才调用
					（2）0：表示创建后立即激活。
					（3）STACK_SIZE_PARAM_IS_A_RESERVATION(0x00010000)：dwStackSize参数指定初始的保留堆栈的大小，
					如果STACK_SIZE_PARAM_IS_A_RESERVATION标志未指定，dwStackSize将会设为系统预留的值
			LPDWORD lpThreadId//threadidentifier：传出参数，用于获得线程ID，如果为NULL则不返回线程ID
		)
	*/
	sortq = CreateThread(NULL, 0, ThreadProc, &paramq, 0, NULL);   //创建线程，传入参数

	//sorth
	param paramh;
	paramh.array = arr;
	paramh.start = mid + 1;         //[
	paramh.end = n - 1;             //]
	sorth = CreateThread(NULL, 0, ThreadProc, &paramh, 0, NULL);   //创建线程，传入参数

	// 两个子进程先对前后部分分别进行排序，最后由主线程进行归并
	WaitForSingleObject(sortq, INFINITE);   //等待线程执行结束返回主线程
	WaitForSingleObject(sorth, INFINITE);   //等待线程执行结束返回主线程

	// 关闭线程、释放线程资源。不是终止线程。
	CloseHandle(sortq);
	CloseHandle(sorth);

	//主线程进行归并排序 
	cout << "主进程" << endl;
	int k = 0, i = 0, j = mid + 1;
	int temp[MAX];
	while (i <= mid && j <= n - 1)
	{
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= n - 1) temp[k++] = arr[j++];

	for (int i = 0, j = 0; j <= n - 1; j++, i++) arr[j] = temp[i];

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}