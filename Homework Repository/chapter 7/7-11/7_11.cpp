// 7-11
// Stack Ŭ���� ����
// << ������: ���� Ǫ�� (push)
// >> ������: ���� �� (pop)
// ! ������: ������ ������� Ȯ��

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;    // ���� �迭�� ���� ����
    int top;     // ������ �� �� �ε��� (top of stack)

public:
    // ������: �迭 ���� �Ҵ� �� top �ʱ�ȭ
    Stack() {
        arr = new int[10];
        top = -1;
    }

    // �Ҹ���: ���� �޸� ����
    ~Stack() {
        delete[] arr;
    }

    // ��� �ִ��� Ȯ�� (������ ������� true ��ȯ)
    bool operator!() const {
        return top == -1;
    }

    // ���� �ϳ� Ǫ�� (push) ? << ������
    Stack& operator<<(int value) {
        if (top < 9)  // �ִ� 10�������� Ǫ��
            arr[++top] = value;
        return *this;
    }

    // ���� �ϳ� �� (pop) ? >> ������
    void operator>>(int& value) {
        if (top >= 0)
            value = arr[top--];
    }
};

int main() {
    Stack st;

    st << 3 << 5 << 10;  // 3, 5, 10�� ������� ���ÿ� push

    while (true) {
        if (!st) break;  // ������� Ȯ��
        int poppedValue;
        st >> poppedValue;  // ���ÿ��� �� ����
        cout << poppedValue << ' ';  // ���
    }

    cout << endl;
    return 0;
}
