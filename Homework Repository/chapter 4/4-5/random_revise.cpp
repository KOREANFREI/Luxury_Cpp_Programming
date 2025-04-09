#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    string s; // 문자열 변수 선언. 사용자 입력 받을 거임
    srand((unsigned int)time(0)); // 난수 생성 시드 설정. 매번 다른 값 나오게 하려고 사용함

    // 프로그램 시작 메시지 출력
    cout << "아래에 한 줄을 입력하세요.(exit을 입력하면 종료합니다)" << endl;

    while (true) { // 무한 루프. exit 입력할 때까지 반복됨
        cout << ">>"; // 입력 프롬프트 출력
        getline(cin, s); // 사용자가 한 줄 입력함. 공백 포함 가능

        if (s == "exit") break; // exit 입력하면 루프 종료

        // 랜덤한 위치에 랜덤한 문자 삽입
        // rand() % s.size(): 문자열 길이 내에서 랜덤 위치 선택
        // 97 + (rand() % 26): 'a'부터 'z' 사이의 랜덤 소문자 생성
        s[rand() % s.size()] = 97 + (rand() % 26); 

        cout << s << endl; // 수정된 문자열 출력
    }

    return 0; // 프로그램 종료
}
