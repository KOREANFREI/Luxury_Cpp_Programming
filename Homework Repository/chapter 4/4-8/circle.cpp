#include <iostream>
using namespace std;


class Circle { // Circle Ŭ���� ����
private:
	double radius;
public:
	void setRadius(int radius) { this->radius = radius; } // ������ ����
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int r = 0;	// ������ �ʱ�ȭ
	int cnt = 0; // ���� �ʱ�ȭ

	int n;	// ���� ���� �ʱ�ȭ

	cout << "���� ���� >> ";
	cin >> n;
	Circle* c = new Circle[n]; // Circle ��ü ���� �Ҵ�

	for (int i = 1; i <= n; i++) { // ���� ������ n ���� ����
		cout << "��" << i << "�� ������ >> ";
		cin >> r;
		c[i].setRadius(r); // ������ ����
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "������ 100���� ū ���� ������ " << cnt << "���Դϴ�." << endl;
}
