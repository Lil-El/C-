#include <iostream>
using namespace std;

// ָ��noexcept�󣬷����쳣����ʾ�������쳣Ҳ����ʾ
// noexcept(true)�� noexcept��__declspec(nothrow)��throw()һ������ʾ�����׳��쳣
/*
* ����noexcept����noexcept(true)ʱ��ʾ�����׳��쳣����ʱ�׳��쳣���޷�����throw���ݣ�
* �����noexcept(false)��ʾ�����׳��쳣����ʱ�׳��쳣���Բ���
* 
	throw()��noexcept��ȣ�noexcept��ֱ���жϳ���
	��Ϊthrow()��֪����ʲô�쳣�����ڵ�ǰ������catchƥ�䣬û������˵���ջ����һ��ȥ�����쳣��һֱ�Ҳ�����ִ��unexpected��һϵ�в���������Ӱ�����
		ʹ�õ������Ŀ�ʱ���㶼��֪��catchʲô����
		���fn() throw(int, double)��fn��throw�������͵Ĵ��󣬱����ǿ���ͨ���ģ�Ҳû�о��档
		֪��������ʲô�쳣��ûʲô���壬����֪�����Ƿ�����쳣�������в�ͬ���Ż�
	����ֱ��ʹ��noexceptֱ��terminate�˳�����

	http://www.wjhsh.net/5iedu-p-11270922.html
*/
int know_key_fn(bool flag) noexcept(false) /* throw() */ {
	if (flag) {
		return 99;
	}
	else {
		throw true; //  "MM"; // 500
	}
}

[[noreturn]] void know_key_main(void) {
	//int a = know_key_fn(false);
	try
	{
		int b = know_key_fn(false);
	}
	catch (const int& err) {
		cout << err << endl;
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...) // ����ȫ�������쳣
	{
		cout << "catch unknown error" << endl;
	}
	// return; // ��Ϊ��noreturn�����Լ�ʹд��return;Ҳ����ʾ����
}