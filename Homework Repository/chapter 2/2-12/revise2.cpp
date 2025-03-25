/*
#include <stdio.h>
int sum();

int main() {
	int n = 0;
	printf("끝 수를 입력하세요>>");
	scanf("%d", &n);
	printf("1에서 %d까지의 합은 %d입니다.\n", n, sum(1, n));

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

int sum(int a, int b); //교재曰 C++에서는 함수의 원형 선언에 매개변수를 모두 선언하여야함

int main() {
	int n = 0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;

	cout << 1 << "에서 " << n << "까지의 합은 " << sum(1, n) << " 입니다." << endl;
	return 0;
}

int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}