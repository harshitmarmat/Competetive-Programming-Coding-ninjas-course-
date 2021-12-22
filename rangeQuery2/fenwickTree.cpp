#include<bits/stdc++.h>
using namespace std;

void update( int * BIT , int index , int n  ,int value){
    for(; index <=n ; index+= index &(-index)){
        BIT[index]+=value;
    }
}

int query(int * BIT , int index){
    int sum =0;
    for(;index>0 ; index -= index & (-index)){
        sum+=BIT[index];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int * input = new int [n+1]();
    int * BIT = new int [n+1]();

    for(int i=1 ; i<=n; i++){
        cin>>input[i];
        update(BIT , i , n+1 , input[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int a, b ;
        cin>>a>>b;
        int ans1 = query(BIT , a );
        int ans2 = query(BIT , b);
        cout<<ans2-ans1<<endl;
    }

    delete[] input;
    delete [] BIT;

}