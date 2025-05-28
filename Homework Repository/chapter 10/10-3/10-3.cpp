#include <iostream>
using namespace std;

// 템플릿 함수: 배열의 원소들을 역순으로 바꿔주는 함수
template <typename T>
void reverseArray(T* x, int size) {
    int j = size - 1; // 뒤쪽 인덱스부터 시작

    // 앞쪽(i)과 뒤쪽(j)을 교환하면서 중앙까지 진행
    for (int i = 0; i < j; i++) {
        T tmp = x[j];  // 임시 변수로 값 교환
        x[j] = x[i];
        x[i] = tmp;

        j--; // 뒤쪽 인덱스를 줄임 (i는 증가하므로 따로 j만 감소)
    }
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 }; // 테스트 배열
    // 배열을 역순으로 뒤집기
    reverseArray(x, 5);
    // 결과 출력: 4 5 100 10 1
    for (int i = 0; i < 5; i++)
        cout << x[i] << ' ';
}
