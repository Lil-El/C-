#include <iostream>
using namespace std;

/*
* SFINAE表示替换失败不是错误( Substitution Failure Is Not An Error)。简单地说，替换就是尝试用提供的类型或值替换模板参数的机制。
* 在某些情况下，如果替换导致无效代码，编译器不应该抛出大量错误，而应该继续尝试其他可用的重载。
* SFINAE概念只是为“健全”的编译器保证这种“健全”的行为。
* 
* C++模板提供了一个SFINAE（subsitate failure is not an error）的机制（模板匹配失败不是错误），
* 这是模板里面一个非常有意思的特性，
* 利用这个机制可以检查一个结构体是否包含某个成员等操作。
*/

/*
* 如果T是一个int类型，那么返回值是bool类型。如果不是int的话，就匹配不到找个实例。
* 使用enable_if的好处是控制函数只接受某些类型的(value==true)的参数，否则编译报错。
*/
template <class T>
typename enable_if<is_integral<T>::value, bool>::type is_odd(T i) { return bool(i % 2); }

/*
* 如果 T 没有 foo, 当没有 sfinae 的时候, 就会直接编译错误, 因为展开的结果不合法, 
* 不过因为现在有 sfinae 第一个展开发现不合法了不会立刻编译错误, 而是会尝试别的重载展开.
*/
template <typename T>
void sfinae_foo(typename T::foo) {}

template <typename T>
void sfinae_foo(T) {}

void sfinae_main() {
	cout << "is_odd: " << is_odd(2) << endl;
//https://www.modb.pro/db/150467
}