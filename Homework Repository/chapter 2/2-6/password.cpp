#include <iostream>
#include <string>
using namespace std;

int main() {
	string pw1, pw2;
	cout <<  "새 암호를 입력하세요 >> ";
	getline(cin, pw1);
	cout << "새 암호를 다시 한번 입력하세요 >> ";
	getline(cin, pw2);
	if (pw1 == pw2){
		cout << "같습니다";
	}
	else {
		cout << "같지 않습니다";
	}


	return 0;
}  