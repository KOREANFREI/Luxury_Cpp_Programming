// 7-1
// Book ��ü�� ���� ���� ������ �ϰ��� �Ѵ�.
/*
Book a("û��", 20000, 300) , b("�̷�", 30000, 500);
a += 500; // å a�� ���� 500�� ����
b -= 500; // å b�� ���� 500�� ����
a.show();
b.show();
*/

// (2) +=, -= ������ �Լ��� Book Ŭ������ **�ܺ� �Լ�(friend �Լ�)**�� �����϶�.

#include <iostream>
using namespace std;

// Book Ŭ���� ����. å ����, ����, ������ ���� ����� ����
class Book {
    string title;    // å ����
    int price;       // å ����
    int pages;       // å ������ ��

public:
    // ������. �⺻���� �־ �׳� Book() �̷��� �ᵵ ��
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    // å ���� ��� �Լ�
    void show() {
        cout << title << " " << price << "�� " << pages << " ������" << endl;
    }

    // ���� ���� ������ �� �ִ� �Լ�
    string getTitle() {
        return title;
    }

    // �ܺ� �Լ��ε�, Ŭ���� ���� �� �ٲٷ��� friend�� �������� ��
    friend Book& operator+= (Book& b, int a);  // ���� �ø� �� ���� ������
    friend Book& operator-= (Book& b, int a);  // ���� ���� �� ���� ������
};

// += ������ �ܺ� �Լ� ����
// Book ��ü�� price�� a��ŭ ������
Book& operator+= (Book& b, int a) {
    b.price += a;
    return b; // �ڱ� �ڽ� �����ؾ� += += �̷� �͵� ����
}

// -= ������ �ܺ� �Լ� ����
// Book ��ü�� price�� a��ŭ ����
Book& operator-= (Book& b, int a) {
    b.price -= a;
    return b;
}

// ���� �Լ�: ��ü ����� ������ �׽�Ʈ
int main() {
    Book a("û��", 20000, 300), b("�̷�", 30000, 500);

    a += 500; // a�� ������ 500�� �ö�
    b -= 500; // b�� ������ 500�� ������

    a.show(); // ��� ���
    b.show();
}
