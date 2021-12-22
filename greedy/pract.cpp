#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>

int tripletSum(int *arr, int n, int sum)
{
    int count = 0;
    sort(arr, arr+n);
    cout<<"Sorted array : ";
    for(int i=0 ; i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl<<endl;
    for(int i = 0; i < n; i++) {  
        cout<<"for i:"<<i<<endl<<endl;
        int start = i+1;
        int end = n-1;
        int val = sum - arr[i];
        while(start < end) {
            cout<<"firstIndex(element) : "<<i<<"("<<arr[i]<<")"<<"\t SecondIndex(element) :"<<start<<"("<<arr[start]<<")"<<"\tThirdIndex(Element): "<<end<<"("<<arr[end]<<")"<<endl;
            if(arr[start] + arr[end] == val) {
                cout<<endl;
                cout<<"We found a triplet : "<<i<<"("<<arr[i]<<")"<<" "<<start<<"("<<arr[start]<<")"<<" "<<end<<"("<<arr[end]<<")"<<" "<<endl;
                int start_element = arr[start];
                int end_element = arr[end];
                if(start_element == end_element) {							//for all duplicate shortcut
                    int total_elements = (end - start + 1);
                    count += ((total_elements * (total_elements - 1)) / 2);
                    cout<<"We found all duplicate Element from "<< start<<" to "<<end<<"(index number) So count updated to "<<count<<"(See shortcut comment in code line 22)"<<endl;
                    break;
                }
                else {
                     int temp_start = start+1, temp_end = end-1;
                    bool check = true;
                     while(temp_start <= temp_end && arr[temp_start] == start_element) {
                         if(check==true){
                             cout<<"We found same consecutive number from index "<<start<<" to ";
                             check=false;
                         }
                        temp_start++;
                    }
                    if(!check){
                        cout<<temp_start-1<<endl;
                    }
                    bool checked= true;
                    while(temp_start <= temp_end && arr[temp_end] == end_element) {
                        if(checked==true){
                            cout<<"We found same consecutive number from index "<<end<<" to ";
                            checked=false;
                         }
                        temp_end--;
                    }
                    if(!checked){
                        cout<<temp_end+1<<endl;
                    }
                    cout<<"We used the formula for duplicate element till some places(see 57 of code)"<<endl;

                    int total_ele_start = temp_start - start;
                    int total_ele_end = end - temp_end;

                    count += (total_ele_start * total_ele_end);
				
                    start = temp_start;
                    end = temp_end;
                    cout<<"count updated :"<<count<<endl;
                }
            } 
            else if(arr[start] + arr[end] < val) {
                cout<<i<<" "<<start<<" "<<end<<" "<<"Sum of Element corresponding to these index is "<<arr[start] + arr[end]+arr[i]<<" smaller than the "<<sum<<" So increase the SecondIndex"<<endl;
                start++;
            }
            else {
                cout<<i<<" "<<start<<" "<<end<<" "<<"Sum of Element corresponding to these index is "<<arr[start] + arr[end]+arr[i]<<" greater than the "<<sum<<" So reduce the thirdIndex"<<endl;
                end--;
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}