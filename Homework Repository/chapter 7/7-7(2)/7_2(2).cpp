// (2) <<, >> �����ڸ� Matrix Ŭ������ ������ �Լ��� �ܺο��� �����մϴ�.
// int �迭�� Matrix ��ü ���� �� ���縦 ������ó�� ǥ���� �� �ֵ��� �����ε��մϴ�.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 ����� ������ �迭�� ǥ��

public:
    // �⺻ ������: ���� 0���� �ʱ�ȭ
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // �ʱⰪ�� �޴� ������
    Matrix(int a, int b, int c, int d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    // ��� ��� �Լ�
    void print() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // �ܺ� ������ �Լ��� ���� friend ����
    friend void operator>>(const Matrix& m, int* outArray);
    friend void operator<<(Matrix& m, const int* inArray);
};

// Matrix���� int �迭�� �� ���� (Matrix >> �迭)
void operator>>(const Matrix& m, int* outArray) {
    for (int i = 0; i < 4; ++i)
        outArray[i] = m.data[i];
}

// int �迭���� Matrix�� �� ���� (Matrix << �迭)
void operator<<(Matrix& m, const int* inArray) {
    for (int i = 0; i < 4; ++i)
        m.data[i] = inArray[i];
}

int main() {
    Matrix matA(4, 3, 2, 1);
    Matrix matB;

    int arrX[4];                  // matA���� ����� �迭
    int arrY[4] = { 1, 2, 3, 4 }; // matB�� ����� �迭

    matA >> arrX;  // Matrix �����͸� �迭�� ����
    matB << arrY;  // �迭 �����͸� Matrix�� ����

    // ����� �迭 ���
    for (int i = 0; i < 4; ++i)
        cout << arrX[i] << ' ';
    cout << endl;

    // ��� ���
    matB.print();

    return 0;
}
