#include <iostream>
void dispalyResult(const char grade,const double cgpa);
int main() {
    char grade = 'A';
    double cgpa = 9.26;
    dispalyResult(grade,cgpa);
    return 0;
}
void dispalyResult(const char grade,const double cgpa) {
   std::cout<<"You have recieved an "<<grade<<" grade"<<'\n';
   std::cout<<"Your cgpa: "<<cgpa<<'\n';
}