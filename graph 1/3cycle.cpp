#include<bits/stdc++.h>
using namespace std;

int threeCycle(int ** board , int size){
    int count =0;
    for(int i=1 ; i<=size; i++){
        for(int j=1 ; j<=size ; j++){
            if(board[i][j]==1){
                for(int k =1; k<=size; k++){
                    if(board[j][k]==1 && board[k][i]==1){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
}

int main(){
    int n ;
    cin>>n;
    int m ;
    cin>>m;
    int ** input  = new int*[3];
    for(int i=1 ;i<=2;i++){
        input[i] =new int [m+1];
        for(int j=1 ; j<=m ;j++){
            cin>>input[i][j];
        }
    }
    int ** board = new int*[m+1];
    for(int i=1 ; i<=m ;i++){
        board[i] = new int [m+1]();
    }
    for(int i=1 ; i<=2;i++){
        for(int j=1 ; j<m ;j++){
            int row = input[i][j];
            int col = input[i][j+1];
            board[row][col] = 1;
            board[col][row] = 1;
        }
    }

    cout<<threeCycle(board ,m)<<endl;
    
}