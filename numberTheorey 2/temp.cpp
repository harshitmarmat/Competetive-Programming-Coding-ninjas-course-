#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "10940243";
    string b = a.substr(0,a.size()-1);
    cout<<b<<endl;
    int c = b[b.size()-1]-'0';
    cout<<c;
}