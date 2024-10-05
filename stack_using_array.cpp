#include <bits/stdc++.h>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

    // Increase the stack when its full (doubles the capacity)
    void increaseSize() {
        capacity *= 2;
        int* temp = new int[capacity];

        for(int i = 0; i <= top; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

public:
    // Constructor to initialize the stack
    Stack(int size = 2) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    // Add an element at the top of the stack
    void push(int value) {
        if(top == capacity - 1) {
            increaseSize();
        }

        arr[++top] = value;
    }

    // Removes the top element of stack
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty! Can't Pop" << endl;
            return;
        }

        top--;
    }

    // Returns the top element of the stack
    int peek() {
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[top];
    }

    // Checks the stack is empty of not
    bool isEmpty() {
        // if(top == -1) {
        //     return true;
        // } else {
        //     return false;
        // }

        return top == -1;
    }

    // Returns the size of the stack
    int size() {
        return top + 1;
    }

    // Destructor to clean the dynamic memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    cout << "Current top element: " << s.peek() << endl;

    s.push(30);
    cout << "Current top element after resizing: " << s.peek() << endl;

    s.push(40);
    cout << "Current size of stack: " << s.size() << endl;

    s.pop();
    cout << "Current top element after pop: " << s.peek() << endl;
    
    return 0;
}