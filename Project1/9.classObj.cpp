#include<iostream>
#include<string>

using namespace std;

class Student {

private:	// ��д�Ļ���Ĭ����private
	int age;
	Student *girlFriend;

protected: // ������Ա��˽�г�Ա���ƣ����ܷ��ʣ�����protected�����������з��ʣ�privateֻ�����Լ��ڲ����ʣ�
	int familyNums;

public:
	string name; // sizeof 40�ֽ�

	// ��ʼ���б�
	Student(string a, int b) :name(a), age(b) {
		name = a;
		age = b;
		familyNums = 4;
	}

	Student(const Student &student) {
		name = student.name;
		age = student.age;
	}

	// ������������Я��������û�з���ֵ
	~Student(void) {}

	// ��Ԫ�������Է���protected��private���������ǲ����ڳ�Ա����
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

	// TODO: ����
}