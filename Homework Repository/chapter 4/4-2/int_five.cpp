#include <iostream>
using namespace std;

int main() {
    // ���� �迭 ���� ������ new ���
    int* arr = new int[5];
    float avg = 0;

    // ��������� ���� 5�� �Է¹���
    cout << "���� 5�� �Է�>>";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i]; // �Է¹��� ���� �迭�� ����
        avg += arr[i]; // ��� ����Ϸ��� ����
    }

    avg /= 5; // ��� ���ϱ� (���� ������ 5)
    cout << "���: " << avg;

    // new�� ���� �迭 �޸� ���� (���ϸ� ���� ����)
    delete[] arr;

    return 0;
}
