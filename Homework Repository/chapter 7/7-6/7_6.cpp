// 7-6 (1)
// 2x2 Matrix 클래스 구현 - 덧셈, 누적 덧셈, 동등 비교 연산자를 멤버 함수로 오버로딩합니다.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 행렬을 1차원 배열로 표현

public:
    // 기본 생성자: 모든 원소를 0으로 초기화
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // 4개의 원소를 직접 초기화하는 생성자
    Matrix(int a, int b, int c, int d) {
        data[0] = a; data[1] = b;
        data[2] = c; data[3] = d;
    }

    // 행렬 내용을 출력
    void display() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // 덧셈 연산자 오버로딩
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 4; ++i)
            result.data[i] = this->data[i] + other.data[i];
        return result;
    }

    // 누적 덧셈 (+=) 연산자 오버로딩
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < 4; ++i)
            data[i] += other.data[i];
        return *this;
    }

    // 동등 비교 (==) 연산자 오버로딩
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

    Matrix C = A + B;  // A와 B를 더한 결과
    A += B;            // A에 B를 더한 결과를 다시 A에 저장

    A.display();
    B.display();
    C.display();

    if (A == C)
        cout << "a and c are the same" << endl;

    return 0;
}
