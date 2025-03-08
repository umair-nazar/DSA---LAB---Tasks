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
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void addAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the end
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a node at any specific position
    void addAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtStart(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the entire linked list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the first node
    void displayFirstNode() {
        if (head != nullptr) {
            cout << "First Node: " << head->value << endl;
        }
    }

    // Display the last node
    void displayLastNode() {
        Node* temp = head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            cout << "Last Node: " << temp->value << endl;
        }
    }

    // Display the middle node
    void displayMiddleNode() {
        Node* slow = head;
        Node* fast = head;
        if (head != nullptr) {
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
            cout << "Middle Node: " << slow->value << endl;
        }
    }
};

int main() {
    LinkedList list;
    list.addAtStart(12);
    list.addAtStart(25);
    list.addAtEnd(5);
    list.addAtEnd(7);
    list.addAtPosition(19, 3);

    cout << "Linked List: ";
    list.displayList();

    list.displayFirstNode();
    list.displayLastNode();
    list.displayMiddleNode();

    return 0;
}
