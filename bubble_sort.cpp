#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void bubbleSort(vector<int>&arr,int n) {
    bool swapped = false ; 
     for (int i=1;i<n;i++) {
        for (int j=0;j<n-i;j++) {
             if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = true ; 
             }
        }
        if (swapped==false) break;
     }
}

int main() {
    vector<int>arr = {10,1,3,2,7,6};
    bubbleSort(arr,6);
    for (int i : arr) {
        cout<<i<<" ";
    }
    return 0;
}