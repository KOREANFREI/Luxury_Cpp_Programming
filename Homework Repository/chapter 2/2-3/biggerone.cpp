#include <iostream>
using namespace std;

int main() {
	int a, b;

	cout << "두수를 입력하여라";
	cin >> a >> b; 
	cout << "큰수 = " << (a > b ? a : b);

	return 0;
}