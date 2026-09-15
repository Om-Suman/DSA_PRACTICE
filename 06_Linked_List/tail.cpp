#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void insertAtTail(Node*& head, int d) {
    Node* temp = new Node;
    temp->data = d;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
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
    Node* head = nullptr;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int elem;
        cin >> elem;
        insertAtTail(head, elem);
    }
    print(head);
    insertAtTail(head,100);
    print (head);
    return 0;
}
