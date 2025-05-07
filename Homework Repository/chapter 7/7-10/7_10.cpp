// 7-10
// 통계 데이터를 저장하고 처리하는 Statistics 클래스
// !, <<, ~, >> 연산자를 멤버 함수로 오버로딩해서 자연스럽게 통계 처리를 할 수 있도록 구현

#include <iostream>
using namespace std;

class Statistics {
private:
    int* data;     // 동적 배열 (최대 10개 저장)
    int count;     // 현재 저장된 데이터 개수

public:
    // 생성자: 메모리 동적 할당 및 count 초기화
    Statistics() {
        data = new int[10];
        count = 0;
    }

    // 소멸자: 동적 메모리 해제
    ~Statistics() {
        delete[] data;
    }

    // 현재 비어 있는지 확인하는 연산자 (!stat)
    bool operator!() const {
        return (count == 0);  // 배열만 확인하지 말고, 실제 데이터 유무 확인
    }

    // 정수 한 개를 통계 데이터에 추가 (stat << 100)
    Statistics& operator<<(int value) {
        if (count < 10) {
            data[count++] = value;
        }
        return *this;
    }

    // ~stat: 현재 저장된 모든 데이터 출력
    void operator~() const {
        for (int i = 0; i < count; ++i)
            cout << data[i] << ' ';
        cout << endl;
    }

    // >>avg: 평균을 외부 변수에 저장
    void operator>>(float& avg) const {
        if (count == 0) {
            avg = 0;
            return;
        }
        int sum = 0;
        for (int i = 0; i < count; ++i)
            sum += data[i];
        avg = static_cast<float>(sum) / count;
    }
};

int main() {
    Statistics stat;

    if (!stat)
        cout << "현재 통계 데이타가 없습니다." << endl;

    int temp[5];
    cout << "5 개의 정수를 입력하라 >> ";
    for (int i = 0; i < 5; ++i)
        cin >> temp[i];

    // 입력된 값들을 통계 객체에 추가
    for (int i = 0; i < 5; ++i)
        stat << temp[i];

    // 추가 데이터 입력
    stat << 100 << 200;

    // 현재까지 저장된 데이터 출력
    ~stat;

    // 평균 계산
    float avg;
    stat >> avg;
    cout << "avg = " << avg << endl;

    return 0;
}
