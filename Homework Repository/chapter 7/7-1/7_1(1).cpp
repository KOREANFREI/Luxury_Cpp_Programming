// 7-1
// Book ��ü�� ���� ���� ������ �ϰ��� �Ѵ�.
/*
Book a("û��", 20000, 300) , b("�̷�", 30000, 500);
a += 500; // å a�� ���� 500�� ����
b -= 500; // å b�� ���� 500�� ����
a.show();
b.show();
*/

// (1) +=, -= ������ �Լ��� Book Ŭ������ ��� �Լ��� �����϶�.
#include <iostream>
using namespace std;

// Book Ŭ���� ����. å �ϳ��� ǥ���ϴ� ��ü
class Book {
    string title;    // å ����
    int price;       // å ����
    int pages;       // å ������ ��

public:
    // ������. ����, ����, ������ ���� �ʱ�ȭ����
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    // å ���� ��¿� �Լ�
    void show() {
        cout << title << " " << price << "�� " << pages << " ������" << endl;
    }

    // å ������ �������� �Լ�
    string getTitle() {
        return title;
    }

    // ��� �Լ��� +=, -= �����ε� (������ ���ϰ� ����)
    Book& operator+= (int a);  // ������ a��ŭ ������Ŵ
    Book& operator-= (int a);  // ������ a��ŭ ���ҽ�Ŵ
};

// ��� �Լ� ������� += ����
Book& Book::operator+= (int a) {
    price += a;    // ���� ����
    return *this;  // �ڱ� �ڽ� ��ȯ (ü�̴� ����)
}

// ��� �Լ� ������� -= ����
Book& Book::operator-= (int a) {
    price -= a;    // ���� ����
    return *this;
}

// ���� �Լ�: ��ü �����ϰ� ������ �����ε� �׽�Ʈ
int main() {
    Book a("û��", 20000, 300), b("�̷�", 30000, 500);

    a += 500; // û�� å ���� 500�� �ø�
    b -= 500; // �̷� å ���� 500�� ����

    a.show(); // a å ���� ���
    b.show(); // b å ���� ���
}
