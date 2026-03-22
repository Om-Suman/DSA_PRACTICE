// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ; 
pair<int,int> MaxMin(int arr[],int low,int high) {
    if (low==high) return {arr[low],arr[low]} ; 
    else if (high==low+1) {
        if (arr[low]>arr[high]) return {arr[low],arr[high]} ; 
        else return {arr[high],arr[low]} ; 
    } 
    else {
        int mid =(low+high)/2 ; 
        pair<int,int> left = MaxMin(arr,low,mid) ; 
        pair<int,int> right = MaxMin(arr,mid+1,high) ; 
        
        return {max(left.first,right.first),min(left.second,right.second)} ; 
    }
}
int main() {
    int arr[] = {3,2,3,6,7,2,1,6} ; 
    int n = sizeof(arr)/sizeof(arr[0]) ; 
    pair<int,int> ans = MaxMin(arr,0,n-1) ; 
    
    cout<<"Maximum: "<<ans.first<<endl;
    cout<<"Minmum: "<<ans.second<<endl;

    return 0;
}