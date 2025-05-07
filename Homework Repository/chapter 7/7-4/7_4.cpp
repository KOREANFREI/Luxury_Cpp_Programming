// 7-4
// ���ڿ��� Book ��ü�� ���ؼ�, ������ ���� ������ � �� �տ� ������ Ȯ���ϴ� �ڵ��Դϴ�.
// ���ڿ� < Book �� ������ ������ < �����ڸ� friend �Լ��� �����ε��߱� �����Դϴ�.

#include <iostream>
#include <string>  // string �ڷ��� ���� ���� ����
using namespace std;

// Book Ŭ���� ����: ����, ����, ������ ���� ����� ����
class Book {
	string title;
	int price;
	int pages;

public:
	// ������: �⺻�� �����Ͽ� title, price, pages �ʱ�ȭ
	Book(const string& t = "", int p = 0, int pg = 0) {
		title = t;
		price = p;
		pages = pg;
	}

	// å ���� ��� �Լ�
	void display() const {
		cout << title << " " << price << "�� " << pages << " ������" << endl;
	}

	// ���� ��ȯ�ϴ� �Լ�
	string getTitle() const {
		return title;
	}

	// ���ڿ� < Book �񱳸� ���� friend �Լ� ����
	friend bool operator<(const string& s, const Book& b);
};

// �ܺ� �Լ��� < ������ �����ε�
// ���ڿ� s�� Book ��ü�� ���񺸴� �տ� ���� true ��ȯ
bool operator<(const string& s, const Book& b) {
	return (s.compare(b.title) < 0);  // compare ��� (��Ȯ�ϰ� �����ϰ�)
}

// ���� �Լ�: ����ڷκ��� ���ڿ� �Է¹޾� Book ��ü�� ��
int main() {
	Book myBook("û��", 2000, 300);  // å ������ "û��"
	string inputTitle;

	cout << "å �̸��� �Է��ϼ��� >> ";
	getline(cin, inputTitle);  // ����ڷκ��� ���� �Է� (���� ���� ����)

	// �Է��� ������ å ���񺸴� ������ �տ� ���� ���
	if (inputTitle < myBook)
		cout << myBook.getTitle() << "�� " << inputTitle << "���� �ڿ� �ֱ���!" << endl;

	return 0;
}
