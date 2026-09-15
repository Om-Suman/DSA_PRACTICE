#include <iostream>
using namespace std;
int factorial(int n) {
    if (n==0)  return 1;
    return n * factorial(n-1);
}
int power(int x,int y) {
    if (y==0) return 1 ; 
    return x * power(x,y-1) ; 
}

int main() {
    int n; 
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;
    int ans1 = power(2,3) ; 
    cout<<ans1<<endl;
    return 0;
}