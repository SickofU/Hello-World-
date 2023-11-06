#include<iostream>
#include<vector>
using namespace std;
#include<string>
class stack {
public:
	stack(int n) {
		top = -1;
		store = new char[n];
	}
	stack() {}
	void push(char _c) {
		top++;
		store[top] = _c;
	}

	bool empty() {
		return top == -1;
	}
	char pop() {
		char result = store[top];
		top--;
		return result;
	}
	bool determine() {
		int i = 0;
		
		for (int j = 0; j <= top; j++) {
			if (store[j] == '(') {
				i++;
			}
			else if (store[j] == ')') {
				if (i == 0) {
					return false;
				}
				else
					i--;
			}
		}
		return i == 0;

	}
private:
	int top;
	char* store;
};

int main() {
	int T;
	cin >> T;
	string vps;
	for (int i = 0; i < T; i++) {
		cin >> vps;
		stack testo(vps.length());

		for (int j = 0; j < vps.length(); j++) {
			char c = vps[j];
			testo.push(c);
		}
		if (testo.determine()) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}
}