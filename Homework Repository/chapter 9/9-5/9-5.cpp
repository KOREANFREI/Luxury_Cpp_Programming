#include <iostream>
using namespace std;


// 디지털 회로에서 기본적인 게이트로 OR 게이트 AND 게이트 XOR 게이트 등이 있다
// 이들은 각각 두 입력 신호를 받아 OR연산, AND 연산, XOR 연산을 수행한 결과를 출력한다.
//이 게이트들을 각각 OR GATE, AND GATE 클래스로 작성하고 자 한다 
//OR GATE, XOR GATE, AND GATE 클래스가 AbstractGate를 상속 받도록 작성하라

class AbstractGate { 	 // 디지털 회로의 기본 형태인 논리 게이트의 공통 추상 클래스
protected:
	bool x, y;  // 두 입력 값

public:
	// 입력 값을 설정하는 함수
	void set(bool x, bool y) {
		this->x = x;
		this->y = y;
	}

	// 논리 연산 함수 (파생 클래스에서 반드시 구현해야 함)
	virtual bool operation() = 0;
};

// AND 게이트 클래스: 두 입력이 모두 true일 때만 true 반환
class ANDGate : public AbstractGate {
public:
	bool operation() override {
		return x && y;
	}
};

// OR 게이트 클래스: 둘 중 하나라도 true이면 true 반환
class ORGate : public AbstractGate {
public:
	bool operation() override {
		return x || y;
	}
};

// XOR 게이트 클래스: 입력이 서로 다를 경우 true 반환
class XORGate : public AbstractGate {
public:
	bool operation() override {
		return x != y;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	// 동일한 입력 값을 각 게이트에 설정
	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	// bool 값을 true/false로 출력
	cout.setf(ios::boolalpha);

	// 각 게이트의 연산 결과 출력
	cout << "And gate 결과는 " << andGate.operation() << endl;
	cout << "Or gate 결과는 " << orGate.operation() << endl;
	cout << "XOR gate 결과는 " << xorGate.operation() << endl;

	return 0;
}