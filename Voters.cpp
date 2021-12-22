#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int sum = n1+ n2 +n3;
    ll arr[sum];
    map<ll,ll> m;
    for(int i=0 ;i< n1 ; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    for(int i=0 ;i< n2 ; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    for(int i=0 ;i< n3 ; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    map<ll ,ll> :: iterator it;
    vector<ll> v;
    for( it = m.begin(); it!=m.end();it++){
        if(it->second >=2){
            v.push_back(it->first);
        }
    }
    cout<<v.size()<<endl;
    for( int i=0 ; i<v.size();i++){
        cout<<v[i]<<endl;
    }
}