#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int arr[] = {3,2,7,6,5,8,5};
    // sort(arr,arr+7);
    cout<<binary_search(arr,arr+7,2)<<endl;
    cout<<lower_bound(arr,arr+7,3)-arr;
    cout<<upper_bound(arr,arr+7,3)-arr;
    
}