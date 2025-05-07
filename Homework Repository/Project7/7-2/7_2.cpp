// 7-2

//(1) �� ���� == ������ �Լ��� ���� Book Ŭ������ �ۼ��϶�.
#include <iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << " " << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() {
		return title;
	}

	// price, title, ��ü ��
	bool operator== (int price);
	bool operator== (string title);
	bool operator== (Book b);
};

bool Book::operator== (int price) {
	if (this->price == price)
		return true;
	return false;
}
bool Book::operator== (string title) {
	if (this->title == title)
		return true;
	return false;
}
bool Book::operator== (Book b) {
	if (this->title == b.title && this->price == b.price
		&& this->pages == b.pages)
		return true;
	return false;
}

int main() {
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl; // price �� 
	if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // å title �� 
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl;  // title, price, pages ��� �� 
}

