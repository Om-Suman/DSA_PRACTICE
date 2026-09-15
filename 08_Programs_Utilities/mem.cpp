#include <iostream>

int main() {
    std::string fruit = "Banana";
    int age = 69;
    bool voter=true;
    std::string fruitA[] = {"banana","apple","mango","orange"};

    std::cout<<&fruit<<'\n';
    std::cout<<&age<<'\n';
    std::cout<<&voter<<'\n';
    std::cout<<&fruitA<<'\n';



    return 0;
}