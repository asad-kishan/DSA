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

class LinkedList {
    Node* head;
    int length;

public:
    LinkedList() {
        head = nullptr;
        length = 0;
    }

    // Insert at the front of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Insert a value in the specified index (0 based index);
    void insert(int value, int idx) {
        if(idx < 0 || idx > length) {
            cout << "Error! Specified Index is out of range." << endl;
            return;
        }

        if(idx == 0) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < idx-1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    // Insert at the tail of the list
    void insertAtTail(int value) {
        insert(value, length);
    }

    // Delete the front node
    void deleteAtHead() {
        if(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    // Delete the node at specified Index (0 based index)
    void deleteByIdx(int idx) {
        if(idx < 0 || idx >= length) {
            cout << "Error! Specified Index is out of range." << endl;
            return;
        }

        if(idx == 0) {
            deleteAtHead();
            return;
        }

        Node* current = head;
        for(int i = 0; i < idx-1; i++) {
            current = current->next;
        }

        Node* targetNode = current->next;
        current->next = targetNode->next;
        delete targetNode;
        length--;
    }

    // Delete a node of specified value
    void deleteByValue(int value) {
        Node* current = head;
        Node* prev = nullptr;

        if(current && current->data == value) {
            deleteAtHead();
            return;
        }

        while(current) {
            if(current->data == value) {
                break;
            }

            prev = current;
            current = current->next;
        }

        if(current == nullptr) {
            return;
        }

        prev->next = current->next;
        delete current;
        length--;
    }

    // Print the linked list 
    void printList() {
        Node* temp = head;

        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search an element and returns index of its first occurance
    int search(int value) {
        int idx = 0;
        Node* temp = head;

        while(temp) {
            if(temp->data == value) {
                return idx;
            }
            
            idx++;
            temp = temp->next;
        }
        
        return -1; // return -1 if doesn't exist 
    }

    // Length of the list
    int size() {
        return length;
    }

    // Destructor to free memory of the entire list
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;

        while(current) {
            nextNode = current->next; 
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }
};

int main(void) {
    LinkedList list;

    list.insertAtHead(60);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    cout << "Linked List: ";
    list.printList();
    cout << "Size of the list: " << list.size() << endl;

    list.insert(10, 0);
    list.insert(50, 4);
    list.insert(70, 6);
    list.insertAtTail(80);
    cout << "Linked List: ";
    list.printList();
    cout << "Size of the list: " << list.size() << endl;

    list.deleteByIdx(7);
    list.deleteAtHead();
    list.deleteByValue(20);
    cout << "Linked List: ";
    list.printList();
    cout << "Size of the list: " << list.size() << endl;

    int num = 50;
    cout << "The index of " << num << " is: " << list.search(num) << endl; 

    return 0;
}
