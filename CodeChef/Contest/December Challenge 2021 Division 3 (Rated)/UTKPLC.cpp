#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;cin>>t;
	while(t--){
		char Input1,Input2,Input3;
		cin>>Input1>>Input2>>Input3;
		char offer1,offer2;
		cin>>offer1>>offer2;
		if(Input1==offer1){
			cout<<offer1<<endl;
		}
		else if(Input1==offer2){
			cout<<offer2<<endl;
		}
		else if(Input2==offer1){
			cout<<offer1<<endl;
		}
		else if(Input2==offer2){
			cout<<offer2<<endl;
		}
		else if(Input3==offer1){
			cout<<offer1<<endl;
		}
		else if(Input3==offer2){
			cout<<offer2<<endl;
		}
	}
}