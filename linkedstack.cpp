#include<iostream>

struct node {
    int data;
    node* next;
    node() {
        next = NULL;
    }
    node(int val) : data(val), next(nullptr) {}
};

class stack {
private:
    node* top; // ž�� �� ������ ���Ҹ� ����Ŵ
    //���ÿ����� ž

public:
    stack() : top(nullptr) {}

    stack(const stack& anotherstack);

    stack& operator=(stack &org);
    // ���ÿ� ��Ҹ� �߰� (push)
    void push(int value) {
        node* newnode = new node(value);
        newnode->next = top;
        top = newnode;
        //top�� nullptr�� ����Ű�� �־��µ�, ����带 ����Ű�� ��.
    }

    // ���ÿ��� ��Ҹ� �����ϰ� ��ȯ (pop)
    int pop() {
        if (isempty()) {
            std::cerr << "������ ����ֽ��ϴ�." << std::endl;
            return -1; // ���� ���� ��ȯ
        }

        int poppedvalue = top->data;
        node* temp = top;
        top = temp ->next;
        delete[] temp;
     
        return poppedvalue;
    }

    // ������ ����ִ��� Ȯ��
    bool isempty() {
        return top == nullptr;
    }

    // ������ �� �� ��Ҹ� ��ȯ (peek)
    int peek() {
        if (isempty()) {
            std::cerr << "������ ����ֽ��ϴ�." << std::endl;
            return -1; // ���� ���� ��ȯ
        }
        return top->data;
    }
};

stack& stack::operator=(stack &org) {
    //���Կ����� �����ε��ϱ�
    if (this == &org) {
        return *this;
    }
    while (!isempty()) {
        pop();
    } //���� ���� 
    if (org.top) {
        node* temp = org.top;
        while (temp) {
            push(temp->data);
            temp = temp->next; //������ �� �־��ִ� �۾�
        }
    }
    return *this;
}
stack::stack(const stack& anotherstack) {
    node* ptr1;
    node* ptr2;
    if (anotherstack.top == NULL)
        top = NULL;
    else
    {
        top = new node;
        top->data = anotherstack.top->data;
        ptr1 = anotherstack.top->next;
        ptr2 = top;
        while (ptr1 != NULL) {
            ptr2->next = new node;
            ptr2 = ptr2->next;
            ptr2->data = ptr1->data;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
    }
}
/*
��������� �ٸ��� �����ϴ� ���
top=NULL;
if(org.top){
node* temp=org.top;
while(temp){
push(temp->data); 
temp=temp->next;
}
*/





int main() {
    stack mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    std::cout << "�� �� ���: " << mystack.peek() << std::endl; // ���: 3

    mystack.pop();
    std::cout << "�� �� ��Ҹ� �����ϰ� ��ȯ: " << mystack.pop() << std::endl; // ���: 2

    return 0;
}
