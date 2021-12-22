#include<bits/stdc++.h>
using namespace std;

int minSquare( int ** grid ,int **output, int n){
	for( int i=1 ;i<n ;i++){
		for(int j=1 ;j<n;j++){
			if(grid[i][j]==0){
				continue;
			}
			output[i][j]= 1+ min(output[i-1][j],min(output[i-1][j-1],output[i][j-1]));
		}
	}
	int ans=0;
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			ans+=output[i][j];
		}
	}
	cout<<endl
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl
	}
	cout<<endl

	return ans;
}


int condSquare(int ** grid , int n){
	int ** output = new int* [n];
	for( int i=0 ;i<n ;i++){
		output[i] = new int [n]();
		for( int j=0 ;j<n ;j++){
			if(grid[i][j]==0){
				for(int k=0;k<n;k++){
					output[i][k]=0;
				}
				for(int k=0;k<n;k++){
					output[k][j]=0;
				}
			}
			continue;
		}
	}
	int ans = 0;	
	for(int i=1 ;i<n ;i++){
		for(int j=1 ;j<n ;j++){
			if(output[i][j]==0){
				continue;
			}
			if(output[i-1][j-1]==0){
				int count =1;
				for( ; i-count>=0 && j-count>=0;count++){
					if(output[i-count][j]==1 && output[i][j-count]==1){
						ans++;
					}
				}
			}
		}
	}
	cout<<endl
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl
	}
	cout<<endl
	return ans;		
}

int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ** grid = new int *[n];
		for(int i= 0 ;i<n ;i++){
			grid[i]= new int[n];
			for(int j=0 ;j<n ;j++){
				cin>>grid[i][j];
			}
		}
		int ** output = new int* [n];
		for( int i=0 ;i<n ;i++){
			output[i] = new int [n]();
		}

		output[0][0]=grid[0][0];

		for ( int i=1 ;i<n ;i++){
			output[0][i] = grid[0][i];
			output[i][0] = grid[i][0];
		}
		int ans1 = minSquare(grid, output, n);
		int ans2 = condSquare(grid ,n);

		cout<<ans1+ans2<<endl;

	}
}