#include<iostream>
using namespace std;

int keypadCount(int n , string output[] ,
  string key[]){
    if(n==0){
        output[0]="";
        return 1;
    }
    int smallans = keypadCount(n/10,output,key);
    string current  = key[n%10];
    for( int i=1;i<current.size();i++){
        for( int j =0 ;j<smallans ; j++){
            output[j+(i*smallans)] = output[j]+current[j];
        }
    }
    for( int i=0 ; i<smallans ;i++){
        output[i]= output[i]+ current[i];
    }

    return smallans*current.size();

}

int keypad( int n , string * output){

    string key[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return keypadCount( n,output, key);
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        string output[1000];
        int count  = keypad(n,output);
        for(int i=0 ; i< count ;i++){
            cout<<output[i]<<endl;
        }
    }
}