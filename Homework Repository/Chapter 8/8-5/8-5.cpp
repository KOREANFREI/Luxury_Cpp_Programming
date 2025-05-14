#include <iostream>
#include <string>
using namespace std;

// 내부적으로 int 배열을 관리하는 기초 클래스
class ArrayBuffer {
private:
	int maxSize;
	int* buffer;

protected:
	
	ArrayBuffer(int maxSize = 100) { // 생성자: 지정한 크기만큼 배열 동적 할당
		this->maxSize = maxSize;
		buffer = new int[maxSize];}
	
	~ArrayBuffer() { // 소멸자: 메모리 해제
		delete[] buffer;}
	
	void write(int idx, int value) { // 값 저장
		buffer[idx] = value;}

	
	int read(int idx) { // 값 읽기
		return buffer[idx];}

	int capacity() { 	// 최대 용량 반환
		return maxSize;}
};

class MyQueue : public ArrayBuffer {
	int front;  // 꺼낼 위치
	int rear;   // 넣을 위치

public:
	MyQueue(int size) : ArrayBuffer(size), front(0), rear(0) {} 	// 생성자: front와 rear 초기화

	int capacity() { 	// 큐 전체 용량 반환
		return ArrayBuffer::capacity();
	}

	int length() { 	// 현재 저장된 요소 개수 반환
		return rear - front;
	}

	void enqueue(int value) { 	// 큐에 값 삽입
		write(rear++, value);
	}

	int dequeue() { 	// 큐에서 값 제거 및 반환
		return read(front++);
	}
};


int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
	return 0;
}