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
        cout << "Ŀ�� �ӽ� ����,\t  Ŀ��: " << coffee << "\t��: " << water << "\t����: " << sugar << endl;
    }

    void fill() {
        coffee = 10;
        water = 10;
        sugar = 10;
    }

    void drinkEspresso() {
        if (coffee < 1 || water < 1) {
            cout << "��ᰡ �����Ͽ� ���� �ٸ� �� �ֽ��ϴ�." << endl; // ��ᰡ �����ϸ� ������ ������ ��찡 �߻��ؼ� ��ᰡ �����ϸ� ���� ��Ḧ �پ��� �ڵ�� ����� ���ҽ��ϴ� 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 1, 0);
    }

    void drinkAmericano() {
        if (coffee < 1 || water < 2) {
            cout << "��ᰡ �����Ͽ� ���� �ٸ� �� �ֽ��ϴ�." << endl;// ��ᰡ �����ϸ� ������ ������ ��찡 �߻��ؼ� ��ᰡ �����ϸ� ���� ��Ḧ �پ��� �ڵ�� ����� ���ҽ��ϴ� 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 2, 0);
    }

    void drinkSugarCoffee() {
        if (coffee < 1 || water < 2 || sugar < 1) {
            cout << "��ᰡ �����Ͽ� ���� �ٸ� �� �ֽ��ϴ�." << endl;// ��ᰡ �����ϸ� ������ ������ ��찡 �߻��ؼ� ��ᰡ �����ϸ� ���� ��Ḧ �پ��� �ڵ�� ����� ���ҽ��ϴ� 
        }
        coffee = max(coffee - 1, 0);
        water = max(water - 2, 0);
        sugar = max(sugar - 1, 0);
    }
};

int main() {
    coffeeMachine java(5, 10, 3); // Ŀ�Ƿ�:5, ����:10, ������:3���� �ʱ�ȭ

    java.drinkEspresso();         // ���������� ����� (Ŀ��:1, ��:1 �Һ�)
    java.show();                  // ���� Ŀ�� �ӽ� ���� ���

    java.drinkAmericano();        // �Ƹ޸�ī�� ����� (Ŀ��:1, ��:2 �Һ�)
    java.show();                  // ���� Ŀ�� �ӽ� ���� ���

    java.drinkSugarCoffee();      // ���� Ŀ�� ����� (Ŀ��:1, ��:2, ����:1 �Һ�)
    java.show();                  // ���� Ŀ�� �ӽ� ���� ���

    java.fill();                  // Ŀ�� �ӽ� ��� ä��� (Ŀ��:10, ��:10, ����:10)
    java.show();                  // ���� Ŀ�� �ӽ� ���� ���

    return 0;
}
