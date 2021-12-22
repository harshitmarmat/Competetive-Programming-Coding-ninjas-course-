#include<iostream>
using namespace std;
#include"fraction.h"

int main (){
    fraction f1(9,3);
    f1.display();
    fraction f2(10,2);
    f2.display();
    fraction f3 = f1 + f2;
    f3.display();
    fraction f4 = f1 * f2; 
    f4.display();
    fraction f5 = ++(++f1);
    f5.display();
    f1.display();
    fraction f6= f1++;
    f6.display();
    f1.display();
    f2.display();
    (f1+=f2)+=f2;
    f1.display();

}