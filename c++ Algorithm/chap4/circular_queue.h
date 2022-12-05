#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
inline void error(const char* message) {
	cout << message << endl;
	exit(1);
}
class Circular_Queue {
protected:
	int front;	//첫번째 원소의 앞을 가리킴
	int rear;	//마지막 원소를 가리킴
	int data[MAX_QUEUE_SIZE];
public:
	Circular_Queue() :front(0), rear(0) {}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return front == (rear + 1) % MAX_QUEUE_SIZE;
	}
	void enque(int item) {	//큐에 데이터 삽입
		if (isFull())
			error("큐가 꽉찼습니다.");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = item;
		}
	}

	int deque() {			//첫번째 데이터 반환 및 삭제
		if (isEmpty()) {
			error("큐가 비어있습니다.");
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {			//첫 항목을 큐에서 빼지 않고 반환
		if (isEmpty()) {
			error("큐가 비어있습니다.");
		}
		else
			return data[(front + 1)%MAX_QUEUE_SIZE];
	}
	void display() {
		if (isEmpty())
			cout << "비어 있습니다.";
		else
		{
			for (int i = front+1; i !=rear; i++) {
				cout << data[i];
				cout << '/';
				i = i % MAX_QUEUE_SIZE;
			}
			cout << data[rear]<<endl;
		}
	}
};
