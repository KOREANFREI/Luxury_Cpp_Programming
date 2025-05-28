#include <iostream>
using namespace std;

// Circle 클래스 정의: 원의 반지름을 저장하고 비교 연산을 위한 기능 포함
class Circle {
    int radius;  // 반지름 정보

public:
    Circle(int radius = 1);  // 생성자: 기본 반지름은 1
    int getRadius() { return radius; }  // 반지름 반환

    bool operator>(Circle op2);  // 연산자 > 오버로딩
};

// 생성자 정의
Circle::Circle(int radius) {
    this->radius = radius;
}

// > 연산자 오버로딩: 두 원의 반지름 비교
bool Circle::operator>(Circle op2) {
    if (radius > op2.radius)
        return true;
    else
        return false;
}

// 템플릿 함수 bigger: 두 인자 중 더 큰 값을 반환
template <class T>
T bigger(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int a = 20, b = 50, c;
    c = bigger(a, b);  // int형 비교
    cout << "20과 50중 큰 값은 " << c << endl;

    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);  // Circle 객체 비교
    cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}
