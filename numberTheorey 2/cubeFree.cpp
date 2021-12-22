#include<bits/stdc++.h>
using namespace std;
#define range 1000000

int main(){
    int * arr = new int[range+1];
    for(int i=0 ;i<=range;i++){
        arr[i]=0;
    }
    for(int i=2; i<=100 ; i++){
        for(int j=i*i*i; j<=range ; j*=2){
            arr[j]=-1;
        }
    }
    int k=1;
    for(int i=1; i<=range ;i++){
        if(arr[i]==-1){
            continue;
        }
        arr[i]= k;
        k++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(arr[n]==-1){
            cout<<"Not Cube Free"<<endl;
        }
        else{
            cout<<arr[n]<<endl;
        }
    }
}