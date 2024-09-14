#include <iostream>
using namespace std;

void erase(int A[], int n , int i){
    for(int j = i ; j <= n-1 ; j++){
        A[j] = A[j+1];
    }
    n--;
}

void printArray(int A[] , int n){
    for (int i = 0; i <n ; i++){
        cout<< A[i]<<" ";
    }
}

int main() {
    int n= 12;
    int A[12] = {1,2,3,4,5,6,7,8,9,10};

    erase(A,10,5);
    printArray(A,n);
    return 0;
}