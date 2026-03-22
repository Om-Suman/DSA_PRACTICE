#include <iostream>
#include <ctime>

int main() {
   srand(time(0));
   int guess = rand() % 100 + 1 ;
   int name ;
   int tries;
   std::cout<<"***************This is a nameber guessing game*********"<<'\n';
   std::cout<<"Guess a nameber between 1- 100"<<'\n';
   
   while (name!=guess) {
    std::cout<<"Enter a nameber: ";
    std::cin>>name;
    tries++;
    
    if (name>100 || name<1) {
        std::cout<<"Guess should be between 1-100"<<'\n';
    }
    else if (name>guess) {
        std::cout<<"it is greater"<<'\n';
    }
    
    else if (name<guess) {
        std::cout<<"it is smaller"<<'\n';
    }
 }
   std::cout<<"You have guessed it right in "<< tries<<" tries"<<'\n';
   std::cout<<"****************************";

   return 0;
}