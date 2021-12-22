#include<iostream>
using namespace std;

int solve( int * arr , int n){
    int current_max = 0;
    int best_max = 0;
    for( int i=0; i<n ;i++){
        if(current_max<0){
            current_max = 0;
        }
        current_max += arr[i];
        if( best_max<current_max){
            best_max = current_max;
        }
    }
    return best_max;
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for( int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);
}