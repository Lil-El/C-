#include<iostream>
#include<string>

using namespace std;

// Student�������ļ���class Student�ᵼ��һЩ�������Ը���ΪStructStudent
struct StructStudent {
	int age;
	string name;

	StructStudent() = default; // �Զ����ɺ�����
	StructStudent(int a, string n) : age(a), name(n) {}
};

// �����ض��壬���߿����ǣ�typedef struct Teacher Teacher; Teacher Mino;
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
	// ����ʱ��struct��д�ɲ�д��struct Student s1; Student s1; ����һ����
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