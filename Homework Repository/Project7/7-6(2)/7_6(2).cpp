// 7-6 (2)
// ������ �����ε��� friend �Լ��� �ܺο��� ������ Matrix Ŭ�����Դϴ�.

#include <iostream>
using namespace std;

class Matrix {
private:
    int values[4];

public:
    // �⺻ ������
    Matrix() {
        for (int i = 0; i < 4; ++i)
            values[i] = 0;
    }

    // 4���� ������ �޾� �ʱ�ȭ�ϴ� ������
    Matrix(int x1, int x2, int x3, int x4) {
        values[0] = x1; values[1] = x2;
        values[2] = x3; values[3] = x4;
    }

    // ��� �� ��� �Լ�
    void display() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << values[i] << ' ';
        cout << '}' << endl;
    }

    // ������ �����ε��� ���� friend �Լ� ����
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend void operator+=(Matrix& m1, const Matrix& m2);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
};

// �� ����� ���� ����� ��ȯ�ϴ� �Լ�
Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix result;
    for (int i = 0; i < 4; ++i)
        result.values[i] = m1.values[i] + m2.values[i];
    return result;
}

// ù ��° ��Ŀ� �� ��° ����� ���ϴ� �Լ�
void operator+=(Matrix& m1, const Matrix& m2) {
    for (int i = 0; i < 4; ++i)
        m1.values[i] += m2.values[i];
}

// �� ����� ������ ���ϴ� �Լ�
bool operator==(const Matrix& m1, const Matrix& m2) {
    for (int i = 0; i < 4; ++i)
        if (m1.values[i] != m2.values[i])
            return false;
    return true;
}

int main() {
    Matrix A(1, 2, 3, 4);
    Matrix B(2, 3, 4, 5);
    Matrix C = A + B;

    A += B;

    A.display();
    B.display();
    C.display();

    if (A == C)
        cout << "a and c are the same" << endl;

    return 0;
}
