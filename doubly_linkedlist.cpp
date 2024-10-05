#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert a node at the front of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        newNode->prev = nullptr;

        if(head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    // Insert a node at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        newNode->next = nullptr;

        if(tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    // Delete the first node from the list
    void deleteAtHead() {
        if(!head) {
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    // Delete the last node from the list
    void deleteAtTail() {
        if(!tail) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if(tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    // Delete a node by its value
    void deleteNode(int value) {
        Node* temp = head;
        while(temp && temp->data != value) {
            temp = temp->next;
        }

        if(!temp) {
            return;
        }

        if(temp == head) {
            deleteAtHead();
            return;
        }

        if(temp == tail) {
            deleteAtTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Print the list form head to tail
    void printList() {
        Node* temp = head;

        cout << "List: ";
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print the list form tail to head (reverse order)
    void printReverse() {
        Node* temp = tail;

        cout << "Reverse List: ";
        while(temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Destructor to clean dynamic memory
    ~DoublyLinkedList() {
        Node* current = head;
        Node* prev;

        while(current) {
            prev = current;
            current = current->next;
            delete prev;
        }

        head = tail = nullptr;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtHead(10);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteNode(10);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteNode(30);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteNode(40);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteNode(20);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.insertAtHead(2);
    dll.insertAtTail(3);
    dll.insertAtHead(1);
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteAtHead();
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteAtTail();
    dll.printList();
    dll.printReverse();
    cout << endl;

    dll.deleteAtTail();
    dll.printList();
    dll.printReverse();
    cout << endl;

    return 0;
}