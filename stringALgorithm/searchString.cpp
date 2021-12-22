#include <bits/stdc++.h>
using namespace std;

int * getLps( string pattern){
    int * arr = new int [pattern.size()]();

    int j=0 ; 
    for(int i=1 ; i<pattern.size();){
        if(pattern[i]==pattern[j]){
            j++;
            arr[i] = j;
            i++;
        }
        else{
            if(j==0){
                arr[i]=0;
                i++;
            }
            else{
                j= arr[j-1];
            }
        }
    }
    return arr;
}


bool searchString(string text , string pattern){
    int i=0,j=0;
    int * lps = getLps(pattern);
    while(i<text.size() && j<pattern.size()){
        if(text[i]== pattern[j]){
            i++;
            j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j= lps[j-1];
            }
        }
    }
    if(j==pattern.size()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string text,pattern;
        cin>>text>>pattern;
        if(searchString(text , pattern)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}