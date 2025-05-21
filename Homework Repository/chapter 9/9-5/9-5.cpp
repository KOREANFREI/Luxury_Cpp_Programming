#include <iostream>
using namespace std;


// ������ ȸ�ο��� �⺻���� ����Ʈ�� OR ����Ʈ AND ����Ʈ XOR ����Ʈ ���� �ִ�
// �̵��� ���� �� �Է� ��ȣ�� �޾� OR����, AND ����, XOR ������ ������ ����� ����Ѵ�.
//�� ����Ʈ���� ���� OR GATE, AND GATE Ŭ������ �ۼ��ϰ� �� �Ѵ� 
//OR GATE, XOR GATE, AND GATE Ŭ������ AbstractGate�� ��� �޵��� �ۼ��϶�

class AbstractGate { 	 // ������ ȸ���� �⺻ ������ �� ����Ʈ�� ���� �߻� Ŭ����
protected:
	bool x, y;  // �� �Է� ��

public:
	// �Է� ���� �����ϴ� �Լ�
	void set(bool x, bool y) {
		this->x = x;
		this->y = y;
	}

	// �� ���� �Լ� (�Ļ� Ŭ�������� �ݵ�� �����ؾ� ��)
	virtual bool operation() = 0;
};

// AND ����Ʈ Ŭ����: �� �Է��� ��� true�� ���� true ��ȯ
class ANDGate : public AbstractGate {
public:
	bool operation() override {
		return x && y;
	}
};

// OR ����Ʈ Ŭ����: �� �� �ϳ��� true�̸� true ��ȯ
class ORGate : public AbstractGate {
public:
	bool operation() override {
		return x || y;
	}
};

// XOR ����Ʈ Ŭ����: �Է��� ���� �ٸ� ��� true ��ȯ
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

	// ������ �Է� ���� �� ����Ʈ�� ����
	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	// bool ���� true/false�� ���
	cout.setf(ios::boolalpha);

	// �� ����Ʈ�� ���� ��� ���
	cout << "And gate ����� " << andGate.operation() << endl;
	cout << "Or gate ����� " << orGate.operation() << endl;
	cout << "XOR gate ����� " << xorGate.operation() << endl;

	return 0;
}