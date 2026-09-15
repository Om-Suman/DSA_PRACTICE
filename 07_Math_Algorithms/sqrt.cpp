#include <iostream>
using namespace std;

int binarySearch(int n) {
    int s = 0;
    int e = n;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        long long square = (long long)mid * mid; 
        
        if (square == n) {
            return mid;
        }
        if (square > n) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

int mySqrt(int x) {
    return binarySearch(x);
}

double morePresion(int num,int precision,int tempSol ) {
    double factor = 1 ; 
    double ans  = tempSol ; 

    for (int i=0;i<precision;i++) {
        factor/=10 ; 

        for (double j = ans ; j*j<num;j+=factor) {
            ans = j ; 
        }
    }
    return ans ; 
}

int main() {
    int n ; 
    cout << "Enter any number : "<<endl ; 
    cin >> n; 
    int tempsol = mySqrt(n);
    cout<<"Answer is " << morePresion(n,3,tempsol);
    return 0;
}
