#include<iostream>
using namespace std;
#define PI 3.14


class Student{
    public:
    int rollno;
    int age;
    char *name;

    Student(int r ,int a , char * n){
        rollno = r;
        age = a;
        name = n;
    }

    void display(){
        cout<< rollno<<" "<<age<<" "<<name<<endl;
    }
};

int main(){
    char name[] = "abcn";
    Student s1(10,100,name);
    s1.display();
    Student s2(20 ,9,name);
    s2=s1;
    s2.display();
    s2.name[2] = 'z';
    s1.display();
    s2.display();

}