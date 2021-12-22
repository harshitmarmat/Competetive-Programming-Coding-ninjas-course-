#include<iostream>
using namespace std;

int main(){
    int arr[1000][1000];
    int M,N;
    cin>>M>>N;
    
    for(int i=0; i<M; i++){
        for(int j=0 ; j<N;  j++){
            cin>>arr[M][N];
        }
    }
    for(int i=0; i<M ; i++){
        for(int j=0 ; j<N;  j++){
            cout<<arr[M][N]<<" ";
        }
        cout<<endl;
    }
    
    for( int i=0 ; i<N ;i++){
        int sum = 0;
        for(int j=0 ; j<M ; j++){
            sum+=arr[N][M];
        }
    	cout<<sum<<" ";
    }
}