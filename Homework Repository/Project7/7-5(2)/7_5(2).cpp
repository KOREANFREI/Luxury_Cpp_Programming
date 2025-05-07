// (2) +�� == �����ڸ� Color Ŭ������ friend �Լ��� ������ �ڵ��Դϴ�.
// r, g, b ���� ���ϰų� ���� �� �ֵ��� �����ڸ� �ܺο��� �����ϰ� friend�� ����մϴ�.

#include <iostream>
using namespace std;

class Color {
private:
    int red, green, blue;

public:
    // �⺻ ������: ������(0,0,0)
    Color() : red(0), green(0), blue(0) {}

    // �Ű����� ������: �Է°����� ���� �ʱ�ȭ
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    // ���� ������ ����ϴ� �Լ�
    void print() const {
        cout << red << ' ' << green << ' ' << blue << endl;
    }

    // friend �Լ��� �����Ͽ� private ��� ���� ���
    friend Color operator+(const Color& c1, const Color& c2);
    friend bool operator==(const Color& c1, const Color& c2);
};

// + ������ ����: �� ������ �� ��Ҹ� ���� ���ο� �� ��ȯ
Color operator+(const Color& c1, const Color& c2) {
    return Color(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue);
}

// == ������ ����: �� ���� ��Ұ� ��� ������ true ��ȯ
bool operator==(const Color& c1, const Color& c2) {
    return (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue);
}

// ���� �Լ�: ���� ��ü ���� �׽�Ʈ
int main() {
    Color colorRed(255, 0, 0);   // ���� ����
    Color colorBlue(0, 0, 255);  // ���� �Ķ�

    // �� ���� ���� ����� ����
    Color result = colorRed + colorBlue;
    result.print();  // ���� ���: 255 0 255

    Color fuchsia(255, 0, 255);  // ��� ���

    // ������ ������ ��
    if (result == fuchsia)
        cout << "����� ����";
    else
        cout << "����� �ƴ�";

    return 0;
}
