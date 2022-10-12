#include<iostream>
#include<string>

using namespace std;

// 调用一个函数要执行很多步骤：调用前要先保存寄存器，并在返回时恢复，复制实参，程序还必须转向一个新位置执行。
// 内联函数使用inline关键字，是给编译器的提议，为了优化代码的执行效率。编译器会把该函数的代码副本放置在调用的地方，以空间换取时间。
// 内联函数代码简短，逻辑简单。代码不能过长过于复杂，必须循环次数少，不能是递归等；否则的话编译器会按照普通函数处理
// 类的成员函数都是inline的
// inline的声明、定义必须在一个文件中，如果分开进行声明、定义会有错误。

inline int getMax(int a, int b) {
	return a > b ? a : b;
}

class Student {

private:	// 不写的话，默认是private
	int age;
	Student *girlFriend;

protected: // 保护成员和私有成员类似，不能访问；但是protected可以在子类中访问，private只能在自己内部访问；
	int familyNums;

public:
	static int count; // static修饰变量、函数：所有的class的实例共享一个变量、函数
	string name = "0"; // sizeof 40字节

	Student(string a) :name(a) {
		age = 0;
		count++;
	}
	// 初始化列表
	Student(string a, int b) :name(a), age(b) {
		name = a;
		age = b;
		familyNums = 4;
		count++;
	}

	// 不写拷贝构造函数，会自动生成一个缺省的-浅拷贝
	// 浅拷贝：普通类型的可以正常，但是对于class中的指针来说，新旧对象会引用同一个地址。所以需要重新定义拷贝构造函数，为指针分配内存
	// 一个函数的参数形参为Student xxx时，也会调用拷贝构造函数（函数调用时，形参会拷贝实参），所以需要使用引用
	// 函数返回值是Student时，也会调用拷贝函数
	Student(const Student &student) {
		name = student.name;
		age = student.age;
		girlFriend = new Student("Mino", 18);
	}

	// TODO: [移动构造函数](https://blog.csdn.net/weixin_44788542/article/details/126284429)

	// 析构函数不能携带参数、没有返回值
	~Student(void) {}

	// 友元函数可以访问protected，private变量，但是不属于成员函数
	// 友元函数访问，友元函数不能被const修饰
	// 参数是Student类型时，会调用拷贝构造函数，导致形参boy和实参boy不是同一个对象，所以传入Student *指针 或者 Student &引用
	// 为了防止指针或引用的指向改变，参数可以添加const进行修饰
	/*friend string getGrilFriendName(Student *boy) {
		return (*boy).girlFriend->name;
	}*/
	friend string getGrilFriendName(const Student &boy) {
		return boy.girlFriend->name;
	}

	Student *operator=(const string &n) {
		name = n;
	}

	static int getCount() {
		return count;
	}

	void setGirl(Student *girl) {
		girlFriend = girl;
	}

	Student *getGirl() {
		return girlFriend;
	}

	// 每个对象都有一个this指针；友元不是内部函数，所以获取不到this
	int getAge() {
		return this->age;
	}

	string getName();
};
string Student::getName() {
	return name;
}
// 初始化静态成员
int Student::count = 0;

void clsObj_main() {
	// 创建实例：
	// 1. Student boy(...);
	// 2. Student boy = Student(...);
	Student a("yyxxd"); // 使用构造函数
	Student b = (string)"yxd"; // 使用operator重载=

	Student boy("MIno1", 24); // https://blog.csdn.net/weixin_46624734/article/details/123520772
	cout << &boy << endl; // https://blog.csdn.net/wangzai32100/article/details/125346027
	cout << &boy.name << endl;
	cout << "*********************************" << endl;
	cout << boy.getAge() << endl;
	boy.name = "Mino2";
	cout << boy.name << endl;
	cout << boy.getName() << endl;

	Student girl("Sunny", 18);
	girl.setGirl(&boy);
	Student sister = girl;
	cout << boolalpha << (girl.name == sister.name) << endl;
	cout << girl.getGirl() << endl; // boy address
	cout << sister.getGirl() << endl; // 使用缺省的复制拷贝函数时，和上面的地址一致；浅拷贝

	boy.setGirl(&girl);
	cout << boy.getGirl() << boy.getGirl()->name << endl;
	cout << getGrilFriendName(boy) << endl;

	cout << "inline function Max: " << getMax(10, 100) << endl;

	cout << "*********************************" << endl;
	// 指向类的指针
	// 1. Student *ptr = &boy;
	// 2. Student *ptr = new Student("A", 0);
	Student *ptr = nullptr;
	ptr = &boy;
	cout << (*ptr).name << endl; // -> 等于 (*x).
	cout << ptr->name << endl;
	ptr = &girl;
	cout << ptr->name << endl;

	cout << Student::count << endl;
	cout << Student::getCount() << endl;
}