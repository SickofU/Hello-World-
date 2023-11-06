#include<iostream>
using namespace std;
#include<string>
struct Node {
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int _data) {
		next = NULL;
		data = _data;
	}
};
class stack {
public:
	stack() {
		head = NULL;
		start = NULL;
	}



	int algorithm(int i) {
		int result = -1;

		Node* temp = start;
		for (int j = 0; j < i; j++) {
			temp = temp->next;
		}
		int cp = temp->data;
		while (temp != NULL) {

			if (temp->data > cp) {
				result = temp->data;
				break;
			}
			temp = temp->next;

		}

		return result;
	}

	void push(int _num) {
		Node* newNode = new Node(_num);
		if (empty()) {
			head = newNode;
			start = newNode;
		}
		else {
			head->next = newNode;
			head = newNode;
		}
	}
	void display(int N) {
		//돌면서 보여주기
		Node* dp = start;
		for (int i = 0; i < N; i++) {
			cout << dp->data << " ";
			dp = dp->next;
		}
	}
	bool empty() {
		return head == NULL;
	}

	Node* head;
	Node* start;
};

int main() {
	int N;
	stack test;
	stack result;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		test.push(num);
	}
	for (int i = 0; i < N; i++) {

		result.push(test.algorithm(i));
	}
	result.display(N);
}



/*

*/