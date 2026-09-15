#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int k) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2; // Correct calculation of mid
        
        if (arr[mid] == k) {
            ans = mid;
            e = mid - 1; // Move left to find the first occurrence
        }
        else if (arr[mid] > k) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}
int lastOcc(int arr[], int n, int k) {  
    int s = 0;
    int e = n - 1;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2; 
        
        if (arr[mid] == k) { 
            ans = mid;
            s = mid + 1; 
        }
        else if (arr[mid] > k) {  // right move
            e = mid - 1;
        }
        else {   // left move
            s = mid + 1;
        }
    }
    return ans;
}
int totalocc(int arr[],int n,int k) {
    int x = firstOcc(arr,n,k);
    int y = lastOcc(arr,n,k);
    return (y-x)+1;
}

int main() {
    int arr[7] = {1,2,3,4,4,4,4}; // Sorted array
    cout <<"first occurrence of 4 is at index "<< firstOcc(arr, 7, 4) << endl;
    cout<<"last index of 4 is at index " <<lastOcc(arr,7,4)<<endl;
    cout<<"total occurence of 4 is "<<totalocc(arr,7,4)<<endl;
    return 0;
}
