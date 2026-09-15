#include <iostream>
#include <vector>
using namespace std;
void reverse (vector<int>&arr,int n) {
    // int s = 0 ; 
    // int e = n-1 ; 
    // while (s<=e) {
    //     swap(arr[s],arr[e]);
    //     s++;
    //     e--;
    // }
   for (int i=0;i<n/2;i++) {
    swap(arr[i],arr[n-1-i]);
   }
}

int main() {
    vector<int>arr = {1,2,3,4,5,6};
    reverse(arr,6);
    for (int i : arr) {
        cout<<i<<" ";
    }
    return 0;
}