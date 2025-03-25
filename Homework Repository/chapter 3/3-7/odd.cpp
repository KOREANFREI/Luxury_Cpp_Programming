#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
    Random();
    int nextOdd();
    int nextEven();
    int nextOddInRange(int a, int b);
    int nextEvenInRange(int a, int b);
};

Random::Random() {
    srand((unsigned int)time(0));
}

int Random::nextOdd() {
    int n = rand();
    if (n % 2 == 0) n++;
    return n;
}

int Random::nextEven() {
    int n = rand();
    if (n % 2 != 0) n++;
    return n;
}

int Random::nextOddInRange(int a, int b) {
    if (a % 2 == 0) a++;
    if (b % 2 == 0) b--;
    if (a > b) return -1;
    int range = (b - a) / 2 + 1;
    return a + (rand() % range) * 2;
}

int Random::nextEvenInRange(int a, int b) {
    if (a % 2 != 0) a++;
    if (b % 2 != 0) b--;
    if (a > b) return -1;
    int range = (b - a) / 2 + 1;
    return a + (rand() % range) * 2;
}

int main() {
    Random r;

    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextEven();
        cout << n << ' ';
    }
    cout << endl << endl;

    cout << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextOddInRange(2, 9);
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
