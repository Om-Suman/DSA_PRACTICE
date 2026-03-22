#include <iostream>


int main() {
    srand(time(NULL));
    int name1 = rand() % 6 + 1 ;
    int name2 = rand() % 6 + 1 ;
    int name3 = rand() % 6 + 1 ;
    std::cout<<name1<<'\n' ;
    std::cout<<name2<<'\n' ;
    std::cout<<name3<<'\n' ;
    return 0;
}