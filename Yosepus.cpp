#include <iostream>

class MyQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~MyQueue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full, cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty, cannot dequeue." << std::endl;
            return -1;
        }

        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
};

void josephus(int n, int k) {
    MyQueue queue(n);

    for (int i = 1; i <= n; i++) {
        queue.enqueue(i);
    }

    std::cout << "<";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            int item = queue.dequeue();
            queue.enqueue(item);
        }

        int eliminated = queue.dequeue();
        std::cout << eliminated;
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ">" << std::endl;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    josephus(n, k);

    return 0;
}
