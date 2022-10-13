#include<iostream>
#include<string>

using namespace std;

// ����һ������Ҫִ�кܶಽ�裺����ǰҪ�ȱ���Ĵ��������ڷ���ʱ�ָ�������ʵ�Σ����򻹱���ת��һ����λ��ִ�С�
// ��������ʹ��inline�ؼ��֣��Ǹ������������飬Ϊ���Ż������ִ��Ч�ʡ���������Ѹú����Ĵ��븱�������ڵ��õĵط����Կռ任ȡʱ�䡣
// �������������̣��߼��򵥡����벻�ܹ������ڸ��ӣ�����ѭ�������٣������ǵݹ�ȣ�����Ļ��������ᰴ����ͨ��������
// ��ĳ�Ա��������inline��
// inline�����������������һ���ļ��У�����ֿ�����������������д���

inline int getMax(int a, int b) {
	return a > b ? a : b;
}

class Student {

private:	// ��д�Ļ���Ĭ����private
	int age;
	Student *girlFriend;

protected: // ������Ա��˽�г�Ա���ƣ����ܷ��ʣ�����protected�����������з��ʣ�privateֻ�����Լ��ڲ����ʣ�
	int familyNums;

public:
	static int count; // static���α��������������е�class��ʵ������һ������������
	string name = "0"; // sizeof 40�ֽ�

	Student(string a) :name(a) {
		age = 0;
		count++;
	}
	// ��ʼ���б�
	Student(string a, int b) :name(a), age(b) {
		name = a;
		age = b;
		familyNums = 4;
		count++;
	}

	// ��д�������캯�������Զ�����һ��ȱʡ��-ǳ����
	// ǳ��������ͨ���͵Ŀ������������Ƕ���class�е�ָ����˵���¾ɶ��������ͬһ����ַ��������Ҫ���¶��忽�����캯����Ϊָ������ڴ�
	// һ�������Ĳ����β�ΪStudent xxxʱ��Ҳ����ÿ������캯������������ʱ���βλ´��ʵ�Σ���������Ҫʹ������
	// ��������ֵ��Studentʱ��Ҳ����ÿ�������
	Student(const Student &student) {
		name = student.name;
		age = student.age;
		girlFriend = new Student("Mino", 18);
	}

	// TODO: [�ƶ����캯��](https://blog.csdn.net/weixin_44788542/article/details/126284429)

	// ������������Я��������û�з���ֵ
	~Student(void) {}

	// ��Ԫ�������Է���protected��private���������ǲ����ڳ�Ա����
	// ��Ԫ�������ʣ���Ԫ�������ܱ�const����
	// ������Student����ʱ������ÿ������캯���������β�boy��ʵ��boy����ͬһ���������Դ���Student *ָ�� ���� Student &����
	// Ϊ�˷�ָֹ������õ�ָ��ı䣬�����������const��������
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

	// ÿ��������һ��thisָ�룻��Ԫ�����ڲ����������Ի�ȡ����this
	int getAge() {
		return this->age;
	}

	string getName();
};
string Student::getName() {
	return name;
}
// ��ʼ����̬��Ա
int Student::count = 0;

void clsObj_main() {
	// ����ʵ����
	// 1. Student boy(...);
	// 2. Student boy = Student(...);
	Student a("yyxxd"); // ʹ�ù��캯��
	Student b = (string)"yxd"; // ʹ��operator����=

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
	cout << sister.getGirl() << endl; // ʹ��ȱʡ�ĸ��ƿ�������ʱ��������ĵ�ַһ�£�ǳ����

	boy.setGirl(&girl);
	cout << boy.getGirl() << boy.getGirl()->name << endl;
	cout << getGrilFriendName(boy) << endl;

	cout << "inline function Max: " << getMax(10, 100) << endl;

	cout << "*********************************" << endl;
	// ָ�����ָ��
	// 1. Student *ptr = &boy;
	// 2. Student *ptr = new Student("A", 0);
	Student *ptr = nullptr;
	ptr = &boy;
	cout << (*ptr).name << endl; // -> ���� (*x).
	cout << ptr->name << endl;
	ptr = &girl;
	cout << ptr->name << endl;

	cout << Student::count << endl;
	cout << Student::getCount() << endl;
}