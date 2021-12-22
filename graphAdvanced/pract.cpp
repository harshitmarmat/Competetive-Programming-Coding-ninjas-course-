#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> p;
    p.insert(10);
    p.insert(20);
    p.insert(30);
    set<int> q;
    q.insert(30);
    q.insert(20);
    q.insert(10);
    if(p==q){
        cout<<"equal set"<<endl;
    }
    else{
        cout<<"Not equal set"<<endl;
    }
}