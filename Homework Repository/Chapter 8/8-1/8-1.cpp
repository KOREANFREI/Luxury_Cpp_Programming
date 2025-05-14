#include <iostream>
#include <string>
using namespace std;

// �������� ������ Circle Ŭ����
class Circle {
	int radius;  // ���� ������

public:
	// ������: �⺻���� 0
	Circle(int radius = 0) { this->radius = radius; }

	// ������ ���� ��ȯ
	int getRadius() { return radius; }

	// ������ ���� ����
	void setRadius(int radius) { this->radius = radius; }

	// ���� ���̸� ���
	double getArea() { return 3.14 * radius * radius; }
};

// �̸��� ���� ���� ǥ���ϴ� NamedCircle Ŭ���� (Circle ���)
class NamedCircle : public Circle {
	string label;  // ���� �̸�

public:
	// ������: �������� �̸��� �޾Ƽ� �ʱ�ȭ
	NamedCircle(int r = 0, string text = "") : Circle() {
		setRadius(r);  // �θ� Ŭ���� �Լ��� ������ ����
		label = text;  // �̸� ����
	}

	// ���� ���� ��� (������ + �̸�)
	void show() {
		int rad = getRadius();  // getRadius() ���� ������ ��� ����
		cout << "�������� " << rad << "�� " << label << endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");  // ������ 3, �̸��� "waffle"
	waffle.show();                    // ���� ���
	return 0;
}
