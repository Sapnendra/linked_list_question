#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;  
        this -> prev = NULL;
    }

    // destructor
    ~Node() {
        int value = this -> data;
        // memory free
        if(this -> data == NULL) {
            delete next;
            next = NULL;
        }
        cout <<"Memory is free for node with data : "<< value << endl;
    }
};

// find length of linked list
int getlength(Node* head) {
    Node* temp = head;
    int count = 0;
    while( temp != NULL ) {
        count++;
        temp = temp -> next;
    } 
    return count;
}

// traversing on doubly linked list
void print(Node* &head, Node* &tail) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
    cout <<"Head : " << head -> data << endl;
    cout <<"Tail : " << tail -> data << endl;
}

// Insert an element at start or head
void insertAtHead(Node* &head, Node* &tail, int d) {
    // empty list
    if(head ==NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        // more than two element
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
}

// Insert An element at tail or end of the linked list
void insertAtTail(Node* &tail, Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        tail -> next = temp;
        head -> prev = tail;
        tail = temp;
    }
}

// deletion on doubly linked list
void deleteNode(int position, Node* &head) {
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        temp -> next = NULL;
        head = temp -> next;
        delete temp;
    } else {
        // deletion an middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }   
}

int main() {
    Node* node1 = new Node(4);

    Node* head = node1;
    Node* tail = node1;
    print(head, tail);

    //cout << getlength(head) << endl;
    insertAtHead(head, tail, 3);
    print(head, tail);

    insertAtTail(tail, head, 5);
    print(head, tail);

    insertAtTail(tail, head, 6);
    print(head, tail);

    insertAtTail(tail, head, 7);
    print(head, tail);

    insertAtTail(tail, head, 8);
    print(head, tail);

    deleteNode(3,head);
    print(head, tail);

    deleteNode(2,head);
    print(head, tail);

    deleteNode(4,head);
    print(head, tail);

    return 0;
}