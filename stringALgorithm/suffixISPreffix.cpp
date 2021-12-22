#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int * arr = new int[s.length()];
    arr[0]=0;
    int j=0;
    int i=1;
    for( ; i< s.length();){
        if(s[i]==s[j]){
            arr[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j==0){
                arr[i]=j;
                i++;
            }
            else{
                j= arr[j-1];
            }
        }
    }
    for(int i=0; i<s.length();i++){
        cout<<arr[i]<<" ";
    }
}