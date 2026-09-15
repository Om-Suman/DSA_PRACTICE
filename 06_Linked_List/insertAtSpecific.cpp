#include <iostream>
using namespace std;
struct Node {
    int data ;
    Node * next ; 
    Node(int data) {
        this->data = data ; 
        this->next = nullptr ; 
    }
};

void insertAtHead(Node * & head , int d) {
    Node * temp = new Node(d);
    temp->next = head ; 
    head = temp ; 
}
void insertAtTail(Node *&tail,int d) {
    Node * temp = new Node(d) ; 
    tail->next = temp ; 
    tail = temp ; 
}
void insertAfter( Node * &head,int key , int d) {
    if (key==1) {
        insertAtHead(head,d);
        return ;
    }
    Node * current = head ; 
    while (current!=nullptr) {
        if (current->data==key) break ; 
        current = current->next ; 
    }
    // if (current->next==NULL) {
    //     insertAtTail(tail,d);
    //     return ; 
    // }

    Node * newNode = new Node(d);
    newNode->next = current->next ; 
    current->next = newNode ; 
}
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; 
}
 
int main() {
    // Node* head = new Node(2);
    // head->next = new Node(3);
    // head->next->next = new Node(5);
    // head->next->next->next = new Node(6);
    // print(head);
    // insertAfter(head,2,9);
    // print(head);
   Node* head = nullptr;
   Node* tail = nullptr; 
   int size = 5;
    
    for (int i = 0; i < size; i++) {
        int elem;
        cin >> elem;
        if (head == nullptr) {
            head = new Node(elem);
            tail = head; 
        } else {
            insertAtTail(tail, elem);
        }
    }
    
    print(head);
    return 0;
}

