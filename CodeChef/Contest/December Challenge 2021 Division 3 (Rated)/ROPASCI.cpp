#include<bits/stdc++.h>
using namespace std;

char findWinner(char a,char b){
	if(a==b){
		return a;
	}
	if(a=='S'){
		if(b=='R'){
			return b;
		}
		if(b == 'P'){
			return a;
		}
	}
	if(a=='P'){
		if(b=='R'){
			return a;
		}
		if(b == 'S'){
			return b;
		}
	}
	if(a=='R'){
		if(b=='S'){
			return a;
		}
		if(b == 'P'){
			return b;
		}
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string str;
		cin>>str;
		vector<char> R(n+1);
		vector<char> P(n+1);
		vector<char> S(n+1);
		vector<char> result(n+1);
		result[n]= str[n-1];

		R[n] = findWinner('R',str[n-1]);
		S[n] = findWinner('S',str[n-1]);
		P[n] = findWinner('P',str[n-1]);

		for(int i=n-1;i>=1;i--){
			char r_res = findWinner('R',str[i-1]);
			if(r_res=='R'){
				R[i] = R[i+1];
			}
			else if(r_res=='P'){
				R[i] = P[i+1];
			}
			else{
				R[i]=S[i+1];
			}

			char p_res = findWinner('P',str[i-1]);
			if(p_res=='R'){
				P[i] = R[i+1];
			}
			else if(p_res=='P'){
				P[i] = P[i+1];
			}
			else{
				P[i]=S[i+1];
			}

			char s_res = findWinner('S',str[i-1]);
			if(s_res=='R'){
				S[i] = R[i+1];
			}
			else if(s_res=='P'){
				S[i] = P[i+1];
			}
			else{
				S[i]=S[i+1];
			}

			if(str[i-1]=='R'){
				result[i]=R[i+1];
			}
			else if(str[i-1]=='S'){
				result[i]=S[i+1];
			}
			else if(str[i-1]=='P'){
				result[i]=P[i+1];
			}
		}
		for(int i=1 ;i<=n ;i++){
			cout<<result[i];
		}
		cout<<endl;
	}
}