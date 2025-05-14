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

// ������ �ִ� ���� ǥ���ϴ� ColorPoint Ŭ���� (Point ���)
class ColorPoint : public Point {
	string color;  // ���� ����

public:
	// ������: ��ǥ�� ���� �ʱ�ȭ
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}

	// ��ǥ ���� �Լ�
	void setPoint(int x, int y) {
		move(x, y);  // ��ȣ�� move() ���
	}

	// ���� ���� �Լ�
	void setColor(string color) {
		this->color = color;
	}

	// ���� ���� ���
	void show() {
		cout << color << " �� ���� (" << getX() << ", " << getY() << ") ��ġ�� �ֽ��ϴ�." << endl;
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");    
	cp.setPoint(10, 20);           
	cp.setColor("BLUE");          
	cp.show();                    
	return 0;
}
