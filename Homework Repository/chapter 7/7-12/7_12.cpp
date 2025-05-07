// 7-12
// ���� �迭�� ������������ �����ϴ� SortedArray Ŭ����
// ������, ���� ������, �Ҹ���, =, + ������ �����ε� ����

#include <iostream>
using namespace std;

class SortedArray {
private:
    int* arr;   // ���� �迭 ������
    int length; // ���� �迭 ũ��

    // ���� ���� �Լ� (��������)
    void sortAscending() {
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

public:
    // �⺻ ������: �迭 ����
    SortedArray() : arr(nullptr), length(0) {}

    // �迭�� ũ�⸦ �޾� �ʱ�ȭ�ϴ� ������
    SortedArray(int input[], int len) {
        length = len;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = input[i];
    }

    // ���� ������: ���� ���� ����
    SortedArray(const SortedArray& other) {
        length = other.length;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = other.arr[i];
    }

    // �Ҹ���: �޸� ����
    ~SortedArray() {
        delete[] arr;
    }

    // ���� ������ �����ε� (=)
    SortedArray& operator=(const SortedArray& other) {
        if (this == &other) return *this; // �ڱ� �ڽ� üũ

        delete[] arr; // ���� �޸� ��ȯ

        length = other.length;
        arr = new int[length];
        for (int i = 0; i < length; ++i)
            arr[i] = other.arr[i];

        return *this;
    }

    // ���� ������ �����ε� (+)
    SortedArray operator+(const SortedArray& other) {
        SortedArray result;
        result.length = this->length + other.length;
        result.arr = new int[result.length];

        for (int i = 0; i < this->length; ++i)
            result.arr[i] = this->arr[i];
        for (int i = 0; i < other.length; ++i)
            result.arr[this->length + i] = other.arr[i];

        return result;
    }

    // �迭 ���� ��� �Լ�
    void print() {
        sortAscending();  // ��� ���� ���� ����
        cout << "�迭 ��� : ";
        for (int i = 0; i < length; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

int main() {
    int a[] = { 2, 20, 6 };
    int b[] = { 10, 7, 8, 30 };

    SortedArray arr1(a, 3);
    SortedArray arr2(b, 4);
    SortedArray arr3;

    arr3 = arr1 + arr2;  // + ���� �� ���ο� ��ü ���� �� = �������� ����

    arr1.print();
    arr2.print();
    arr3.print();

    return 0;
}
