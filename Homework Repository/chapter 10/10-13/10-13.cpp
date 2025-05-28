#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, int> hScore;  // �̸��� ������ �����ϴ� map �����̳�
	string name;
	int score;
	int menu;
	bool conti = true;

	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << endl;

	while (conti) {
		cout << "�Է�:1, ��ȸ:2, ����: 3 >>  ";
		cin >> menu;

		switch (menu) {
		case 1:
			// �̸��� ������ �Է¹޾� map�� ����
			cout << "�̸��� ����>> ";
			cin >> name >> score;
			hScore.insert(make_pair(name, score));  // ������ �̸��� �̹� ������ ���Ե��� ����
			break;

		case 2:
			// �̸����� ������ ��ȸ
			cout << "�̸�>> ";
			cin >> name;

			// �ش� �̸��� map�� �����ϴ��� Ȯ��
			if (hScore.find(name) == hScore.end())
				cout << "�ش��ϴ� �̸� ����" << endl;
			else
				cout << name << "�� ������ " << hScore[name] << endl;
			break;

		case 3:
			// ����
			cout << "���α׷��� �����մϴ�...";
			conti = false;
			break;
		}
	}
}
