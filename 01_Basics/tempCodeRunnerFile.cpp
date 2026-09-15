#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;  // Read the number of queries
    
    std::set<int> mySet;
    
    for (int i = 0; i < n; ++i) {
        int y, x;
        std::cin >> y >> x;  // Read the type and the integer for each query