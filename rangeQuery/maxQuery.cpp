#include<bits/stdc++.h>
using namespace std;

void buildTree( int * input , int * segmentedTree , int start , int end , int treeIndex){

    if( start== end){
        segmentedTree[treeIndex] = input[start];
        return ;
    }

    int mid = (start+end)/2;
    buildTree( input , segmentedTree , start ,mid , 2* treeIndex);
    buildTree( input , segmentedTree , mid+1 , end , 2*treeIndex+1);
    segmentedTree[treeIndex]= max(segmentedTree[2*treeIndex], segmentedTree[2*treeIndex+1]);
    return ;
}

int queryTree(int * segementedTree , int start , int end , int left , int right ,  int treeIndex){

    if(end<left || start>right){
        return 0;
    }
    if(left<=start && end<=right){
        return segementedTree[treeIndex];
    }
    int mid = (start + end )/2;
    int ans1 = queryTree( segementedTree , start ,mid , left , right , 2*treeIndex);
    int ans2 = queryTree( segementedTree , mid+1 , end , left , right ,2*treeIndex+1);
    return max(ans1,ans2);
}

int main(){
    int n;
    cin>>n;
    int * input = new int [n];
    for(int i=0 ; i<n ; i++){
        cin>>input[i];
    }
    int * segmentedTree = new int [4*n]();
    buildTree( input,segmentedTree, 0 , n-1 , 1);
    int q;
    cin>>q;
    while(q--){
        int left ,right;
        cin>>left>>right; 
        cout<<queryTree( segmentedTree,0 , n-1 , left ,right , 1)<<endl;
    }
    delete [] input;
    delete [] segmentedTree;
}