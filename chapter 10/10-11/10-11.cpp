#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 개별 책 정보를 담는 Book 클래스
class Book {
private:
    string title, author; // 책 제목과 저자
    int year;             // 출판 연도

public:
    Book(); // 기본 생성자
    Book(string title, string author, int year); // 매개변수 있는 생성자

    void set(string title, string author, int year); // 책 정보 설정
    string getAuthor() { return author; }            // 저자 반환
    int getYear() { return year; }                   // 출판 연도 반환
    void show();                                     // 책 정보 출력
};

// 기본 생성자: 초기값 설정
Book::Book() {
    title = "";
    author = "";
    year = 1000; // 비현실적인 초기값으로 설정
}

// 매개변수 있는 생성자
Book::Book(string title, string author, int year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

// set 함수: 책 정보를 입력받아 멤버 변수에 저장
void Book::set(string title, string author, int year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

// 책 정보를 출력하는 함수
void Book::show() {
    cout << year << "년도, " << title << ", " << author << endl;
}


// 여러 책을 관리하는 BookManager 클래스
class BookManager {
private:
    vector<Book> v;             // 책 정보를 담는 벡터
    void bookIn();              // 책 입고 처리
    void searchByAuthor();      // 저자 검색
    void searchByYear();        // 연도 검색

public:
    void run(); // 전체 실행 흐름
};

// 책을 입고받는 함수 (반복 입력, -1이면 종료)
void BookManager::bookIn() {
    int year;
    string title, author;
    Book bk;

    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while (true) {
        cout << "년도>> ";
        cin >> year;
        cin.ignore(); // 줄바꿈 문자 제거 (getline 대비)

        if (year == -1)
            break;

        cout << "책이름>> ";
        getline(cin, title);

        cout << "저자>> ";
        getline(cin, author);

        bk.set(title, author, year); // 책 정보 설정
        v.push_back(bk);             // 벡터에 추가
    }

    cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
}

// 사용자가 입력한 저자 이름으로 검색
void BookManager::searchByAuthor() {
    cout << "검색하고자 하는 저자 이름을 입력하세요>> ";
    string author;
    getline(cin, author); // 전체 이름 입력 받기

    for (int i = 0; i < v.size(); ++i) {
        Book bk = v[i];
        if (author == bk.getAuthor())
            bk.show(); // 일치하는 경우 출력
    }
}

// 사용자가 입력한 연도로 검색
void BookManager::searchByYear() {
    cout << "검색하고자 하는 년도를 입력하세요>> ";
    int year;
    cin >> year;

    for (int i = 0; i < v.size(); ++i) {
        Book bk = v[i];
        if (year == bk.getYear())
            bk.show(); // 일치하는 경우 출력
    }
}

// 전체 흐름을 실행
void BookManager::run() {
    bookIn();          // 책 입력
    searchByAuthor();  // 저자 검색
    searchByYear();    // 연도 검색
}

// main 함수: 프로그램 시작점
int main() {
    BookManager man;
    man.run();
}
