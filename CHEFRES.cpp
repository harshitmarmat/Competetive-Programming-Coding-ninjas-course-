#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<pair<int,int>> v1;
        for(int i=0 ; i<m;i++){
            int a,b;
            cin>>a>>b;
            v1.push_back(make_pair(a,b));
        }
        sort(v1.begin(),v1.end());

        while(n--){
            int curr;
            cin>>curr;
            // int position;
            int position = lower_bound(v1.begin(),v1.end(),make_pair(curr,0))-v1.begin();
            if(position==0){
                int ans = v1[0].first - curr;
                cout<<ans<<endl;
            }
            else{
                int ans =-1;
                if( v1[position-1].first > curr){
                    ans =0;
                }
                else if(position < v1.size()){
                    ans = v1[position].first - curr;
                }
                cout<<ans<<endl;
            }
        }
    }
}