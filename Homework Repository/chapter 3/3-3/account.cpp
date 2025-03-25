#include <iostream>
using namespace std;

class Account {
private : 
	int id; //���� id �κ� ���� 
	int money; // �� ���� 
	string name; //���� �̸� ���� 
public:
	
	Account(string n, int i, int m) { name = n; id = i;  money = m; }
	void deposit(int m) { money += m; }


	int withdraw(int m) {
		if (money < m) {
			int A_withdraw = money;
			money = 0;
			return A_withdraw;
		}
		else {
			money -= m;
			return m;
		}
	}

	string getOwner() {
		return name;
	}
	
	int inquiry() {
		return money;
	}
};



int main() {
	Account a("kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ���� 
	a.deposit(50000); // 5000�� ���� 
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000�� ���� 
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}