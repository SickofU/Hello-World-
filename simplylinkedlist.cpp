#include<iostream>
using namespace std;

class Node2 {
	Node2* prev;
	Node2* next;
	int data;
public: 
	Node2(int val = 0) {
		data = val;
		prev = NULL;
		next = NULL;

	}
	Node2* getPrev() { return prev; }
	Node2* getNext() { return next; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { next = n; }
	void display();
	bool hasData(int val) { return data == val; }
	void insertnext(Node2* n) {
		if (n != NULL) {
			n->prev = this;
			n->next = next;
			if (next != NULL)next->prev = n;
			next = n;
		}
	}
	Node2* remove() {
		if (prev != NULL)prev->next = next;
		if (next != NULL) next->prev = prev;
		return this;
	}

};
class DoubleLinkedlist {
	Node2 org;//헤드노드
public:
	DoubleLinkedlist() {
		org = 0;
	}
	~DoubleLinkedlist() { while (!isEmpty())delete remove(0); }
	Node2* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == NULL; }
	Node2* getEntry(int pos) {
		Node2* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL)break;
		return n;
	}
	void insert(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertnext(n);

	}
	Node2* remove(int pos) {
		Node2* n = getEntry(pos);
		return n->remove();
	}
	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}
	void replace(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertnext(n);
		}
	}
	int size() {
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void display() {
		printf("[이중 연결리스트 항목수 = %2d] :", size());
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display();
		printf("\n");
	}
};
int main() {

	DoubleLinkedlist testia;
	testia.insert(0, new Node2(10));
	testia.insert(0, new Node2(20));
	testia.insert(1, new Node2(30));
	testia.insert(testia.size(), new Node2(40));
	testia.insert(2, new Node2(50));
	testia.remove(2);
	testia.remove(testia.size() - 1);
	testia.replace(1, new Node2(90));
	

}