/*
#include <stdio.h>
int sum();

int main() {
	int n = 0;
	printf("�� ���� �Է��ϼ���>>");
	scanf("%d", &n);
	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum(1, n));

}

int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;

	}
	return res;
}
*/
#include <iostream>
using namespace std;

int sum(int a, int b); //������ C++������ �Լ��� ���� ���� �Ű������� ��� �����Ͽ�����

int main() {
	int n = 0;
	cout << "�� ���� �Է��ϼ���>>";
	cin >> n;

	cout << 1 << "���� " << n << "������ ���� " << sum(1, n) << " �Դϴ�." << endl;
	return 0;
}

int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}