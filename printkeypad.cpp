#include<iostream>
using namespace std;

void printkey( int num ,string * input, string output){
    if(num <= 0){
        cout<<output<<endl;
        return ;
    }
    string curr = input[num%10];
    for( int i=0 ; i<curr.size(); i++){
        printkey(num/10,input,curr[i]+output);
    }
}

void print(int num){
    string input [] = {"", "", "abc" , "def","ghi","jkl","mno","pqrs" , "tuv","wxyz"};
    string output;
    printkey(num,input,output);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        print(n);
    }
}