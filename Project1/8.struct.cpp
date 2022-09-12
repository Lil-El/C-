#include<iostream>
#include<string>

using namespace std;

struct Student {
	int age;
	string name;
};

// 类型重定义，或者可以是：typedef struct Teacher Teacher; Teacher Mino;
typedef struct {
	int age;
	string name;
} Teacher;

void printStudent(struct Student student) {
	cout << student.name << endl;
	cout << student.age << endl;
}
void printStudent(struct Student *student) {
	cout << student->name << endl;
	cout << student->age << endl;
}

void strcut_main() {
	struct Student mino;
	mino.name = "Mino";
	mino.age = 24;
	printStudent(mino);

	struct Student *stu_point = &mino;
	printStudent(stu_point);

	Teacher mino2;
}