#include<iostream>
#include<string>

using namespace std;

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
}