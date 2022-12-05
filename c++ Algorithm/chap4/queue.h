#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
inline void error(const char* message) {
	cout << message << endl;
	exit(1);
}
class queue {
protected:
	int front;	//ù��° ������ ���� ����Ŵ
	int rear;	//������ ���Ҹ� ����Ŵ
	int data[MAX_QUEUE_SIZE];
public:
	queue() :front(-1), rear(-1) {}
	void enque(int item) {	//ť�� ������ ����
		if (isFull())
			error("ť�� ��á���ϴ�.");
		else {
			data[++rear] = item;
		}
	}

	int deque() {			//ù��° ������ ��ȯ �� ����
		if (isEmpty()) {
			error("ť�� ����ֽ��ϴ�.");
		}
		else 
			return data[++front];
		
	}
	int peek() {			//ù �׸��� ť���� ���� �ʰ� ��ȯ
		if (isEmpty()) {
			error("ť�� ����ֽ��ϴ�.");
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
			cout << "��� �ֽ��ϴ�.";
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
