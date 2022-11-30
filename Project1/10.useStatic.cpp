//#include "pch.h" // 引入pch.h或者framework.h都可以

/*
	使用lib：只需要找到.h文件，.lib文件；
	方法1.
		将h/lib文件拷贝到项目目录下，即可运行
	方法2. （../）
		将h/lib文件拷贝到任意目录下，通过incclude"../../xxx.h" pragma(lib, "../../xxx.lib")方式
	方法3. (没../)
		将h/lib文件拷贝到任意目录中，include “xxx.h”，需要配置包含目录
		需要配置库目录
		还要加pragma(xxx.lib)，不然只能不知道使用哪个lib
	方法4. （没有pragma）
		同上，删除pragma，再设置附加依赖项
	方法5.
		vs引用中引入lib库，设置include路径；

*/

void useStatic_main() {
	/*StaticOne a(1);
	a.sayHello();

	fnStaticLib1();*/
}
