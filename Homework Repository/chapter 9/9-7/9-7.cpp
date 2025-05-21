
#include <iostream>
#include <string>
using namespace std;

// Shape 클래스는 공통된 도형 속성(이름, 너비, 높이)을 가진 추상적 개념
class Shape {
protected:
	string name;
	int width, height;

public:
	// 생성자: 도형 이름, 폭과 높이를 초기화
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}

	// 넓이 계산용 가상 함수 (파생 클래스에서 오버라이딩)
	virtual double getArea() {
		return 0.0;
	}

	// 도형 이름 반환
	string getName() {
		return name;
	}
};

// 타원형 도형을 표현하는 클래스 (Shape 상속)
class Oval : public Shape {
public:
	// 생성자: 폭과 높이로 타원 정의
	Oval(string n, int w, int h) : Shape(n, w, h) {}

	// 타원의 넓이 계산: πab
	double getArea() override {
		return width * height * 3.14;
	}
};

// 직사각형 도형 클래스
class Rect : public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) {}

	// 사각형 넓이: 가로 × 세로
	double getArea() override {
		return width * height;
	}
};

// 삼각형 도형 클래스
class Triangular : public Shape {
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) {}

	// 삼각형 넓이: (가로 × 높이) ÷ 2
	double getArea() override {
		return (width * height) * 0.5;
	}
};


int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++) {
		cout << p[i]->getName() << " 넓이 " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
	return 0;
}