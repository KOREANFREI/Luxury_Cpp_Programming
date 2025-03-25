#include <iostream>
using namespace std;

class coffeeMachine {
private:
    int coffee;
    int sugar;
    int water;

public:
    coffeeMachine(int c, int w, int s) {
        coffee = c;
        water = w;
        sugar = s;
    }

    void show() {
        cout << "커피 머신 상태,\t  커피: " << coffee << "\t물: " << water << "\t설탕: " << sugar << endl;
    }

    void fill() {
        coffee = 10;
        water = 10;
        sugar = 10;
    }

    void drinkEspresso() {
        if (coffee < 1 || water < 1) {
            cout << "재료가 부족하여 맛이 다를 수 있습니다." << endl; // 재료가 부족하면 음수가 나오는 경우가 발생해서 재료가 부족하면 남은 재료를 다쓰는 코드로 만들어 보았습니다 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 1, 0);
    }

    void drinkAmericano() {
        if (coffee < 1 || water < 2) {
            cout << "재료가 부족하여 맛이 다를 수 있습니다." << endl;// 재료가 부족하면 음수가 나오는 경우가 발생해서 재료가 부족하면 남은 재료를 다쓰는 코드로 만들어 보았습니다 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 2, 0);
    }

    void drinkSugarCoffee() {
        if (coffee < 1 || water < 2 || sugar < 1) {
            cout << "재료가 부족하여 맛이 다를 수 있습니다." << endl;// 재료가 부족하면 음수가 나오는 경우가 발생해서 재료가 부족하면 남은 재료를 다쓰는 코드로 만들어 보았습니다 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 2, 0);
        sugar = max(sugar - 1, 0);
    }
};

int main() {
    coffeeMachine java(5, 10, 3); // 커피량:5, 물량:10, 설탕량:3으로 초기화

    java.drinkEspresso();         // 에스프레소 만들기 (커피:1, 물:1 소비)
    java.show();                  // 현재 커피 머신 상태 출력

    java.drinkAmericano();        // 아메리카노 만들기 (커피:1, 물:2 소비)
    java.show();                  // 현재 커피 머신 상태 출력

    java.drinkSugarCoffee();      // 설탕 커피 만들기 (커피:1, 물:2, 설탕:1 소비)
    java.show();                  // 현재 커피 머신 상태 출력

    java.fill();                  // 커피 머신 재료 채우기 (커피:10, 물:10, 설탕:10)
    java.show();                  // 현재 커피 머신 상태 출력

    return 0;
}
