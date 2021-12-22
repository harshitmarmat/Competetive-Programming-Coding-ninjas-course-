#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //Vector
    /*
       vector<int> v;
    for( int i=0; i< 5 ; i++){
        v.push_back(i+1);
    }
    vector<int>:: iterator it;
    for( it = v.begin(); it!=v.end() ; it++){
        cout<<*it<<endl;
    }
    for(int i=0 ; i<v.size(); i++){
        cout<<v[i]<<endl;
    }*/

    //string
    /*
    string s = "Harshit ";
    cout<<s<<endl;
    cout<<s.length()<<endl;
    string s2(s);
    cout<<s<<endl;
    cout<<s2<<endl;
    s[2]='f';
    cout<<s<<endl;
    cout<<s2<<endl;
    cout<<*(&s)<<endl;
    cout<<&s2<<endl;

    s=s.substr(2,9);
    cout<<s<<endl;
    */
    
    //Pair
    /*
    pair<int,char> p(1,'b');
    cout<<p.first<<" "<<p.second<<endl;
    pair<int,string> p1;
    p1.first = 2;
    p1.second = "Harshit";
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,char> p2;
    p2 = make_pair(32,97);
    cout<<p2.first<<" "<<p2.second<<endl;
    pair<int,pair<int,string>> p3(4,p1);
    cout<<p3.first<<" "<<p3.second.second<<endl;
    */
   //set
   /*
   set<int> s;
   int arr[]= {97,1000,100,99,98,96,95,94,2};
   for( int i=0 ; i<9 ; i++){
       s.insert(arr[i]);
   }

   set<int> :: iterator it;
   for( it = s.begin(); it!= s.end(); it++){
       cout<<*it<<endl;
   }

    int count =0;
//    cout<<s.find(99)<<endl;
   if(s.find(99)!=s.end()){
       count++;
       cout<<"yes"<<" "<<count<<endl;
   }
   */

  //map

//   map<int,int> m;

//   int arr[] = {2,3,1,5,2,1,4};

//   for(int i=0 ; i<7 ; i++){
//       m[arr[i]]++;
//   }

//   map<int,int> :: iterator it;

//   for( it = m.begin(); it!=m.end() ; it++){
//       cout<<it->first<<" : "<<it->second<<endl;
//   }
//     m.erase(2);

//     for( it = m.begin(); it!=m.end() ; it++){
//       cout<<it->first<<" : "<<it->second<<endl;
//   }

    //unordered_map

      unordered_map<int,int> m;

  int arr[] = {2,3,1,5,2,1,4};

  for(int i=0 ; i<7 ; i++){
      m[arr[i]]++;
  }

  unordered_map<int,int> :: iterator it;

  for( it = m.begin(); it!=m.end() ; it++){
      cout<<it->first<<" : "<<it->second<<endl;
  }
    m.erase(2);

    for( it = m.begin(); it!=m.end() ; it++){
      cout<<it->first<<" : "<<it->second<<endl;
  }



}