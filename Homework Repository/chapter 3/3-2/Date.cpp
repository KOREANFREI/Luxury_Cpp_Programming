#include <iostream>
#include <string>
using namespace std;

class Date { //Date Ŭ���� ��� 
private:
	int year; 
	int month;
	int day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }

	Date(string serial); // ���ڿ��޾Ƽ� ��¥�� �ʱ�ȭ �ϴ� ������, Date(string serial)

	void show() {
		cout << year << "��" << month << "��" << day << "��" << endl;
	}

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

Date::Date(string serial) { 
	int i = 0, j = 0; //��κ��� ���� �ʱ�ȭ �ϴ� �κ�
	for (i = 0; i < serial.length(); i++) { //ù��° '/' ��ġ ã�� 
		if (serial[i] == '/') break;
	}
	for (j = i + 1; j < serial.length(); j++) { // �ι�° '/' ��ġ ã�� 
		if (serial[j] == '/') break;
	}
	year = stoi(serial.substr(0, i)); //2�忡�� ����߾��µ� �ٽ� �����ϸ� stoi �Լ��� ���� ���ڿ��� ���ڷ� ���� 
	month = stoi(serial.substr(i + 1, j - i - 1)); // ó�� '/'�� �ι�° '/' ������ ���ڿ��� ��ȯ�ؼ� month�� ����
	day = stoi(serial.substr(j + 1));//�ι�° '/' ������ ���ڿ��� ��ȯ�ؼ� day�� ����
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	return 0;
}