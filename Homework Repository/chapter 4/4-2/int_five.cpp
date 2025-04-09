#include <iostream>
using namespace std;

int main() {
    // 동적 배열 만들어서 쓰려고 new 사용
    int* arr = new int[5];
    float avg = 0;

    // 사용자한테 숫자 5개 입력받음
    cout << "정수 5개 입력>>";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i]; // 입력받은 숫자 배열에 저장
        avg += arr[i]; // 평균 계산하려고 더함
    }

    avg /= 5; // 평균 구하기 (총합 나누기 5)
    cout << "평균: " << avg;

    // new로 만든 배열 메모리 해제 (안하면 문제 생김)
    delete[] arr;

    return 0;
}
