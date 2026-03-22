#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int result = binarySearch(arr, arr.size(), 4);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
