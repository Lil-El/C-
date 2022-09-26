#include <windows.h>
#include <iostream>
using namespace std;

#define MAX 100   //����ռ����ֵ

int arr[MAX];   //�����������

typedef struct param {    //��Ϊ�̲߳�������Ľṹ��
	int *array;
	int start, end;
}param;

void swap(int *a, int *b)   //ѡ���������õ��Ľ�������
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

DWORD WINAPI ThreadProc(LPVOID lpParameter)   //�̵߳Ļص�����
{   //����ѡ������
	cout << "�ӽ���" << endl;
	param *p;
	p = (param *)lpParameter;  //���̲߳���ǿ��ת��Ϊ��������
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
	return 0L;
}

void thread_main()
{
	int n;
	//�������롢��ʼ��
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
	sortq = CreateThread(NULL, 0, ThreadProc, &paramq, 0, NULL);   //�����̣߳��������

	//sorth
	param paramh;
	paramh.array = arr;
	paramh.start = mid + 1;         //[
	paramh.end = n - 1;             //]
	sorth = CreateThread(NULL, 0, ThreadProc, &paramh, 0, NULL);   //�����̣߳��������

	// �����ӽ����ȶ�ǰ�󲿷ֱַ����������������߳̽��й鲢
	WaitForSingleObject(sortq, INFINITE);   //�ȴ��߳�ִ�н����������߳�
	WaitForSingleObject(sorth, INFINITE);   //�ȴ��߳�ִ�н����������߳�

	//���߳̽��й鲢���� 
	cout << "������" << endl;
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