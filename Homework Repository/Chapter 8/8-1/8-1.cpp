#include <iostream>
#include <string>
using namespace std;

// 반지름을 가지는 Circle 클래스
class Circle {
	int radius;  // 원의 반지름

public:
	// 생성자: 기본값은 0
	Circle(int radius = 0) { this->radius = radius; }

	// 반지름 값을 반환
	int getRadius() { return radius; }

	// 반지름 값을 설정
	void setRadius(int radius) { this->radius = radius; }

	// 원의 넓이를 계산
	double getArea() { return 3.14 * radius * radius; }
};

// 이름이 붙은 원을 표현하는 NamedCircle 클래스 (Circle 상속)
class NamedCircle : public Circle {
	string label;  // 원의 이름

public:
	// 생성자: 반지름과 이름을 받아서 초기화
	NamedCircle(int r = 0, string text = "") : Circle() {
		setRadius(r);  // 부모 클래스 함수로 반지름 설정
		label = text;  // 이름 저장
	}

	// 원의 정보 출력 (반지름 + 이름)
	void show() {
		int rad = getRadius();  // getRadius() 값을 변수에 잠깐 저장
		cout << "반지름이 " << rad << "인 " << label << endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");  // 반지름 3, 이름은 "waffle"
	waffle.show();                    // 정보 출력
	return 0;
}
