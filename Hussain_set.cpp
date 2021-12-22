#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin>>n>>m;
    ll arr[n];
    for( int i=0;i<n ;i++){
        cin>>arr[i];
    }
    int end = n-1;
    sort(arr,arr+n);
    queue<ll> q;
    int count =0;
    
    while(m--){
        int curr_count;
        cin>>curr_count;
        ll ans;
        for(;count<curr_count ;count++){
            if(end>=0 && (q.empty() || arr[n]>= q.front() )){
                ans = arr[end];
                end--;
            }
            else{
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }

}