#include <iostream>
using namespace std;


class Circle { // Circle Ŭ���� ����
private: 
	double radius;
public:
	void setRadius(double r) {// ������ ����
		radius = r;
	}
	double getArea() { // ���� ���
		return 3.14 * radius * radius;
	}
};

int main() {	
	Circle c[3]; //3���� Circle ��ü �迭 ����
	int r = 0;	// ������ �ʱ�ȭ
	int cnt = 0; // ���� �ʱ�ȭ

	for (int i = 1; i <= 3; i++) { // ���� �̸�����	1, 2, 3���� ����
		cout << "��" << i << "�� ������ >> ";
		cin >> r;
		c[i].setRadius(r); // ������ ����
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "������ 100���� ū ���� ������ " << cnt << "���Դϴ�." << endl;
}