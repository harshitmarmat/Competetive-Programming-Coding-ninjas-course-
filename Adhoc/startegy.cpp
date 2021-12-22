#include<bits/stdc++.h>
using namespace std;

void swap( int * arr ,int x ,int j){
    int temp= arr[x];
    arr[x]=arr[j];
    arr[j]= temp;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int opponent[n];
        for(int i=0 ; i<n ;i++){
            cin>>opponent[i];
        }
        int myteam[n];
        for (int i=0 ;i<n ; i++){
            myteam[i]=i+1;
        }
        int count =0;
        int swap_count = 0;
        bool check = false;
        for( int i=n-1;i>=0;i--){
            if(myteam[i]!=opponent[i]){
                while(count<=2){
                    count++;
                    if(myteam[i-count]==opponent[i]){
                        break;
                    }
                }
                if(count==1){
                    swap(myteam,i,i-count);
                    swap_count+=count;
                    count=0;
                    continue;
                }
                if(count==2){
                    swap(myteam,i-(count-1),i-count);
                    swap(myteam,i,i-(count-1));
                    swap_count+=count;
                    count=0;
                    continue;
                }
                else{
                    check=true;
                    cout<<"No"<<endl;
                    break;
                }
            }
        }
        if( !check){
            cout<<"Yes"<<endl<<swap_count<<endl;
        }

    }
}