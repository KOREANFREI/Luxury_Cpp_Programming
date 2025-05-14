#include <iostream>
#include <string>
using namespace std;

// 개별 좌석 클래스: 이름 저장 및 예약/취소 기능 제공
class Seat {
	string name;

public:
	Seat(string n = "---") { name = n; }

	// 좌석 예약
	void reservation(string n) { name = n; }

	// 좌석 취소 (이름을 기본값으로 초기화)
	void cancle() { name = "---"; }

	// 현재 좌석 상태 출력
	void show() { cout << name; }
};

// 시간별 비행편 클래스 (좌석 배열 포함)
class Schedule {
	Seat* schedule;     // 좌석 8개
	string time;        // 운항 시간

public:
	// 생성자: 좌석 배열 할당, 시간 초기값 설정
	Schedule(string time = "00시") {
		schedule = new Seat[8];
		this->time = time;
	}

	// 특정 좌석에 예약자 이름 등록
	void reservation(int index, string name) {
		schedule[index].reservation(name);
	}

	// 특정 좌석 예약 취소
	void cancle(int index) {
		schedule[index].cancle();
	}

	// 전체 좌석 상태 출력
	void show() {
		for (int i = 0; i < 8; i++) {
			schedule[i].show();
			cout << "\t";
		}
		cout << endl;
	}

	// 시간 설정
	void setTime(string time) {
		this->time = time;
	}

	// 시간 반환
	string getTime() {
		return time;
	}
};

// 항공사 전체 예약 시스템 클래스 (총 3대의 비행기 관리)
class AirlineBook {
	Schedule* airlines;

public:
	// 생성자: 3개의 Schedule 생성 및 시간 설정
	AirlineBook() {
		airlines = new Schedule[3];
		airlines[0].setTime("07시");
		airlines[1].setTime("12시");
		airlines[2].setTime("17시");
	}

	// 특정 시간대 예약 현황 출력
	void show(int index) {
		cout << airlines[index].getTime() << '\t';
		airlines[index].show();
	}

	// 좌석 예약
	void reservation(int index, int seat, string name) {
		airlines[index].reservation(seat, name);
	}

	// 좌석 취소
	void cancle(int index, int seat, string name) {
		airlines[index].cancle(seat);
	}
};

// 사용자 입력 및 메뉴 처리를 담당하는 Console 클래스
class Console {
public:
	static int menu;
	static int time;
	static AirlineBook hansung;

	// 프로그램 실행 진입점
	static void start() {
		cout << "***** 한성항공 예약 시스템에 오신 것을 환영합니다 *****" << endl;
		while (true) {
			showMenu();
			switch (menu) {
			case 1:
				reservation(); break;
			case 2:
				cancle(); break;
			case 3:
				show(); break;
			case 4:
				cout << "프로그램을 종료합니다." << endl;
				return;
			default:
				cout << "올바른 메뉴 번호를 입력하세요." << endl;
			}
		}
	}

	// 메뉴 출력 및 선택
	static void showMenu() {
		cout << "\n예약:1, 취소:2, 조회:3, 종료:4 >> ";
		cin >> menu;
	}

	// 예약 처리
	static void reservation() {
		cout << "시간 선택 - 07시:1, 12시:2, 17시:3 >> ";
		cin >> time;

		hansung.show(time - 1);

		int seatNum;
		string name;

		cout << "좌석 번호 (1~8) >> ";
		cin >> seatNum;

		cout << "예약자 이름 >> ";
		cin >> name;

		hansung.reservation(time - 1, seatNum - 1, name);
	}

	// 취소 처리
	static void cancle() {
		cout << "시간 선택 - 07시:1, 12시:2, 17시:3 >> ";
		cin >> time;

		hansung.show(time - 1);

		int seatNum;
		string name;

		cout << "좌석 번호 (1~8) >> ";
		cin >> seatNum;

		cout << "예약자 이름 >> ";
		cin >> name;

		hansung.cancle(time - 1, seatNum - 1, name);
	}

	// 전체 예약 현황 출력
	static void show() {
		for (int i = 0; i < 3; i++) {
			hansung.show(i);
		}
	}
};

// 정적 변수 정의
int Console::menu = 0;
int Console::time = 0;
AirlineBook Console::hansung;

// 메인 함수
int main() {
	Console::start();
	return 0;
}
