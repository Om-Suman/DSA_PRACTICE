#include <iostream>
using namespace std;

int helper(int arr[], int n, int x) {

    int left = 0;
    int right = 0;

    int sum = 0;
    int count = 0;

    while (right < n) {

        sum += arr[right];

        while (sum > x) {
            sum -= arr[left];
            left++;
        }

        if (sum == x) {
            count++;
        }

        right++;
    }

    return count;
}

int main() {

    int n;
    cin >> n;

    int sum;
    cin >> sum;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = helper(arr, n, sum);

    cout << ans << endl;
}