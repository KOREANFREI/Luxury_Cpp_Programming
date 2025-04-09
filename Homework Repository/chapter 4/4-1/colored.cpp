#include <iostream>
using namespace std;

class Color {
	int red, green, blue;	
public:
	Color() {
		red = green = blue = 0;
	}
	Color(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
	void setcolor(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}	
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
};

int main() {
	Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
	Color* p;					  // Color타입의 포인터 변수 p 생성
	p = &screenColor;		// (1) p가 ScreenColor의 주소를 가지도록 코드 작성
	p->show();				// (2) p와 show()를 이용하여SCreenColor의 색을 출력
	Color colors[3];		// (3) Color타입의 colors 배열을 선언, 원소는 3개
	p = colors;				// (4) p가 colors[0]의 주소를 가지도록 코드 작성
	

	//(5) p와 setColor()을 이용하여 colors[0], colors[1], colors[2]가 각각 빨강, 초록, 파랑색을 가지도록 코드 작성 

	p[0].setcolor(255, 0, 0); // colors[1]에 빨간색을 대입
	p[1].setcolor(0, 255, 0); // colors[2]에 초록색을 대입
	p[2].setcolor(0, 0, 255); // colors[3]에 파란색을 대입

	//(6) p와 show()를 이용하여 colors[0], colors[1], colors[2]의 색을 출력 for 문 이용
	for (int i = 0; i < 3; i++) {
		p[i].show();

	}

}