#include <iostream>
using namespace std;

// 템플릿 함수: 두 배열을 연결(concatenate)하여 새로운 배열을 동적 생성
template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    int newSize = sizea + sizeb; // 전체 크기 = 두 배열의 크기 합

    T* arr = new T[newSize]; // 새 배열을 동적 생성 (반환할 배열)

    // 첫 번째 배열의 내용을 앞쪽에 복사
    for (int i = 0; i < sizea; ++i)
        arr[i] = a[i];

    // 두 번째 배열의 내용을 이어서 복사
    for (int i = 0; i < sizeb; ++i)
        arr[i + sizea] = b[i];

    return arr; // 새로 만든 배열의 포인터 반환
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };      // 첫 번째 배열
    int y[] = { 7, 2, 11, 23, 62 };      // 두 번째 배열

    // concat 함수 호출 → 두 배열을 이어붙인 새 배열 동적 생성
    int* arr = concat(x, 5, y, 5);

    // 결과 출력: 1 10 100 5 4 7 2 11 23 62
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }

    // 메모리 해제는 과제 요구 사항에 따라 생략 가능 (기말이라면 delete[] arr 필요)
}
