#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>&arr,int n) {
     for (int i=0;i<n-1;i++) {
        int minIndex = i ; 
        for (int j=i+1;j<n;j++) {
            if (arr[j] < arr[minIndex]) minIndex = j ; 
        }
        swap(arr[minIndex],arr[i]);
     }
}
int main() {
    vector<int>arr = {5,3,4,1,2};
    selectionSort(arr,5);
    for (int i : arr) {
        cout<<i<<" ";   
    }
    return 0;
}