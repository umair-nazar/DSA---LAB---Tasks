#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d = 0) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  // If the list is empty, head and tail are the same
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  // If the list is empty, head and tail are the same
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at the center (middle) of the list
    void insertAtMiddle(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            Node* temp = head;
            int count = 0;
            while (temp != nullptr) {
                count++;
                temp = temp->next;
            }

            int middle = count / 2;
            temp = head;
            for (int i = 0; i < middle; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int d, int pos) {
        if (pos < 1) {
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(d);
        if (pos == 1) {
            insertAtBeginning(d);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of bounds\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Display the list in order
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list in reverse
    void displayReverse() {
        Node* temp = tail;
        cout << "Reversed Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtPosition(15, 2);

    cout << "Before inserting at the middle:\n";
    list.display();
    list.displayReverse();

    list.insertAtMiddle(25);

    cout << "\nAfter inserting at the middle:\n";
    list.display();
    list.displayReverse();

    return 0;
}
