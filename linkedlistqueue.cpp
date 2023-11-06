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
            rear->next = newNode;//rear�� ����Ű�� �ִ� ������ ��尡 ���ε��� ģ���� ����Ű�� �Ѵ�.
            rear = newNode;// rear�� ����Ų��.
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;  // Error code (you can use a different error handling approach)
        }
        int data = front->data;
        Node* temp = front; // �� ������ ���ÿ����� ����.
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
        while (front != nullptr) { //�������Ͱ� �Ǿ��� ��, �����ϱ�
            Node* temp = front;
            front = front->next; //����� ������ ���� �ͼ��ҵ�
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
