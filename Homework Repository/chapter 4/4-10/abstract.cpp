#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;  // �̸� �����
public:
	Person() { name = ""; }  // �⺻ ������ ȣ������
	Person(string name) { this->name = name; }  // �̸� �ʱ�ȭ ������ ȣ������
	string getName() { return name; }  // �̸� ��ȯ����
	void setName(string name) { this->name = name; }  // �̸� ��������
};

class Family {
	Person* members;  // ���� ������ �迭
	int count;  // ���� ������ ��
	string familyName;  // ���� �̸�
public:
	Family(string familyName, int count);  // ������ ȣ������
	void display();  // ���� ���� �������
	void assignName(int index, string name);  // ������ �̸� ��������
	~Family();  // �Ҹ��� ȣ������
};

Family::Family(string familyName, int count) {
	this->familyName = familyName;  // ���� �̸� ��������
	this->count = count;  // ���� ������ �� ��������
	members = new Person[count];  // ������ �迭 ���� �Ҵ�����
}

void Family::display() {
	cout << familyName << " ������ �� " << count << "���Դϴ�." << endl;
	for (int i = 0; i < count; i++) {
		cout << members[i].getName() << "\t";  // �� �������� �̸� �������
	}
	cout << endl;
}

void Family::assignName(int index, string name) {
	members[index].setName(name);  // ������ �̸� ��������
}

Family::~Family() {
	delete[] members;  // ���� �Ҵ�� �迭 �޸� ��������
}

int main() {
	Family* simpsonFamily = new Family("Simpson", 3);  // Simpson ���� ��������
	simpsonFamily->assignName(0, "Mr. Simpson");  // ù ��° ������ �̸� ��������
	simpsonFamily->assignName(1, "Mrs. Simpson");  // �� ��° ������ �̸� ��������
	simpsonFamily->assignName(2, "Bart Simpson");   // �� ��° ������ �̸� ��������

	simpsonFamily->display();  // ���� ���� �������

	delete simpsonFamily;  // ���� �Ҵ�� ��ü �޸� ��������
	return 0;
}
