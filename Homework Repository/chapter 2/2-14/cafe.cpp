#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char coffee[100];
    int number;
    int sum_money = 0;

    cout << "���������� " << 2000 << "��, �Ƹ޸�ī�� "
        << 2300 << "��, īǪġ�� "
        << 2500 << "���Դϴ�." << endl;

    for (;;) {
        cout << "�ֹ�>> ";
        cin >> coffee >> number;

        if (strcmp(coffee, "����������") == 0) {
            cout << 2000 * number << "���Դϴ�. ���ְ� �弼��.\n";
            sum_money += 2000 * number;
        }
        else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) {
            cout << 2300 * number << "���Դϴ�. ���ְ� �弼��.\n";
            sum_money += 2300 * number;
        }
        else if (strcmp(coffee, "īǪġ��") == 0) {
            cout << 2500 * number << "���Դϴ�. ���ְ� �弼��.\n";
            sum_money += 2500 * number;
        }

        if (sum_money >= 20000) {
            cout << "���� " << sum_money << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~" << endl;
            break;
        }
    }

    return 0;
}
