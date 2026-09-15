#include <iostream> 

int main() {
    int rows;
    int cols;
    std::cout<<"Enter no of rows: ";
    std::cin>>rows;
    std::cout<<"Enter no of cols: ";
    std::cin>>cols;
    int matrix[rows][cols];
  
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
           std::cin>>matrix[i][j];
        }
    }
    std::cout<<"\n";
    for (int i=0; i<rows;i++) {
        for (int j=0;j<cols;j++) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<'\n';
        
    }
    return 0;
}