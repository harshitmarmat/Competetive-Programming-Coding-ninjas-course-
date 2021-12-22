#include<bits/stdc++.h>
using namespace std;

void buildTree(int *strength , int * coward , pair<int,int> * segmentedTree , int start ,int end , int treeIndex){

    if(start == end){
        pair<int,int> ans;
        ans.first = strength[start];
        ans.second = start;
        segmentedTree[treeIndex] = ans;
        return;
    }

    int mid = (start + end )/2;
    buildTree(strength , coward , segmentedTree , start , mid , 2*treeIndex);
    buildTree(strength , coward , segmentedTree , mid+1 ,end , 2*treeIndex+1);
    pair<int,int> ans1 = segmentedTree[2*treeIndex];
    pair<int,int> ans2 = segmentedTree[2*treeIndex+1];
    pair<int,int> ans;
    if(ans1.first == ans2.first){
        int index1 = ans1.second;
        int index2 = ans2.second;
        if(coward[index1]>coward[index2]){
            ans = ans2;
        }
        else{
            ans = ans1;
        }
    }
    else{
        if(ans1.first>ans2.first){
            ans = ans1;
        }
        else{
            ans = ans2;
        }
    }
    segmentedTree[treeIndex]=ans;
    return;
}

int query( int* coward,int* strength, pair<int,int> * segmentedTree , int start ,int end ,int left ,int right , int treeIndex){

    if(end<left || start>right){
        return 0;
    }
    if(start>=left && right>=end){
        return segmentedTree[treeIndex].second;
    }
    int mid= (start+end)/2;
    int ans1 = query(coward , strength,segmentedTree ,start , mid , left ,right, 2*treeIndex);
    int ans2 = query(coward,strength, segmentedTree , mid+1 , end , left , right ,2*treeIndex+1);
    if(strength[ans1]== strength[ans2]){
        if(coward[ans1]>coward[ans2]){
            return ans2;
        }
        else{
            return ans1;
        }
    }
    else{
        if(strength[ans1]>strength[ans2]){
            return ans1;
        }
        else{
            return ans2;
        }
    }
}

int main(){
    int n ;
    cin>>n;
    int * strength = new int[n];
    for(int i=0 ;i<n ;i++){
        cin>>strength[i];
    }
    int * coward = new int [n];
    for(int i=0 ;i<n ;i++){
        cin>>coward[i];
    }
    pair<int,int> * segmentedTree = new pair<int,int> [4*n];
    buildTree(strength , coward ,segmentedTree , 0 ,n-1 , 1);
    // for(int i=1 ;i<4*n;i++){
    //     cout<<segmentedTree[i].first<<" "<<segmentedTree[i].second<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int left,right;
        cin>>left>>right;
        int ans = query(coward , strength , segmentedTree , 0 ,n-1 , left-1, right-1 ,1)+1;
        cout<<ans<<endl;
    }
    delete [] strength;
    delete[] coward;
    delete [] segmentedTree;
}