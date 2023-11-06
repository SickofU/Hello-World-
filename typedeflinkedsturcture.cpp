#include<iostream>

 typedef int Item; //int 타입을 item으로 바꿔쓰기
typedef struct node {
	Item data;
	struct node* link;
}Node, * NodePtr;

typedef NodePtr StackPtr;

void Push(StackPtr& pStack, Item item);
void Pop(StackPtr& pStack, Item& item);
int IsEmpty(StackPtr pStack);

int main() {
	StackPtr pStack = NULL;
	Item item;
	for (int i = 0; i < 10; i++)
		Push(pStack, i);
	while (!IsEmpty(pStack)) {
		Pop(pStack, item);
		printf("%d ", item);
	}
}

int IsEmpty(StackPtr pStack) {
	return pStack == NULL;
}

void Push(StackPtr& pStack, Item item) {
	NodePtr pNode = (NodePtr)malloc(sizeof(Node));
	if (!pNode)
		return;
	pNode->data = item;
	pNode->link = pStack;
	pStack = pNode;
}

void Pop(StackPtr& pStack, Item& item) {
	if (pStack == NULL)return;
	item = pStack->data;
	pStack = pStack->link;
}