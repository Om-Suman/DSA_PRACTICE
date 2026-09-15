#include <iostream>
using namespace std;

class Stack {
    public : 
            int *arr;
            int top;
            int size;
        
        Stack(int size) {
            this->size = size ; 
            arr = new int[size] ; 
            top = -1 ; 
        }
    
        void push(int element) {
             if (size-top>1) {
                top++;
                arr[top] = element ; 
              }
             else {
                cout<<"Stack Overflow"<<endl;
             }
        }
        void pop() {
              if (top>=0) {
                top--;
              }
              else {
                  cout<<"Stack Underflow"<<endl;
              }
        }
        int peek() {
              if (top>=0 && top<size) {
                return arr[top];
              }
              else {
                cout<<"Stack is Empty"<<endl;
                return -1 ; 
              }
        }
        bool isEmpty() {
              return top==-1;
        }
};
int main() {
    Stack s1(5);
    s1.push(22);
    s1.push(24);
    s1.push(26);
    cout<<s1.peek() <<endl;
    s1.pop();
    cout<<s1.peek() <<endl;
    s1.pop();
    s1.pop();
    s1.peek();


    return 0;
}