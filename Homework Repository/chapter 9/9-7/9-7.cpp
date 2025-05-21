
#include <iostream>
#include <string>
using namespace std;

// Shape Ŭ������ ����� ���� �Ӽ�(�̸�, �ʺ�, ����)�� ���� �߻��� ����
class Shape {
protected:
	string name;
	int width, height;

public:
	// ������: ���� �̸�, ���� ���̸� �ʱ�ȭ
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}

	// ���� ���� ���� �Լ� (�Ļ� Ŭ�������� �������̵�)
	virtual double getArea() {
		return 0.0;
	}

	// ���� �̸� ��ȯ
	string getName() {
		return name;
	}
};

// Ÿ���� ������ ǥ���ϴ� Ŭ���� (Shape ���)
class Oval : public Shape {
public:
	// ������: ���� ���̷� Ÿ�� ����
	Oval(string n, int w, int h) : Shape(n, w, h) {}

	// Ÿ���� ���� ���: ��ab
	double getArea() override {
		return width * height * 3.14;
	}
};

// ���簢�� ���� Ŭ����
class Rect : public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) {}

	// �簢�� ����: ���� �� ����
	double getArea() override {
		return width * height;
	}
};

// �ﰢ�� ���� Ŭ����
class Triangular : public Shape {
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) {}

	// �ﰢ�� ����: (���� �� ����) �� 2
	double getArea() override {
		return (width * height) * 0.5;
	}
};


int main() {
	Shape* p[3];
	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30, 40);
	p[2] = new Triangular("�佺Ʈ", 30, 40);

	for (int i = 0; i < 3; i++) {
		cout << p[i]->getName() << " ���� " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
	return 0;
}