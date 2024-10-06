#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
    Node* top;
    int length;

public:
    Stack() {
        top = nullptr;
        length = 0;
    }

    // Insert an element at the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        length++;
    }

    // Remove an element from the top of the stack
    void pop() {
        if(!top) {
            cout << "Stack is empty! Can't pop" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        length--;
    }

    // Return the top element of the stack
    int peek() {
        if(!top) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return top->data;
    }

    // Check if the stack is empty or not
    bool isEmpty() {
        return top == nullptr;
    }

    // Return the size of the stack
    int size() {
        return length;
    }

    // Destructor to clean dynamic memory
    ~Stack() {
        while(top) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}