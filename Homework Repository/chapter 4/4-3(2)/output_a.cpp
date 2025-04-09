#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; // 문자열 저장할 변수
    int cnt = 0; // 'a' 개수 세는 변수

    // 사용자로부터 문자열 입력 받음
    cout << "문자열 입력: ";
    getline(cin, s);

    size_t index = 0; // 검색 시작 위치 초기화

    while (true) {
        index = s.find('a', index); // find()로 'a'를 검색
        if (index == string::npos) break; // 더 이상 없으면 종료
        cnt++; // 찾았으니 카운트 증가
        index++; // 다음 위치로 이동 (중복 방지)
    }

    // 결과 출력
    cout << "문자 'a'는 " << cnt << "개 있습니다." << endl;
    return 0;
}
