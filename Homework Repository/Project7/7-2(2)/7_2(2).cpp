// (2) == ������ �� ���� �ܺ� friend �Լ��� �ۼ��϶�.

#include <iostream>
using namespace std;

// å Ŭ���� ����: ����, ����, ������ ���� ����� ����
class Book {
	string title;
	int price;
	int pages;

public:
	// ������: �⺻�� ������ �����ؼ� ���ϰ� ���� �� ����
	Book(string t = "", int p = 0, int pg = 0) {
		title = t;
		price = p;
		pages = pg;
	}

	// å ������ ����ϴ� �Լ� (�̸��� showInfo�� �ٲ���!)
	void showInfo() const {
		cout << title << " " << price << "�� " << pages << " ������" << endl;
	}

	// ���� ��ȯ �Լ�
	string getTitle() const {
		return title;
	}

	// �ܺ� ������ �Լ����� private ����� �����Ϸ��� friend �ʿ���
	friend bool operator== (const Book& b, int p);              // ���� �񱳿�
	friend bool operator== (const Book& b, const string& t);    // ���� �񱳿�
	friend bool operator== (const Book& lhs, const Book& rhs);  // ��ü �񱳿�
};

// ������ ������ ���ϴ� �Լ�. �׳� ���ݸ� ����
bool operator== (const Book& b, int p) {
	return (b.price == p);  // ������ ������ true
}

// ������ ������ ��. compare �Լ� �Ἥ ��¦ �ٸ��� �ۼ���
bool operator== (const Book& b, const string& t) {
	return (b.title.compare(t) == 0);  // ���ڿ� �� ����� 0�̸� ����
}

// �� Book ��ü�� ������ ������ Ȯ��
bool operator== (const Book& lhs, const Book& rhs) {
	// ����, ����, ������ �� ��� ���ƾ� ���� å�̶�� �Ǵ�
	return (lhs.title == rhs.title && lhs.price == rhs.price && lhs.pages == rhs.pages);
}

// ���� �Լ�: �� �����ڵ��� �� �۵��ϴ��� �׽�Ʈ
int main() {
	Book bookA("��ǰ C++", 30000, 500);         // ù ��° å
	Book bookB("��ǰ C++", 30000, 500);         // �� ��° å

	// ������ ������ ��
	if (bookA == 30000)
		cout << "���� 30000��" << endl;

	// ������ ������ ��
	if (bookA == "��ǰ C++")
		cout << "��ǰ C++ �Դϴ�." << endl;

	// �� å�� ������ ������ �� (������ ������ �޶� �ٸ�)
	if (bookA == bookB)
		cout << "�� å�� ���� å�Դϴ�." << endl;

	return 0;
}
