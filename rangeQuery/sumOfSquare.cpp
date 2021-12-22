#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void buildTree( int * input , pair<ll,int> * segmentedTree ,int start ,int end , int treeIndex){
    if(start == end){
        pair<ll,int> ans;
        ans.first = input[start]*input[start];
        ans.second = input[start];
        segmentedTree[treeIndex] = ans;
        return ;
    }
    int mid = (start+end)/2;
    buildTree(input , segmentedTree , start , mid ,2*treeIndex);
    buildTree(input , segmentedTree , mid+1 , end , 2*treeIndex+1);
    pair<ll,int> ans1 = segmentedTree[2*treeIndex];
    pair<ll,int> ans2 = segmentedTree[2*treeIndex+1];
    pair<ll,int> result;
    result.first = ans1.first+ ans2.first;
    result.second = ans1.second+ ans2.second;
    segmentedTree[treeIndex] = result;
    return;
}

ll sumOfSquare(pair<ll,int> * segmentedTree , int start ,int end , int left  , int right , int treeIndex){
    if(end<left || right<start){
        return 0;
    }
    if(left<=start && right>=end){
        return segmentedTree[treeIndex].first;
    }
    int mid = (start+end)/2;
    ll ans1 = sumOfSquare(segmentedTree , start,mid, left , right , 2* treeIndex);
    ll ans2 = sumOfSquare(segmentedTree,mid+1 ,end , left , right , 2*treeIndex+1);
    return ans1+ans2;
}

void updateRange(pair<ll,int> * segmentedTree , pair<int,int> * lazyTree , int start ,int end ,int left, int right ,int treeIndex , int value,bool ans){
    if(start>right){
        return ;
    }
    if(lazyTree[treeIndex].second!=0){
        if(lazyTree[treeIndex].second==1){
            segmentedTree[treeIndex].first += (2*value*(segmentedTree[treeIndex].second))+(value*value*((end-start)+1));
            segmentedTree[treeIndex].second += value*((end-start)+1);
        }
        if(lazyTree[treeIndex].second==2){
            segmentedTree[treeIndex].first += (value*value)*((end-start)+1);
            segmentedTree[treeIndex].second += value*((end-start)+1);
        }
        if(start!=end){
            lazyTree[2*treeIndex].first = lazyTree[treeIndex].first;
            lazyTree[2*treeIndex].second = lazyTree[treeIndex].second;
            lazyTree[2*treeIndex+1].first = lazyTree[treeIndex].first;
            lazyTree[2*treeIndex+1].second = lazyTree[treeIndex].second;
        }
        lazyTree[treeIndex].first=0;
        lazyTree[treeIndex+1].first=0;
    }
    if(end<left || right<start){
        return ;
    }
    
    if(left<=start && right>=end && ans){
        segmentedTree[treeIndex].first += (2*value*(segmentedTree[treeIndex].second))+(value*value*((end-start)+1));
        segmentedTree[treeIndex].second += value*((end-start)+1);
        if(start!=end){
            lazyTree[2*treeIndex].first =value;
            lazyTree[2*treeIndex].second=1;
            lazyTree[2*treeIndex+1].first =value;
            lazyTree[2*treeIndex+1].second=1;
        }
        return ;
    }
    if(left<=start && right>=end && !ans){
        segmentedTree[treeIndex].first += (value*value)*((end-start)+1);
        segmentedTree[treeIndex].second += value*((end-start)+1);
        if(start!=end){
            lazyTree[2*treeIndex].first =value;
            lazyTree[2*treeIndex].second=2;
            lazyTree[2*treeIndex+1].first =value;
            lazyTree[2*treeIndex+1].second=2;
        }
        return ;
    }
    int mid = (start+end)/2;
    updateRange(segmentedTree , lazyTree , start , mid ,left,right,2*treeIndex,value,ans);
    updateRange(segmentedTree ,lazyTree, mid+1 , end , left,right, 2*treeIndex+1 , value,ans);
    pair<ll,int> ans1 = segmentedTree[2*treeIndex];
    pair<ll,int> ans2 = segmentedTree[2*treeIndex+1];
    pair<ll,int> result;
    result.first = ans1.first+ ans2.first;
    result.second = ans1.second+ ans2.second;
    segmentedTree[treeIndex] = result;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int * input = new int[n];
        for(int i=0 ; i<n ;i++){
            cin>>input[i];
        }
        pair<ll,int> * segmentedTree = new pair<ll,int>[4*n]();
        buildTree(input , segmentedTree , 0 , n-1 , 1);
        pair<int,int> * lazyTree = new pair<int,int>[4*n]();
        // for(int i = 1 ; i<4*n ;i++){
        //     cout<<segmentedTree[i].first<<" "<<segmentedTree[i].second<<endl;
        // }
        while(q--){
            int current ; 
            cin>>current;
            if(current==2){
                int left,right;
                cin>>left>>right;
                cout<<sumOfSquare(segmentedTree, 0 ,n-1 , left,right , 1)<<endl;
            }
            if(current ==1){
                int left,right ,value;
                cin>>left>>right>>value;
                updateRange(segmentedTree,lazyTree,0,n-1,left,right,1,value , true);
            }
            if(current ==0){
                int left,right ,value;
                cin>>left>>right>>value;
                updateRange(segmentedTree,lazyTree,0,n-1,left,right,1,value , false);
            }
        }
        delete [] input;
        delete [] segmentedTree;
        delete [] lazyTree;
    }
}