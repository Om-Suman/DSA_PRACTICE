#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverseWords(vector<char>&s) {
   int start = 0 ; 
   int n = s.size();

   for (int end = 0 ;end<=n;end++) {
      if (end==n || s[end]==' ') {
        reverse(s.begin() + start ,s.begin()+end);
        start = end + 1 ; 
      }
   }
   reverse(s.begin(),s.end());
}
int main() {
    vector<char>arr = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    reverseWords(arr);
    for (char i : arr) {
        cout<<i<<" ";
    }
    return 0;
}