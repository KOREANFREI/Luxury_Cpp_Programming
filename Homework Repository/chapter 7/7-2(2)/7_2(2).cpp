// (2) == 연산자 세 개를 외부 friend 함수로 작성하라.

#include <iostream>
using namespace std;

// 책 클래스 정의: 제목, 가격, 페이지 수를 멤버로 가짐
class Book {
	string title;
	int price;
	int pages;

public:
	// 생성자: 기본값 설정도 가능해서 편하게 만들 수 있음
	Book(string t = "", int p = 0, int pg = 0) {
		title = t;
		price = p;
		pages = pg;
	}

	// 책 정보를 출력하는 함수 (이름은 showInfo로 바꿨음!)
	void showInfo() const {
		cout << title << " " << price << "원 " << pages << " 페이지" << endl;
	}

	// 제목 반환 함수
	string getTitle() const {
		return title;
	}

	// 외부 연산자 함수들이 private 멤버에 접근하려면 friend 필요함
	friend bool operator== (const Book& b, int p);              // 가격 비교용
	friend bool operator== (const Book& b, const string& t);    // 제목 비교용
	friend bool operator== (const Book& lhs, const Book& rhs);  // 전체 비교용
};

// 가격이 같은지 비교하는 함수. 그냥 가격만 비교함
bool operator== (const Book& b, int p) {
	return (b.price == p);  // 가격이 같으면 true
}

// 제목이 같은지 비교. compare 함수 써서 살짝 다르게 작성함
bool operator== (const Book& b, const string& t) {
	return (b.title.compare(t) == 0);  // 문자열 비교 결과가 0이면 같음
}

// 두 Book 객체가 완전히 같은지 확인
bool operator== (const Book& lhs, const Book& rhs) {
	// 제목, 가격, 페이지 수 모두 같아야 같은 책이라고 판단
	return (lhs.title == rhs.title && lhs.price == rhs.price && lhs.pages == rhs.pages);
}

// 메인 함수: 비교 연산자들이 잘 작동하는지 테스트
int main() {
	Book bookA("명품 C++", 30000, 500);         // 첫 번째 책
	Book bookB("고품 C++", 30000, 500);         // 두 번째 책

	// 가격이 같은지 비교
	if (bookA == 30000)
		cout << "정가 30000원" << endl;

	// 제목이 같은지 비교
	if (bookA == "명품 C++")
		cout << "명품 C++ 입니다." << endl;

	// 두 책이 완전히 같은지 비교 (지금은 제목이 달라서 다름)
	if (bookA == bookB)
		cout << "두 책이 같은 책입니다." << endl;

	return 0;
}
