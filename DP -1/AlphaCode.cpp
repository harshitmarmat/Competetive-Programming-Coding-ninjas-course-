#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll alpha1( string n){

    int m = pow(10,9)+7;
    if( n.size()==0 || n.size()==1){
        return 1;
    }

    ll output = (alpha1(n.substr(1)))%m;
    ll num = (n[0]-48)*10 +(n[1]-48);
    if(num<=26){
        (output+=alpha1(n.substr(2)))%m;
    }

    return output%m;

}

ll alpha2( string n,ll * arr){

    int m = pow(10,9)+7;
    if( n.size()==0 || n.size()==1){
        return 1;
    }
    if(arr[n.size()]>0){
        return (arr[n.size()])%m;
    }
    ll output = (alpha2(n.substr(1),arr))%m;
    ll num = (((n[0]-48)*10) +((n[1]-48)));
    if(num<=26){
        (output+=alpha2(n.substr(2),arr)%m)%m;
    }
    arr[n.size()]= output%m;
    return output%m;

}

ll alpha3(string n){
    ll * output = new ll[n.size()+1]{0};
    output[0]=1;
    output[1]=1;
    for( int i=2 ; i<=n.size();i++){
        output[i] = output[i-1];
        ll num = (((n[0]-48)*10) +((n[1]-48)));
        if(num<=26){
            output[i]+=output[i-2];
        }
    }
    return output[n.size()];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string n; 
        cin>>n;
        ll arr[n.size()]={0};
        cout<<alpha1(n)<<endl; 
        cout<<alpha2(n,arr)<<endl;
        cout<<alpha3(n)<<endl;
    }
}