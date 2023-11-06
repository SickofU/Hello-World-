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
	//�Ȱ��� �ø� ����Ʈ�� ���� �ֱ� ������ circle ��ü ���� ���Ḯ��Ʈ�� �̷���� �ִ�.
	//�̰� �ٲٱ� ���ؼ� circle�� ������ �����͸� �� ���� ��ü�� �������־���Ѵ�.
	Node* temp = circle.head;
	//���� ��带 private �� �־�� �ؼ� ĸ��ȭ�� �ؾ������� �׷��� �� �Լ��� ���������
	//Ȥ�� �д� ���� �ִٸ�, �˾Ƽ� �������� �ٲ��ֽ� �� �Ͻ��ϴ�.
	//�Ʊ�� �Ȱ��� �� ÷ ���ҷ� �ϴ� �����սô�.

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
	//ù°�ٿ� ���� ��Ͽ� �ִ� ���� ���� N�� �ݺ� ����� ���� ���� K���־�����.
	cin >> N >> K;
	char ele;
	//������ ���� ��� ����� N���� ���� ����
	//�ݺ� ��ų K���� ã�Ƽ� ���� ���Ḯ��Ʈ�� �����
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

