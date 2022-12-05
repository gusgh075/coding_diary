#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
inline void error(const char* message) {
	cout << message << endl;
	exit(1);
}
class queue {
protected:
	int front;	//첫번째 원소의 앞을 가리킴
	int rear;	//마지막 원소를 가리킴
	int data[MAX_QUEUE_SIZE];
public:
	queue() :front(-1), rear(-1) {}
	void enque(int item) {	//큐에 데이터 삽입
		if (isFull())
			error("큐가 꽉찼습니다.");
		else {
			data[++rear] = item;
		}
	}

	int deque() {			//첫번째 데이터 반환 및 삭제
		if (isEmpty()) {
			error("큐가 비어있습니다.");
		}
		else 
			return data[++front];
		
	}
	int peek() {			//첫 항목을 큐에서 빼지 않고 반환
		if (isEmpty()) {
			error("큐가 비어있습니다.");
		}
		else
		return data[front + 1];
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return rear == MAX_QUEUE_SIZE;
	}
	void display() {
		if (isEmpty())
			cout << "비어 있습니다.";
		else
		{
			for (int i = front + 1; i <= rear; i++) {
				cout << data[i];
				if (i == rear)
					break;
				cout << '/';
			}
		}
	}
};
