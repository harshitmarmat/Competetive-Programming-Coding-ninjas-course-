#include<bits/stdc++.h>
using namespace std;

class triplet{
    public:
        int gcd;
        int x;
        int y;
};

triplet extendedEuclid( int a ,int b){
    if(b==0){
        triplet ans;
        ans.gcd = a;
        ans.x=1;
        ans.y=0;
        return ans;
    }

    triplet smallans = extendedEuclid( b, a%b);
    triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x -(a/b)*smallans.y;
    return ans;
}

int solve(int a, int b){
    triplet ans =extendedEuclid(a,b);
    return ans.x;
}

int main(){
    int a = 10;
    int b = 5;
    cout<<solve(a,b)<<endl;
}