#include<bits/stdc++.h>
using namespace std;

class dsu{

    unordered_map<int, dsu *> map;

    dsu * searchInSetHelper(dsu * node){
        // dsu * node = map[data];

        while(node->parent!= node){
            node = node->parent;
        }
        node->parent = node;
        return node->parent;
    }

    public:
        int data ;
        int rank;
        dsu * parent;

        void initialLise(int data){
            dsu * node = new dsu();
            node->data =data;
            node->rank = 0;
            node->parent = node;
            map[data] = node;
        }

        void unionSet(int data1 , int data2){
            dsu *  parent1 = searchInSetHelper(map[data1]);
            dsu *  parent2 = searchInSetHelper(map[data2]);
            if(parent1->rank>=parent2->rank){
                if(parent1->rank == parent2->rank){
                    parent1->rank = parent1->rank+1;
                }
                parent2->parent  = parent1; 
            }
            else{
                parent1->parent = parent2;
            }
        }

        int searchInSet(int data){
            return searchInSetHelper(map[data])->data;
        }
};

int main(){
    dsu ds;
    ds.initialLise(0);
    ds.initialLise(2);
    ds.initialLise(3);
    ds.initialLise(4);
    ds.initialLise(5);
    ds.initialLise(6);
    ds.initialLise(1);

    ds.unionSet(0,1);
    ds.unionSet(1,2);
    ds.unionSet(5,4);
    ds.unionSet(3,5);
    ds.unionSet(2,6);
    ds.unionSet(6,5);

    cout<<ds.searchInSet(1)<<endl;
    cout<<ds.searchInSet(3)<<endl;
    cout<<ds.searchInSet(2)<<endl;
    cout<<ds.searchInSet(4)<<endl;
    cout<<ds.searchInSet(5)<<endl;
    cout<<ds.searchInSet(6)<<endl;
}