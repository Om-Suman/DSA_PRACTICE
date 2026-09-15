#include <iostream>
#include <queue>
using namespace std;
class Node {
    public : 
    int data ; 
    Node * left ; 
    Node * right ; 

    Node(int data)  : data(data) , left(NULL) , right(NULL)  {}
};
Node* buildTree(Node* root) {
    int data;
    cin >> data;
    root = new Node(data);    

    if(data == -1) {
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
void levelOrder(Node * root) {
     queue<Node*> q  ;
     q.push(root);
     q.push(NULL);
     while (!q.empty()) {
        Node * temp = q.front() ; 
        q.pop() ; 
        if (temp==NULL) {
            cout<<endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
              if (temp->left) {
                q.push(temp->left);
              }
              if (temp->right) {
                q.push(temp->right);
              }
        }
        
     }
}
void inOrder(Node* &root) {
    if (root==nullptr) return ; 
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right) ; 
}
void preOrder(Node* &root) {
    if (root==nullptr) return ; 
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right) ; 
}
void postOrder(Node* &root) {
    if (root==nullptr) return ; 
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void builtFromLevelOrder(Node *&root) {
    queue<Node*>q;
    int data ; 
    cout<<"Enter data for root: ";
    cin>>data ; 
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node * temp = q.front() ; 
        q.pop() ; 

        cout<<"Enter the left Node for: "<<temp->data<<endl;
        int leftData ; 
        cin>>leftData ; 
        if (leftData!=-1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter the right Node for: "<<temp->data<<endl;
        int rightData ; 
        cin>>rightData ; 
        if (rightData!=-1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main() {
    Node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // root = buildTree(root);
    builtFromLevelOrder(root);
    cout<<"Level order traversal : "<<endl;
    levelOrder(root);
    return 0;
}