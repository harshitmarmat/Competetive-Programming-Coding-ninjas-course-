#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    double  val1 = (double)(p1.first)/(p1.second);
    double  val2 = (double)(p2.first)/(p2.second) ;
    return val1 > val2;
}

int main(){
    int n; 
    cin>>n ;
    int weight;
    cin>>weight;
    pair<int ,int >  * input = new pair<int, int > [n];

    for (int i=0 ; i< n ;i++){
        int start;
        int end ; 
        cin>>start>>end;
        pair<int,int> p; 
        p.first = start;
        p.second = end;
    }
    sort(input, input+n, compare);
    int tillWeight = 0;
    double finalValue = 0;
    for(int i=0 ;i< n ;i++){
        if(tillWeight+input[i].second<=weight){
            tillWeight+=input[i].second;
            finalValue += input[i].first;
            continue;
        }
        int remaining = weight-tillWeight;
        finalValue += ((double)remaining/input[i].second)*input[i].first;
        break;
    }
    cout<<finalValue<<endl;
}