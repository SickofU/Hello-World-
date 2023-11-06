#include<iostream>
using namespace std;

struct Node {
	char data;
	Node* next;
	Node(char _data) {
		data = _data;
		next = NULL;
	}
	Node() {
		data = 'a';
		next = NULL;
	}
};
class playlist {
public:

	playlist() {
		head = NULL;

	}
	void insert(char _data) {
		Node* newNode = new Node(_data);
		if (head == NULL) {
			head = newNode;
		}
		else {

			newNode->next = head;
			head = newNode;
		}

	}
	void getitem(char _data, playlist& circle) {
		Node* temp = head;

		while (temp != NULL) {
			if (temp->data == _data) {
				circle.insert(_data);
				break;
			}
			temp = temp->next;
		}



	}
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		delete[] temp;
		cout << endl;
	}


	Node* head;
};




void MakeCircleList(playlist& circle) {
	//똑같은 플리 리스트를 쓰고 있기 때문에 circle 객체 또한 연결리스트로 이루어져 있다.
	//이걸 바꾸기 위해서 circle의 마지막 포인터를 맨 뒤의 객체와 연결해주어야한다.
	Node* temp = circle.head;
	//원래 헤드를 private 에 넣어야 해서 캡슐화를 해야하지만 그래서 겟 함수를 써야하지만
	//혹시 읽는 분이 있다면, 알아서 그정도는 바꿔주실 줄 믿습니다.
	//아까랑 똑같이 맨 첨 원소로 일단 접근합시다.

	if (circle.head == nullptr) {
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = circle.head;

}





int main() {
	int N, K;
	playlist test;
	playlist circle;
	//첫째줄에 음악 목록에 있는 음악 개수 N과 반복 재생할 음악 개수 K가주어진다.
	cin >> N >> K;
	char ele;
	//기존의 음악 목록 만들고 N개의 음악 개수
	//반복 시킬 K개를 찾아서 원형 연결리스트로 만들기
	for (int i = 0; i < N; i++) {
		cin >> ele;
		test.insert(ele);
	}
	for (int j = 0; j < K; j++) {
		cin >> ele;
		(test.getitem(ele, circle));

	}
	test.display();
	circle.display();
	MakeCircleList(circle);

	for (int i = 0; i < 5; i++) {
		cout << circle.head->data << "   ";
		circle.head = circle.head->next;
	}

}

