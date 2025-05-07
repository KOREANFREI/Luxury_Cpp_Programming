// 7-3
// ! 연산자를 오버로딩해서 책이 공짜인지 확인하는 코드입니다.
// 책의 가격이 0이면 공짜로 간주합니다. (!book → 공짜 책 판별)

#include <iostream>
using namespace std;

// Book 클래스 선언: 제목, 가격, 페이지 수를 멤버로 가짐
class Book {
private:
    string title;
    int price;
    int pages;

public:
    // 생성자: 책의 기본 정보를 초기화함
    Book(const string& t = "", int p = 0, int pg = 0) {
        title = t;
        price = p;
        pages = pg;
    }

    // 책 정보를 출력하는 함수
    void display() const {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }

    // 제목 가져오는 함수
    string getTitle() const {
        return title;
    }

    // ! 연산자 오버로딩: 가격이 0이면 true 반환 (공짜 책)
    bool operator!() const;
};

// ! 연산자 구현: 책 가격이 0이면 공짜로 간주
bool Book::operator!() const {
    return (price == 0);  // 조건문 없이 간단히 표현
}

// 메인 함수: 공짜 책인지 여부를 ! 연산자를 통해 확인
int main() {
    Book fleaBook("벼룩시장", 0, 50);  // 가격이 0인 책

    // ! 연산자를 통해 공짜인지 판별
    if (!fleaBook)
        cout << "공짜다" << endl;

    return 0;
}
