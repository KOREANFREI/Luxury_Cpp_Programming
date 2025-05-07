// 7-6 (1)
// 2x2 Matrix Ŭ���� ���� - ����, ���� ����, ���� �� �����ڸ� ��� �Լ��� �����ε��մϴ�.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 ����� 1���� �迭�� ǥ��

public:
    // �⺻ ������: ��� ���Ҹ� 0���� �ʱ�ȭ
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // 4���� ���Ҹ� ���� �ʱ�ȭ�ϴ� ������
    Matrix(int a, int b, int c, int d) {
        data[0] = a; data[1] = b;
        data[2] = c; data[3] = d;
    }

    // ��� ������ ���
    void display() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // ���� ������ �����ε�
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 4; ++i)
            result.data[i] = this->data[i] + other.data[i];
        return result;
    }

    // ���� ���� (+=) ������ �����ε�
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < 4; ++i)
            data[i] += other.data[i];
        return *this;
    }

    // ���� �� (==) ������ �����ε�
    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 4; ++i)
            if (data[i] != other.data[i])
                return false;
        return true;
    }
};

int main() {
    Matrix A(1, 2, 3, 4);
    Matrix B(2, 3, 4, 5);

    Matrix C = A + B;  // A�� B�� ���� ���
    A += B;            // A�� B�� ���� ����� �ٽ� A�� ����

    A.display();
    B.display();
    C.display();

    if (A == C)
        cout << "a and c are the same" << endl;

    return 0;
}
