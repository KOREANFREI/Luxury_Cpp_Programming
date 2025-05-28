#include <iostream>
using namespace std;

// Circle Ŭ���� ����: ���� �������� �����ϰ� �� ������ ���� ��� ����
class Circle {
    int radius;  // ������ ����

public:
    Circle(int radius = 1);  // ������: �⺻ �������� 1
    int getRadius() { return radius; }  // ������ ��ȯ

    bool operator>(Circle op2);  // ������ > �����ε�
};

// ������ ����
Circle::Circle(int radius) {
    this->radius = radius;
}

// > ������ �����ε�: �� ���� ������ ��
bool Circle::operator>(Circle op2) {
    if (radius > op2.radius)
        return true;
    else
        return false;
}

// ���ø� �Լ� bigger: �� ���� �� �� ū ���� ��ȯ
template <class T>
T bigger(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int a = 20, b = 50, c;
    c = bigger(a, b);  // int�� ��
    cout << "20�� 50�� ū ���� " << c << endl;

    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);  // Circle ��ü ��
    cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
}
