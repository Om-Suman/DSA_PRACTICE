#include <iostream>
int main() {
    std::string name;
    double cgpa;
    
    std::cout<<"What is your full name: ";
    std::getline(std::cin>>std::ws,name);
    

    std::cout<<"what was your cgpa: ";
    std::cin>>cgpa;

    std::cout<<"Hello "<<name<<", You got "<<cgpa<<" cgpa in your exam";
    return 0;
}