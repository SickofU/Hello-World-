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
	//굳이 링크드로 할 필요 없어 보여서 선형 큐로 구현해봄
	//선형큐로 구현할 때는 이즈풀과 이즈엠티가 rear=front인 상황에서 조건을 만족하기 때문에
	//maxlength 기호 구현해야한다.
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
	//RQ에 데이터 입력
	int num;
	for (int j = 0; j < N; j++) {
		cin >> num;
		RQ.enQueue(num);
	}
	for (int k = 0; k < N; k++) {
		cin >> num;
		numbers[k] = num;
	}//num을 이용해 넣어주기
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