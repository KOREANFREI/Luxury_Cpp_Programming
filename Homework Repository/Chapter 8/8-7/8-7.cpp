#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;

protected:
	BaseMemory(int size) { mem = new char[size]; }

	// ������ ��ġ�� �� ���� ����
	void save(char value, int pos) {
		mem[pos] = value;
	}

	// ���ڿ��� ���� ���̸�ŭ ����
	void saveBlock(char* src, int len) {
		for (int i = 0; i < len; ++i)
			mem[i] = src[i];
	}

	// ����� �� �б�
	char load(int pos) const {
		return mem[pos];
	}
};

// ROM Ŭ���� (�б� ����)
class ROM : public BaseMemory {
public:
	// ���� �� ���� ����
	ROM(int size, char* initData, int len) : BaseMemory(size) {
		saveBlock(initData, len);  // ���� �迭�� �ʱ�ȭ ������ ����
	}

	// �б⸸ ����
	char read(int pos) {
		return load(pos);
	}
};

// RAM Ŭ���� (�а� ���� ��� ����)
class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}

	// ������ ����
	void write(int pos, char value) {
		save(value, pos);
	}

	// ������ �б�
	char read(int pos) {
		return load(pos);
	}
};

int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	return 0;
}
