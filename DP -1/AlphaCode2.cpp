#include<bits/stdc++.h>
using namespace std;

int alphaCode(int * s1 , int n , int * arr){
    
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(arr[n]>0){
        return arr[n];
    }
    int output = alphaCode(s1 , n-1,arr);
    if((s1[n-2]*10)+ (s1[n-1])<=26){
        output+= alphaCode(s1,n-2,arr);
    }
    arr[n]= output;
    return arr[n];
}

int alphaCodeI(int * input , int n){
    int * output = new int[n+1];
    output[0]=1;
    output[1]=1;
    for(int i=2; i<=n;i++){
        output[i]=output[i-1];
        if(input[i-2]*10+input[i-1]<=26){
            output[i]+=output[i-2];
        } 
    }

    int ans= output[n];
    delete [] output;
    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s1;
        cin>>s1;
        int * input = new int[s1.size()];
        for(int i=0 ;i<s1.size();i++){
            input[i]= s1[i]-'0';
        }
        int * arr= new int [s1.size()+1]();
        cout<<alphaCode(input,s1.size(),arr)<<endl;
        cout<<alphaCodeI(input,s1.size())<<endl;
        delete  [] arr;

    }
}