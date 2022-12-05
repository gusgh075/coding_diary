#include "circular_queue.h"

class deque :public Circular_Queue {
public:
	deque() {}
	void addFront(int item) {
		if (isFull()) {
			error("덱이 포화상태입니다.\n");
		}
		else {
			data[front] = item;
			front = (front - 1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	int deleteFront() {
		return dequeue();
	}
	int getFront() {
		peek();
	}
	void addRear(int item) {
		enqueue(item);
	}
	int deleteRear() {
		if (isEmpty()) {
			error("덱이 공백상태입니다.\n");
		}
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
	int getRear() {
		if (isFull())
			error("덱이 포화상태입니다.\n");
		else
			return data[rear];
	}
	void display() {
		cout << "덱 내용 : ";
		int maxi = front < rear ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front+1; i <=maxi; i++) {
			cout << '[' << data[i%MAX_QUEUE_SIZE] << ']';
		}
		cout << endl;
	}
};