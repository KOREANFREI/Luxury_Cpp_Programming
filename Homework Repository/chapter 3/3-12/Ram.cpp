#include <iostream>
#include "ram.h"
using namespace std;

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}

Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address) { return mem[address]; }

void Ram::write(int address, char value) { mem[address] = value; }