#include<iostream>
using namespace std;

class queue {
public:

	queue(int n) {
		store = new int[n];
		front = 0;
		rear = 0;
	}
	queue() {}
	void enQueue(int _num) {
		store[rear] = _num;
		rear++;
	}
	int deQueue() {
		int result;
		result = store[front];
		front++;
		return result;
	}
	int getfront() {
		return store[front];
	}
private:
	//���� ��ũ��� �� �ʿ� ���� ������ ���� ť�� �����غ�
	//����ť�� ������ ���� ����Ǯ�� ���Ƽ�� rear=front�� ��Ȳ���� ������ �����ϱ� ������
	//maxlength ��ȣ �����ؾ��Ѵ�.
	int maxlength;
	int* store;
	int front;
	int rear;

};
class stack {
public:
	stack(int n) {
		top = -1;
		store = new int[n];
	}
	stack() {
		top = -1;

	}
	void push(int n) {
		top++;
		store[top] = n;
	}
	int pop() {
		int result;
		result = store[top];
		top--;
		return result;
	}
	int gettop() {
		return store[top];
	}
	bool isempty() {
		return top == -1;
	}
private:
	int top;
	int* store;
};

int main() {
	int N;
	cin >> N;
	int* numbers;
	numbers = new int[N];
	queue RQ(N);
	queue LQ(N);
	stack MS(N);
	//RQ�� ������ �Է�
	int num;
	for (int j = 0; j < N; j++) {
		cin >> num;
		RQ.enQueue(num);
	}
	for (int k = 0; k < N; k++) {
		cin >> num;
		numbers[k] = num;
	}//num�� �̿��� �־��ֱ�
	int i = 0;
	while (1) {





		if (numbers[i] == RQ.getfront()) {
			LQ.enQueue(RQ.deQueue());
			i++;

		}
		else if (numbers[i] < RQ.getfront()) {

			if (numbers[i] == MS.gettop()) {
				LQ.enQueue(MS.pop());
				i++;

			}
			else {
				cout << "IMPOSSIBLE";
				break;
			}
		}
		else {
			MS.push(RQ.deQueue());
		}

		if (i == N) {
			if (MS.isempty()) {
				cout << "POSSIBLE";
				break;
			}
			else
				cout << "IMPOSSIBLE";
			break;
		}


	}






}