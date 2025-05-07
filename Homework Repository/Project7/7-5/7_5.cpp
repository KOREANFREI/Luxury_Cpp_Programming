// 7-5 (1)
// Color 클래스: 빨강(red), 초록(green), 파랑(blue) 성분을 가지는 색상 클래스입니다.
// 연산자 오버로딩을 통해 색상 덧셈과 비교를 멤버 함수로 구현합니다.

#include <iostream>
using namespace std;

class Color {
private:
    int red, green, blue;

public:
    // 기본 생성자: 검정색(0,0,0)으로 초기화
    Color() : red(0), green(0), blue(0) {}

    // 매개변수 생성자: 사용자가 지정한 색상 값으로 초기화
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    // 색상 값 출력 함수
    void print() const {
        cout << red << ' ' << green << ' ' << blue << endl;
    }

    // + 연산자 오버로딩: 색상끼리 더하기
    Color operator+(const Color& other) const {
        return Color(red + other.red, green + other.green, blue + other.blue);
    }

    // == 연산자 오버로딩: 색상 값이 완전히 같을 때 true 반환
    bool operator==(const Color& other) const {
        return (red == other.red && green == other.green && blue == other.blue);
    }
};

// 메인 함수: 색상 객체를 더하고 비교해보기
int main() {
    Color colorRed(255, 0, 0);      // 빨강 색
    Color colorBlue(0, 0, 255);     // 파랑 색
    Color mixedColor;

    mixedColor = colorRed + colorBlue;  // 두 색을 더함 → 보라색
    mixedColor.print();                 // 출력 결과: 255 0 255

    Color fuchsia(255, 0, 255);         // 비교용 색상

    // 같은 색인지 확인
    if (mixedColor == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";

    return 0;
}
