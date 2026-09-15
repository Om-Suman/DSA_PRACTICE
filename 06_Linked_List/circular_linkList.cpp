#include <iostream>
using namespace std;
class Node {
     public :
             int data ; 
             Node * next;
             Node(int d) {
                data = d ; 
                next = nullptr ; 
             }
             ~Node() {
                if (this->next!=NULL) {
                    delete next ; 
                    next = NULL ; 
                }
             }
};
void insertNode(Node * &tail,int element,int d) { 
    if (tail==nullptr) {
        Node * newNode = new Node(d);
        tail = newNode ; 
        newNode->next = newNode ; 
    }
    else {
        Node * curr = tail ; 
        while (curr->data!=element) {
            curr = curr->next ; 
        }
        Node * temp = new Node(d);
        temp->next = curr->next ; 
        curr->next = temp ;  
    }

}  
void printNode(Node * tail) {
    if (tail==NULL) {
        cout<<"List is empty"<<endl;
        return ; 
    }
    Node * temp = tail ; 
    do {
        cout<<tail->data<<" " ; 
        tail = tail->next ; 
    } while (tail!=temp);
    cout<<endl;
}
void deleteNode(Node *&tail,int value) {
    if (tail==NULL) {
         cout<<"List is empty"<<endl;
         return ; 
    }
    else {
          Node * prev = tail ; 
          Node * curr =  prev->next ; 
          while (curr -> data!=value) {
            prev = curr ; 
            curr = curr->next ; 
          }
          prev->next = curr->next ; 
          if (prev==curr) {
            tail = NULL ; 
          }
          else if (tail==curr) {
            tail = prev ; 
          }
          curr->next = NULL ; 
          delete curr ; 
    }
}
int main() {
    Node * tail = nullptr ; 
    insertNode(tail,5,3);
    printNode(tail);
    insertNode(tail,3,5);
    printNode(tail);
    //insertNode(tail,5,7);
    // printNode(tail);
    // insertNode(tail,7,9);
    // printNode(tail);
    // insertNode(tail,5,6);
    // printNode(tail);
    // insertNode(tail,9,10);
    // printNode(tail);
    // insertNode(tail,3,4);
    // printNode(tail);
    deleteNode(tail,5);
    printNode(tail);
    return 0;
}