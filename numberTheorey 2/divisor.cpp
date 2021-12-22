#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<int> primeToN(int n){
    bool * arr = new bool [n+1];
    vector<int > v;
    for(int i=0 ; i<=n ; i++ ){
        arr[i] = true;
    }

    arr[0]= false;
    arr[1]= false;

    for(int i=2 ; i<= n ;i++){
        if(arr[i]){
            v.push_back(i);
            for(int j=i*i ; j<=n ;j+=i){
                arr[j] = false;
            }
        }
    }    
    delete [] arr;
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> prime = primeToN(n) ;
        ll result = 1 ;
        for(int i=0 ;i<prime.size() ; i++){
            int current  = prime[i];
            int count=0;
            while((n/current)!=0){
                count = (count +(n/current))%MOD;
                current*=prime[i];
            }
            result = (result * (count +1))%MOD;
        }
        cout<<result<<endl;
    }
}