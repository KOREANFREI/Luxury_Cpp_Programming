#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int X, Y;
    char math[100];
    char* symbol;
    char* context = nullptr;  // strtok_s���� ����� ���ؽ�Ʈ �����Ͷ�� �ϴµ� �� �𸣰ڽ��ϴ�
                              // atoi �Լ��� ���� ���ؼ��� Strtok �Լ��� ����ؾ��ϴµ� unsafe �ϴ� �Ͽ� strtok_s�� ����� ���ҽ��ϴ� 

    while (true) {
        cout << "? ";
        cin.getline(math, 100);

        char* token = strtok_s(math, " ", &context);
        if (token == NULL) {
            cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �õ��ϼ���." << endl;
            continue;
        }
        X = atoi(token);

        token = strtok_s(NULL, " ", &context);
        if (token == NULL) {
            cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �õ��ϼ���." << endl;
            continue;
        }
        symbol = token;

        token = strtok_s(NULL, " ", &context);
        if (token == NULL) {
            cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �õ��ϼ���." << endl;
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
                cout << "0���� ���� �� �����ϴ�." << endl;
            }
        }
        else if (*symbol == '%') {
            if (Y != 0) {
                cout << X << " % " << Y << " = " << X % Y << endl;
            }
            else {
                cout << "0���� ���� �� �����ϴ�." << endl;
            }
        }
        else {
            cout << "�߸��� �������Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}
