#include <iostream> 
using namespace std;

int main() {
	float a, b, c, d, e;
	cout << 5 << " ���� �Ǽ��� �Է��϶� >> ";
	cin >> a >> b >> c >> d >> e;

	float maxVal = a;

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (d > maxVal) maxVal = d;
    if (e > maxVal) maxVal = e;

	cout << "���� ū ����: " << maxVal << "\n"; 

	return 0;
}