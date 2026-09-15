#include <iostream>
using namespace std;
class Node {
    public: 
        int data; 
        Node* next; 
        Node(int data) {
            this->data = data; 
            this->next = NULL; 
        }
        ~Node() {
            int value = this->data ; 
            if (this->next !=NULL) {
                delete next ; 
                this->next = NULL ; 
            }
            cout<<"memory is free for node with data "<<value<<endl; 
        }
};
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp; 
    tail = temp; 
}
void deleteNode(Node * &head,int position) {
    if (position==1) {
         Node * temp = head ; 
         head = head->next ; 
         temp->next = NULL  ;
         delete temp ; 
    }
    else {
           Node * curr = head ; 
           Node * prev = nullptr ; 
           int cnt  = 1 ; 
           while (cnt<position) { 
            prev = curr ; 
            curr = curr->next ;
            cnt++ ; 
           }
            prev->next = curr->next ; 
            curr->next = NULL ; 
            delete curr ;  
    }
}
void deleteNodeByValue(Node * &head,int value) {
     Node * temp = head ; 
     int position = 1 ; 
     while (temp!=nullptr) {
        if (temp->data==value) {
            deleteNode(head,position) ; 
            temp = head ; 
            position = 1 ; 
        }
        temp = temp->next ;
        position++ ; 
     }
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
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);
    print(head);
    deleteNodeByValue(head,3);
    print(head);
    return 0;
}