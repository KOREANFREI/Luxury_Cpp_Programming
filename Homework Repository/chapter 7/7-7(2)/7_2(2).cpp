// (2) <<, >> 연산자를 Matrix 클래스의 프렌드 함수로 외부에서 구현합니다.
// int 배열과 Matrix 객체 간의 값 복사를 연산자처럼 표현할 수 있도록 오버로딩합니다.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 행렬을 일차원 배열로 표현

public:
    // 기본 생성자: 전부 0으로 초기화
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // 초기값을 받는 생성자
    Matrix(int a, int b, int c, int d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    // 행렬 출력 함수
    void print() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // 외부 연산자 함수를 위해 friend 선언
    friend void operator>>(const Matrix& m, int* outArray);
    friend void operator<<(Matrix& m, const int* inArray);
};

// Matrix에서 int 배열로 값 복사 (Matrix >> 배열)
void operator>>(const Matrix& m, int* outArray) {
    for (int i = 0; i < 4; ++i)
        outArray[i] = m.data[i];
}

// int 배열에서 Matrix로 값 복사 (Matrix << 배열)
void operator<<(Matrix& m, const int* inArray) {
    for (int i = 0; i < 4; ++i)
        m.data[i] = inArray[i];
}

int main() {
    Matrix matA(4, 3, 2, 1);
    Matrix matB;

    int arrX[4];                  // matA에서 복사될 배열
    int arrY[4] = { 1, 2, 3, 4 }; // matB로 복사될 배열

    matA >> arrX;  // Matrix 데이터를 배열로 복사
    matB << arrY;  // 배열 데이터를 Matrix에 대입

    // 복사된 배열 출력
    for (int i = 0; i < 4; ++i)
        cout << arrX[i] << ' ';
    cout << endl;

    // 행렬 출력
    matB.print();

    return 0;
}
