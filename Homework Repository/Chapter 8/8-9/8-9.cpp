#include <iostream>
#include <string>
using namespace std;

// ���� �¼� Ŭ����: �̸� ���� �� ����/��� ��� ����
class Seat {
	string name;

public:
	Seat(string n = "---") { name = n; }

	// �¼� ����
	void reservation(string n) { name = n; }

	// �¼� ��� (�̸��� �⺻������ �ʱ�ȭ)
	void cancle() { name = "---"; }

	// ���� �¼� ���� ���
	void show() { cout << name; }
};

// �ð��� ������ Ŭ���� (�¼� �迭 ����)
class Schedule {
	Seat* schedule;     // �¼� 8��
	string time;        // ���� �ð�

public:
	// ������: �¼� �迭 �Ҵ�, �ð� �ʱⰪ ����
	Schedule(string time = "00��") {
		schedule = new Seat[8];
		this->time = time;
	}

	// Ư�� �¼��� ������ �̸� ���
	void reservation(int index, string name) {
		schedule[index].reservation(name);
	}

	// Ư�� �¼� ���� ���
	void cancle(int index) {
		schedule[index].cancle();
	}

	// ��ü �¼� ���� ���
	void show() {
		for (int i = 0; i < 8; i++) {
			schedule[i].show();
			cout << "\t";
		}
		cout << endl;
	}

	// �ð� ����
	void setTime(string time) {
		this->time = time;
	}

	// �ð� ��ȯ
	string getTime() {
		return time;
	}
};

// �װ��� ��ü ���� �ý��� Ŭ���� (�� 3���� ����� ����)
class AirlineBook {
	Schedule* airlines;

public:
	// ������: 3���� Schedule ���� �� �ð� ����
	AirlineBook() {
		airlines = new Schedule[3];
		airlines[0].setTime("07��");
		airlines[1].setTime("12��");
		airlines[2].setTime("17��");
	}

	// Ư�� �ð��� ���� ��Ȳ ���
	void show(int index) {
		cout << airlines[index].getTime() << '\t';
		airlines[index].show();
	}

	// �¼� ����
	void reservation(int index, int seat, string name) {
		airlines[index].reservation(seat, name);
	}

	// �¼� ���
	void cancle(int index, int seat, string name) {
		airlines[index].cancle(seat);
	}
};

// ����� �Է� �� �޴� ó���� ����ϴ� Console Ŭ����
class Console {
public:
	static int menu;
	static int time;
	static AirlineBook hansung;

	// ���α׷� ���� ������
	static void start() {
		cout << "***** �Ѽ��װ� ���� �ý��ۿ� ���� ���� ȯ���մϴ� *****" << endl;
		while (true) {
			showMenu();
			switch (menu) {
			case 1:
				reservation(); break;
			case 2:
				cancle(); break;
			case 3:
				show(); break;
			case 4:
				cout << "���α׷��� �����մϴ�." << endl;
				return;
			default:
				cout << "�ùٸ� �޴� ��ȣ�� �Է��ϼ���." << endl;
			}
		}
	}

	// �޴� ��� �� ����
	static void showMenu() {
		cout << "\n����:1, ���:2, ��ȸ:3, ����:4 >> ";
		cin >> menu;
	}

	// ���� ó��
	static void reservation() {
		cout << "�ð� ���� - 07��:1, 12��:2, 17��:3 >> ";
		cin >> time;

		hansung.show(time - 1);

		int seatNum;
		string name;

		cout << "�¼� ��ȣ (1~8) >> ";
		cin >> seatNum;

		cout << "������ �̸� >> ";
		cin >> name;

		hansung.reservation(time - 1, seatNum - 1, name);
	}

	// ��� ó��
	static void cancle() {
		cout << "�ð� ���� - 07��:1, 12��:2, 17��:3 >> ";
		cin >> time;

		hansung.show(time - 1);

		int seatNum;
		string name;

		cout << "�¼� ��ȣ (1~8) >> ";
		cin >> seatNum;

		cout << "������ �̸� >> ";
		cin >> name;

		hansung.cancle(time - 1, seatNum - 1, name);
	}

	// ��ü ���� ��Ȳ ���
	static void show() {
		for (int i = 0; i < 3; i++) {
			hansung.show(i);
		}
	}
};

// ���� ���� ����
int Console::menu = 0;
int Console::time = 0;
AirlineBook Console::hansung;

// ���� �Լ�
int main() {
	Console::start();
	return 0;
}
