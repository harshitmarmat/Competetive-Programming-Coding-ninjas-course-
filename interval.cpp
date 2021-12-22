#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int,int> arr[n];    
    for(int i=0 ; i<n ;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    if(n==1){
        cout<<arr[0].first<<" "<<arr[0].second<<endl;
        return 0;
    }
    pair<int,int> output[n];
    int count =0;
    for(int i=0 ;i<n;i++){
        int ans1 = arr[i].first;
        int ans2 = arr[i].second;
        if(i+1<n && arr[i].second>arr[i+1].first){
            ans2 = max(arr[i].second,arr[i+1].second);
            i++;
        }
        else if(i-1>0 && output[i-1].second> arr[i].first ){
            ans2= max(output[i-1].second,arr[i].second);
            pair<int,int> final;
            final.first = ans1;
            final.second = ans2;
            output[count] = final;
            continue;
        }
        pair<int,int> final;
        final.first = ans1;
        final.second = ans2;
        output[count++] = final;
    }

    for(int i=0 ; i<count;i++){
        cout<<output[i].first<<" "<<output[i].second<<endl;
    }
    return 0;
}