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

    // Print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addAtStart(3);
    list.addAtEnd(5);
    list.addAtEnd(7);
    
    cout << "Linked List: ";
    list.printList();

    return 0;
}
