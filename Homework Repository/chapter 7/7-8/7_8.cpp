// 7-8
// Circle 클래스에서 전위 및 후위 증가 연산자(++)를 friend 외부 함수로 오버로딩합니다.
// 반지름(radius)을 1씩 증가시키는 동작을 합니다.

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    // 생성자: 기본값은 0
    Circle(int r = 0) : radius(r) {}

    // 반지름 출력 함수
    void display() const {
        cout << "radius = " << radius << " 인 원" << endl;
    }

    // 전위, 후위 연산자를 외부에서 정의할 수 있게 friend 선언
    friend Circle& operator++(Circle& c);        // 전위 증가
    friend Circle operator++(Circle& c, int);    // 후위 증가
};

// 전위 증가 연산자 (++a)
// radius를 먼저 증가시키고, 자기 자신을 참조로 반환
Circle& operator++(Circle& c) {
    ++c.radius;
    return c;  // 증가된 객체를 참조로 반환
}

// 후위 증가 연산자 (a++)
// 현재 객체 상태를 저장한 후, radius를 증가시키고 이전 상태를 값으로 반환
Circle operator++(Circle& c, int) {
    Circle temp = c;  // 증가 전 상태 저장
    c.radius++;
    return temp;      // 증가 전 복사본 반환
}

int main() {
    Circle circleA(5);   // 반지름 5
    Circle circleB(4);   // 반지름 4

    ++circleA;           // 전위 증가 → 6
    circleB = circleA++; // 후위 증가 → circleB는 6, circleA는 7

    circleA.display();   // 출력: radius = 7 인 원
    circleB.display();   // 출력: radius = 6 인 원

    return 0;
}
