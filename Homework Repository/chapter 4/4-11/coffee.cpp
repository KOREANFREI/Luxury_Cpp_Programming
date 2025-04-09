#include <iostream>
using namespace std;

class Container {
	int size;  // ����� ��
public:
	Container() { size = 10; }  // ������ ȣ������
	void fill() { size = 10; }  // ��Ḧ ä����
	void consume() { if (size > 0) size--; }  // ��Ḧ �ϳ� �������
	int getSize() { return size; }  // ���� ��� �� ��ȯ����
};

class CoffeVendingMachine {
	Container tong[3];  // Ŀ��, ��, ���� ����� �����̳� �迭
	void fill() {  // ��� ��Ḧ ä����
		for (Container& c : tong) {
			c.fill();  // �� �����̳� ä���
		}
	}
	void selectEspresso() {  // ���������� �������
		tong[0].consume();
		tong[1].consume();
	}
	void selectAmericano() {  // �Ƹ޸�ī�� �������
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
	}
	void selectSugarCoffee() {  // ����Ŀ�� �������
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
	}
	void show() {  // ���� ���� ǥ������
		cout << "Ŀ�� " << tong[0].getSize()
			<< ", �� " << tong[1].getSize()
			<< ", ���� " << tong[2].getSize() << endl;
	}
public:
	void run() {  // ���Ǳ� �۵� ��������
		int menu;
		cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
		while (true) {
			cout << "�޴��� �����ּ���(1.����������, 2.�Ƹ޸�ī��, 3.����Ŀ��, 4.�ܷ�����, 5.ä���) >>";
			cin >> menu;
			switch (menu) {
			case 1:  // ���������� ��������
				if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
					cout << "���ᰡ �����մϴ�." << endl;
				}
				else {
					selectEspresso();
					cout << "���������� �弼��." << endl;
				}
				break;
			case 2:  // �Ƹ޸�ī�� ��������
				if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
					cout << "���ᰡ �����մϴ�." << endl;
				}
				else {
					selectAmericano();
					cout << "�Ƹ޸�ī�� �弼��." << endl;
				}
				break;
			case 3:  // ����Ŀ�� ��������
				if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
					cout << "���ᰡ �����մϴ�." << endl;
				}
				else {
					selectSugarCoffee();
					cout << "����Ŀ�� �弼��." << endl;
				}
				break;
			case 4:  // �ܷ� Ȯ������
				show();
				break;
			case 5:  // ��� ä����
				fill();
				show();
				break;
			default:
				break;  // �ƹ��͵� �� ����
			}
		}
	}
};

int main() {
	CoffeVendingMachine machine;  // ���Ǳ� ��ü ��������
	machine.run();                // ���Ǳ� �۵�����
	return 0;
}
