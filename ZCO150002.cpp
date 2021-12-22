#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n; 
    cin>>n;
    ll arr[n];
    int k;
    cin>>k;
    for(int i=0 ;i< n ;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    ll count =0;
    for(int i=0 ,j = i+1; j<n ; j++){
        if( arr[j]-arr[i]>=k){
            count = count +(n-j);
            i++;
            j=i;
        }
    }
    cout<<count<<endl;
}