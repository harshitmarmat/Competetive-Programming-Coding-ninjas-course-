#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0){
			cout<<0<<endl<<0<<endl;
			continue;
		}
		string output= "";
		if(n>m){
			output = output + "0";
			for(int i=0 ;i<m ;i++){
				output= output + "10";
			}
			int current = n-m;
			for( int i=1;i<current;i++){
				output=output+"100";
			}
			output=output+"10";
		}
		else if(m>n){
			output = output + "1";
			for(int i=0 ;i<n ;i++){
				output= output + "01";
			}
			int current=m-n;
			for(int i=1 ;i<current;i++){
				output+="011";
			}
			output=output+"01";
		}
		else if(m==n){
			for( int i=0 ;i<=n ; i++){
				output=output+"01";
			}
		}
		cout<<output.size()<<endl<<output<<endl;
	}
}