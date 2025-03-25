#include <iostream> 
using namespace std;

int main() {
	float a, b, c, d, e;
	cout << 5 << " 개의 실수를 입력하라 >> ";
	cin >> a >> b >> c >> d >> e;

	float maxVal = a;

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (d > maxVal) maxVal = d;
    if (e > maxVal) maxVal = e;

	cout << "가장 큰 값은: " << maxVal << "\n"; 

	return 0;
}