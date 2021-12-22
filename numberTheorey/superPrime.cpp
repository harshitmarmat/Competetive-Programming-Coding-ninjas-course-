#include<bits/stdc++.h>
using namespace std;

vector<int> primeToN(int n){
    bool * arr = new bool [n+1];
    for(int i=0 ; i<=n; i++){
        arr[i]= true;
    }
    arr[0]=false;
    arr[1]= false;
    vector<int> v;
    for(int i=2; i<=n/2 ;i++){
        if(arr[i]){
            v.push_back(i);
            for(int j=2*i; j<=n/2; j+=i){
                arr[j]=false;
            }
        }
    }
    delete [] arr;
    return v;
}

int main(){

    int n;
    cin>>n;
    vector <int> prime = primeToN(n);
    // for(int i=0 ;i<prime.size();i++){
    //     cout<<prime[i]<<" "; 
    // }
    int count=0;
    for(int i=0;i<prime.size();i++){
        for(int j=i+1;j<prime.size();j++){
            if(prime[i]*prime[j]>n){
                break;
            }
            cout<<prime[i]*prime[j]<<" ";
            count++;
        }
    }
    cout<<count<<endl;
}