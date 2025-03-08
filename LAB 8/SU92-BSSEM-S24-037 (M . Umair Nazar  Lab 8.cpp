#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int v = 0) {
        value = v;
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

    // Insert at the beginning of the list
    void insertAtStart(int v) {
        Node* newNode = new Node(v);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  // When the list is empty, both head and tail point to the new node
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int v) {
        Node* newNode = new Node(v);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert in the middle of the list
    void insertAtMiddle(int v) {
        Node* newNode = new Node(v);
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
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int v, int position) {
        if (position < 1) {
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(v);
        if (position == 1) {
            insertAtStart(v);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
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

    // Display the list from the beginning to the end
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list from the end to the beginning
    void displayReverse() {
        Node* temp = tail;
        cout << "Reversed Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->value;
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

    // Adding nodes at different positions
    list.insertAtStart(10);
    list.insertAtEnd(30);
    list.insertAtEnd(50);
    list.insertAtEnd(70);
    list.insertAtPosition(20, 2);

    cout << "Before inserting in the middle:\n";
    list.display();
    list.displayReverse();

    list.insertAtMiddle(40);

    cout << "\nAfter inserting in the middle:\n";
    list.display();
    list.displayReverse();

    return 0;
}
