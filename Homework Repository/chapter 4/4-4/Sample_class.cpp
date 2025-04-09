#include <iostream>
using namespace std;

class Sample {
    int* p; // 동적 배열 포인터
    int size; // 배열 사이즈

public:
    // 생성자. 배열 만들기
    Sample(int n) {
        size = n;
        p = new int[n]; // n개만큼 동적할당
    }

    // 입력 받는 함수. 사용자가 숫자 입력하면 배열에 저장
    void read() {
        cout << size << "개 숫자 입력>> ";
        for (int i = 0; i < size; i++) {
            cin >> p[i]; // 그냥 차례대로 저장
        }
    }

    // 배열 내용 출력. 그냥 화면에 찍어주는 거
    void write() {
        cout << "저장된 배열: ";
        for (int i = 0; i < size; i++) {
            cout << p[i] << " "; // 순회하면서 출력
        }
        cout << endl;
    }

    // 제일 큰 값 찾기. 처음꺼 저장하고 하나씩 비교
    int big() {
        int max = p[0]; // 일단 첫번째 값으로 초기화
        for (int i = 1; i < size; i++) {
            if (p[i] > max) max = p[i]; // 더 크면 갈아치움
        }
        return max;
    }

    // 소멸자. 할당했던 메모리 반납 필수!
    ~Sample() {
        delete[] p; // 안하면 메모리 누수
    }
};

int main() {
    Sample s(10); // 객체 생성. 크기 10으로
    s.read();     // 입력 받고
    s.write();    // 출력 하고
    cout << "가장 큰 수는? " << s.big() << endl; // 찾은 값 출력
    return 0;
}
