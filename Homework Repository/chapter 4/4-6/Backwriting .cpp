#include <iostream> 
#include <string>
using namespace std;

int main() {
	string s;
	cout << "�Ʒ��� ������ �Է��ϼ���.(exit�� �Է��ϸ� ����˴ϴ�.)" << endl;

	while (true) { // exit ���������� ��� �ݺ��ϴ� ���ѷ��� ����
		cout << " >>";// �Է� ���� ��� 
		getline(cin, s); // ���� �Է¹ޱ�, cin >>�� ������ �������� �Է¹ޱ� ������ getline ���

		if (s == "exit") { // exit �Է½� ����
			break; // ���ѷ��� Ż��
		}

		// �Է¹��� ���ڿ��� �Ųٷ� ���
		for (int i = s.length() - 1; i >= 0; i--) { // ���ڿ� ���� -1 ���� 0���� �Ųٷ� ���
			cout << s[i]; // �Ųٷ� ���
		}
		cout << endl; // �ٹٲ�
	}
	return 0;
}
