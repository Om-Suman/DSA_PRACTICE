#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to reverse a doubly linked list
void reverse(Node*& head) {
    if (!head) return;

    Node* temp = nullptr;
    Node* current = head;

    // Swap the previous and next pointers for each node
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the cases when the list is empty or contains only one node
    if (temp != nullptr) {
        head = temp->prev;
    }
}

// Utility function to print the list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Utility function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    cout << "Original List: ";
    printList(head);

    reverse(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
