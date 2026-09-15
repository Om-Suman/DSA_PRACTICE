#include <iostream>

int getProduct(int num[],int len);

int main() {
    std::string name[] = {"ram","naman","raju","rohan","rahul"};

     for (int i=0; i<size(name);i++) {
          std::cout<<name[i]<<'\n';
     }
    
    int num[] = {1,4,9,16} ; 
    int len = std::size(num) ;
    for (int num1 : num) {
        std::cout<<num1<<'\n';
    }
    int product = getProduct(num,len) ; 

    std::cout<<product ; 

    return 0;
}

int getProduct(int num[],int len) {
    int product = 1;
     for (int i=0;i<len;i++){
            product *=num[i] ;
     }
     return  product ;
}