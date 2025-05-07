// 7-7 (1)
// Matrix 클래스에서 <<, >> 연산자를 **멤버 함수**로 오버로딩합니다.
// int 배열과 행렬 간의 값을 주고받을 수 있게 합니다.

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[4];  // 2x2 행렬을 1차원 배열로 간단히 표현

public:
    // 기본 생성자: 모두 0으로 초기화
    Matrix() {
        for (int i = 0; i < 4; ++i)
            data[i] = 0;
    }

    // 네 개의 값을 받아 초기화하는 생성자
    Matrix(int a, int b, int c, int d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    // 행렬 내용 출력 함수
    void print() const {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; ++i)
            cout << data[i] << ' ';
        cout << '}' << endl;
    }

    // >> 연산자: 행렬의 값을 배열로 복사
    void operator>>(int* outArray) const {
        for (int i = 0; i < 4; ++i)
            outArray[i] = data[i];
    }

    // << 연산자: 배열의 값을 행렬에 복사
    void operator<<(const int* inArray) {
        for (int i = 0; i < 4; ++i)
            data[i] = inArray[i];
    }
};

int main() {
    Matrix matA(4, 3, 2, 1);          // 초기값 지정된 행렬
    Matrix matB;                      // 빈 행렬 (0으로 초기화)

    int arrX[4];                      // 행렬 → 배열 저장용
    int arrY[4] = { 1, 2, 3, 4 };     // 배열 → 행렬 복사용

    matA >> arrX;  // matA에서 arrX로 값 복사
    matB << arrY;  // arrY에서 matB로 값 복사

    // 배열 출력
    for (int i = 0; i < 4; ++i)
        cout << arrX[i] << ' ';
    cout << endl;

    // 행렬 출력
    matB.print();

    return 0;
}
