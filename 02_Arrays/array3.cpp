#include <iostream>

int  searchArray(int arr[],int element,int size) {
    for (int i=0;i<size;i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void sort(int arr[],int size) {
    int temp;
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                temp = arr[j] ;
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int rollno[] = {10,5,6,23,12,4,7,13};
    int size = std::size(rollno);
    int elem;
    int index;
    std::cout<<"Enter the elements you are searching for : ";
    std::cin>>elem;
    index = searchArray(rollno,elem,size);

    if (index!=-1){
        std::cout<<elem<<" is at index "<<index<<'\n';
    }
    else {
        std::cout<<"Element is not present\n";
    }
    
    sort(rollno,size);

    for (int element : rollno) {
        std::cout<<element<<" ";
    }
    
    return 0;
}