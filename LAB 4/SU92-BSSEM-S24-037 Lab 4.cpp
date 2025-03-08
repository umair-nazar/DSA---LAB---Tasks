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

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

 
    void addAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

 
    void addAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Add a node at a specific position
    void addAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtStart(val);
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                if (temp == nullptr) {
                    cout << "Position out of range!" << endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }


    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addAtStart(50);
    list.addAtEnd(30);
    list.addAtPosition(70, 2);

    cout << "The linked list is: ";
    list.printList();

    return 0;
}
