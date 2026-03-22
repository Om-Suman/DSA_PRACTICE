#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1; 
    int pageSum = 0; 

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false; 
            }
            pageSum = arr[i];
        }
    }
    return true; 
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0; 
    int sum = 0;
    for (int i : arr) sum += i;
    int e = sum;
    int ans = -1; 

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = mid; 
            e = mid - 1; 
        } else {
            s = mid + 1;
        }
    }
    return ans; 
}

int main() {
    vector<int> books = {12, 34, 67, 90}; // Example book page counts
    int n = books.size();
    int m = 2; // Number of students
    cout << "Minimum pages: " << allocateBooks(books, n, m) << endl;
    return 0;
}
