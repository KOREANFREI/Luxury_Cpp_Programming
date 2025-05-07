// (2) +와 == 연산자를 Color 클래스의 friend 함수로 구현한 코드입니다.
// r, g, b 값을 더하거나 비교할 수 있도록 연산자를 외부에서 정의하고 friend로 허용합니다.

#include <iostream>
using namespace std;

class Color {
private:
    int red, green, blue;

public:
    // 기본 생성자: 검정색(0,0,0)
    Color() : red(0), green(0), blue(0) {}

    // 매개변수 생성자: 입력값으로 색상 초기화
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    // 색상 정보를 출력하는 함수
    void print() const {
        cout << red << ' ' << green << ' ' << blue << endl;
    }

    // friend 함수로 선언하여 private 멤버 접근 허용
    friend Color operator+(const Color& c1, const Color& c2);
    friend bool operator==(const Color& c1, const Color& c2);
};

// + 연산자 정의: 두 색상의 각 요소를 더한 새로운 색 반환
Color operator+(const Color& c1, const Color& c2) {
    return Color(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue);
}

// == 연산자 정의: 세 가지 요소가 모두 같으면 true 반환
bool operator==(const Color& c1, const Color& c2) {
    return (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue);
}

// 메인 함수: 색상 객체 연산 테스트
int main() {
    Color colorRed(255, 0, 0);   // 순수 빨강
    Color colorBlue(0, 0, 255);  // 순수 파랑

    // 두 색을 더한 결과를 저장
    Color result = colorRed + colorBlue;
    result.print();  // 예상 출력: 255 0 255

    Color fuchsia(255, 0, 255);  // 기대 결과

    // 색상이 같은지 비교
    if (result == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";

    return 0;
}
