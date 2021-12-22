#include<bits/stdc++.h>
using namespace std;
#define range 1000000000

vector<pair<int ,int > start(int k , bool * prime ){
    vector<pair<int ,int > primeFactorK;  
    if(k==prime[k]){
        pair p;
        p.first = k;
        p.second = 1;
        primeFactorK.push_back(p);
    }
    else{
        for(int i=0; i*i<=k ; i++){
            int divisor = prime[i];
            int x= k;
            int count=0;
            while(x%divisor==0){
                count++;
                x\=divisor;
            }
            pair p ;
            p.first = divisor;
            p.second = count;
            primeFactorK.push_back(p);
        }
    }
    return primeFactorK;
}

int main(){

    //sieve for prime num upto 1000000000
    bool * prime = new bool[range+1];
    for( int i=0 ; i<=range ; i++){
        prime[i]=true;
    }
    prime[0]= false;
    prime[1]= false;
    for( int i=2 ; i*i <= range ; i++){
        for (int j= i*i ; j<= range ;j+=i){
            prime[j] = false;
        }
    }

    int n;
    cin>>n;
    int k ; 
    cin>>k;

    int * input = new int [n];

    for (int i=0 ; i<n ; i++){
        cin>>input[i];
    }
    vector<pair<int,int>> primeFactorK = start(k,prime);       //this will return the pair vector of k
    
    for(int i=0 ; i<n ;i++){
        vector<pair<int,int>> dpf ;
        for(int i=0 ;i< primeFactorK.size() ; i++ ){
            pair p;
            p.first = primeFactorK[i].first;
            p.second = 0;
            dpf.push_back(p);
        }
        for(int j= i+1 ; j<n ; j++){
            int current = input[j];
            for ( int i=0 ; i<dpf.size() ;i++){
                int divisor = dpf[i].first;
                while(current % divisor != 0){
                    
                }
            }
        }
    }


}