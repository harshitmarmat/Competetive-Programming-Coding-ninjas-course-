#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int * arr = new int [n+1];
    for(int i=0; i<=n ;i++){
        arr[i]= i;
    }

    for(int i=2 ; i<= n ;i++){
        if(arr[i]==i){
            for(int j=i*i ;j<=n ;j++){
                arr[j]=arr[i];
            }
        }
    }
    
    bool * input = new bool [n+1];
    for(int i=0 ; i<=n ;i++){
        input[i]=false;
    }

    for(int i=n ;i>0 ;i--){
        if(!input[i]){
            int current = i;
            int ld =arr[current];
            vector<int> v;
            while(current%ld!=0){
                int x= current;
                while(x>0){
                    input[x]=false;
                    v.push_back(current);
                    x/=ld;
                }
                ld=arr[current/ld];
            }
            sort(v.begin(),v.end());
            for(int i=0 ; i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }



    
}