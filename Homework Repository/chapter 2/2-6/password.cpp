#include <iostream>
#include <string>
using namespace std;

int main() {
	string pw1, pw2;
	cout <<  "�� ��ȣ�� �Է��ϼ��� >> ";
	getline(cin, pw1);
	cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ��� >> ";
	getline(cin, pw2);
	if (pw1 == pw2){
		cout << "�����ϴ�";
	}
	else {
		cout << "���� �ʽ��ϴ�";
	}


	return 0;
}  