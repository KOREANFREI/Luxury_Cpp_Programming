#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;

protected:
	BaseMemory(int size) { mem = new char[size]; }

	// 지정된 위치에 한 글자 저장
	void save(char value, int pos) {
		mem[pos] = value;
	}

	// 문자열을 지정 길이만큼 복사
	void saveBlock(char* src, int len) {
		for (int i = 0; i < len; ++i)
			mem[i] = src[i];
	}

	// 저장된 값 읽기
	char load(int pos) const {
		return mem[pos];
	}
};

// ROM 클래스 (읽기 전용)
class ROM : public BaseMemory {
public:
	// 생성 시 내용 복사
	ROM(int size, char* initData, int len) : BaseMemory(size) {
		saveBlock(initData, len);  // 내부 배열에 초기화 데이터 저장
	}

	// 읽기만 가능
	char read(int pos) {
		return load(pos);
	}
};

// RAM 클래스 (읽고 쓰기 모두 가능)
class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}

	// 데이터 저장
	void write(int pos, char value) {
		save(value, pos);
	}

	// 데이터 읽기
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
