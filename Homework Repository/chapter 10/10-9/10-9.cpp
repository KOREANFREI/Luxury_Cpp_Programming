#include <iostream>
#include <vector>
#include <numeric>  // accumulate ����� ���� ���

using namespace std;

int main() {
    vector<int> v;
    int input;

    while (true) {
        cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>> ";
        cin >> input;

        if (input == 0) break;

        v.push_back(input);

        // �Էµ� ���� ��� ���
        for (int n : v) {
            cout << n << ' ';
        }

        // ��� ��� �� ���
        double sum = accumulate(v.begin(), v.end(), 0);
        cout << endl << "��� = " << sum / v.size() << endl;
    }
}
