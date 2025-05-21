
#include <iostream>
using namespace std;

//Converter Ŭ������ ��ӹ޾� �޷��� ��ȭ�� ȯ���ϴ� WonToDollar Ŭ������ �ۼ��϶�
//main() �Լ��� �������� ������ ����

// ȯ�� ��ȯ�� ���� �߻� Ŭ����
class Converter {
protected:
	double ratio; // ��ȯ ���� (��: 1�޷� = 1010���� ���, ratio = 1010)

	// ���� ��ȯ ������ ���� Ŭ������ ����
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;

public:
	// ������: ��ȯ ���� �ʱ�ȭ
	Converter(double ratio) { this->ratio = ratio; }

	// ��ȯ ���� �Լ�: �Է� �ް� ��� ���
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << " �� �ٲߴϴ�:";
		cout << getSourceString() << "�� �Է��ϼ��� >> ";
		cin >> src;
		cout << "��ȯ��� : " << convert(src) << getDestString() << endl;
	}
};

// Converter�� ��ӹ޾� ��ȭ �� �޷� ��ȯ ��� ����
class WonToDollar : public Converter {
public:
	WonToDollar(double ratio = 1.0) : Converter(ratio) {}

	// ��ȯ: ��ȭ �� �޷�
	double convert(double src) override {
		return src / ratio;
	}

	string getSourceString() override { return "��"; }
	string getDestString() override { return "�޷�"; }
};

int main() {
	// 1�޷� = 1010�� ����
	WonToDollar wd(1010);
	wd.run();
	return 0;
}