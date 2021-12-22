#include<bits/stdc++.h>
using namespace std;

void buildTree(int * input , int * segmentedTree , int start , int end , int treeIndex){

    if( start == end){
        int count =0;
        if(input[start]%2 ==0){
            count++;
        }
        segmentedTree[treeIndex] = count;
        return;
    }

    int mid = (start + end )/2;
    buildTree( input , segmentedTree , start, mid ,2*treeIndex);
    buildTree(input , segmentedTree , mid+1 , end , 2*treeIndex+1);
    segmentedTree[treeIndex]  = segmentedTree[2*treeIndex]+ segmentedTree[2*treeIndex+1];
    return;
}

void updateTree(int * input  , int * segmenetedTree , int start , int end , int treeIndex ,int index , int value ){

    if(start == end){
        if(value%2==0){
            if(input[start]%2!=0){
                segmenetedTree[treeIndex]++;
            }
        }
        else{
            if(input[start]%2==0){
                segmenetedTree[treeIndex]--;
            }
        }
        input[index] = value;
        return;
    }
    int mid = (start + end)/2;
    if(mid>index){
        updateTree(input , segmenetedTree, start , mid+1 , 2*treeIndex , index , value );
    }
    else{
        updateTree(input , segmenetedTree , mid+1 , end , 2* treeIndex+1 , index , value);
    }
    segmenetedTree[treeIndex] = segmenetedTree[2*treeIndex] + segmenetedTree[2*treeIndex+1];
    return ;
}

int queryTree(int * segmentedTree , int start ,int end ,int left , int right ,int treeIndex , bool ans){

    if(end<left || start>right){
        return 0;
    }
    if(left<=start && right>=end){
        if(ans){
            return segmentedTree[treeIndex];
        }
        else{
            return ((end-start)+1)-segmentedTree[treeIndex];
        }
    }
    int mid = (start+end)/2;
    int ans1 = queryTree(segmentedTree , start , mid , left , right , 2*treeIndex ,ans);
    int ans2 = queryTree(segmentedTree , mid+1 , end , left , right , 2*treeIndex+1 , ans);
    return ans1+ans2;
}

int main(){
    int n; 
    cin>>n;
    int * input = new int [n];
    for(int i=0 ; i< n ; i++){
        cin>>input[i];
    }
    int *  segmentedTree = new int[4*n]();
    buildTree( input , segmentedTree , 0 , n-1, 1);
    for( int i=1; i<4*n;i++){
        cout<<segmentedTree[i]<<" ";
    }
    cout<<endl;

    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            updateTree(input , segmentedTree , 0 , n-1 , 1, b-1 , c);
            cout<<"UPDATED TREE :"<<endl;
            for( int i=1; i<4*n;i++){
                cout<<segmentedTree[i]<<" ";
            }
            cout<<endl;
        }
        if( a==1){
            cout<<queryTree(segmentedTree , 0 ,n-1 , b , c ,1, true)<<endl;
        }
        if(a==2){
            cout<<queryTree(segmentedTree , 0 , n-1 , b , c ,1, false)<<endl;
        }

    }
}