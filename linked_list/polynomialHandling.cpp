#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
    
    Node(int coeff, int power) {
        this->coeff = coeff;
        this->power = power;
        this->next = nullptr;
    }
};

void insertAtTail(Node*& head, Node*& tail, int coeff, int power) {
    Node* temp = new Node(coeff, power);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* addPoly(Node* node1, Node* node2) {
    Node* poly1 = node1;
    Node* poly2 = node2;
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;

    while (poly1 != nullptr || poly2 != nullptr) {
        if (poly1 != nullptr && (poly2 == nullptr || poly1->power > poly2->power)) {
            insertAtTail(resultHead, resultTail, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly2 != nullptr && (poly1 == nullptr || poly2->power > poly1->power)) {
            insertAtTail(resultHead, resultTail, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            insertAtTail(resultHead, resultTail, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    return resultHead;
}

void print(Node* node) {
    Node* temp = node;
    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->power;
        temp = temp->next;
        if (temp != nullptr) cout << " + "; // Print "+" between terms
    }
    cout << endl;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* tail1 = nullptr; // Tail for poly1
    Node* tail2 = nullptr; // Tail for poly2

    for (int i = 0; i < n1; i++) {
        int coeff, power;
        cin >> coeff >> power;
        insertAtTail(poly1, tail1, coeff, power);
    }
    for (int i = 0; i < n2; i++) {
        int coeff, power;
        cin >> coeff >> power;
        insertAtTail(poly2, tail2, coeff, power);
    }

    Node* result = addPoly(poly1, poly2);
    print(result);

    return 0;
}
