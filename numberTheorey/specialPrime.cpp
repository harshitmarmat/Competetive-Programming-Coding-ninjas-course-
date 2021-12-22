#include<bits/stdc++.h>
using namespace std;



int main(){
    int n ; 
    cin>>n;
    vector<int> prime;
    bool primeCheck[n] ;
    for(int i=0 ;i<n ;i++){
        primeCheck[i] = true;
    }
    primeCheck[0]= false;
    primeCheck[1] = false;
    int count = 0;
    for( int i=2; i<n ; i++){
        if(primeCheck[i]){
            prime.push_back(i);
            for(int j= i*i ;j<n ;j+=i){
                primeCheck[j]= false;
            }
        }
    }

    // cout<<count<<endl;
    // for(int i =0 ; i<prime.size();i++){
    //     cout<<prime[i]<<" ";
    // }
    for(int i=0; i<prime.size()-1;i++){
        int check = prime[i]+ prime[i+1]+1;
        if(check>n ){
            break;
        }
        if(primeCheck[check]){
            count++;
        }
    }
    cout<<count<<endl;
}