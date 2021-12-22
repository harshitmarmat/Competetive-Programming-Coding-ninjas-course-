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

int main(){
    int a=15;
    int b=10;
    triplet ans = extendedEuclid(a,b);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;
}