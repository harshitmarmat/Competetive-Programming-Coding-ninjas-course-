#include<bits/stdc++.h>
using namespace std;

int magicGrid(int ** input,int sr, int sc , int er,int ec){
    if(sr==er && sc == ec){
        return 1;
    }
    if(sr>er || sc>ec){
        return INT_MAX;
    }
    int first = magicGrid(input,sr+1,sc ,er ,ec)-input[sr+1][sc];
    int second = magicGrid( input,sr,sc+1,er,ec)-input[sr][sc+1];
    return min(first,second);
}

int main(){
    int t;
    cin>>t;
    while( t--){
        int r;
        cin>>r;
        int c;
        cin>>c;
        int ** input = new int*[r];
        for ( int i=0 ; i<r ;i++){
            input[i] = new int [c];
            for( int j=0;j<c;j++){
                cin>>input[i][j];
            }
        }
        cout<<magicGrid(input,0,0,r-1,c-1)<<endl;
    }
}