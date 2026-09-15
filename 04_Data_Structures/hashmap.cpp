#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string a = "aabcade";
    vector<int>rec;
    for (int i=0;i<a.size();i++) {
        int x=count(a.begin(),a.end(),a[i]);
        rec.push_back(x);
    }
    int ans = *max_element(rec.begin(),rec.end());
    cout<<ans<<endl;
    return 0;
}x