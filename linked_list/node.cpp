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
};

void insertAtHead(Node * &tail,Node* &head, int d) {
    if (head==nullptr) {
        Node * temp = new Node(d);
        head = tail = temp ; 
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
    
}
void insertAtTail(Node* &tail,Node* &head,int d) {
    if (tail==NULL) {
        Node * temp = new Node(d);
        head = tail = temp ; 
     }
     else {
        Node * temp = new Node(d);
        tail->next = temp ; 
        tail = temp ; 
     }
}
void insertAtPosition(Node*&head, int position,int d) {
    Node* temp = head ;
    int cnt = 1 ; 
    while (cnt<position-1) {
        temp = temp-> next ; 
        cnt++;
    }
    Node * nodeToInsert = new Node(d) ;
    nodeToInsert->next = temp->next ; 
    temp->next = nodeToInsert ; 
}

void print(Node* head) {
    Node* temp = head; 
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int size ; 
    cin>>size;
    Node * head = nullptr ; 
    Node * tail = nullptr ; 

    for (int i=1;i<=size ;i++) {
        int elem ; 
        cin>>elem;
        insertAtTail(tail,head,elem);
    }
    print(head);
    insertAtPosition(head,3,5) ; 
    print(head) ; 
    
    return 0;
}
