//cin.getline(buf,10000,';');�� �̿��Ͽ� �ؽ�Ʈ�� Ű����� ���� ������ �ȴ�. 
// ���ڸ� �ҹ��ڷ� �ٲ� �� tolower(char c)�Լ��� �̿��ϰ�,
//���ĺ����� �˻��ϱ� ���� isalpha(charc) �Լ��� �̿��϶�, �ؽ�Ʈ �Է��� ���� �Ϸ���
//�Է��� �ؽ�Ʈ�� �޸��忡 �Է����� ctrl-c�� �����ϰ� ,DOS ����â�� ���콺 ������ ��ư�� ������ �����ֱ⸦ �����ϸ� �ȴ�.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char buf[10000];
    int alpha[26] = { 0 };
    int total = 0;

    
    cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�.\n" << "�ؽ�Ʈ�� ���� ;�Դϴ�. 10000������ �����մϴ�.\n";
    cin.getline(buf, 10000, ';');

    for (int i = 0; buf[i] != '\0'; i++) {
        if (isalpha(buf[i])) {
            char lower = tolower(buf[i]);
            alpha[lower - 'a']++;
            total++;
        }
    }

    cout << "�� ���ĺ� �� " << total << "\n\n";

    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'a') << " (" << alpha[i] << ")\t: ";
        for (int j = 0; j < alpha[i]; j++) {
            cout << '*';
        }
        cout << "\n";
    }

    return 0;
}
