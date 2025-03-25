#include <iostream>
using namespace std;

int main() {
    int Main_menu, order;
    string menu[3] = { "짬뽕", "짜장", "군만두" };

    cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;


    for (;;) {
        cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
        cin >> Main_menu;

        if (Main_menu == 4) {
            cout << "오늘 영업은 끝났습니다." << endl;
            break;
        }

        if (Main_menu > 0 && Main_menu < 4) {
            cout << "몇인분?";
            cin >> order;
            cout << menu[Main_menu - 1] << ' ' << order << "인분 나왔습니다" << endl;
        }
        else {
            cout << "다시 주문하세요!!" << endl;
        }
    }

    return 0;
}
