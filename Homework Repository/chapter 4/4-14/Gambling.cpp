#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 게임을 관리하는 클래스
class GamblingGame {
    string playerNames[2];  // 두 명의 플레이어 이름 저장
    int turn;               // 현재 차례를 나타내는 변수

public:
    GamblingGame() {  // 생성자에서 초기화했음
        srand((unsigned)time(NULL));  // 랜덤 시드 설정했음
        turn = 0;  // 첫 번째 플레이어부터 시작

        for (int i = 0; i < 2; i++) {
            cout << i + 1 << "번째 선수 이름 >> ";
            cin >> playerNames[i];  // 이름 입력받았음
        }
        cout << endl;
    }

    void play() {  // 게임 실행 메서드
        while (true) {
            cout << playerNames[turn] << ": ";
            string dummy;
            getline(cin, dummy);  // 엔터 입력 대기

            int nums[3];  // 랜덤 숫자 배열
            for (int i = 0; i < 3; i++) {
                nums[i] = rand() % 3;  // 랜덤 숫자 생성
            }

            cout << endl << "\t\t" << nums[0] << '\t' << nums[1] << '\t' << nums[2] << '\t';
            if (nums[0] == nums[1] && nums[1] == nums[2]) {  // 숫자가 모두 같으면 승리
                cout << playerNames[turn] << "님 승리!\n";
                break;
            }
            turn = (turn + 1) % 2;  // 다음 차례로 넘어감
        }
    }
};

int main() {
    cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
    GamblingGame game;  // 게임 객체 생성했음
    game.play();        // 게임 실행했음
}
