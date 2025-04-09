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
	Color screenColor(255, 0, 0); // �������� screenColor ��ü ����
	Color* p;					  // ColorŸ���� ������ ���� p ����
	p = &screenColor;		// (1) p�� ScreenColor�� �ּҸ� �������� �ڵ� �ۼ�
	p->show();				// (2) p�� show()�� �̿��Ͽ�SCreenColor�� ���� ���
	Color colors[3];		// (3) ColorŸ���� colors �迭�� ����, ���Ҵ� 3��
	p = colors;				// (4) p�� colors[0]�� �ּҸ� �������� �ڵ� �ۼ�
	

	//(5) p�� setColor()�� �̿��Ͽ� colors[0], colors[1], colors[2]�� ���� ����, �ʷ�, �Ķ����� �������� �ڵ� �ۼ� 

	p[0].setcolor(255, 0, 0); // colors[1]�� �������� ����
	p[1].setcolor(0, 255, 0); // colors[2]�� �ʷϻ��� ����
	p[2].setcolor(0, 0, 255); // colors[3]�� �Ķ����� ����

	//(6) p�� show()�� �̿��Ͽ� colors[0], colors[1], colors[2]�� ���� ��� for �� �̿�
	for (int i = 0; i < 3; i++) {
		p[i].show();

	}

}