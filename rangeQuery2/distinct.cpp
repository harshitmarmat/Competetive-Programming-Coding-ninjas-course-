#include<bits/stdc++.h>
using namespace std;
class event{
    public:
        int first , second, index;
};

bool compare( event e1 , event e2){
    return e1.second <e2.second;
}

void update( int index , int value , int n ,int *BIT){
    for( ; index<= n ; index += (index&(-index))){
        BIT[index]+=value;
    }
}

int queryvalue( int index , int* BIT){
    int count = 0 ;
    for(;index>0;index-=(index&(-index))){
        count+= BIT[index];
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int * input = new int[n+1];
    for(int i=1 ; i<=n ; i++){
        cin>>input[i];
    }
    int q;
    cin>>q;
    event * query = new event[q];
    for(int i=0 ; i<q ; i++){
        cin>>query[i].first>>query[i].second;
        query[i].index = i;
    }
    sort( query , query+q , compare);
    int * BIT = new int[n+1]();
    int * ans = new int [q];
    int totalIndex =0 ;
    int k=0 ;

    int * last = new int [1000001];
    for(int i=0 ; i<= 1000000;i++){
        last[i] = -1;
    }

    for(int i=1 ; i<=n ; i++){
        if(last[input[i]]!= -1){
            update(last[input[i]] , -1 ,n , BIT);
        }
        else{
            totalIndex++;
        }
        update(i , 1 , n , BIT);
        last[input[i]]=i;
        while(k<q && query[k].second == i){
            ans[query[k].index] = totalIndex -queryvalue(query[k].first-1,BIT);
            k++;
        }
    }
    for(int i=0 ; i<q ; i++){
        cout<<ans[i]<<endl;
    }
    
}