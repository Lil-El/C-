#include<iostream>
#include<exception>
using namespace std;

/*
* 
* void fn() throw() {}
* �ں������throw()��ʾ��
	throw(type) ��ʾ���ܻ��׳�type���͵��쳣
	throw()     ��ʾ�����׳��쳣
	throw(...)  ��ʾ�����׳��κ��쳣


  ��C++11�У�ʹ��noexcept���棬�쳣����false��������true
  void fn() noexcept {}

  ��C++17�У�throw()��������
*/

// ͨ���̳С�����exception��ʵ���Լ����쳣��exception��һ����������what�����Ի�ȡ�쳣����ԭ��
struct MyException : public exception {
	const char *what() const throw() {
		return "It's my error!";
	}
};

/*
* �ùؼ��ָ��߱������������в��ᷢ���쳣,�������ڱ������Գ�����������Ż���
���������ʱ��noexecpt���������׳����쳣����������ڲ���׽���쳣����ɴ���������������׳��쳣���������ֱ����ֹ
https://blog.csdn.net/u011942101/article/details/123940489
https://blog.csdn.net/qq_24127015/article/details/104412800
*/
void oneExcepFn() throw() {
	throw 1;
}

void excp_main() {
	try {
		throw MyException();
		//throw "Division by zero condition!";
	}
	catch (const char *msg) {
		cout << msg;
	}
	catch (MyException &err) {
		cout << err.what();
	}
	catch (const exception &e) {
		cout << e.what();
	}
}