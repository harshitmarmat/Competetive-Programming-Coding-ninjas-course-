#include<iostream>
using namespace std;


void InsertElement(int * arr , int &index, int capacity , int element){
    if(index>= capacity){
        int newarr[2*capacity];
        for( int i=0 ; i<capacity ;i++){
            newarr[i]=arr[i];
        }
        capacity*=2;
        arr = newarr;
    }
    arr[index]=element;
    index++;
    return;
}

void TraverseArray(int * arr , int &index ){
    for(int i = 0; i<index;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftShift( int *arr , int i ,int z){
    for( ;i<z ;i++){
        arr[i]=arr[i+1];
    }
}

void DeleteElement(int * arr, int &index , int element){
    for(int i=0 ; i<index; i++){
        if( arr[i]==element){
            leftShift(arr, i ,index);
            index--;
            cout<<element<<" Successfully deleted!!"<<endl;
            return;
        }
    }
    cout<<element<<" is not present in the Array"<<endl;
}

void FindElement( int * arr , int index ,int element){
    for( int i=0 ; i<index ; i++){
        if( arr[i]== element ){
            cout<<"Position of "<<element<<" in the array is "<<i<<endl;
            return;
        }
    }
    cout<<element<<" is not present in the Array."<<endl;
}

void SortArray( int * arr , int index){
    for(int i=0 ; i<index ; i++){
        int min = arr[i];
        int minIndex = i;
        for(int j=i+1 ; j<index ; j++ ){
            if( arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i]= min;
        arr[minIndex]= temp;
    }
    cout<<"Sorted Array :";
    for(int i=0 ; i<index ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[100];
    int capacity = 100;
    int index = 0;
    char ch = 'y';
    int element;
    while(ch=='y'){
        cout<<"Menu"<<endl;
        cout<<"1. Insert the Element in the Array."<<endl;
        cout<<"2. Delete the Element from the Array."<<endl;
        cout<<"3. Traverse the Array."<<endl;
        cout<<"4. Find the element (linear search)."<<endl;
        cout<<"5. Sort the Array (Selection sort)."<<endl;
        
        int check;
        cout<<"Choose the option : ";
        cin>>check;
        switch(check){
            case 1 : cout<<"Enter the element : ";
                     cin>>element;
                     InsertElement( arr , index , capacity , element);
                     break;

            case 2 : cout<<"Enter the element that you want to delete : ";
                     cin>>element;   
                     DeleteElement( arr , index , element);
                     break;

            case 3 :cout<<"Array : "; 
                    TraverseArray(arr,index);
                    break;

            case 4 : cout<<"Enter the element of which you want to find the position : ";
                     cin>>element;
                     FindElement(arr,index , element);
                     break;

            case 5 : SortArray(arr , index);
                    break;

            default : cout<<"Invalid option!!"<<endl;       
        }
        cout<<"Do you want to continue?"<<endl;
        cout<<"press (y/n) : ";
        cin>>ch;
    }
}