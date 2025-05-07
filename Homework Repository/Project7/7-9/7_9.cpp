// 7-9
// Circle 클래스와 정수 사이의 덧셈 연산(int + Circle)을 지원하기 위한 연산자 오버로딩입니다.
// 이 연산은 외부 friend 함수로 정의되어야만 동작합니다 (정수가 왼쪽에 오기 때문).

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    // 생성자: 기본 반지름은 0
    Circle(int r = 0) : radius(r) {}

    // 현재 반지름을 출력
    void display() const {
        cout << "radius = " << radius << " 인 원" << endl;
    }

    // 정수 + Circle 형태의 연산을 위해 friend 함수 선언
    friend Circle operator+(int r, const Circle& c);
};

// 정수와 Circle을 더하는 연산자 오버로딩
// 반지름을 r + c.radius로 계산해서 새로운 Circle 반환
Circle operator+(int r, const Circle& c) {
    return Circle(r + c.radius);  // 바로 생성자 이용
}

int main() {
    Circle circleA(5);         // 반지름 5인 원
    Circle circleB(4);         // 반지름 4인 원

    // 1 + circleA: 정수와 원의 반지름 더함 → circleB에 저장
    circleB = 1 + circleA;

    // 결과 출력
    circleA.display();         // radius = 5 인 원
    circleB.display();         // radius = 6 인 원

    return 0;
}
