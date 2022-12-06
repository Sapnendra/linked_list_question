#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    // destructor
    ~Node() {
        int value = this -> data;
        if(this -> data == NULL) {
            delete next;
            next = NULL;
        }
        cout <<"Memory is free for node with data : "<< value << endl;
    }
};

void insertNode(Node* &tail, int element, int data) {
    // for empty list
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    } else {
        // for Non-empty list
        // Assuming that the element present int the list
        Node* curr = tail;
        while(curr -> data != element) {
            curr = curr -> next;
        }
        // element founded 
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail) {
    Node* temp = tail;
    do {
        cout << tail -> data <<" ";
        tail = tail -> next;
    } while (tail != temp);
    cout << endl;
}

// deletion on doubly linked list
void deleteNode(Node* tail, int value) {
    // for empty list
    if(tail == NULL) {
        cout << "list is empty, please try again: "<< endl;
        return;
    }
    
    Node* prev = tail;
    Node* curr = prev -> next;
    //
    if(curr == prev) {
        tail = NULL;
    }
    // for Non-empty list
    // assuming that the "value" is present in the linked list
    // for more than two element
    while(curr -> data != value) {
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    if(tail == curr) {
        tail = prev;
    }
    curr -> next = NULL;
    delete curr;
}

int main() {

    Node* tail = NULL;

    insertNode(tail, 1, 11);
    print(tail);

    insertNode(tail, 11, 12);
    print(tail);

    insertNode(tail, 12, 13);
    print(tail);

    insertNode(tail, 13, 14);
    print(tail);

    insertNode(tail, 12, 50);
    print(tail);

    insertNode(tail, 50, 51);
    print(tail);

    insertNode(tail, 51, 52);
    print(tail);

    deleteNode(tail, 52);
    print(tail);

    deleteNode(tail, 12);
    print(tail);

    return 0;
}