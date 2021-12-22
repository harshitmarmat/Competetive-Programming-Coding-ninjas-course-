#include<bits/stdc++.h>
using namespace std;

void buildTree( int * input , int * segmentedTree , int start  , int end , int treeIndex){
    
    if(start == end){
        segmentedTree[treeIndex] = input [start];
        return ;
    }
    int mid = ( start+end)/2;

    buildTree(input , segmentedTree , start , mid, 2* treeIndex);
    buildTree( input , segmentedTree , mid+1 , end , 2* treeIndex+1);

    segmentedTree[treeIndex] = min(segmentedTree[2* treeIndex], segmentedTree[ 2*treeIndex+1]);
    return ;

}

void updateTree( int * segmentedTree, int * lazyTree , int start , int end , int left, int right , int treeIndex , int value){
    if( start>left){
        return ;
    }

    if( lazyTree[treeIndex]!=0){
        segmentedTree[treeIndex] +=lazyTree[treeIndex];
        if(start != end){
            lazyTree[2*treeIndex] +=lazyTree[treeIndex];
            lazyTree[2*treeIndex+1] +=lazyTree[treeIndex];
        }
        lazyTree[treeIndex] =0;
    }
    if(end<left || start>right){
        return ;
    }

    if( left<=start && right>=end){
        segmentedTree[treeIndex]+=value;
        if(start != end){
            lazyTree[2*treeIndex] +=value;
            lazyTree[2*treeIndex+1] +=value;
        }
        return;
    }
    int mid = (start+end)/2;
    updateTree(segmentedTree , lazyTree , start , mid , left ,right , 2* treeIndex , value);
    updateTree(segmentedTree , lazyTree , mid+1 , end , left ,right , 2* treeIndex+1 , value);
    segmentedTree[treeIndex] = min(segmentedTree[2* treeIndex],segmentedTree[2*treeIndex+1]);
    return;
}

int main(){

    int n;
    cin>>n ; 
    int * input = new int[n];
    for(int i=0 ; i<n ; i++){
        cin>>input[i];
    }
    int * segmentedTree = new int [4*n]();
    int * lazyTree = new int [4*n]();
    buildTree(input , segmentedTree, 0 , n-1 , 1);
    int t;
    cin>>t;
    while(t--){
        int a,b,value;
        cin>>a>>b>>value;
        updateTree(segmentedTree , lazyTree , 0 , n-1 , a, b , 1 , value);
        for(int i =1 ; i<4*n ;i++){
            cout<<segmentedTree[i]<<endl;
        }
        cout<<"Lazy Tree:"<<endl;
        for(int i =1 ; i<4*n ;i++){
            cout<<lazyTree[i]<<endl;
        }

    }
    return 0;
}