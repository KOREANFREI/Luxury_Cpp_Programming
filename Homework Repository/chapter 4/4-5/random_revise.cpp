#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    string s; // ���ڿ� ���� ����. ����� �Է� ���� ����
    srand((unsigned int)time(0)); // ���� ���� �õ� ����. �Ź� �ٸ� �� ������ �Ϸ��� �����

    // ���α׷� ���� �޽��� ���
    cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;

    while (true) { // ���� ����. exit �Է��� ������ �ݺ���
        cout << ">>"; // �Է� ������Ʈ ���
        getline(cin, s); // ����ڰ� �� �� �Է���. ���� ���� ����

        if (s == "exit") break; // exit �Է��ϸ� ���� ����

        // ������ ��ġ�� ������ ���� ����
        // rand() % s.size(): ���ڿ� ���� ������ ���� ��ġ ����
        // 97 + (rand() % 26): 'a'���� 'z' ������ ���� �ҹ��� ����
        s[rand() % s.size()] = 97 + (rand() % 26); 

        cout << s << endl; // ������ ���ڿ� ���
    }

    return 0; // ���α׷� ����
}
