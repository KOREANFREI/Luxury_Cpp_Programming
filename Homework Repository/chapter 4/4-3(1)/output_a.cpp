#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; // ���ڿ� ������ ����
    int cnt = 0; // 'a' ���� ���� ����

    // ����ڷκ��� ���ڿ� �Է� ����
    cout << "���ڿ� �Է�: ";
    getline(cin, s);

    // ���ڿ��� �� ���� �˻�
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'a') { // at()���� ���� Ȯ��
            cnt++; // 'a' �߰��ϸ� ī��Ʈ ����
        }
    }

    // ��� ���
    cout << "���� 'a'�� " << cnt << "�� �ֽ��ϴ�." << endl;
    return 0;
}
