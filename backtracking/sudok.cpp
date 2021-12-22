#include<bits/stdc++.h>
using namespace std;

bool ispossiblegrid(int **board, int row, int col, int num){
    int rowstart = row - (row%3);
    int colstart = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[rowstart+i][colstart+j]==num){
                return false;
            }
        }
    }
    return true;
}

bool ispossiblecol(int **board, int col, int num){
    for(int j=0;j<9;j++){
        if(board[j][col]==num){
            return false;
        }
    }
    return true;
}

bool ispossiblerow(int **board, int row, int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num){
            return false;
        }
    }
    return true;
}

bool ispossible(int **board, int row, int col, int num){
    
    if( ispossiblerow(board,row,num) && ispossiblecol(board,col,num) && ispossiblegrid(board,row,col,num)){
        return true;
    }
    return false;
}

bool isfull(int** board, int &row, int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row =i;
                col =j;
                return false;
            }
        }
    }
    return true;
}


bool solvesodoku(int ** board){
    int row;
    int col;
    if(isfull(board,row,col)){
        return true;
    }
    
    for(int i=1;i<=9;i++){
        if(ispossible(board,row,col,i)){
            board[row][col]=i;
            if(solvesodoku(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    
    return false;
    
}

int main(){
    
    int **board = new int*[9];
    for(int i=0;i<9;i++){
        board[i]=new int[9];
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    if(solvesodoku(board)){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}