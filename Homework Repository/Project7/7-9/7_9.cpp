// 7-9
// Circle Ŭ������ ���� ������ ���� ����(int + Circle)�� �����ϱ� ���� ������ �����ε��Դϴ�.
// �� ������ �ܺ� friend �Լ��� ���ǵǾ�߸� �����մϴ� (������ ���ʿ� ���� ����).

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    // ������: �⺻ �������� 0
    Circle(int r = 0) : radius(r) {}

    // ���� �������� ���
    void display() const {
        cout << "radius = " << radius << " �� ��" << endl;
    }

    // ���� + Circle ������ ������ ���� friend �Լ� ����
    friend Circle operator+(int r, const Circle& c);
};

// ������ Circle�� ���ϴ� ������ �����ε�
// �������� r + c.radius�� ����ؼ� ���ο� Circle ��ȯ
Circle operator+(int r, const Circle& c) {
    return Circle(r + c.radius);  // �ٷ� ������ �̿�
}

int main() {
    Circle circleA(5);         // ������ 5�� ��
    Circle circleB(4);         // ������ 4�� ��

    // 1 + circleA: ������ ���� ������ ���� �� circleB�� ����
    circleB = 1 + circleA;

    // ��� ���
    circleA.display();         // radius = 5 �� ��
    circleB.display();         // radius = 6 �� ��

    return 0;
}
