#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; // 문자열 저장할 변수
    int cnt = 0; // 'a' 개수 세는 변수

    // 사용자로부터 문자열 입력 받음
    cout << "문자열 입력: ";
    getline(cin, s);

    // 문자열의 각 문자 검사
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'a') { // at()으로 문자 확인
            cnt++; // 'a' 발견하면 카운트 증가
        }
    }

    // 결과 출력
    cout << "문자 'a'는 " << cnt << "개 있습니다." << endl;
    return 0;
}
