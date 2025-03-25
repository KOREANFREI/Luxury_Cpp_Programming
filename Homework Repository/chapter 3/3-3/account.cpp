#include <iostream>
using namespace std;

class Account {
private : 
	int id; //기태 id 부분 들어갈것 
	int money; // 돈 들어갈곳 
	string name; //기태 이름 들어갈곳 
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
	Account a("kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성 
	a.deposit(50000); // 5000원 저금 
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000원 저금 
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}