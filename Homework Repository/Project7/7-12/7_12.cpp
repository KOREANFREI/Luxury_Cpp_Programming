// 7-12
// 정수 배열을 오름차순으로 유지하는 SortedArray 클래스
// 생성자, 복사 생성자, 소멸자, =, + 연산자 오버로딩 구현

#include <iostream>
using namespace std;

class SortedArray {
private:
    int* arr;   // 동적 배열 포인터
    int length; // 현재 배열 크기

    // 내부 정렬 함수 (오름차순)
    void sortAscending() {
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

public:
    // 기본 생성자: 배열 없음
    SortedArray() : arr(nullptr), length(0) {}

    // 배열과 크기를 받아 초기화하는 생성자
    SortedArray(int input[], int len) {
        length = len;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = input[i];
    }

    // 복사 생성자: 깊은 복사 수행
    SortedArray(const SortedArray& other) {
        length = other.length;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = other.arr[i];
    }

    // 소멸자: 메모리 해제
    ~SortedArray() {
        delete[] arr;
    }

    // 대입 연산자 오버로딩 (=)
    SortedArray& operator=(const SortedArray& other) {
        if (this == &other) return *this; // 자기 자신 체크

        delete[] arr; // 기존 메모리 반환

        length = other.length;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = other.arr[i];

        return *this;
    }

    // 덧셈 연산자 오버로딩 (+)
    SortedArray operator+(const SortedArray& other) {
        SortedArray result;
        result.length = this->length + other.length;
        result.arr = new int[result.length];

        for (int i = 0; i < this->length; ++i)
            result.arr[i] = this->arr[i];
        for (int i = 0; i < other.length; ++i)
            result.arr[this->length + i] = other.arr[i];

        return result;
    }

    // 배열 내용 출력 함수
    void print() {
        sortAscending();  // 출력 전에 정렬 수행
        cout << "배열 출력 : ";
        for (int i = 0; i < length; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

int main() {
    int a[] = { 2, 20, 6 };
    int b[] = { 10, 7, 8, 30 };

    SortedArray arr1(a, 3);
    SortedArray arr2(b, 4);
    SortedArray arr3;

    arr3 = arr1 + arr2;  // + 연산 → 새로운 객체 생성 → = 연산으로 복사

    arr1.print();
    arr2.print();
    arr3.print();

    return 0;
}
