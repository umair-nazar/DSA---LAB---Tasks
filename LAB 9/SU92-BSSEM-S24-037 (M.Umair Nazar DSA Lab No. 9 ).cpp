#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    void addAtStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void addAtPosition(int value, int position) {
        if (position == 0) {
            addAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp->next == head) {
                addAtEnd(value);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void addAtMiddle(int value) {
        if (!head) {
            addAtStart(value);
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node(value);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    void print() {
        if (!head) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void printInReverse() {
        if (!head) return;

        Node* temp = head;
        Node* prev = NULL;
        Node* nextNode = NULL;

        do {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        } while (temp != head);

        head->next = prev;
        head = prev;

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;

        temp = head;
        prev = NULL;
        nextNode = NULL;
        do {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        } while (temp != head);
        head->next = prev;
        head = prev;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addAtStart(10);
    cll.addAtEnd(20);
    cll.addAtEnd(30);
    cll.addAtPosition(25, 2);
    cll.addAtMiddle(15);

    cout << "Circular Linked List in order: ";
    cll.print();

    cout << "Circular Linked List in reverse order: ";
    cll.printInReverse();

    return 0;
}
