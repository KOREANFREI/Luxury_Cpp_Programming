#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; // ���ڿ� ������ ����
    int cnt = 0; // 'a' ���� ���� ����

    // ����ڷκ��� ���ڿ� �Է� ����
    cout << "���ڿ� �Է�: ";
    getline(cin, s);

    size_t index = 0; // �˻� ���� ��ġ �ʱ�ȭ

    while (true) {
        index = s.find('a', index); // find()�� 'a'�� �˻�
        if (index == string::npos) break; // �� �̻� ������ ����
        cnt++; // ã������ ī��Ʈ ����
        index++; // ���� ��ġ�� �̵� (�ߺ� ����)
    }

    // ��� ���
    cout << "���� 'a'�� " << cnt << "�� �ֽ��ϴ�." << endl;
    return 0;
}
