#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
    Random();
    int next();                    
    int nextInRange(int a, int b); 
};

Random::Random() {
    srand((unsigned int)time(0));
}

int Random::next() {
    int n = rand();
    if (n % 2 != 0) n++;
    return n;
}

int Random::nextInRange(int a, int b) {
    if (a % 2 != 0) a++; 
    if (b % 2 != 0) b--;
    if (a > b) return -1; 
    int range = (b - a) / 2 + 1;
    return a + (rand() % range) * 2; 
}

int main() {
    Random r;

    cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl << endl;

    cout << "-- 2���� 10������ ���� ¦�� ���� 10�� --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 10);
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
