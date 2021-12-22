#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll kadane( int * arr ,int n){
    ll current_max = 0;
    ll best_max = 0;

    for(int i=0 ; i<n ; i++){
        current_max += arr[i];
        best_max = max( current_max , best_max);
        if( current_max<0){
            current_max = 0;
        }
    }
    return best_max;
}

ll maxSumArray( int * arr , int n , int k){
    ll kadane_sum = kadane(arr,n);

    if( k==1){
        return kadane_sum;
    }
    ll current_suffix_sum = 0, current_prefix_sum = 0;
    ll max_suffix_sum = INT_MIN , max_prefix_sum = INT_MIN;

    for( int i=0 ; i< n ; i++){
        current_prefix_sum += arr[i];
        max_prefix_sum = max(current_prefix_sum, max_prefix_sum);
    }

    ll total_sum = current_prefix_sum;

    for(int i=n-1 ; i>=0 ; i--){
        current_suffix_sum += arr[i];
        max_suffix_sum = max(current_suffix_sum,max_suffix_sum);
    }
    ll ans;
    if(total_sum<0){
        ans = max( max_suffix_sum + max_prefix_sum , kadane_sum);
    }
    else{
        ans = max( max_suffix_sum + max_prefix_sum + ( total_sum * ( k-2 )) , kadane_sum);
    }

    return ans;
}



int main (){
     int t;
     cin>>t;
     while(t--){
         int n,k;
         cin>>n>>k;
         int * arr = new int[n];
         for(int i=0; i<n; i++){
             cin>>arr[i];
         }
         cout<<maxSumArray(arr,n,k)<<endl;
         delete [] arr;
     }
}