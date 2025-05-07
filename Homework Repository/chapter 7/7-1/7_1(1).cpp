// 7-1
// Book 객체에 대해 다음 연산을 하고자 한다.
/*
Book a("청춘", 20000, 300) , b("미래", 30000, 500);
a += 500; // 책 a의 가격 500원 증가
b -= 500; // 책 b의 가격 500원 감소
a.show();
b.show();
*/

// (1) +=, -= 연산자 함수를 Book 클래스의 멤버 함수로 구현하라.
#include <iostream>
using namespace std;

// Book 클래스 선언. 책 하나를 표현하는 객체
class Book {
    string title;    // 책 제목
    int price;       // 책 가격
    int pages;       // 책 페이지 수

public:
    // 생성자. 제목, 가격, 페이지 수를 초기화해줌
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    // 책 정보 출력용 함수
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }

    // 책 제목을 가져오는 함수
    string getTitle() {
        return title;
    }

    // 멤버 함수로 +=, -= 오버로딩 (정수값 더하고 빼기)
    Book& operator+= (int a);  // 가격을 a만큼 증가시킴
    Book& operator-= (int a);  // 가격을 a만큼 감소시킴
};

// 멤버 함수 방식으로 += 구현
Book& Book::operator+= (int a) {
    price += a;    // 가격 증가
    return *this;  // 자기 자신 반환 (체이닝 가능)
}

// 멤버 함수 방식으로 -= 구현
Book& Book::operator-= (int a) {
    price -= a;    // 가격 감소
    return *this;
}

// 메인 함수: 객체 생성하고 연산자 오버로딩 테스트
int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);

    a += 500; // 청춘 책 가격 500원 올림
    b -= 500; // 미래 책 가격 500원 내림

    a.show(); // a 책 정보 출력
    b.show(); // b 책 정보 출력
}
