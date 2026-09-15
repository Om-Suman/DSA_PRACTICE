#include <iostream>
#include <string>
int getDigit(const int number);
int getEvenSum(std::string creditCardNumber);
int getOddSum(std::string creditCardNumber);

int main() {
    std::string creditCardNum;
    int result = 0;

    std::cout<<"Enter your credit card number: ";
    std::cin>>creditCardNum;

    result = getEvenSum(creditCardNum) + getOddSum(creditCardNum);

    if (result % 10 == 0) {
        std::cout<<creditCardNum<<" is valid";
    }
    else {
        std::cout<<creditCardNum<<" is not valid";
    }



    return 0;
}

int getDigit(const int number) {
    return number % 10 + number/10 % 10 ;
}
int getEvenSum(std::string creditCardNumber){
    int sum=0;
    for (int i=creditCardNumber.size()-2;i>=0;i-=2) {
        sum+=getDigit((creditCardNumber[i]-48)*2);
    }
    return sum;
}
int getOddSum(std::string creditCardNumber) {
    int sum=0;
    for (int i=creditCardNumber.size()-1;i>=0;i-=2) {
        sum+=getDigit(creditCardNumber[i]-48);
    }
    return sum;
}