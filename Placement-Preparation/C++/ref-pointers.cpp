#include<iostream>
using namespace std;

int main()
{
    // References

    // this is a reference to original variable
    // so any change to reference variable will also change the original variable
    int original_variable=10;
    int &ref_variable=original_variable;
    cout<<ref_variable<<endl;

    // here we see the original variable has also changed 
    ref_variable=20;
    cout<<ref_variable<<" "<<original_variable<<endl;

    
    // Pointers
    int var=10;
    int *ptr=&var;

    cout<<"value at ptr: "<<ptr<<endl;
    cout<<"Value at *ptr: "<<*ptr<<endl;


    return 0;
}