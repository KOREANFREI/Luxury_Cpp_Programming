#include <iostream>
#include <vector>
#include <numeric>  // accumulate 사용을 위한 헤더

using namespace std;

int main() {
    vector<int> v;
    int input;

    while (true) {
        cout << "정수를 입력하세요(0을 입력하면 종료)>> ";
        cin >> input;

        if (input == 0) break;

        v.push_back(input);

        // 입력된 벡터 요소 출력
        for (int n : v) {
            cout << n << ' ';
        }

        // 평균 계산 및 출력
        double sum = accumulate(v.begin(), v.end(), 0);
        cout << endl << "평균 = " << sum / v.size() << endl;
    }
}
