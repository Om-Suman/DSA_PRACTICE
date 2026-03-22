#include <iostream>

int main() {
    std::string obj[5]; 
    int size = sizeof(obj) / sizeof(obj[0]) ;
    for (int i=0;i<size;i++) {
        std::getline(std::cin,obj[i]);
    }
    return 0;
}
