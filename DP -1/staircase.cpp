#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

 int main (){
     int m = pow(10,9)+7;
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n;
        ll * output= new ll[n+1];
        output[0]=0;
        output[1]=1;
        output[2]=2;
        output[3]=4;
        for(int i=4; i<=n;i++){
            output[i] = ((output[i-3]%m)+(output[i-2]%m)+(output[i-1])%m)%m;
        }
        cout<<output[n]<<endl;
        delete [] output;
     }
 }