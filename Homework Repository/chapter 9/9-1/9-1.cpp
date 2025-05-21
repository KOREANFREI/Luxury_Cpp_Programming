
#include <iostream>
using namespace std;

//Converter 클래스를 상속받아 달러를 원화로 환산하는 WonToDollar 클래스를 작성하라
//main() 함수와 실행결과는 다음과 같다

// 환율 변환을 위한 추상 클래스
class Converter {
protected:
	double ratio; // 변환 비율 (예: 1달러 = 1010원일 경우, ratio = 1010)

	// 실제 변환 동작은 하위 클래스가 구현
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;

public:
	// 생성자: 변환 비율 초기화
	Converter(double ratio) { this->ratio = ratio; }

	// 변환 실행 함수: 입력 받고 결과 출력
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << " 로 바꿉니다:";
		cout << getSourceString() << "을 입력하세요 >> ";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};

// Converter를 상속받아 원화 → 달러 변환 기능 구현
class WonToDollar : public Converter {
public:
	WonToDollar(double ratio = 1.0) : Converter(ratio) {}

	// 변환: 원화 → 달러
	double convert(double src) override {
		return src / ratio;
	}

	string getSourceString() override { return "원"; }
	string getDestString() override { return "달러"; }
};

int main() {
	// 1달러 = 1010원 기준
	WonToDollar wd(1010);
	wd.run();
	return 0;
}