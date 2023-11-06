#include<iostream>
using namespace std;


class pinballstack {
public:
	pinballstack() {
		top = -1;
		score = 0;
	}
	void scores(int _score) {
		score = _score;
	}
	void insert(int item) {
		top++;
		store[top] = item;

	}
	int display() {
		int result = 0;
		while (top >= 0) {
			result += store[top];
			top--;
		}
		return score * result;
	}
private:
	int store[10];
	int top;
	int score;
};
//아 스택 5개 구현이구나

int main() {
	int num;
	int score;
	pinballstack test1, test2, test3, test4, test5;
	for (int i = 0; i < 3; i++) {
		cin >> num; //첫째 줄에 핀볼의 시작 상태가 주어진다.
		test1.insert(num);
	}

	for (int i = 0; i < 3; i++) {
		cin >> num; //첫째 줄에 핀볼의 시작 상태가 주어진다.
		test2.insert(num);
	}for (int i = 0; i < 3; i++) {
		cin >> num; //첫째 줄에 핀볼의 시작 상태가 주어진다.
		test3.insert(num);
	}for (int i = 0; i < 3; i++) {
		cin >> num; //첫째 줄에 핀볼의 시작 상태가 주어진다.
		test4.insert(num);
	}for (int i = 0; i < 3; i++) {
		cin >> num; //첫째 줄에 핀볼의 시작 상태가 주어진다.
		test5.insert(num);
	}

	//둘째 줄에 각 세로 칸의 점수를 나타내는 숫자 다섯개가 주어진다.
	cin >> score;
	test1.scores(score);
	cin >> score;
	test2.scores(score);
	cin >> score;
	test3.scores(score);
	cin >> score;
	test4.scores(score);
	cin >> score;
	test5.scores(score);
	int x, y;
	for (int i = 0; i < 10; i++) {
		cin >> x >> y;

		if (x == 1) {
			test1.insert(y);
		}
		else if (x == 2) {
			test2.insert(y);
		}
		else if (x == 3) {
			test3.insert(y);
		}
		else if (x == 4) {
			test4.insert(y);
		}
		else if (x == 5) {
			test5.insert(y);
		}

	}

	cout << test1.display() << endl;
	cout << test2.display() << endl;
	cout << test3.display() << endl;
	cout << test4.display() << endl;
	cout << test5.display() << endl;


}