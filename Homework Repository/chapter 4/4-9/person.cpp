#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;  // �̸� �����
    string tel;   // ��ȭ��ȣ �����
public:
    Person() {  // ������ ȣ�� �� �ʱ�ȭ����
        name = "";
        tel = "";
    }
    string getName() {  // �̸� ��ȯ�ϴ� �Լ���
        return name;
    }
    string getTel() {  // ��ȭ��ȣ ��ȯ�ϴ� �Լ���
        return tel;
    }
    void set(string name, string tel) {  // �̸��̶� ��ȭ��ȣ ��������
        this->name = name;
        this->tel = tel;
    }
};

int main() {
    Person p[3];  // Person ��ü �迭 �������

    cout << "�̸��� ��ȭ��ȣ�� �Է��� �ּ���\n" << endl;
    for (int i = 0; i < 3; i++) {
        string name, tel;
        cout << "��� " << i + 1 << ">> ";
        cin >> name >> tel;  // �Է¹޾���
        p[i].set(name, tel);  // ��ü�� ��������
    }

    cout << "��� ����� �̸�: "
        << p[0].getName() << " "
        << p[1].getName() << " "
        << p[2].getName() << endl;  // ����� �̸� �������

    cout << "��ȭ��ȣ �˻��� �̸�>> ";
    string target;
    cin >> target;  // �˻��� �̸� �Է¹޾���

    for (int i = 0; i < 3; i++) {
        if (p[i].getName() == target) {  // �Է��� �̸��̶� ������
            cout << "��ȭ��ȣ: " << p[i].getTel() << endl;  // ã���� ��ȭ��ȣ �����
            return 0;  // ã������ ����
        }
    }

    cout << "�˻� ����" << endl;  // �� ã���� ���� �޽��� �������
    return 0;
}
