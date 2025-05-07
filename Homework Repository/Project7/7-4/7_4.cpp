// 7-4
// 문자열과 Book 객체를 비교해서, 제목이 사전 순으로 어떤 게 앞에 오는지 확인하는 코드입니다.
// 문자열 < Book 이 가능한 이유는 < 연산자를 friend 함수로 오버로딩했기 때문입니다.

#include <iostream>
#include <string>  // string 자료형 쓰기 위해 포함
using namespace std;

// Book 클래스 정의: 제목, 가격, 페이지 수를 멤버로 가짐
class Book {
	string title;
	int price;
	int pages;

public:
	// 생성자: 기본값 포함하여 title, price, pages 초기화
	Book(const string& t = "", int p = 0, int pg = 0) {
		title = t;
		price = p;
		pages = pg;
	}

	// 책 정보 출력 함수
	void display() const {
		cout << title << " " << price << "원 " << pages << " 페이지" << endl;
	}

	// 제목만 반환하는 함수
	string getTitle() const {
		return title;
	}

	// 문자열 < Book 비교를 위해 friend 함수 선언
	friend bool operator<(const string& s, const Book& b);
};

// 외부 함수로 < 연산자 오버로딩
// 문자열 s가 Book 객체의 제목보다 앞에 오면 true 반환
bool operator<(const string& s, const Book& b) {
	return (s.compare(b.title) < 0);  // compare 사용 (정확하고 간단하게)
}

// 메인 함수: 사용자로부터 문자열 입력받아 Book 객체와 비교
int main() {
	Book myBook("청춘", 2000, 300);  // 책 제목은 "청춘"
	string inputTitle;

	cout << "책 이름을 입력하세요 >> ";
	getline(cin, inputTitle);  // 사용자로부터 제목 입력 (띄어쓰기 포함 가능)

	// 입력한 제목이 책 제목보다 사전상 앞에 오면 출력
	if (inputTitle < myBook)
		cout << myBook.getTitle() << "이 " << inputTitle << "보다 뒤에 있구나!" << endl;

	return 0;
}
