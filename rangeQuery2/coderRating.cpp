#include<bits/stdc++.h>
using namespace std;

class coder{
    public:
        int x;
        int y;
        int index ; 
};

bool compare(coder c1 , coder c2){
    if(c1.x == c2.x){
        return c1.y <c2.y;
    }
    return c1.x < c2.x;
}

void update (int y , int * BIT){
    for(; y<=100000 ; y+=y&(-y)){
        BIT[y]++;
    }
}

int query (int y , int * BIT){
    int count  =0;
    for(; y>0 ; y-=y&(-y)){
        count+=BIT[y];
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    coder * input = new coder[n];
    for(int i=0 ;i<n ;i++){
        cin>>input[i].x>>input[i].y;
        input[i].index = i;
    }

    sort(input , input+n , compare);
    int * BIT = new int [100000]();
    int * ans = new int[n];

    for( int i=0 ;i<n ;){
        int end = i;
        while(end<n && input[i].x==input[end].x && input[i].y==input[end].y){
            end++;
        }
        for( int j=i ; j<end ;j++){
            ans[input[j].index]= query(input[j].y,BIT);
        }
        for( int j=i ; j<end ;j++){
            update(input[j].y , BIT);
        }
        i = end;
    }
    for (int i=0 ; i<n ;i++){
        cout<<ans[i]<<endl;
    }
}