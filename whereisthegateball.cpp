#include<iostream>

using namespace std;
enum cmd { L = 0, R, U, D };


class lineararray {
public:
	lineararray(int n) {
		size = n;
		row = n;
		col = n;
		store = new int* [row];
		for (int i = 0; i < row; i++) {
			store[i] = new int[col];
		}
		currentPosX = 1;



		currentPosY = 1;
	}
	lineararray() {
		store = new int* [row];
		for (int i = 0; i < row; i++) {
			store[i] = new int[col];
		}
		row = 0;
		col = 0;
		size = 0;
		currentPosX = 1;
		currentPosY = 1;
	}
	bool hutswing() {
		//Çê½ºÀ®ÀÎ°¡

	}
	void left() {
		//Çê½ºÀ®ÀÎÁö º¸°í ½ÇÇà
		if ((currentPosX - 1) == 0) {
			cout << "Çê½ºÀ®Çß¾î";
		}
		else
			currentPosX = currentPosX - 1;

	}
	void right() {
		if ((currentPosX + 1) == size + 1) {
			cout << "Çê½ºÀ®Çß¾î";
		}
		else
			currentPosX = currentPosX + 1;

	}
	void up() {
		if ((currentPosY + 1) == size + 1) {
			cout << "Çê½ºÀ®Çß¾î";
		}
		else
			currentPosY = currentPosY + 1;
	}
	void down() {
		if ((currentPosY - 1) == 0)
			cout << "Çê½ºÀ®Çß¾î";
		else
			currentPosY = currentPosY - 1;
	}
	void lastpos() {
		cout << " (" << currentPosX << "," << currentPosY << ")";
	}
private:
	int** store; // ÀÌÁßÆ÷ÀÎÅÍ·Î ÁöÁ¤
	int row;
	int col;
	int currentPosX;
	int currentPosY;
	int size;
};

int main() {

	int N;
	cin >> N;// NÀÌ ÁÖ¾îÁü. ÀÌ°Ô ¸î ¹ÙÀÌ ¸î Å©±â °ø°£ÀÓ.
	char c;
	int swing;//swing È½¼ö ¸î¹ø ÀÔ·ÂÇÒ °ÇÁö
	cin >> swing;
	lineararray test(N);

	for (int i = 0; i < swing; i++) {
		cin >> c;

		switch (c) {
		case 'L':
			test.left();
			break;
		case 'R':
			test.right();
			break;
		case'U':
			test.up();
			break;
		case'D':
			test.down();
			break;
		}

	}
	test.lastpos();

}
