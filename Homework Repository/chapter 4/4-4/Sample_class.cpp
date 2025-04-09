#include <iostream>
using namespace std;

class Sample {
    int* p; // ���� �迭 ������
    int size; // �迭 ������

public:
    // ������. �迭 �����
    Sample(int n) {
        size = n;
        p = new int[n]; // n����ŭ �����Ҵ�
    }

    // �Է� �޴� �Լ�. ����ڰ� ���� �Է��ϸ� �迭�� ����
    void read() {
        cout << size << "�� ���� �Է�>> ";
        for (int i = 0; i < size; i++) {
            cin >> p[i]; // �׳� ���ʴ�� ����
        }
    }

    // �迭 ���� ���. �׳� ȭ�鿡 ����ִ� ��
    void write() {
        cout << "����� �迭: ";
        for (int i = 0; i < size; i++) {
            cout << p[i] << " "; // ��ȸ�ϸ鼭 ���
        }
        cout << endl;
    }

    // ���� ū �� ã��. ó���� �����ϰ� �ϳ��� ��
    int big() {
        int max = p[0]; // �ϴ� ù��° ������ �ʱ�ȭ
        for (int i = 1; i < size; i++) {
            if (p[i] > max) max = p[i]; // �� ũ�� ����ġ��
        }
        return max;
    }

    // �Ҹ���. �Ҵ��ߴ� �޸� �ݳ� �ʼ�!
    ~Sample() {
        delete[] p; // ���ϸ� �޸� ����
    }
};

int main() {
    Sample s(10); // ��ü ����. ũ�� 10����
    s.read();     // �Է� �ް�
    s.write();    // ��� �ϰ�
    cout << "���� ū ����? " << s.big() << endl; // ã�� �� ���
    return 0;
}
