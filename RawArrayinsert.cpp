#include <iostream>
using namespace std;

void insert(int A[], int n , int i , int e){
      for(int j = n-1 ; j>= i ;j--){
        A[j+1] = A[j];
    }
    A[i] = e;
    n++;
}

void printArray(int A[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<A[i]<<" ";
    }
}


int main(){
    int n = 15;
    int A[12] = {1,2,3,4,5,6,7,8,9,10};

    insert(A,10,5,124);
    printArray(A , n);

  
}