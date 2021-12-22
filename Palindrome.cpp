#include<iostream> 
using namespace std;
// #include<string>

bool finalPalindrome(char * input,int si, int ei){
    if(si>=ei){
        return true;
    }
    if(input[si]==input[ei]){
        return finalPalindrome(input ,si+1, ei-1);
        // cout<<input<<endl;
    }
    
    return false;
}

bool checkPalindrome( char * input){
    if(input[0]=='\0')
    // int size=0;
    // for(int i=0 ;input[i]!='\0';i++){
    //     size++;
    // }

    // return finalPalindrome(input,0,size-1);
}

int main(){
    char * input =new char[100]; 
    cin>>input;
    // cout<<input;
    if(checkPalindrome(input)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
}