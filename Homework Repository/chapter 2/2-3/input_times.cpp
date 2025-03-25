#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cout << "두 수를 입력하라: ";
    cin >> X >> Y;
    cout << "큰 수 = " << (X > Y ? X : Y);
    return 0;
}
