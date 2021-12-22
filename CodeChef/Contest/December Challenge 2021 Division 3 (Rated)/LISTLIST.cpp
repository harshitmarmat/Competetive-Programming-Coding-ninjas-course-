#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n;cin>>n;
		int * arr = new int[n];
		unordered_map<int,int> umap;
		for(int i=0 ;i<n;i++){
			cin>>arr[i];
			umap[arr[i]]++;
		}
		int maxTillNow =0;
		for(int i=0 ;i<n ;i++){
			if(umap[arr[i]]>maxTillNow){
				maxTillNow=umap[arr[i]];
				continue;
			}
		}
		if(maxTillNow==n){
			cout<<0<<endl;
		}
		else if(maxTillNow==1){
			cout<<-1<<endl;
		}
		else{
			cout<<n-(maxTillNow-1)<<endl;
		}
	}
}