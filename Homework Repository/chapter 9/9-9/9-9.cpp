#include <iostream>
#include <string>
using namespace std;

/*
��� �����ʹ� �𵨸�, ������, �μ� �ż�, �μ� ���� �ܷ��� ��Ÿ���� ������ ������.
print() �Լ��� show() �Լ��� ���� �Լ��� �����Ͽ�,
�� ������ Ÿ�Կ� �°� �������̵��ǵ��� �Ѵ�.

print() �Լ��� �־��� �ż���ŭ ����Ʈ�ϴ� ������ �����ϸ�,
show() �Լ��� ���� �������� �𵨸�, ������, �μ� �ż�, ���� �ܷ� ���� ���¸� ����Ѵ�.

��ũ�� �����ʹ� ��ũ �ܷ� ������,
������ �����ʹ� ��� �ܷ� ������ �߰������� ������ �־�� �ϸ�,
������ print() �Լ����� �ܷ��� üũ�� �� ��� ���θ� �����ؾ� �Ѵ�.

InkJetPrinter ��ü�� LaserPrinter ��ü�� ���� �������� �����Ͽ� ����Ѵ�.
*/

//�������� ���� ����� ������ �߻� Ŭ����
class Printer {
	string model;
	string manufacturer;
	int printedCount;     // �� ����� ������ ��
	int availableCount;   // ���� ���� ���� ��

protected:
	// ������: �ʱ� ���� ����
	Printer(string mo = "", string me = "", int a = 0) {
		model = mo;
		manufacturer = me;
		availableCount = a;
		printedCount = 0;
	}

	// ��� ���� ���� Ȯ�� (���� ���� ����)
	bool isValidPrint(int pages) {
		return availableCount >= pages;
	}

	// ���� ���� ������ (protected�� �Ļ� Ŭ�������� ���)
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }

	// ���� ������
	void setPrintedCount(int count) { printedCount = count; }
	void setAvailableCount(int count) { availableCount = count; }

	// ���� ���� �Լ� (�Ļ� Ŭ�������� �ݵ�� ����)
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

// ��ũ�� ������ Ŭ����
class InkJetPrinter : public Printer {
	int availableInk;  // ���� ��ũ��

public:
	// ������: ��ũ�� ���� �ʱ�ȭ
	InkJetPrinter(string mo = "", string me = "", int a = 0, int ink = 0)
		: Printer(mo, me, a), availableInk(ink) {
	}

	// ��ũ�� ������� Ȯ��
	bool hasEnoughInk(int pages) {
		return availableInk >= pages;
	}

	// ��� ����
	void print(int pages) override {
		if (!isValidPrint(pages)) {
			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
			return;
		}
		if (!hasEnoughInk(pages)) {
			cout << "��ũ�� �����Ͽ� ����� �� �����ϴ�." << endl;
			return;
		}
		// ��� ����
		setPrintedCount(getPrintedCount() + pages);
		setAvailableCount(getAvailableCount() - pages);
		availableInk -= pages;
		cout << "����Ʈ�߽��ϴ�." << endl;
	}

	// ���� ���� ���
	void show() override {
		cout << getModel() << ", " << getManufacturer()
			<< ", ���� ���� " << getAvailableCount()
			<< "��, ���� ��ũ " << availableInk << endl;
	}

	// ��ũ ������
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int ink) { availableInk = ink; }
};

// ������ ������ Ŭ����
class LaserPrinter : public Printer {
	int availableToner;  // ���� ��ʷ�

public:
	// ������
	LaserPrinter(string mo = "", string me = "", int a = 0, int toner = 0)
		: Printer(mo, me, a), availableToner(toner) {
	}

	// ��� ��� ���� Ȯ��
	bool hasEnoughToner(int pages) {
		return availableToner >= pages;
	}

	// ��� ����
	void print(int pages) override {
		if (!isValidPrint(pages)) {
			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
			return;
		}
		if (!hasEnoughToner(pages)) {
			cout << "��ʰ� �����Ͽ� ����� �� �����ϴ�." << endl;
			return;
		}
		// ��� ����
		setPrintedCount(getPrintedCount() + pages);
		setAvailableCount(getAvailableCount() - pages);
		availableToner -= pages;
		cout << "����Ʈ�߽��ϴ�." << endl;
	}

	// ���� ���
	void show() override {
		cout << getModel() << ", " << getManufacturer()
			<< ", ���� ���� " << getAvailableCount()
			<< "��, ���� ��� " << availableToner << endl;
	}

	// ��� ������
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int toner) { availableToner = toner; }
};

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;

	cout << "��ũ�� : ";
	ink->show();
	cout << "������ : ";
	laser->show();
	cout << endl;

	int printerType, pages;
	char cont;

	while (true) {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printerType >> pages;

		if (printerType == 1) {
			ink->print(pages);
		}
		else if (printerType == 2) {
			laser->print(pages);
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		ink->show();
		laser->show();

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> cont;
		if (cont == 'n' || cont == 'N') break;
	}

	delete ink;
	delete laser;

	return 0;
}