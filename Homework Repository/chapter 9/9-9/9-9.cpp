#include <iostream>
#include <string>
using namespace std;

/*
모든 프린터는 모델명, 제조사, 인쇄 매수, 인쇄 종이 잔량을 나타내는 정보를 가진다.
print() 함수와 show() 함수는 가상 함수로 선언하여,
각 프린터 타입에 맞게 오버라이딩되도록 한다.

print() 함수는 주어진 매수만큼 프린트하는 동작을 수행하며,
show() 함수는 현재 프린터의 모델명, 제조사, 인쇄 매수, 종이 잔량 등의 상태를 출력한다.

잉크젯 프린터는 잉크 잔량 정보를,
레이저 프린터는 토너 잔량 정보를 추가적으로 가지고 있어야 하며,
각자의 print() 함수에서 잔량을 체크한 뒤 출력 여부를 결정해야 한다.

InkJetPrinter 객체와 LaserPrinter 객체는 각각 동적으로 생성하여 사용한다.
*/

//프린터의 공통 기능을 정의한 추상 클래스
class Printer {
	string model;
	string manufacturer;
	int printedCount;     // 총 출력한 페이지 수
	int availableCount;   // 현재 남은 용지 수

protected:
	// 생성자: 초기 상태 설정
	Printer(string mo = "", string me = "", int a = 0) {
		model = mo;
		manufacturer = me;
		availableCount = a;
		printedCount = 0;
	}

	// 출력 가능 여부 확인 (남은 용지 기준)
	bool isValidPrint(int pages) {
		return availableCount >= pages;
	}

	// 각종 정보 접근자 (protected로 파생 클래스에서 사용)
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }

	// 정보 변경자
	void setPrintedCount(int count) { printedCount = count; }
	void setAvailableCount(int count) { availableCount = count; }

	// 순수 가상 함수 (파생 클래스에서 반드시 구현)
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

// 잉크젯 프린터 클래스
class InkJetPrinter : public Printer {
	int availableInk;  // 남은 잉크량

public:
	// 생성자: 잉크량 포함 초기화
	InkJetPrinter(string mo = "", string me = "", int a = 0, int ink = 0)
		: Printer(mo, me, a), availableInk(ink) {
	}

	// 잉크가 충분한지 확인
	bool hasEnoughInk(int pages) {
		return availableInk >= pages;
	}

	// 출력 수행
	void print(int pages) override {
		if (!isValidPrint(pages)) {
			cout << "용지가 부족하여 출력할 수 없습니다." << endl;
			return;
		}
		if (!hasEnoughInk(pages)) {
			cout << "잉크가 부족하여 출력할 수 없습니다." << endl;
			return;
		}
		// 출력 수행
		setPrintedCount(getPrintedCount() + pages);
		setAvailableCount(getAvailableCount() - pages);
		availableInk -= pages;
		cout << "프린트했습니다." << endl;
	}

	// 현재 상태 출력
	void show() override {
		cout << getModel() << ", " << getManufacturer()
			<< ", 남은 용지 " << getAvailableCount()
			<< "장, 남은 잉크 " << availableInk << endl;
	}

	// 잉크 접근자
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int ink) { availableInk = ink; }
};

// 레이저 프린터 클래스
class LaserPrinter : public Printer {
	int availableToner;  // 남은 토너량

public:
	// 생성자
	LaserPrinter(string mo = "", string me = "", int a = 0, int toner = 0)
		: Printer(mo, me, a), availableToner(toner) {
	}

	// 토너 충분 여부 확인
	bool hasEnoughToner(int pages) {
		return availableToner >= pages;
	}

	// 출력 수행
	void print(int pages) override {
		if (!isValidPrint(pages)) {
			cout << "용지가 부족하여 출력할 수 없습니다." << endl;
			return;
		}
		if (!hasEnoughToner(pages)) {
			cout << "토너가 부족하여 출력할 수 없습니다." << endl;
			return;
		}
		// 출력 성공
		setPrintedCount(getPrintedCount() + pages);
		setAvailableCount(getAvailableCount() - pages);
		availableToner -= pages;
		cout << "프린트했습니다." << endl;
	}

	// 상태 출력
	void show() override {
		cout << getModel() << ", " << getManufacturer()
			<< ", 남은 용지 " << getAvailableCount()
			<< "장, 남은 토너 " << availableToner << endl;
	}

	// 토너 접근자
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int toner) { availableToner = toner; }
};

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;

	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laser->show();
	cout << endl;

	int printerType, pages;
	char cont;

	while (true) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printerType >> pages;

		if (printerType == 1) {
			ink->print(pages);
		}
		else if (printerType == 2) {
			laser->print(pages);
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		ink->show();
		laser->show();

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> cont;
		if (cont == 'n' || cont == 'N') break;
	}

	delete ink;
	delete laser;

	return 0;
}