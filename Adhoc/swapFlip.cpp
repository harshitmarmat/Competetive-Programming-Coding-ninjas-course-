#include<iostream>>
using namespace std;

int main(){
    string a;
    string b;
    cin>>a>>b;
    int count=0;
    for(int i=0 ;i<a.size();i++){
        if(a[i]==b[i]){
            continue;
        }
        if(i+1<a.size() && a[i+1]!=b[i+1] && a[i+1]!= a[i]){
            cost++;
            i++;
            continue;
        }
        else{
            cost++;
        }
    }
}