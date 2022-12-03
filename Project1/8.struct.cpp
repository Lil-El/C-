#include<iostream>
#include<string>

using namespace std;

/*
* 1.继承权限：struct默认为public，而class默认的为private。
  2.访问权限：struct默认的成员变量访问控制权限是public，而class默认的成员变量访问权限则为private。
*/

// Student和其他文件的class Student会导致一些错误，所以更名为StructStudent
struct StructStudent {
	int age;
	string name;

	StructStudent() = default; // 自动生成函数体
	StructStudent(int a, string n) : age(a), name(n) {}
};

// 类型重定义，或者可以是：typedef struct Teacher Teacher; Teacher Mino;
typedef struct {
	int age;
	string name;
} Teacher;

void printStudent(struct StructStudent student) {
	cout << student.name << endl;
	cout << student.age << endl;
}

void printStudent(struct StructStudent* student) {
	cout << student->name << endl;
	cout << student->age << endl;
}

using Fn = int(*)();

template<typename T>
struct tempStruct {
private:
	T age;
public:
	tempStruct() : age(3) {}
	T static getAge() {
		return 1; // return age; 错误，age不是静态的，无法获取
	}
	void getA() {}
	Fn getB;
};

int getNum() {
	return 1;
}

void struct_main() {
	// 定义时，struct可写可不写；struct Student s1; Student s1; 都是一样的
	StructStudent mino;
	mino.name = "Mino";
	mino.age = 24;
	printStudent(mino);

	StructStudent* stu_point = &mino;
	printStudent(stu_point);

	struct StructStudent s1(22, "YXD");
	printStudent(s1);

	Teacher mino2;

	tempStruct<int> s3;
	s3.getB = getNum;
	// s3.getA(); 无法拿到成员参数
	cout << tempStruct<int>::getAge() << endl;
	cout << s3.getB() << endl;

}