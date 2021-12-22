#include<bits/stdc++.h>
using namespace std;

class event{
    public:
        char first;
        int second;
};

void update( int index, int q , int value,int *BIT){
    for(;index<q; index+=(index&(-index))){
        BIT[index]+=value;
    }
}

int query( int index , int * BIT){
    int count =0 ;
    for( ; index>0 ; index-=(index&(-index))){
        count+=BIT[index];
    }
    return count;
}

int main(){
    int q ;
    cin>>q;
    
    event * input = new event[q];
    int * arr = new int[q];
    unordered_map<int,int> CC;
    int j=0;
    for(int i=0 ; i<q ;i++){
        cin>>input[i].first>>input[i].second;
        if(input[i].first =='I'){
            if(CC.find(input[i].second)== CC.end()){
                arr[j] = input[i].second;
                j++;
            }
        }
    }
    sort(arr,arr+j);
    // for(int i=0 ; i<j ;i++){
    //     cout<<arr[i]<<" ";
    // }
    unordered_map<int,int> map;
    for( int i=1 ;i<=j;i++){
        map[arr[i-1]] = i;
    }

    int * BIT = new int[q]();

    // unordered_map<int,int> :: iterator it = map.begin();
    // while(it != map.end()){
    //     cout<<it->first<<endl;
    //     it++;
    // }
    for( int i=0 ;i<q ;i++){
        int current = input[i].second;
        if(input[i].first=='I'){
            if(query(map[current],BIT)==query(map[current]-1,BIT)){
                update(map[current],q,1,BIT);
            }
        }
        else if(input[i].first=='D'){
            if(query(map[current],BIT)!=query(map[current]-1,BIT)){
                update(map[current],q,0,BIT);
            }
        }
        else if(input[i].first=='K'){
            if(current -1> j){
                cout<<"invalid"<<endl;
            }
            else{
                cout<<arr[current-1]<<endl;
            }
        }
        else if ( input[i].first =='C'){
            int check = (lower_bound(arr,arr+q,input[i].second)-arr)-1;
            if(check>=0){
                cout<<query(map[arr[check]],BIT)<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }

}