#include <iostream>
#include <queue>
using namespace std;

class Node {
public : 
    int data; 
    Node *left; 
    Node *right; 

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// Function prototypes
Node* minValueInBST(Node* root);

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            cout << endl;
            if(!q.empty()) { 
                q.push(NULL);
            }  
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d); 
        return root; 
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d); 
    }
    return root; 
}

Node* deleteFromBST(Node* root, int val) {
    if (root==nullptr) {
        return nullptr ; 
    }
    if (root->data<val) {
        root->right = deleteFromBST(root->right,val);
    }
    else if (root->data>val) {
        root->left = deleteFromBST(root->left,val) ; 
    }
    else {
        // no child + right child
        if (root->left==nullptr) {
            Node * temp = root->right ; 
            delete root ; 
            return temp ; 
        }
        // left child
        if (root->right==nullptr) {
            Node * temp = root->left ; 
            delete root ; 
            return temp ; 
        }
        Node * succ = minValueInBST(root->right);
        root->data = succ->data ; 
        root->right = deleteFromBST(root->right,succ->data);
    }
    return root ; 
}

Node* minValueInBST(Node* root) {
    if (root == nullptr) return nullptr;  // Return nullptr if root is null
    
    Node* temp = root; 
    while(temp->left != nullptr) {
        temp = temp->left; 
    }
    return temp; 
}

Node* maxValueInBST(Node* root) {
    if (root == nullptr) return nullptr;  // Return nullptr if root is null
    
    Node* temp = root; 
    while(temp->right != nullptr) {
        temp = temp->right; 
    }
    return temp;
}

void takeInput(Node*& root) {
    int data; 
    cin >> data; 

    while(data != -1) {
        root = insertIntoBST(root, data); 
        cin >> data; 
    }
}

bool searchInBST(Node* root, int d) {
    Node* temp = root; 
    
    while(temp != nullptr) {
        if(temp->data == d) {
            return true; 
        }
        if(temp->data > d) {
            temp = temp->left;
        } else {
            temp = temp->right; 
        }
    }
    return false;
}

int main() {
    Node* root = new Node(50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);
    deleteFromBST(root,30);
    levelOrderTraversal(root);
    return 0;
}
