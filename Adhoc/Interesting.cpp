#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class dual{
    public:
        ll incr;
        ll decr;
};

dual solve( ll * arr ,int n, ll x){
    ll increment = 0;
    ll decrement = 0;
    for( int i=0 ;i<n ;i++){
        if(arr[i]<x){
            increment=increment+(x-arr[i]);
        }
        else{
            decrement = decrement+(arr[i]-x);
        }
    }
    dual ans;
    ans.incr = increment;
    ans.decr = decrement;
    return  ans;
}

int main(){
    int n;
    ll x, y;
    cin>>n>>x>>y;
    ll arr[n];
    ll count = 0;
    for( int i=0 ; i<n;i++){
        cin>>arr[i];
        count+=arr[i];
    }

    sort(arr,arr+n);
    ll start = arr[0];
    ll end = arr[n-1];
    ll ans = INT_MAX;
    while( start<=end){
        ll mid = (start+end)/2;
        dual p = solve(arr,n,mid);
        if(p.incr>=p.decr){
            ll cost= (p.decr*x)+((p.incr-p.decr))*y;
            if( ans>cost){
                ans= cost;
            }
            end = mid-1;
        }
        else{
            start =mid+1;
        }
    }
    cout<<ans;
}