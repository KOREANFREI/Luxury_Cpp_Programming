#include <iostream>
using namespace std;

// ���ø� �Լ�: �پ��� Ÿ���� �迭���� �ִ밪�� ã�� �Լ�
template <typename T>
T biggest(T* x, int size) {
    T big = x[0]; // ù ��° ���Ҹ� �ʱ� �ִ밪���� ����

    // ��� ���Ҹ� ��ȸ�ϸ鼭 ���� ū ���� ã��
    for (int i = 0; i < size; i++) {
        if (x[i] > big)
            big = x[i]; // �� ū ���� �߰��ϸ� big ����
    }

    return big; // ���� �ִ밪 ��ȯ
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 }; // �׽�Ʈ�� ���� �迭
    cout << biggest(x, 5) << endl;  // �ִ밪 ��� (100)
}
