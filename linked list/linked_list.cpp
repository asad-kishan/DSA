#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

class LinkedList {
    Node* head;
    int size;

    // Helper function to print the list in reverse order
    void reversePrintHelper(Node* node) {
        if(node) {
            reversePrintHelper(node->next);
            cout << node->data << " ";
        }
    }

public:
    LinkedList() : head(nullptr), size(0) {};

    // Insert at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at the specified index
    void insert(int idx, int value) {
        if(!idx) {
            insertAtHead(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        while(--idx) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Remove the node at the head of the list
    void eraseAtHead() {
        if(!head) {
            return;
        }

        Node* temp = head;
        head = temp->next;
        delete temp;
        size--;
    }

    // Remove the node at the specified index
    void erase(int idx) {
        if(!idx) {
            eraseAtHead();
            return;
        }

        Node* temp = head;
        while(--idx) {
            temp = temp->next;
        }

        Node* target = temp->next;
        temp->next = temp->next->next;
        delete target;
        size--;
    }

    // Print all the elements of the list
    void print() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Print all the elements in reverse order
    void reversePrint() {
        reversePrintHelper(head);
        cout << endl;
    }

    // Search for the first occurence of a value and return its index, or -1 if not found
    int searchValue(int value) {
        Node* temp = head;
        int idx = 0;

        while(temp) {
            if(temp->data == value) {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    // Search all the occurance of a value and return its indexes
    vector<int> searchAllValues(int value) {
        vector<int> arr;
        Node* temp = head;
        int idx = 0;

        while(temp) {
            if(temp->data == value) {
                arr.push_back(idx);
            }

            temp = temp->next;
            idx++;
        }

        return arr;
    }

    // Get the size of the linked list
    int getSize() {
        return size;
    }

    // Destructor to clean up dynamically allocated memory 
    ~LinkedList() {
        Node* temp = head;
        while(temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList l;
    l.insertAtHead(5);
    l.insertAtHead(4);
    l.insertAtHead(3);
    l.insertAtHead(2);
    l.insertAtHead(1);
    l.print();
    l.reversePrint();
    cout << "size: " << l.getSize() << endl << endl;

    l.insert(0, 0);
    l.print();
    cout << "size: " << l.getSize() << endl << endl;

    l.erase(5);
    l.print();
    cout << "size: " << l.getSize() << endl << endl;

    return 0;
}