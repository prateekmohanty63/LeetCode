#include<iostream>
using namespace std;

int main()
{
    // malloc 

    int var_len=10;

    int *ptr;

    // allocating memory to the pointer using malloc()
    ptr=(int*)malloc(sizeof(int)*var_len);
    
    for(int i=0;i<var_len;i++)
    cout<<*(ptr+i);

    cout<<endl;

    float *r=new float(75.25);
    cout<<*r;

    return 0;
}