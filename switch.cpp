#include <iostream>
#include <string>

int main() {
    int stream;
    std::cout<<"Enter your stream(science-1,commerce-2, arts-3): ";
    std::cin>>stream;

    switch(stream) {
        case 1 :
          std::cout<<"You have chosen science";
          break;

        case 2 : 
           std::cout<<"You have chosen commerce";
           break;

        case 3 : 
           std::cout<<"You have chosen arts";
           break;

        default :
           std::cout<<"Choose a valid nameber: ";
           break;
    }

    return 0;
}