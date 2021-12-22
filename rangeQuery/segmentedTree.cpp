#include<bits/stdc++.h>
using namespace std;

void buildTree( int * input , int n, int * segmentedTree , int si , int ei , int treeIndex){

    if(si==ei){
        segmentedTree[treeIndex] = input[si];
        return;
    }

    int mid = (si+ei)/2;
    buildTree( input, n , segmentedTree , si , mid,2*treeIndex);
    buildTree(input, n, segmentedTree, mid+1 ,ei, 2*treeIndex+1);

    segmentedTree[treeIndex] = segmentedTree[2*treeIndex]+ segmentedTree[(2*treeIndex)+1];
}

void updateTree( int * input , int * segmentTree , int start ,int end , int treeIndex , int index , int value){
    
    if(start==end){
        input[index]= value;
        segmentTree[treeIndex] = value;
        return;
    }
    
    int mid = (start+end)/2;
    if(index<=mid){
        updateTree(input ,segmentTree , start ,mid ,2*treeIndex , index , value);
    }
    else{
        updateTree(input ,segmentTree , mid+1 ,end ,2*treeIndex+1 , index , value);
    }
    segmentTree[treeIndex] = segmentTree[2*treeIndex] + segmentTree[2*treeIndex+ 1];
}

int queryTree( int * segmentedTree ,int si, int ei, int TreeIndex, int left , int right){
    if(ei<left || si>right){
        return 0;
    }
    int leftAns = 0 ,rightAns = 0;
    if(si>=left && ei<=right){
        return segmentedTree[TreeIndex];
    }
    int mid = (si+ei)/2;
    int ans1 = queryTree(segmentedTree,si,mid,2*TreeIndex , left , right);
    int ans2 = queryTree(segmentedTree,mid+1,ei,2*TreeIndex+1 , left , right);
    return ans1 + ans2;
}

int main(){
    int n ;
    cin>>n;
    int * input = new int [n];
    for (int i=0; i<n ; i++){
        cin>>input[i];
    }
    int * segmentedTree = new int [2*n];

    buildTree(input,n,segmentedTree, 0, n-1 , 1);
    for ( int i=1 ;i<2*n ;i++){
        cout<<segmentedTree[i]<<endl;
    } 

    updateTree(input, segmentedTree , 0 ,n-1, 1 , 0 , 4);
    cout<<"Updated Array:\n";
    for ( int i=1 ;i<4*n ;i++){
        cout<<segmentedTree[i]<<endl;
    }

    // cout<<queryTree(segmentedTree ,0,n-1, 1, 1,3)<<endl;
    // cout<<segmentedTree[]
    delete [] input;
    delete [] segmentedTree; 
}