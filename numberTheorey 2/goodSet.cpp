#include<bits/stdc++.h>
using namespace std;
#define range 100000
#define MOD 100000007
typedef long long ll;


int main(){
    int * arr = new int [range+1];
    for (int i=0; i<= range ; i++){
        arr[i] = 0;
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int * input = new int [n];
        for (int i=0 ; i< n ; i++){
            cin>>input[i];
            arr[input[i]]++;
        }
        sort(arr, arr+n);
        for(int i=0 ; i<n; i++){
            for(int j=input[i]*2;j<=input[n-1];j+=input[i]){
                if(arr[j]>0){
                    arr[j]= (arr[j]+arr[input[i]])%MOD;
                }
            }
        }
        ll count = 0;
        for( int i=0 ; i<n ; i++){
            count = (count + arr[input[i]])%MOD;
        }
        cout<<count<<endl;
    }

    delete [] arr;
}