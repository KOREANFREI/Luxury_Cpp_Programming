#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���� å ������ ��� Book Ŭ����
class Book {
private:
    string title, author; // å ����� ����
    int year;             // ���� ����

public:
    Book(); // �⺻ ������
    Book(string title, string author, int year); // �Ű����� �ִ� ������

    void set(string title, string author, int year); // å ���� ����
    string getAuthor() { return author; }            // ���� ��ȯ
    int getYear() { return year; }                   // ���� ���� ��ȯ
    void show();                                     // å ���� ���
};

// �⺻ ������: �ʱⰪ ����
Book::Book() {
    title = "";
    author = "";
    year = 1000; // ���������� �ʱⰪ���� ����
}

// �Ű����� �ִ� ������
Book::Book(string title, string author, int year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

// set �Լ�: å ������ �Է¹޾� ��� ������ ����
void Book::set(string title, string author, int year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

// å ������ ����ϴ� �Լ�
void Book::show() {
    cout << year << "�⵵, " << title << ", " << author << endl;
}


// ���� å�� �����ϴ� BookManager Ŭ����
class BookManager {
private:
    vector<Book> v;             // å ������ ��� ����
    void bookIn();              // å �԰� ó��
    void searchByAuthor();      // ���� �˻�
    void searchByYear();        // ���� �˻�

public:
    void run(); // ��ü ���� �帧
};

// å�� �԰�޴� �Լ� (�ݺ� �Է�, -1�̸� ����)
void BookManager::bookIn() {
    int year;
    string title, author;
    Book bk;

    cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl;
    while (true) {
        cout << "�⵵>> ";
        cin >> year;
        cin.ignore(); // �ٹٲ� ���� ���� (getline ���)

        if (year == -1)
            break;

        cout << "å�̸�>> ";
        getline(cin, title);

        cout << "����>> ";
        getline(cin, author);

        bk.set(title, author, year); // å ���� ����
        v.push_back(bk);             // ���Ϳ� �߰�
    }

    cout << "�� �԰�� å�� " << v.size() << "���Դϴ�." << endl;
}

// ����ڰ� �Է��� ���� �̸����� �˻�
void BookManager::searchByAuthor() {
    cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>> ";
    string author;
    getline(cin, author); // ��ü �̸� �Է� �ޱ�

    for (int i = 0; i < v.size(); ++i) {
        Book bk = v[i];
        if (author == bk.getAuthor())
            bk.show(); // ��ġ�ϴ� ��� ���
    }
}

// ����ڰ� �Է��� ������ �˻�
void BookManager::searchByYear() {
    cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>> ";
    int year;
    cin >> year;

    for (int i = 0; i < v.size(); ++i) {
        Book bk = v[i];
        if (year == bk.getYear())
            bk.show(); // ��ġ�ϴ� ��� ���
    }
}

// ��ü �帧�� ����
void BookManager::run() {
    bookIn();          // å �Է�
    searchByAuthor();  // ���� �˻�
    searchByYear();    // ���� �˻�
}

// main �Լ�: ���α׷� ������
int main() {
    BookManager man;
    man.run();
}
