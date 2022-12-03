#include <iostream>
using namespace std;

/*
	__attribute__是一个编译器指令，其实是 GNU C 的一种机制，本质是一个编译器的指令.
	在声明的时候可以提供一些属性，在编译阶段起作用，来做多样化的错误检查和高级优化。

	在Linux环境下可以使用。

	修饰变量、函数、类型（结构体、联合体、枚举等）

	__attribute__支持的类型：
		函数属性(Function Attribute)	类型属性(Type Attributes)	变量属性(Variable Attribute)	Clang特有的
		noreturn	                    aligned						alias							availability
		noinline						packed						at(address)						overloadable
		always_inline					bitband						aligned
		flatten														deprecated
		pure														noinline
		const														packed
		constructor													weak
		destructor													weakref(“target”)
		sentinel													section(“name”)
		format														unused
		format_arg													used
		section														visibility(“visibility_type”)
		used														zero_init
		unused
		deprecated
		weak
		malloc
		alias
		warn_unused_result
		nonnull

	noreturn：这个属性告诉编译器函数不会返回，这可以用来抑制关于未达到代码路径的错误。 C库函数abort（）和exit（）都使用此属性声明
	aligned：设置字节对齐
	pure：定义函数为纯函数
	const：该属性只能用于带有数值类型参数的函数上。当重复调用带有数值参数的函数时，由于返回值是相同的，所以此时编译器可以进行优化处理，除第一次需要运算外，其它只需要返回第一次的结果就可以了，进而可以提高效率。该属性主要适用于没有静态状态(static state)和副作用的一些函数，并且返回值仅仅依赖输入的参数。
	deprecated：告诉编译器已经过时
*/
// attribute是GNU C的，在MSVC中是使用 _declspec(align())

// 函数需要返回int值，如果中途退出会报错；所以为my_exit函数添加noreturn
void know_attr_main() {
	return;
}