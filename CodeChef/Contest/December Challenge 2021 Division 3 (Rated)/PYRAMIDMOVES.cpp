#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;

const int mod = 1e9 + 7;

const int MAXF = 1e5;

lli fact[MAXF+1];

ll powmod(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

lli last_elem(lli a){
	return((a+1)*a)/2;
}

pair<lli,lli> getIndex(lli n){
	lli a = -1;
	lli idx = -1;
	if(n==1){
	    pair<lli,lli> ans;
	    ans.first=1;
	    ans.second=1;
		return ans;
	}

	lli st = 2;
	lli end = 1+ ceil(sqrt(2*n));
	while(st<=end){
		a = (st+end)/2;
		if(last_elem(a)>=n && last_elem(a-1)<n){
			break;
		}
		else if( last_elem(a)>n){
			end = a-1;
		}
		else{
			st = a +1;
		}
	}
	idx = n - (a *(a-1))/2;
	pair<lli,lli> ans;
    ans.first=a;
    ans.second=idx;
	return ans;
}

int main(){

	fact[0]=1;
	fact[1]=1;
	for(int i=2 ;i<=MAXF ; i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
	int t;
	cin>>t;
	while(t--){
	 	lli s,e;
	 	cin>>s>>e;
	 	lli ans =-1;
	 	pair<lli,lli> res1 , res2;
	 	res1 = getIndex(s);
	 	res2 = getIndex(e);

	 	lli siv1 = res1.first;
	 	lli sidx = res1.second;
	 	lli eiv1 = res2.first;
	 	lli eidx = res2.second;

	 	lli L = eiv1-siv1;
	 	lli K = eidx-sidx;
	 	lli mod = 1e9 +7;
    
	 	if(L<=0 || K<0 || K>L){
	 		ans = 0;
	 	}
	 	else{
	 		ans = nCk(L,K,mod);
	 		
	 	}
	 	cout<<ans<<endl;
	}
}