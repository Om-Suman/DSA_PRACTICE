#include <iostream>

int main() {
    double temp;
    char unit;
    double result;
    std::cout<<"Enter (C/c) for celcius or (F/f) for farenheight"<<'\n';
    std::cout<<"Enter the unit of the temperature: ";
    std::cin>>unit;

    if (unit=='C' || unit=='c') {
        std::cout<<"Enter the temperature: ";
        std::cin>>temp;
        result = (temp*1.8) + 32 ;
        std::cout<<"Required temperature in Farenheight is "<<result<<" F";
        }
    else if (unit=='F' || unit=='f') {
        std::cout<<"Enter the temperature: ";
        std::cin>>temp;
        result = (temp-32)/1.8 ;
        std::cout<<"Required temperature in Farenheight is "<<result<<" C";
        }
    else {
        std::cout<<"You have entered wrong choice";
    }

    

    
    return 0;
}