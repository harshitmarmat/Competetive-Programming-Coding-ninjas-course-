#include<bits/stdc++.h>
using namespace std;
#define range 1000000000

int main(){
    int * seive = new int [range+1];
    for(int i=0 ; i<=range ; i++){
        seive[i]=i;
    }

    for( int i=2 ; i<=range ; i++){
        if(seive[i]==i){
            seive[i]--;
            for(int j=2*i ; j<=range ; j+=i ){
                seive[j] = (seive[j]*(i-1))/i;
            }
        }
    }

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<seive[n]<<endl;
    }

    delete [] seive;
}