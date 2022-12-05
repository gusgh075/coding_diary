#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
inline void error(const char* message) {
	cout << message << endl;
	exit(1);
}
class Circular_Queue {
protected:
	int front;	//ù��° ������ ���� ����Ŵ
	int rear;	//������ ���Ҹ� ����Ŵ
	int data[MAX_QUEUE_SIZE];
public:
	Circular_Queue() :front(0), rear(0) {}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return front == (rear + 1) % MAX_QUEUE_SIZE;
	}
	void enque(int item) {	//ť�� ������ ����
		if (isFull())
			error("ť�� ��á���ϴ�.");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = item;
		}
	}

	int deque() {			//ù��° ������ ��ȯ �� ����
		if (isEmpty()) {
			error("ť�� ����ֽ��ϴ�.");
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {			//ù �׸��� ť���� ���� �ʰ� ��ȯ
		if (isEmpty()) {
			error("ť�� ����ֽ��ϴ�.");
		}
		else
			return data[(front + 1)%MAX_QUEUE_SIZE];
	}
	void display() {
		if (isEmpty())
			cout << "��� �ֽ��ϴ�.";
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
