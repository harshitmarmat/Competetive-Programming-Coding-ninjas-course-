#include<iostream>
using namespace std;

class Triplets{
    public:
        int x;
        int y;
        int gcd;
};

Triplets Euclid(int a ,int b){
    if(b==0){
        Triplets ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0; 
        return ans;
    }

    Triplets smallAns = Euclid(b,a%b);  
    Triplets ans;
    ans.gcd = smallAns.gcd;
    ans.x =smallAns.y;
    ans.y = smallAns.x-(a/b)*smallAns.y;
    return ans;
}

int main(){
    int a;
    int b;
    cin>>a>>b;
    Triplets ans = Euclid(a,b);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;
}