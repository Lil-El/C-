#include <iostream>
/*
    #include<>表示使用系统文件
    #include""表示使用自己的文件
    引入.h是旧写法
    新的标准使用头文件可以不带.h；
*/
using namespace std;
/*
    在C程序中，可以用宏代码提高执行效率。宏代码本身不是函数，但使用起来象函数。
    预处理器用复制宏代码的方式代替函数调用，省去了参数压栈、生成汇编语言的CALL调用、返见参数、执行return等过程.丛而提高了速度。(避免函数调思, 提高程序效夹)
*/

// 空宏，没什么意义
#define ABC(args, ...)

void know_marco_main() {
    enum Type {
        Apple,
        Pear,
        Car,
        Book
    };
}