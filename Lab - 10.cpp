#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val = -1) {
        value = val;
        next = nullptr;
    }
};

class StackLinkedList {
    Node* topNode;

public:
    StackLinkedList() {
        topNode = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void display() {
        Node* current = topNode;

        while (current != nullptr) {
            cout << current->value;

            if (current->next != nullptr) {
                cout << " , ";
            } else {
                cout << endl;
            }
            current = current->next;
        }
    }

    void pop() {
        if (topNode == nullptr) return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    void pushAtEnd(int val) {
        Node* newNode = new Node(val);

        if (topNode == nullptr) {
            topNode = newNode;
            return;
        }

        Node* current = topNode;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void popAtEnd() {
        if (topNode == nullptr) return;

        if (topNode->next == nullptr) {
            delete topNode;
            topNode = nullptr;
            return;
        }

        Node* current = topNode;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }
};

class StackArray {
    int stack[100];
    int topIndex;

public:
    StackArray() {
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex == 99) {
            cout << "Stack is Full.\n";
            return;
        }
        stack[++topIndex] = val;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack is empty.\n";
            return;
        }

        stack[topIndex--] = 0;
    }

    void display() {
        if (topIndex == -1) {
            cout << "Stack is Empty.\n";
            return;
        }

        for (int i = 0; i <= topIndex; i++) {
            cout << stack[i];
            if (i != topIndex) {
                cout << " <> ";
            }
        }
        cout << "\n";
    }

    int getStackLength() {
        return topIndex + 1;
    }

    int getStackSize() {
        return 100;
    }

    void pushAtEnd(int val) {
        if (topIndex == 99) {
            cout << "Stack is Full.\n";
            return;
        }

        stack[++topIndex] = val;

        int previous = stack[0];
        stack[0] = stack[topIndex];
        for (int i = 1; i <= topIndex; i++) {
            int current = stack[i];
            stack[i] = previous;
            previous = current;
        }
    }

    void popAtEnd() {
        if (topIndex == -1) return;

        for (int i = 0; i < topIndex; i++) {
            stack[i] = stack[i + 1];
        }
        topIndex--;
    }
};

int main() {
    cout << "<---------------Stack With LinkedList-------------->:\n";
    StackLinkedList linkedStack;
    linkedStack.push(15);
    linkedStack.push(27);
    linkedStack.push(42);
    linkedStack.push(58);
    linkedStack.push(63);
    linkedStack.push(90);
    linkedStack.display();

    cout << "\nAfter Pushing at End.\n";
    linkedStack.pushAtEnd(100);
    linkedStack.display();

    cout << "\nAfter Popping at end\n";
    linkedStack.popAtEnd();
    linkedStack.display();

    cout << "\nNormal Popping.\n";
    linkedStack.pop();
    linkedStack.display();

    cout << "\n\n<--------------Stack With Array:------------->\n";
    StackArray arrayStack;
    arrayStack.push(10);
    arrayStack.push(20);
    arrayStack.push(30);
    arrayStack.push(40);
    arrayStack.push(50);
    arrayStack.push(60);
    arrayStack.display();

    cout << "\nAfter Pushing at end.\n";
    arrayStack.pushAtEnd(99);
    arrayStack.display();

    cout << "\nAfter Popping at end.\n";
    arrayStack.popAtEnd();
    arrayStack.display();

    cout << "\nNormal Popping.\n";
    arrayStack.pop();
    arrayStack.display();

    return 0;
}
