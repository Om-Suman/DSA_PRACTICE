#include <iostream>
#include <deque>
using namespace std;
    
int main() {
    //pop_back(),pop_front(),push_back(),push_front(),front(),back(),size(),at()
    deque<int>d;
    d.push_back(2);
    d.push_front(3);
    for (int i : d) cout<<i<<" ";
    cout<<endl;
    cout<<"Element at back: "<<d.back()<<endl<<"Element at front: "<<d.front()<<endl;
    d.erase(d.begin());
    for (int i : d) cout<<i<<" ";
    return 0;
}