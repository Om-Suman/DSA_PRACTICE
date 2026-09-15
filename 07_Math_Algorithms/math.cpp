#include <iostream>
#include <cmath>
int main(){
    double l;
    double h;
    double hp;
    
    std::cout<<"What is the length of the right angled triangle: ";
    std::cin>>l;

    std::cout<<"What is the height of the right angled triangle: ";
    std::cin>>h;

    hp = sqrt(pow(l,2)+pow(h,2)) ;

    std::cout<<"Hypotenuse of that triangle is  "<< hp;



    return 0;
}