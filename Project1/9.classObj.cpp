#include<iostream>
#include<string>

using namespace std;

class Student {

private:	// 不写的话，默认是private
	int age;
	Student *girlFriend;

protected: // 保护成员和私有成员类似，不能访问；但是protected可以在子类中访问，private只能在自己内部访问；
	int familyNums;

public:
	string name; // sizeof 40字节

	// 初始化列表
	Student(string a, int b) :name(a), age(b) {
		name = a;
		age = b;
		familyNums = 4;
	}

	Student(const Student &student) {
		name = student.name;
		age = student.age;
	}

	// 析构函数不能携带参数、没有返回值
	~Student(void) {}

	// 友元函数可以访问protected，private变量，但是不属于成员函数
	friend int getGrilFriendName(Student boy) {
		return boy.age;
	}

	void setGirl(Student *girl) {
		girlFriend = girl;
	}

	Student *getGirl() {
		return girlFriend;
	}

	int getAge() {
		return age;
	}

	string getName();
};
string Student::getName() {
	return name;
}

void clsObj_main() {
	Student boy("MIno", 24); // https://blog.csdn.net/weixin_46624734/article/details/123520772
	cout << &boy << endl; // https://blog.csdn.net/wangzai32100/article/details/125346027
	cout << &boy.name << endl;
	cout << "*********************************" << endl;
	cout << boy.getAge() << endl;
	boy.name = "Mino2";
	cout << boy.name << endl;
	cout << boy.getName() << endl;

	Student girl("Sunny", 18);
	Student sister = girl;
	cout << boolalpha << (girl.name == sister.name) << endl;

	boy.setGirl(&girl);
	cout << boy.getGirl()->name << endl;
	cout << getGrilFriendName(boy) << endl;

	// TODO: 内联
}