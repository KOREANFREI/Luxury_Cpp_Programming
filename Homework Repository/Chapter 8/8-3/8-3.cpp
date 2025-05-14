#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;

public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }

protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

// 색상이 있는 점을 표현하는 ColorPoint 클래스 (Point 상속)
class ColorPoint : public Point {
	string color;  // 색상 정보

public:
	// 생성자: 좌표와 색상 초기화
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}

	// 좌표 변경 함수
	void setPoint(int x, int y) {
		move(x, y);  // 보호된 move() 사용
	}

	// 색상 변경 함수
	void setColor(string color) {
		this->color = color;
	}

	// 현재 상태 출력
	void show() {
		cout << color << " 색 점은 (" << getX() << ", " << getY() << ") 위치에 있습니다." << endl;
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");    
	cp.setPoint(10, 20);           
	cp.setColor("BLUE");          
	cp.show();                    
	return 0;
}
