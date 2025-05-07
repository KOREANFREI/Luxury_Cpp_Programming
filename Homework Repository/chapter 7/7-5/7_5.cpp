// 7-5 (1)
// Color Ŭ����: ����(red), �ʷ�(green), �Ķ�(blue) ������ ������ ���� Ŭ�����Դϴ�.
// ������ �����ε��� ���� ���� ������ �񱳸� ��� �Լ��� �����մϴ�.

#include <iostream>
using namespace std;

class Color {
private:
    int red, green, blue;

public:
    // �⺻ ������: ������(0,0,0)���� �ʱ�ȭ
    Color() : red(0), green(0), blue(0) {}

    // �Ű����� ������: ����ڰ� ������ ���� ������ �ʱ�ȭ
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    // ���� �� ��� �Լ�
    void print() const {
        cout << red << ' ' << green << ' ' << blue << endl;
    }

    // + ������ �����ε�: ���󳢸� ���ϱ�
    Color operator+(const Color& other) const {
        return Color(red + other.red, green + other.green, blue + other.blue);
    }

    // == ������ �����ε�: ���� ���� ������ ���� �� true ��ȯ
    bool operator==(const Color& other) const {
        return (red == other.red && green == other.green && blue == other.blue);
    }
};

// ���� �Լ�: ���� ��ü�� ���ϰ� ���غ���
int main() {
    Color colorRed(255, 0, 0);      // ���� ��
    Color colorBlue(0, 0, 255);     // �Ķ� ��
    Color mixedColor;

    mixedColor = colorRed + colorBlue;  // �� ���� ���� �� �����
    mixedColor.print();                 // ��� ���: 255 0 255

    Color fuchsia(255, 0, 255);         // �񱳿� ����

    // ���� ������ Ȯ��
    if (mixedColor == fuchsia)
        cout << "����� ����";
    else
        cout << "����� �ƴ�";

    return 0;
}
