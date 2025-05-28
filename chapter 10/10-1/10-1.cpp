#include <iostream>
using namespace std;

// 템플릿 함수: 다양한 타입의 배열에서 최대값을 찾는 함수
template <typename T>
T biggest(T* x, int size) {
    T big = x[0]; // 첫 번째 원소를 초기 최대값으로 설정

    // 모든 원소를 순회하면서 가장 큰 값을 찾음
    for (int i = 0; i < size; i++) {
        if (x[i] > big)
            big = x[i]; // 더 큰 값을 발견하면 big 갱신
    }

    return big; // 최종 최대값 반환
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 }; // 테스트용 정수 배열
    cout << biggest(x, 5) << endl;  // 최대값 출력 (100)
}
