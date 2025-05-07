// 7-6 (2)
// 연산자 오버로딩을 friend 함수로 외부에서 구현한 Matrix 클래스입니다.

#include <iostream>
using namespace std;

class Matrix {
private:
    int values[4];

public:
    // 기본 생성자
    Matrix() {
        for (int i = 0; i < 4; ++i)
            values[i] = 0;
    }

    // 4개의 정수를 받아 초기화하는 생성자
    Matrix(int x1, int x2, int x3, int x4) {
        values[0] = x1; values[1] = x2;
        values[2] = x3; values[3] = x4;
    }

    // 행렬 값 출력 함수
    void display() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << values[i] << ' ';
        cout << '}' << endl;
    }

    // 연산자 오버로딩을 위한 friend 함수 선언
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend void operator+=(Matrix& m1, const Matrix& m2);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
};

// 두 행렬을 더한 결과를 반환하는 함수
Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix result;
    for (int i = 0; i < 4; ++i)
        result.values[i] = m1.values[i] + m2.values[i];
    return result;
}

// 첫 번째 행렬에 두 번째 행렬을 더하는 함수
void operator+=(Matrix& m1, const Matrix& m2) {
    for (int i = 0; i < 4; ++i)
        m1.values[i] += m2.values[i];
}

// 두 행렬이 같은지 비교하는 함수
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
