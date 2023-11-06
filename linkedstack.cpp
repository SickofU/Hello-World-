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
    node* top; // 탑은 맨 마지막 원소를 가리킴
    //스택에서의 탑

public:
    stack() : top(nullptr) {}

    stack(const stack& anotherstack);

    stack& operator=(stack &org);
    // 스택에 요소를 추가 (push)
    void push(int value) {
        node* newnode = new node(value);
        newnode->next = top;
        top = newnode;
        //top이 nullptr을 가리키고 있었는데, 뉴노드를 가리키게 됨.
    }

    // 스택에서 요소를 제거하고 반환 (pop)
    int pop() {
        if (isempty()) {
            std::cerr << "스택이 비어있습니다." << std::endl;
            return -1; // 에러 값을 반환
        }

        int poppedvalue = top->data;
        node* temp = top;
        top = temp ->next;
        delete[] temp;
     
        return poppedvalue;
    }

    // 스택이 비어있는지 확인
    bool isempty() {
        return top == nullptr;
    }

    // 스택의 맨 위 요소를 반환 (peek)
    int peek() {
        if (isempty()) {
            std::cerr << "스택이 비어있습니다." << std::endl;
            return -1; // 에러 값을 반환
        }
        return top->data;
    }
};

stack& stack::operator=(stack &org) {
    //대입연산자 오버로딩하기
    if (this == &org) {
        return *this;
    }
    while (!isempty()) {
        pop();
    } //스택 비우기 
    if (org.top) {
        node* temp = org.top;
        while (temp) {
            push(temp->data);
            temp = temp->next; //일일이 다 넣어주는 작업
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
복사생성자 다르게 구현하는 방법
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

    std::cout << "맨 위 요소: " << mystack.peek() << std::endl; // 출력: 3

    mystack.pop();
    std::cout << "맨 위 요소를 제거하고 반환: " << mystack.pop() << std::endl; // 출력: 2

    return 0;
}
