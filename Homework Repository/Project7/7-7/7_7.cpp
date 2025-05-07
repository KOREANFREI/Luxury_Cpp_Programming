// 7-7 (1)
// Matrix Ŭ�������� <<, >> �����ڸ� **��� �Լ�**�� �����ε��մϴ�.
// int �迭�� ��� ���� ���� �ְ���� �� �ְ� �մϴ�.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 ����� 1���� �迭�� ������ ǥ��

public:
    // �⺻ ������: ��� 0���� �ʱ�ȭ
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // �� ���� ���� �޾� �ʱ�ȭ�ϴ� ������
    Matrix(int a, int b, int c, int d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    // ��� ���� ��� �Լ�
    void print() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // >> ������: ����� ���� �迭�� ����
    void operator>>(int* outArray) const {
        for (int i = 0; i < 4; ++i)
            outArray[i] = data[i];
    }

    // << ������: �迭�� ���� ��Ŀ� ����
    void operator<<(const int* inArray) {
        for (int i = 0; i < 4; ++i)
            data[i] = inArray[i];
    }
};

int main() {
    Matrix matA(4, 3, 2, 1);          // �ʱⰪ ������ ���
    Matrix matB;                      // �� ��� (0���� �ʱ�ȭ)

    int arrX[4];                      // ��� �� �迭 �����
    int arrY[4] = { 1, 2, 3, 4 };     // �迭 �� ��� �����

    matA >> arrX;  // matA���� arrX�� �� ����
    matB << arrY;  // arrY���� matB�� �� ����

    // �迭 ���
    for (int i = 0; i < 4; ++i)
        cout << arrX[i] << ' ';
    cout << endl;

    // ��� ���
    matB.print();

    return 0;
}
