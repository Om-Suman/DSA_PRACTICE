#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4, 5};

    // Create an iterator pointing to the beginning of the list
    auto it = l.begin();

    // Advance the iterator by 2 positions
    advance(it, 2);

    // Erase elements from the beginning to the advanced iterator
    l.erase(l.begin(), it);

    // Print the remaining elements in the list
    for (int num : l) 
        cout << num << " ";

    return 0;
}
