#include <iostream>
#include <string>
using namespace std;

// ���������� int �迭�� �����ϴ� ���� Ŭ����
class ArrayBuffer {
private:
	int maxSize;
	int* buffer;

protected:
	
	ArrayBuffer(int maxSize = 100) { // ������: ������ ũ�⸸ŭ �迭 ���� �Ҵ�
		this->maxSize = maxSize;
		buffer = new int[maxSize];}
	
	~ArrayBuffer() { // �Ҹ���: �޸� ����
		delete[] buffer;}
	
	void write(int idx, int value) { // �� ����
		buffer[idx] = value;}

	
	int read(int idx) { // �� �б�
		return buffer[idx];}

	int capacity() { 	// �ִ� �뷮 ��ȯ
		return maxSize;}
};

class MyQueue : public ArrayBuffer {
	int front;  // ���� ��ġ
	int rear;   // ���� ��ġ

public:
	MyQueue(int size) : ArrayBuffer(size), front(0), rear(0) {} 	// ������: front�� rear �ʱ�ȭ

	int capacity() { 	// ť ��ü �뷮 ��ȯ
		return ArrayBuffer::capacity();
	}

	int length() { 	// ���� ����� ��� ���� ��ȯ
		return rear - front;
	}

	void enqueue(int value) { 	// ť�� �� ����
		write(rear++, value);
	}

	int dequeue() { 	// ť���� �� ���� �� ��ȯ
		return read(front++);
	}
};


int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
	return 0;
}