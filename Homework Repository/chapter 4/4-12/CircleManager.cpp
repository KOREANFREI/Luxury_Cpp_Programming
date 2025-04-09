#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;  // ������ ����
    string name;  // �� �̸� ����
public:
    void setCircle(string name, int radius) {  // �̸��̶� ������ ��������
        this->radius = radius;
        this->name = name;
    }
    double getArea() {  // ���� ����ؼ� ��ȯ����
        return radius * radius * 3.14;
    }
    string getName() {  // �̸� �˷���
        return name;
    }
};

class CircleManager {
    Circle* p;  // �� ��ü �迭
    int size;  // �� ����
public:
    CircleManager(int size) {  // �����ڿ��� �� ���� �Է¹޾���
        this->size = size;
        p = new Circle[size];
        string name;
        int radius;
        for (int i = 0; i < size; i++) {
            cout << "�� " << i + 1 << "�� �̸��� ������ >>";
            cin >> name >> radius;  // �̸��̶� ������ �Է¹޾���
            p[i].setCircle(name, radius);  // ��ü�� ��������
        }
    }
    ~CircleManager() {  // �Ҹ��ڿ��� �޸� ��������
        delete[] p;
    }
    void searchByName() {  // �̸����� �˻��ϴ� ���
        string target;
        bool found = false;  // ã�Ҵ��� üũ��
        cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
        cin >> target;  // ã�� �̸� �Է¹޾���
        for (int i = 0; i < size; i++) {
            if (p[i].getName() == target) {  // �̸� ������
                cout << target << "�� ������ " << p[i].getArea() << endl;  // ���� �������
                found = true;
                break;
            }
        }
        if (!found) {  // �� ã���� ��
            cout << target << "�� ã�� �� �����ϴ�." << endl;
        }
    }
    void searchByArea() {  // �������� �˻��ϴ� ���
        int minArea;
        bool first = true;  // ù ��° �׸� üũ��
        cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
        cin >> minArea;  // �ּ� ���� �Է¹޾���
        cout << minArea << "���� ū ���� �˻��մϴ�." << endl;
        for (int i = 0; i < size; i++) {
            if (p[i].getArea() > minArea) {  // ���� �����ϴ��� Ȯ��
                if (!first) cout << ", ";  // �޸��� ����
                cout << p[i].getName() << "�� ������ " << p[i].getArea();  // ��� ���
                first = false;
            }
        }
        if (first) {  // �˻� ��� ���� ��
            cout << "���ǿ� �´� ���� �����ϴ�.";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "���� ���� >> ";
    cin >> n;  // �� ���� �Է¹޾���
    CircleManager manager(n);  // �Ŵ��� ��ü ����
    manager.searchByName();  // �̸� �˻� ����
    manager.searchByArea();  // ���� �˻� ����
}
