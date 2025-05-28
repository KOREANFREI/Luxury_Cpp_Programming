#include <iostream>
using namespace std;

// ���ø� �Լ�: �� �迭�� ����(concatenate)�Ͽ� ���ο� �迭�� ���� ����
template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    int newSize = sizea + sizeb; // ��ü ũ�� = �� �迭�� ũ�� ��

    T* arr = new T[newSize]; // �� �迭�� ���� ���� (��ȯ�� �迭)

    // ù ��° �迭�� ������ ���ʿ� ����
    for (int i = 0; i < sizea; ++i)
        arr[i] = a[i];

    // �� ��° �迭�� ������ �̾ ����
    for (int i = 0; i < sizeb; ++i)
        arr[i + sizea] = b[i];

    return arr; // ���� ���� �迭�� ������ ��ȯ
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };      // ù ��° �迭
    int y[] = { 7, 2, 11, 23, 62 };      // �� ��° �迭

    // concat �Լ� ȣ�� �� �� �迭�� �̾���� �� �迭 ���� ����
    int* arr = concat(x, 5, y, 5);

    // ��� ���: 1 10 100 5 4 7 2 11 23 62
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }

    // �޸� ������ ���� �䱸 ���׿� ���� ���� ���� (�⸻�̶�� delete[] arr �ʿ�)
}
