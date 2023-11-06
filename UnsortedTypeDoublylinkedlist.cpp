#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* header;
    Node<T>* trailer;

public:
    DoublyLinkedList() {
        header = new Node<T>(T()); // ��� ��� ����
        trailer = new Node<T>(T()); // Ʈ���Ϸ� ��� ����
        header->next = trailer;
        trailer->prev = header;
    }

    ~DoublyLinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
        delete header;
        delete trailer;
    }

    bool isEmpty() const {
        return header->next == trailer;
    }

    void insertAfter(Node<T>* prevNode, T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void removeAfter(Node<T>* prevNode) {
        Node<T>* toRemove = prevNode->next;
        prevNode->next = toRemove->next;
        toRemove->next->prev = prevNode;
        delete toRemove;
    }

    void insertFront(T value) {
        insertAfter(header, value);
    }

    void removeFront() {
        if (!isEmpty()) {
            removeAfter(header);
        }
    }

    void insertBack(T value) {
        insertAfter(trailer->prev, value);
    }

    void removeBack() {
        if (!isEmpty()) {
            removeAfter(trailer->prev->prev);
        }
    }

    void display() {
        Node<T>* current = header->next;
        while (current != trailer) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> dll;
    dll.insertFront(1);
    dll.insertFront(2);
    dll.insertBack(3);
    dll.insertBack(4);

    dll.display(); // ���: 2 1 3 4

    dll.removeFront();
    dll.removeBack();

    dll.display(); // ���: 1 3

    return 0;
}
