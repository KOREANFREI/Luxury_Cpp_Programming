// 7-1
// Book 객체에 대해 다음 연산을 하고자 한다.
/*
Book a("청춘", 20000, 300) , b("미래", 30000, 500);
a += 500; // 책 a의 가격 500원 증가
b -= 500; // 책 b의 가격 500원 감소
a.show();
b.show();
*/

// (2) +=, -= 연산자 함수를 Book 클래스의 **외부 함수(friend 함수)**로 구현하라.

#include <iostream>
using namespace std;

// Book 클래스 정의. 책 제목, 가격, 페이지 수를 멤버로 가짐
class Book {
    string title;    // 책 제목
    int price;       // 책 가격
    int pages;       // 책 페이지 수

public:
    // 생성자. 기본값도 있어서 그냥 Book() 이렇게 써도 됨
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    // 책 정보 출력 함수
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }

    // 제목만 따로 가져올 수 있는 함수
    string getTitle() {
        return title;
    }

    // 외부 함수인데, 클래스 내부 값 바꾸려면 friend로 허용해줘야 함
    friend Book& operator+= (Book& b, int a);  // 가격 올릴 때 쓰는 연산자
    friend Book& operator-= (Book& b, int a);  // 가격 내릴 때 쓰는 연산자
};

// += 연산자 외부 함수 구현
// Book 객체의 price를 a만큼 더해줌
Book& operator+= (Book& b, int a) {
    b.price += a;
    return b; // 자기 자신 리턴해야 += += 이런 것도 가능
}

// -= 연산자 외부 함수 구현
// Book 객체의 price를 a만큼 빼줌
Book& operator-= (Book& b, int a) {
    b.price -= a;
    return b;
}

// 메인 함수: 객체 만들고 연산자 테스트
int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);

    a += 500; // a의 가격이 500원 올라감
    b -= 500; // b의 가격이 500원 내려감

    a.show(); // 결과 출력
    b.show();
}
