#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d = 0) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addAtBeginning(int d) {
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int d) {
        Node* newNode = new Node(d);
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

    void addAtPosition(int d, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtBeginning(d);
            return;
        }
        Node* newNode = new Node(d);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Invalid position!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromStart() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromEnd() {
        if (head) {
            Node* temp = head;
            if (!temp->next) {
                head = nullptr;
                delete temp;
                return;
            }
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayFirst() {
        if (head) cout << "First Node: " << head->data << endl;
    }

    void displayLast() {
        if (head) {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            cout << "Last Node: " << temp->data << endl;
        }
    }

    void displayMiddle() {
        if (head) {
            Node* temp = head;
            int count = 0;
            while (temp) {
                count++;
                temp = temp->next;
            }
            int middle = count / 2;
            temp = head;
            for (int i = 0; i < middle; i++) {
                temp = temp->next;
            }
            cout << "Middle Node: " << temp->data << endl;
        }
    }
};

int main() {
    LinkedList list;
    list.addAtBeginning(12);
    list.addAtBeginning(24);
    list.addAtEnd(36);
    list.addAtEnd(48);
    list.addAtPosition(18, 2);
    list.addAtPosition(60, 4);

    cout << "Linked List: ";
    list.display();

    list.displayFirst();
    list.displayLast();
    list.displayMiddle();

    cout << "\nAfter deleting the last node:\n";
    list.deleteFromEnd();
    list.display();

    cout << "\nAfter deleting the first node:\n";
    list.deleteFromStart();
    list.display();

    return 0;
}
