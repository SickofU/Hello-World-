#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front =newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;//rear이 가리키고 있는 마지막 노드가 새로들어온 친구를 가리키게 한다.
            rear = newNode;// rear이 가리킨다.
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;  // Error code (you can use a different error handling approach)
        }
        int data = front->data;
        Node* temp = front; // 이 과정은 스택에서와 같다.
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Queue() {
        while (front != nullptr) { //널포인터가 되었을 때, 끝나니까
            Node* temp = front;
            front = front->next; //지우는 과정은 이제 익숙할듯
            delete temp;
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Queue elements: ";
    myQueue.display();

    int item = myQueue.dequeue();
    if (item != -1) {
        std::cout << "Dequeued item: " << item << std::endl;
    }

    std::cout << "Queue elements after dequeue: ";
    myQueue.display();

    return 0;
}
