#include<bits/stdc++.h>
using namespace std;

int kadane(int * arr, int n ){
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

int maxSumRect( int ** arr, int row ,int col){
    int * kad_arr = new int [col]{0};
    int best = INT_MIN;
    for( int i=0 ; i<row;i++){
        for(int j=0 ; j<col ;j++){
            kad_arr[j]+=arr[i][j];
        }
        int kad_sum = kadane(kad_arr,col);
        if( best<kad_sum){
            best = kad_sum;
        }
    }
    return best ;
}

int main(){
    int t;
    while(t--){
        int row;
        int col;
        cin>>row;
        cin>>col;
        int ** arr = new int*[row];
        for( int i=0 ;i<row ;i++){
            arr[i] = new int [col];
        }
        for (int i=0 ; i<row ; i++){
            for (int j=0 ;j<col;j++){
                cin>>arr[i][j];
            }
        }
        // cout<<"knfasok"<<endl;
        cout<<maxSumRect(arr,row,col)<<endl;
    }   
}