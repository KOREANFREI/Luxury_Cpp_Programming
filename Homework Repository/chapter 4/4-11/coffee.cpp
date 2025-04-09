#include <iostream>
using namespace std;

class Container {
	int size;  // 재료의 양
public:
	Container() { size = 10; }  // 생성자 호출했음
	void fill() { size = 10; }  // 재료를 채웠음
	void consume() { if (size > 0) size--; }  // 재료를 하나 사용했음
	int getSize() { return size; }  // 현재 재료 양 반환했음
};

class CoffeVendingMachine {
	Container tong[3];  // 커피, 물, 설탕 저장용 컨테이너 배열
	void fill() {  // 모든 재료를 채웠음
		for (Container& c : tong) {
			c.fill();  // 각 컨테이너 채우기
		}
	}
	void selectEspresso() {  // 에스프레소 만들었음
		tong[0].consume();
		tong[1].consume();
	}
	void selectAmericano() {  // 아메리카노 만들었음
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
	}
	void selectSugarCoffee() {  // 설탕커피 만들었음
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
	}
	void show() {  // 현재 상태 표시했음
		cout << "커피 " << tong[0].getSize()
			<< ", 물 " << tong[1].getSize()
			<< ", 설탕 " << tong[2].getSize() << endl;
	}
public:
	void run() {  // 자판기 작동 시작했음
		int menu;
		cout << "***** 커피자판기를 작동합니다. *****" << endl;
		while (true) {
			cout << "메뉴를 눌러주세요(1.에스프레소, 2.아메리카노, 3.설탕커피, 4.잔량보기, 5.채우기) >>";
			cin >> menu;
			switch (menu) {
			case 1:  // 에스프레소 선택했음
				if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
					cout << "원료가 부족합니다." << endl;
				}
				else {
					selectEspresso();
					cout << "에스프레소 드세요." << endl;
				}
				break;
			case 2:  // 아메리카노 선택했음
				if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
					cout << "원료가 부족합니다." << endl;
				}
				else {
					selectAmericano();
					cout << "아메리카노 드세요." << endl;
				}
				break;
			case 3:  // 설탕커피 선택했음
				if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
					cout << "원료가 부족합니다." << endl;
				}
				else {
					selectSugarCoffee();
					cout << "설탕커피 드세요." << endl;
				}
				break;
			case 4:  // 잔량 확인했음
				show();
				break;
			case 5:  // 재료 채웠음
				fill();
				show();
				break;
			default:
				break;  // 아무것도 안 했음
			}
		}
	}
};

int main() {
	CoffeVendingMachine machine;  // 자판기 객체 생성했음
	machine.run();                // 자판기 작동했음
	return 0;
}
