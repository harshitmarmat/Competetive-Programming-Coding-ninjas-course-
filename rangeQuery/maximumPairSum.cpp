#include<bits/stdc++.h>
using namespace std;

void updateTree(int * input, pair<int,int> *segmentedTree, int start ,int end ,int treeIndex ,int index , int value){

    if(start == end){
        input[index] = value;
        pair<int,int> ans;
        ans.first= value;
        ans.second = INT_MIN;
        segmentedTree[treeIndex]= ans;
        return;
    }
    int mid= ( start + end)/2;
    if(mid<index){
        updateTree( input , segmentedTree , mid+1 , end, 2*treeIndex+1 , index ,value);
    }
    else{
        updateTree(input , segmentedTree , start , mid , 2* treeIndex , index , value);
    }

    pair<int,int > ans1 = segmentedTree[2*treeIndex];
    pair<int,int> ans2 = segmentedTree[2*treeIndex+1];
    pair<int,int> ans ;
    ans.first = max(ans1.first , ans2.first);
    ans.second = min(max(ans1.first , ans2.second), max( ans1.second,ans2.first));
    segmentedTree[treeIndex]=ans;
    return ;
}

pair<int,int> queryTree( pair<int,int> * segmentedTree, int start , int end , int treeIndex ,int left ,int right){

    if(left>end || right<start){
        pair<int,int> ans;
        ans.first = INT_MIN;
        ans.second = INT_MIN;
        return ans;
    }
    if(left<=start && right>=end){
        return segmentedTree[treeIndex];
    }
    else{
        int mid = (start+end)/2;
        pair<int,int> ans1 = queryTree(segmentedTree , start , mid , 2* treeIndex , left,right);
        pair<int,int> ans2 = queryTree(segmentedTree , mid+1 , end , (2*treeIndex)+1 , left ,right);
        pair<int,int> ans;
        ans.first = max(ans1.first,ans2.first);
        ans.second = min(max(ans1.first,ans2.second),max(ans1.second,ans2.first));
        return ans;
    }

}

void buildTree( int * input ,pair<int,int> * segmentedTree , int start , int end , int treeIndex){
    if(start ==end ){
        pair<int,int> ans;
        ans.first = input[start];
        ans.second = INT_MIN;
        segmentedTree[treeIndex] = ans;
        return;
    }


    int mid = (start+end)/2;
    buildTree(input, segmentedTree , start, mid , 2* treeIndex);
    buildTree(input, segmentedTree , mid+1, end , (2* treeIndex)+1);

    pair<int,int> ans1 = segmentedTree[2*treeIndex];
    pair<int,int> ans2 = segmentedTree[(2*treeIndex)+1];
    pair<int,int> ans;
    ans.first = max(ans1.first , ans2.first);
    ans.second = min(max(ans1.first,ans2.second),max(ans1.second , ans2.first));
    segmentedTree[treeIndex] = ans;
    return;
}

int main(){
    int n ;
    cin>>n;
    int * input = new int [n];
    for (int i=0; i< n ; i++){
        cin>>input[i];
    }
    pair<int,int> * segmentedTree = new pair<int,int>[4*n]; 
    buildTree( input , segmentedTree , 0 ,n-1 , 1);

    // for (int i=1 ; i<4*n ;i++){
    //     cout<<segmentedTree[i].first<<" "<<segmentedTree[i].second<<endl;
    // }

    int t;
    cin>>t;
    while(t--){

        char character;
        int a,b;
        cin>>a>>b;
        if(character=='U'){
            updateTree(input,segmentedTree,0,n-1,1,a , b);
        }
        else{
            pair<int,int> ans = queryTree(segmentedTree, 0, n-1 , 1 , a, b);
            int result = ans.first+ans.second;
            cout<<result<<endl;
        }
    }
    delete [] input;
    delete [] segmentedTree;
}`