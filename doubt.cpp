#include <bits/stdc++.h>
using namespace std;

int chargePhone(long long S){
    int R;
    if(S>=0 && S<=10)
        R=10;
    else if(S>=11 && S<=230)
        R=5;
    else if(S>=231 && S<=559)
        R=8;
    else if(S>=560 && S<=1009)
        R=2;
    else if(S>=1010 && S<=5000)
        R=7;
    else if(S>=5001 && S<=10000)
     R=8;
    else if(S>=10001 && S<=1000000000)
        R=3;
    return R;
}

int chargingSmartPhone(int initcharge, int finalCharge) {
    // write your code here
    long long S = initcharge, T = finalCharge;
    int R;
    int time=0;
    while(S < T){
        R = chargePhone(S);
        S = S+R;
        time++;
    }
    return time;
}


int main() {
    //ios::sync_with_stdio(@);
    //cin.tie()
    vector<int> output;
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int initCharge;
        cin >> initCharge;
        int finalCharge;
        cin >> finalCharge;
        int out_;
        out_ = chargingSmartPhone(initCharge, finalCharge);
        output.push_back(out_);
        //cout << out_;
        //cout << "\n";
    }
    for (int i=0;i<output.size();i++){
        cout << output[i];
        cout << "\n";
    }
    return 0;
}