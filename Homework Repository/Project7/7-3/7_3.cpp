// 7-3
// ! �����ڸ� �����ε��ؼ� å�� ��¥���� Ȯ���ϴ� �ڵ��Դϴ�.
// å�� ������ 0�̸� ��¥�� �����մϴ�. (!book �� ��¥ å �Ǻ�)

#include <iostream>
using namespace std;

// Book Ŭ���� ����: ����, ����, ������ ���� ����� ����
class Book {
private:
    string title;
    int price;
    int pages;

public:
    // ������: å�� �⺻ ������ �ʱ�ȭ��
    Book(const string& t = "", int p = 0, int pg = 0) {
        title = t;
        price = p;
        pages = pg;
    }

    // å ������ ����ϴ� �Լ�
    void display() const {
        cout << title << " " << price << "�� " << pages << " ������" << endl;
    }

    // ���� �������� �Լ�
    string getTitle() const {
        return title;
    }

    // ! ������ �����ε�: ������ 0�̸� true ��ȯ (��¥ å)
    bool operator!() const;
};

// ! ������ ����: å ������ 0�̸� ��¥�� ����
bool Book::operator!() const {
    return (price == 0);  // ���ǹ� ���� ������ ǥ��
}

// ���� �Լ�: ��¥ å���� ���θ� ! �����ڸ� ���� Ȯ��
int main() {
    Book fleaBook("�������", 0, 50);  // ������ 0�� å

    // ! �����ڸ� ���� ��¥���� �Ǻ�
    if (!fleaBook)
        cout << "��¥��" << endl;

    return 0;
}
