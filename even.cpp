#include <iostream>

int main() {
    int name;
    std::cout<<"Enter a nameber: ";
    std::cin>>name;
    name%2? std::cout<<"Even nameber: " : std::cout<<"Odd nameber" ;
    return 0;
}
