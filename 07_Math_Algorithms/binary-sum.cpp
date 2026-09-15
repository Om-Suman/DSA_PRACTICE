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

vector<int> Twosum(vector<int>& nums, int target) {
    int l = nums.size();
    for (int i = 0; i < l; i++) {
        int rem = target - nums[i];
        int index = binarySearch(nums, l, rem);
        if (index != -1 && index != i) { 
            return {i + 1, index + 1};
        }
    }
    return {};
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    vector<int> ans = Twosum(arr, 9);
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
