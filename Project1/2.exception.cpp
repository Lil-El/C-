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

  ��C++17�У�throw(��̬list)�������ˣ�throw()û��
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
*/
/*
* https://zyfforlinux.blog.csdn.net/article/details/50410314
	1. �쳣�׳��Ĵ�����У�����ᱻ��������֮Ϊ��ջ���⣮
		1.1 �쳣�е���Դ��������ڹ������б�����ô�ͻ�����ڴ�й©�����Ա����ڹ�������������������ڹ������н��в����쳣��
			int main() try {
				throw "main";
			} catch(const char* msg) {
				cout << msg << endl;
				return 1;
			}
			����
			Base(int data,string str)try:m_int(data),m_string(str)//�Գ�ʼ���б��п��ܻ���ֵ��쳣Ҳ����в�׽
		   { }catch(const char* msg) {
				cout << "catch a exception" << msg << endl;
		   }
	2. �׳������쳣��ʹ�ø������catch
	3. һֱû��catch���ͻ��Զ�����unexpected��terminate�����������Զ����޸�set_terminate��set_unexpected����
	4. C++��׼�쳣��
		logic_error
		runtime_error
		bad_exception�������޷�Ԥ�ڵ��쳣
		out_of_range
		ranger_error
		bad_alloc�����쳣ͨ��new�׳�
		��
*/
#ifdef _HAS_CXX17
void oneExcepFn() noexcept(false) {
	throw 1;
}
#else
void oneExcepFn() throw() {
	throw 1;
}
#endif

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