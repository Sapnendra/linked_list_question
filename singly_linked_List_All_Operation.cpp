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
        // memory free
        if(this -> data == NULL) {
            delete next;
            next = NULL;
        }
        cout <<"Memory is free for node with data : "<< value << endl;
    }
};

// Insert a elemnet at head of the linked list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

// Insert a elemnet at tail of the linked list
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

// Insert a element at any middle positon
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if(position == 1) {
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count < position-1) {
        temp = temp -> next;
        count++;
    }

    // Insert at last postion
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
    }

    //creating a node for a new data
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

// traverse on linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
}

// deletion on linked list
void deleteNode(int position, Node* &head) {
    // Deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //delete free start Node
        temp -> next = NULL;
        delete temp; 
    } else {
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int count  =  1;
        while( count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {

    //create a new node
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail,head, 1, 22);
    print(head);
    // insertAtPosition(head, 1, 20);
    // print(head);

    cout << "Head: " <<head -> data << endl;
    cout << "Tail: " <<tail -> data << endl;

    deleteNode(4, head);
    print(head);

    cout << "Head: " <<head -> data << endl;
    cout << "Tail: " <<tail -> data << endl;

    return 0;
} 