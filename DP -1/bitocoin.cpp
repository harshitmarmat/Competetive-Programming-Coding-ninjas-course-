#include<bits/stdc++.h>
using namespace std;

int * lds (int * input, int n){
    int * output = new int [n];
    output[n-1]=1;
    for( int i=n-2 ;i>=0;i--){
        output[i]=1;
        for( int j =i+1;j<n ;j++){
            if(input[j]>=input[i]){
                continue;
            }
            int possibleAns = output[j]+1;
            if( output[i]<possibleAns){
                output[i] = possibleAns;
            }
        }
    }
    return output;
}

int* lis(int *input ,int n){
    int * output = new int [n];
    output[0] = 1;
    for( int i=1 ;i<n ;i++){
        output[i]=1;
        for (int j=i-1; j>=0 ;j--){
            if( input[i]<=input[j]){
                continue;
            }
            int possibleAns = output[j]+1;
            if(possibleAns>output[i]){
                output[i]= possibleAns;
            }
        }
    }
    return output;
}

int bitonic(int* input , int n){
    int * lisArr = lis(input,n);
    int * ldsArr = lds(input,n);
    int * output = new int [n];
    int best = INT_MIN;
    // for( int i=0 ; i<n ;i++){
    //     cout<<lisArr[i]<<" ";
    // }
    // cout<<endl;
    // for( int i=0 ;i<n;i++){
    //     cout<<ldsArr[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0 ; i<n ; i++){
        output[i]=(lisArr[i]+ldsArr[i])-1;
        // cout<<output[i]<<" ";
        if(output[i]>=best){
            best =output[i];
        }
    }
    // cout<<endl;
    delete [] lisArr;
    delete [] ldsArr;
    delete [] output;
    return best;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        int * input = new int[n];
        for( int i=0 ; i<n ;i++){
            cin>>input[i];
        }
        cout<<bitonic( input,n)<<endl;    
    }
}