#include <iostream>
using namespace std;


class Circle { // Circle 클래스 정의
private:
	double radius;
public:
	void setRadius(int radius) { this->radius = radius; } // 반지름 설정
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int r = 0;	// 반지름 초기화
	int cnt = 0; // 개수 초기화

	int n;	// 원의 개수 초기화

	cout << "원의 개수 >> ";
	cin >> n;
	Circle* c = new Circle[n]; // Circle 객체 동적 할당

	for (int i = 1; i <= n; i++) { // 원의 개수를 n 으로 설정
		cout << "원" << i << "의 반지름 >> ";
		cin >> r;
		c[i].setRadius(r); // 반지름 설정
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원의 개수는 " << cnt << "개입니다." << endl;
}
