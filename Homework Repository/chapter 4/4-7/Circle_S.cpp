#include <iostream>
using namespace std;


class Circle { // Circle 클래스 정의
private: 
	double radius;
public:
	void setRadius(double r) {// 반지름 설정
		radius = r;
	}
	double getArea() { // 면적 계산
		return 3.14 * radius * radius;
	}
};

int main() {	
	Circle c[3]; //3개의 Circle 객체 배열 선언
	int r = 0;	// 반지름 초기화
	int cnt = 0; // 개수 초기화

	for (int i = 1; i <= 3; i++) { // 원의 이름으롰	1, 2, 3으로 설정
		cout << "원" << i << "의 반지름 >> ";
		cin >> r;
		c[i].setRadius(r); // 반지름 설정
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원의 개수는 " << cnt << "개입니다." << endl;
}