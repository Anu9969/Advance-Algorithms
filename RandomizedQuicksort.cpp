#include <iostream>
#include <cstdlib>  // For rand() function
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
}


int partition(int arr[] ,int l, int r){
    int randomPivotINdex = l+ rand() % (r - l + 1);
    // swap(arr,randomPivotINdex,r);
    // int pivot = arr[r];
    int pivot = arr[randomPivotINdex];
    int i = l-1;

    for(int j=l; j<r; j++ ){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);         
        }

    }
    swap(arr,i+1,r);
    return i+1;

}



void quicksort(int arr[], int l,int r){
    if(l<r){
        int pivot = partition(arr,l,r); 

        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }

}







int main(){

    int arr[6] = {3,6,2,1,5,4};
    quicksort(arr,0,5);
    for(int i =0 ;i <6;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;
}