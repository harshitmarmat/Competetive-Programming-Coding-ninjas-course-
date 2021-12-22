#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr = new int[n];
        for(int i=0 ;i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int count = INT_MAX;
        for(int i=0 ;i<n-1 ; i++){
            int current = arr[i+1]-arr[i];
            if(current<count ){
                count = current;
            }
        }
        cout<<count<<endl;
        delete [] arr;
    }
}