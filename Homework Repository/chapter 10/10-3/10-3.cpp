#include <iostream>
using namespace std;

// ���ø� �Լ�: �迭�� ���ҵ��� �������� �ٲ��ִ� �Լ�
template <typename T>
void reverseArray(T* x, int size) {
    int j = size - 1; // ���� �ε������� ����

    // ����(i)�� ����(j)�� ��ȯ�ϸ鼭 �߾ӱ��� ����
    for (int i = 0; i < j; i++) {
        T tmp = x[j];  // �ӽ� ������ �� ��ȯ
        x[j] = x[i];
        x[i] = tmp;

        j--; // ���� �ε����� ���� (i�� �����ϹǷ� ���� j�� ����)
    }
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 }; // �׽�Ʈ �迭
    // �迭�� �������� ������
    reverseArray(x, 5);
    // ��� ���: 4 5 100 10 1
    for (int i = 0; i < 5; i++)
        cout << x[i] << ' ';
}
