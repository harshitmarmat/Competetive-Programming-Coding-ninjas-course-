#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n ;
        int * arr = new int[ n];
        for(int i=0 ; i<n ;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n,greater<int>());
        int ans =0 ;
    
        for(int i=0 ;i<n ;i++){
            int current = arr[i]*(1<<i);
            ans+=current;
        }
        cout<<ans<<endl;
        delete [] arr;        
    }
}