#include<iostream>
using namespace std;
int board[9][9];

class pairOfRowCol{
    public:
        int row;
        int col;
};

pairOfRowCol emptySpace(int x,int y){
    for( int i=0 ; i<9 ; i++){
        for( int j = 0; j<9 ; j++){
            if(board[i][j]==0){
                pairOfRowCol ans;
                ans.row = i;
                ans.col = j;
                return ans;
            }
        }
    }
    pairOfRowCol ans;
    ans.row = -1;
    ans.col = -1;
    return ans;

}

bool isPossible( pairOfRowCol cell,int x){
    int row_num = cell.row;
    int col_num = cell.col;
    //column-left wise check
    for( int i = col_num-1 ;i>=0 ;i--){
        if(board[row_num][i]==x){
            return false;
        }
    }
    //column-left wise check
    for( int i= col_num-1 ; i<9 ;i++){
        if(board[row_num][i]==x){
            return false;
        }
    }
    //row upper-wise check
    for(int i= row_num-1;i>=0;i--){
        if(board[i][col_num]==x){
            return false;
        }
    }
    //row down wise check
    for( int i= row_num+1 ;i<9;i++){
        if(board[i][col_num]==x){
            return false;
        }
    }
    //box wise check
    int box_row = row_num -(row_num%3);
    int box_col = col_num -(col_num%3);

    for(int i=0;i<3 ;i++){
        for( int j=0 ; j<3 ;j++){
            if(box_row+i == row_num && box_col+i == col_num){
                continue;
            }
            if( board[box_row+i][box_col+i]==x){
                return false;
            }
        }
    }
    return true;
}


bool solveSudoku(int x, int y){
    pairOfRowCol empty = emptySpace(x,y);
    if(empty.row== -1 && empty.col ==-1){
        return true;
    }
    for( int i=1 ; i<10;i++){
        if(isPossible(empty,i)){
            board[empty.row][empty.col]=i;
            if(solveSudoku(empty.row,empty.col)){
                return true;
            }
            board[empty.row][empty.col] = 0;
        }
    }
    return false;
}

int main(){
    for(int i=0 ; i<9 ;i++){
        for( int j=0 ;j<9 ; j++){
            cin>>board[i][j];
        }
    }
    solveSudoku(0,0);
    cout<<"SOLUTION :"<<endl;
    for( int i=0 ; i<9 ;i++){
        for( int j=0; j<9 ;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}