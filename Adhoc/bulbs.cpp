#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x,y;
    cin>>n>>x>>y;
    string bulb;
    cin>>bulb;

    int group =1;
    for( int i=0 ; i<n ;i++ ){
        if(bulb[i]=='1' && i+1<n && bulb[i+1]=='0'){
            group++;
        }
    }
    if(group>1){
        cout<<(group-1)*min(x,y)+y;
    }
    else{
        cout<<0<<endl;
    }
}

