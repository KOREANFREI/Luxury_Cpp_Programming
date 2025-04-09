#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;  // 이름 저장용
public:
	Person() { name = ""; }  // 기본 생성자 호출했음
	Person(string name) { this->name = name; }  // 이름 초기화 생성자 호출했음
	string getName() { return name; }  // 이름 반환했음
	void setName(string name) { this->name = name; }  // 이름 설정했음
};

class Family {
	Person* members;  // 가족 구성원 배열
	int count;  // 가족 구성원 수
	string familyName;  // 가족 이름
public:
	Family(string familyName, int count);  // 생성자 호출했음
	void display();  // 가족 정보 출력했음
	void assignName(int index, string name);  // 구성원 이름 설정했음
	~Family();  // 소멸자 호출했음
};

Family::Family(string familyName, int count) {
	this->familyName = familyName;  // 가족 이름 저장했음
	this->count = count;  // 가족 구성원 수 저장했음
	members = new Person[count];  // 구성원 배열 동적 할당했음
}

void Family::display() {
	cout << familyName << " 가족은 총 " << count << "명입니다." << endl;
	for (int i = 0; i < count; i++) {
		cout << members[i].getName() << "\t";  // 각 구성원의 이름 출력했음
	}
	cout << endl;
}

void Family::assignName(int index, string name) {
	members[index].setName(name);  // 구성원 이름 설정했음
}

Family::~Family() {
	delete[] members;  // 동적 할당된 배열 메모리 해제했음
}

int main() {
	Family* simpsonFamily = new Family("Simpson", 3);  // Simpson 가족 생성했음
	simpsonFamily->assignName(0, "Mr. Simpson");  // 첫 번째 구성원 이름 설정했음
	simpsonFamily->assignName(1, "Mrs. Simpson");  // 두 번째 구성원 이름 설정했음
	simpsonFamily->assignName(2, "Bart Simpson");   // 세 번째 구성원 이름 설정했음

	simpsonFamily->display();  // 가족 정보 출력했음

	delete simpsonFamily;  // 동적 할당된 객체 메모리 해제했음
	return 0;
}
