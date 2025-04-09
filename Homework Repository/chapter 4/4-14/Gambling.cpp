#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ������ �����ϴ� Ŭ����
class GamblingGame {
    string playerNames[2];  // �� ���� �÷��̾� �̸� ����
    int turn;               // ���� ���ʸ� ��Ÿ���� ����

public:
    GamblingGame() {  // �����ڿ��� �ʱ�ȭ����
        srand((unsigned)time(NULL));  // ���� �õ� ��������
        turn = 0;  // ù ��° �÷��̾���� ����

        for (int i = 0; i < 2; i++) {
            cout << i + 1 << "��° ���� �̸� >> ";
            cin >> playerNames[i];  // �̸� �Է¹޾���
        }
        cout << endl;
    }

    void play() {  // ���� ���� �޼���
        while (true) {
            cout << playerNames[turn] << ": ";
            string dummy;
            getline(cin, dummy);  // ���� �Է� ���

            int nums[3];  // ���� ���� �迭
            for (int i = 0; i < 3; i++) {
                nums[i] = rand() % 3;  // ���� ���� ����
            }

            cout << endl << "\t\t" << nums[0] << '\t' << nums[1] << '\t' << nums[2] << '\t';
            if (nums[0] == nums[1] && nums[1] == nums[2]) {  // ���ڰ� ��� ������ �¸�
                cout << playerNames[turn] << "�� �¸�!\n";
                break;
            }
            turn = (turn + 1) % 2;  // ���� ���ʷ� �Ѿ
        }
    }
};

int main() {
    cout << "***** ���� ������ �����մϴ�. *****" << endl;
    GamblingGame game;  // ���� ��ü ��������
    game.play();        // ���� ��������
}
