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
void insertAtTail(Node *&tail,int d)  {
    Node * temp = new Node(d);
    tail->next = temp ; 
    tail = temp ; 
}
void findMax(Node * &head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node * temp = head ; 
    int max = INT_MIN ; 
    while (temp!=nullptr) {
         if (max<temp->data) {
            max = temp->data ; 
         }
         temp = temp->next ; 
    }
    cout<<max<<endl;
}
int main() {
    Node * head = nullptr ; 
    Node * tail = nullptr ; 
    int size ; 
    cin>>size ; 
    for (int i=0;i<size;i++) {
        int elem ; 
        cin>>elem ; 
        if (head==nullptr) {
            head = new Node(elem);
            tail = head; 
        }
        else {
            insertAtTail(tail,elem);
        }
    }
    findMax(head);
    return 0;
}