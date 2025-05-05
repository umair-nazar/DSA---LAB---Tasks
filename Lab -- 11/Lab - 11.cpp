#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val = 0) {
        value = val;
        next = nullptr;
    }
};

class LinkedQueue {
    Node* frontNode;
    Node* rearNode;

public:
    LinkedQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rearNode != nullptr) {
            rearNode->next = newNode;
            rearNode = newNode;
        } else {
            rearNode = frontNode = newNode;
        }
    }

    void dequeue() {
        if (frontNode == nullptr) return;

        Node* tempNode = frontNode;

        if (frontNode->next == nullptr) {
            frontNode = rearNode = nullptr;
        } else {
            frontNode = frontNode->next;
        }

        delete tempNode;
    }

    void display() {
        cout << "Linked List Queue: ";
        Node* current = frontNode;

        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << " <> ";
            }
            current = current->next;
        }

        cout << "\n";
    }
};

class ArrayQueue {
    int queueArray[100];
    int itemCount;

public:
    ArrayQueue() {
        itemCount = 0;
    }

    void enqueue(int val) {
        if (itemCount == 100) {
            cout << "Queue is Full.\n";
            return;
        }

        queueArray[itemCount++] = val;
    }

    void dequeue() {
        if (itemCount == 0) return;

        for (int i = 0; i < itemCount - 1; i++) {
            queueArray[i] = queueArray[i + 1];
        }

        itemCount--;
    }

    void display() {
        cout << "Array Queue: ";
        for (int i = 0; i < itemCount; i++) {
            cout << queueArray[i];
            if (i != itemCount - 1) {
                cout << " <> ";
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "Queue follows the First-In-First-Out (FIFO) rule\n\n";

    cout << "\tQueue with Linked List\n\n";

    LinkedQueue linkedQueue;
    linkedQueue.enqueue(11);
    linkedQueue.enqueue(22);
    linkedQueue.enqueue(33);
    linkedQueue.enqueue(44);
    linkedQueue.enqueue(55);
    linkedQueue.display();

    cout << "\nAfter Dequeue:\n";
    linkedQueue.dequeue();
    linkedQueue.display();

    cout << "\n\n\tQueue with Array:\n\n";

    ArrayQueue arrayQueue;
    arrayQueue.enqueue(101);
    arrayQueue.enqueue(202);
    arrayQueue.enqueue(303);
    arrayQueue.enqueue(404);
    arrayQueue.enqueue(505);
    arrayQueue.enqueue(606);
    arrayQueue.display();

    cout << "\nAfter Dequeue:\n";
    arrayQueue.dequeue();
    arrayQueue.display();

    return 0;
}
