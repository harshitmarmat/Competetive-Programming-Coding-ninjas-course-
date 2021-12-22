#include<bits/stdc++.h>
using namespace std;

class side{
    public:
        int length;
        int height;
};

bool compare(side s1,side s2){
    return s1.height > s2.height;
}

int main(){
        int n ;
        cin>>n;
        vector<side> v;
        for( int i=0 ; i<n ;i++){
            int l ,b;
            cin>>l>>b;
            side s;
            s.length=l;
            s.height = b;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),compare);
        // for( int i=0 ; i<v.size();i++){
        //     cout<<v[i].length<<" "<<v[i].height<<endl;
        // }
        side s1 = v[0];
        int count = 0;
        for( int i=1; i<n;i++){
            if(s1.length < v[i].length){
                int mult = s1.height - v[i].height;
                count =count+ (s1.length*mult);
                s1 = v[i];
            }
        }
        
        count= count + (s1.length*s1.height);
        cout<<count<<endl;
}