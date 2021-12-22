#include<iostream>
using namespace std;

int main(){

    int arr[100][100];
    int n,m;
    n=5;m=8;
    int count =0;
    for(int i = 0; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            arr[i][j]=count;
            count++;
        }
    }

    for( int i=0 ; i<m ; i++){
        for( int j=0 ; j<n ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int check = m*n;
    count =0;
    int rstart =0; 
    int cstart =0;
    bool ans = true;

    while(count<check && ans){
    
        for(int i=cstart ; i<n;i++){
            if(count<check && ans){
                cout<<arr[rstart][i]<<" ";
                count++;
                continue;
            }
            ans= false;
        }
        
        rstart++;

        for(int i=rstart ; i<m ; i++){
            if(count<check && ans){
                cout<<arr[i][n-1]<<" ";
                count++;
                continue;
            }
            ans= false;
        }
    
        n--;

        for( int i=n-1; i>=cstart ;i--){
            if(count<check && ans){
                cout<<arr[m-1][i]<<" ";
                count++; 
                continue;
            }
            ans = false;
        }
        
        m--;
    
        for(int i=m-1 ; i>=rstart ;i--){
            if( count<check && ans){
            cout<<arr[i][cstart]<<" ";
            count++;
            continue;
            }
            ans = false;
        }
        
        cstart++;
    }

}