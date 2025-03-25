#include <iostream>
#include <string>
using namespace std;

class Date { //Date 클래스 명명 
private:
	int year; 
	int month;
	int day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }

	Date(string serial); // 문자열받아서 날짜를 초기화 하는 생성자, Date(string serial)

	void show() {
		cout << year << "년" << month << "월" << day << "일" << endl;
	}

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

Date::Date(string serial) { 
	int i = 0, j = 0; //요부분은 변수 초기화 하는 부분
	for (i = 0; i < serial.length(); i++) { //첫번째 '/' 위치 찾기 
		if (serial[i] == '/') break;
	}
	for (j = i + 1; j < serial.length(); j++) { // 두번째 '/' 위치 찾기 
		if (serial[j] == '/') break;
	}
	year = stoi(serial.substr(0, i)); //2장에도 사용했었는데 다시 정리하면 stoi 함수를 통해 문자열을 숫자로 변경 
	month = stoi(serial.substr(i + 1, j - i - 1)); // 처음 '/'와 두번째 '/' 사이의 문자열을 변환해서 month에 저장
	day = stoi(serial.substr(j + 1));//두번째 '/' 이후의 문자열을 변환해서 day에 저장
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	return 0;
}