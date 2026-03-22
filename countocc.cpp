#include <iostream>
#include <map>
#include <vector>
using namespace std;
    
int main() {
    vector<int> nums = {1,2,2,2,3,3,3,3};
    map<int,int> maps ; 
    for (int i=0;i<nums.size();i++) {
        maps[nums[i]]++;
    }
    for (const auto &map : maps) {
        cout<<map.first<<"->"<<map.second<<endl;
    }
    return 0;
}