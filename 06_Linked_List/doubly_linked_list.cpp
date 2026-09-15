#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    ~Node() {
        if (next) {
            delete next;
            next = nullptr;
        }
    }
};

void insertAtHead(Node *&head, Node *&tail, int d) {
    if (head == nullptr) {
        Node *temp = new Node(d);
        head = tail = temp;
    } else {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d) {
    if (tail == nullptr) {
        Node *temp = new Node(d);
        head = tail = temp;
    } else {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insert(Node *&tail, Node *&head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position) {
    if (head == nullptr) return; // Empty list

    if (position == 1) {
        Node *temp = head;
        if (head->next != nullptr) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = tail = nullptr; // List becomes empty
        }
        temp->next = nullptr;
        delete temp;
    } else {
        Node *curr = head;
        int cnt = 1;

        while (cnt < position && curr != nullptr) {
            curr = curr->next;
            cnt++;
        }

        if (curr == nullptr) return; // Position out of range

        if (curr->next == nullptr) { // Last node
            tail = curr->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
}

void print(Node *head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtHead(head, tail, 7);
    print(head);

    insertAtTail(tail, head, 9);
    print(head);

    insert(tail, head, 2, 10);
    print(head);

    insert(tail, head, 1, 100);
    print(head);

    insert(tail, head, 5, 200);
    print(head);

    deleteNode(head, tail, 1);
    print(head);

    deleteNode(head, tail, 2);
    print(head);

    return 0;
}
