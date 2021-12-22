#include<bits/stdc++.h>
using namespace std;

void updateTree( int * segmentedTree , int * lazyTree , int start , int end, int treeIndex, int left , int right , int value){
    if(start>end){
        return;
    }
    if(lazyTree[treeIndex]!=0){
        segmentedTree[treeIndex]+= lazyTree[treeIndex]*((end-start)+1);
        if(start!=end){
            lazyTree[2*treeIndex]+=lazyTree[treeIndex];
            lazyTree[2*treeIndex+1]+=lazyTree[treeIndex];
        }
        lazyTree[treeIndex]=0;
    }
    if(end<left ||start>right){
        return ;
    }
    if(left<=start && right>=end){
        segmentedTree[treeIndex]+=value*((end-start)+1);
        if(start!= end){
            lazyTree[2*treeIndex]+=segmentedTree[treeIndex];
            lazyTree[2*treeIndex+1]+=segmentedTree[treeIndex];
        }
        return;
    }
    int mid = (start+end)/2;
    updateTree(segmentedTree , lazyTree , start , mid , 2*treeIndex , left , right ,value);
    updateTree(segmentedTree , lazyTree , start , mid , 2*treeIndex , left , right ,value);
    segmentedTree[treeIndex] += segmentedTree[2* treeIndex ]+ segmentedTree[2*treeIndex+1];
    return;
}

int query( int * segmentedTree,int *lazyTree, int start ,int end , int treeIndex , int left , int right ){
    if(start>end){
        return 0;
    }
    
    if(lazyTree[treeIndex]!=0){
        segmentedTree[treeIndex]+= lazyTree[treeIndex]*((end-start)+1);
        if(start!=end){
            lazyTree[2*treeIndex]+=lazyTree[treeIndex];
            lazyTree[2*treeIndex+1]+=lazyTree[treeIndex];
        }
        lazyTree[treeIndex]=0;
    }
    if(end<left || right<start){
        return 0;
    }
    if(left<=start && right>=end){
        return segmentedTree[treeIndex];
    }
    int mid = (start+end)/2;
    int ans1 = query(segmentedTree,lazyTree , start,mid, 2* treeIndex, left , right );
    int ans2 = query(segmentedTree,lazyTree ,mid+1 ,end , 2*treeIndex+1, left , right );
    return ans1+ans2;
}

int main(){
    int n;
    cin>>n;
    
    int * input = new int [n]();
    int * segmentedTree = new int[4*n]();
    int * lazyTree = new int[4*n]();
    int q;
    cin>>q;
    while(q--){
        int check ;
        cin>>check;
        if(check==0){
            int left,right , value ; 
            cin>>left >>right>>value;
            updateTree(segmentedTree , lazyTree , 0 ,n-1 , 1 , left-1 , right -1 ,value);
        }
        if(check==1){
            int left ,right;
            cin>>left>>right;
            cout<<query(segmentedTree ,lazyTree, 0 , n-1 , 1 ,left -1 ,right-1)<<endl;
        }
    }
	delete [] input;
    delete [] segmentedTree;
    delete [] lazyTree;
}   