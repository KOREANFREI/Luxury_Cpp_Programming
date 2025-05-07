// 7-11
// Stack 클래스 구현
// << 연산자: 정수 푸시 (push)
// >> 연산자: 정수 팝 (pop)
// ! 연산자: 스택이 비었는지 확인

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;    // 동적 배열로 스택 구현
    int top;     // 스택의 맨 위 인덱스 (top of stack)

public:
    // 생성자: 배열 동적 할당 및 top 초기화
    Stack() {
        arr = new int[10];
        top = -1;
    }

    // 소멸자: 동적 메모리 해제
    ~Stack() {
        delete[] arr;
    }

    // 비어 있는지 확인 (스택이 비었으면 true 반환)
    bool operator!() const {
        return top == -1;
    }

    // 정수 하나 푸시 (push) ? << 연산자
    Stack& operator<<(int value) {
        if (top < 9)  // 최대 10개까지만 푸시
            arr[++top] = value;
        return *this;
    }

    // 정수 하나 팝 (pop) ? >> 연산자
    void operator>>(int& value) {
        if (top >= 0)
            value = arr[top--];
    }
};

int main() {
    Stack st;

    st << 3 << 5 << 10;  // 3, 5, 10을 순서대로 스택에 push

    while (true) {
        if (!st) break;  // 비었는지 확인
        int poppedValue;
        st >> poppedValue;  // 스택에서 값 꺼냄
        cout << poppedValue << ' ';  // 출력
    }

    cout << endl;
    return 0;
}
