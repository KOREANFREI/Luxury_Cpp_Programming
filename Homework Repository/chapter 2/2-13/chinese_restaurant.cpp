#include <iostream>
using namespace std;

int main() {
    int Main_menu, order;
    string menu[3] = { "«��", "¥��", "������" };

    cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;


    for (;;) {
        cout << "«��:1, ¥��:2, ������:3, ����:4>>";
        cin >> Main_menu;

        if (Main_menu == 4) {
            cout << "���� ������ �������ϴ�." << endl;
            break;
        }

        if (Main_menu > 0 && Main_menu < 4) {
            cout << "���κ�?";
            cin >> order;
            cout << menu[Main_menu - 1] << ' ' << order << "�κ� ���Խ��ϴ�" << endl;
        }
        else {
            cout << "�ٽ� �ֹ��ϼ���!!" << endl;
        }
    }

    return 0;
}
