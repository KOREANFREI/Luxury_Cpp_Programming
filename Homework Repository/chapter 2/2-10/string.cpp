#include <iostream>
#include <string>
using namespace std; 

int main() {
	string prac;
	cout << "���ڿ� �Է�>> ";
	
	getline(cin, prac);
	for (int i = 0; i < prac.length(); i++) {
		cout << prac.substr(0, i+1) << endl;
	}
	
	return 0;

}