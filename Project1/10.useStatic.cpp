//#include "pch.h" // ����pch.h����framework.h������

/*
	ʹ��lib��ֻ��Ҫ�ҵ�.h�ļ���.lib�ļ���
	����1.
		��h/lib�ļ���������ĿĿ¼�£���������
	����2. ��../��
		��h/lib�ļ�����������Ŀ¼�£�ͨ��incclude"../../xxx.h" pragma(lib, "../../xxx.lib")��ʽ
	����3. (û../)
		��h/lib�ļ�����������Ŀ¼�У�include ��xxx.h������Ҫ���ð���Ŀ¼
		��Ҫ���ÿ�Ŀ¼
		��Ҫ��pragma(xxx.lib)����Ȼֻ�ܲ�֪��ʹ���ĸ�lib
	����4. ��û��pragma��
		ͬ�ϣ�ɾ��pragma�������ø���������
	����5.
		vs����������lib�⣬����include·����

*/

void useStatic_main() {
	/*StaticOne a(1);
	a.sayHello();

	fnStaticLib1();*/
}
