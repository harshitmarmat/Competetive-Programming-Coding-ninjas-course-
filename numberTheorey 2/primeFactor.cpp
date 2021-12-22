#include<bits/stdc++.h>
using namespace std;
#define  range 1000000

int main(){
    int * arr = new int[range+1];
    for(int i=0 ; i<= range ; i++){
        arr[i]=0;
    }

    for(int i=2 ; i<= range ; i++){
        if(arr[i]==0){
            int count =1;
            for(int j=i ; j<= range ;j=i*count){
                arr[j]++;
                count++;
            }
        }
    }

    int ** nf = new int * [11];
    for(int row=0 ; row<=10 ; row++){
        nf[row] = new int [range+1];
        for(int col = 0 ; col<= range; col++){
            if(row ==arr[col]){
                nf[row][col] = nf[row][col-1]+1;
            }
            else{
                nf[row][col] = nf[row][col-1];
            }
        }
    }

    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;

        int ans = nf[n][b] - nf[n][a-1];
        cout<<ans<<endl;

    }
    for(int i=0 ;i<=10 ; i++){
        delete [] nf[i];
    }
    delete [] nf;
    delete [] arr;
}