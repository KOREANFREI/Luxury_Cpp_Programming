// 7-8
// Circle Ŭ�������� ���� �� ���� ���� ������(++)�� friend �ܺ� �Լ��� �����ε��մϴ�.
// ������(radius)�� 1�� ������Ű�� ������ �մϴ�.

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    // ������: �⺻���� 0
    Circle(int r = 0) : radius(r) {}

    // ������ ��� �Լ�
    void display() const {
        cout << "radius = " << radius << " �� ��" << endl;
    }

    // ����, ���� �����ڸ� �ܺο��� ������ �� �ְ� friend ����
    friend Circle& operator++(Circle& c);        // ���� ����
    friend Circle operator++(Circle& c, int);    // ���� ����
};

// ���� ���� ������ (++a)
// radius�� ���� ������Ű��, �ڱ� �ڽ��� ������ ��ȯ
Circle& operator++(Circle& c) {
    ++c.radius;
    return c;  // ������ ��ü�� ������ ��ȯ
}

// ���� ���� ������ (a++)
// ���� ��ü ���¸� ������ ��, radius�� ������Ű�� ���� ���¸� ������ ��ȯ
Circle operator++(Circle& c, int) {
    Circle temp = c;  // ���� �� ���� ����
    c.radius++;
    return temp;      // ���� �� ���纻 ��ȯ
}

int main() {
    Circle circleA(5);   // ������ 5
    Circle circleB(4);   // ������ 4

    ++circleA;           // ���� ���� �� 6
    circleB = circleA++; // ���� ���� �� circleB�� 6, circleA�� 7

    circleA.display();   // ���: radius = 7 �� ��
    circleB.display();   // ���: radius = 6 �� ��

    return 0;
}
