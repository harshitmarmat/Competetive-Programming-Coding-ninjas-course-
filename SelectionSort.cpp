#include<iostream>
#include<climits>
using namespace std;

int find_small_index(int * arr, int size){
    int min = INT_MAX;
    int count = 0;
    for( int i=0 ; i< size ; i++){
        if( arr[i]< min){
            min = arr[i];
            count = i;
        }
    }
    return count;
}

int * swap(int arr[], int a , int b){
    int count = arr[a];
    arr[a]=arr[b];
    arr[b]= count ;
    return arr;
}

void solve(int*arr ,int size){
    for(int i=0;i<size;i++){
        int index_small = find_small_index(arr+i,size-i);
        arr = swap(arr,i,index_small+i);
    }
    for( int i =0 ; i< size; i++){
        cout<< arr[i]<<" ";
    }
}

int main(){
    int size;
    cin>>size;
    int arr[100];
    for( int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    solve(arr,size);
}