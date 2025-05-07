// 7-10
// ��� �����͸� �����ϰ� ó���ϴ� Statistics Ŭ����
// !, <<, ~, >> �����ڸ� ��� �Լ��� �����ε��ؼ� �ڿ������� ��� ó���� �� �� �ֵ��� ����

#include <iostream>
using namespace std;

class Statistics {
private:
    int* data;     // ���� �迭 (�ִ� 10�� ����)
    int count;     // ���� ����� ������ ����

public:
    // ������: �޸� ���� �Ҵ� �� count �ʱ�ȭ
    Statistics() {
        data = new int[10];
        count = 0;
    }

    // �Ҹ���: ���� �޸� ����
    ~Statistics() {
        delete[] data;
    }

    // ���� ��� �ִ��� Ȯ���ϴ� ������ (!stat)
    bool operator!() const {
        return (count == 0);  // �迭�� Ȯ������ ����, ���� ������ ���� Ȯ��
    }

    // ���� �� ���� ��� �����Ϳ� �߰� (stat << 100)
    Statistics& operator<<(int value) {
        if (count < 10) {
            data[count++] = value;
        }
        return *this;
    }

    // ~stat: ���� ����� ��� ������ ���
    void operator~() const {
        for (int i = 0; i < count; ++i)
            cout << data[i] << ' ';
        cout << endl;
    }

    // >>avg: ����� �ܺ� ������ ����
    void operator>>(float& avg) const {
        if (count == 0) {
            avg = 0;
            return;
        }
        int sum = 0;
        for (int i = 0; i < count; ++i)
            sum += data[i];
        avg = static_cast<float>(sum) / count;
    }
};

int main() {
    Statistics stat;

    if (!stat)
        cout << "���� ��� ����Ÿ�� �����ϴ�." << endl;

    int temp[5];
    cout << "5 ���� ������ �Է��϶� >> ";
    for (int i = 0; i < 5; ++i)
        cin >> temp[i];

    // �Էµ� ������ ��� ��ü�� �߰�
    for (int i = 0; i < 5; ++i)
        stat << temp[i];

    // �߰� ������ �Է�
    stat << 100 << 200;

    // ������� ����� ������ ���
    ~stat;

    // ��� ���
    float avg;
    stat >> avg;
    cout << "avg = " << avg << endl;

    return 0;
}
