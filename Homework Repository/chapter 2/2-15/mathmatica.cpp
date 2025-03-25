#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int X, Y;
    char math[100];
    char* symbol;
    char* context = nullptr;  // strtok_s에서 사용할 컨텍스트 포인터라고 하는데 잘 모르겠습니다
                              // atoi 함수를 쓰기 위해서는 Strtok 함수를 사용해야하는데 unsafe 하다 하여 strtok_s를 사용해 보았습니다 

    while (true) {
        cout << "? ";
        cin.getline(math, 100);

        char* token = strtok_s(math, " ", &context);
        if (token == NULL) {
            cout << "입력이 잘못되었습니다. 다시 시도하세요." << endl;
            continue;
        }
        X = atoi(token);

        token = strtok_s(NULL, " ", &context);
        if (token == NULL) {
            cout << "입력이 잘못되었습니다. 다시 시도하세요." << endl;
            continue;
        }
        symbol = token;

        token = strtok_s(NULL, " ", &context);
        if (token == NULL) {
            cout << "입력이 잘못되었습니다. 다시 시도하세요." << endl;
            continue;
        }
        Y = atoi(token);

        if (*symbol == '+') {
            cout << X << " + " << Y << " = " << X + Y << endl;
        }
        else if (*symbol == '-') {
            cout << X << " - " << Y << " = " << X - Y << endl;
        }
        else if (*symbol == '*') {
            cout << X << " * " << Y << " = " << X * Y << endl;
        }
        else if (*symbol == '/') {
            if (Y != 0) {
                cout << X << " / " << Y << " = " << X / Y << endl;
            }
            else {
                cout << "0으로 나눌 수 없습니다." << endl;
            }
        }
        else if (*symbol == '%') {
            if (Y != 0) {
                cout << X << " % " << Y << " = " << X % Y << endl;
            }
            else {
                cout << "0으로 나눌 수 없습니다." << endl;
            }
        }
        else {
            cout << "잘못된 연산자입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
