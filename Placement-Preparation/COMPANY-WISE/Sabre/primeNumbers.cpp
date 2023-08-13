#include<iostream>
using namespace std;


bool isPrime(int num)
{
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)return false;
    }
    return true;
}

int main()
{
    int n,k;
    cin>>n>>k;

    int temp=1;

    while(n!=0)
    {
        if(isPrime(temp))
        {
            int lastDigit=temp%10;
            if(lastDigit==k){
                cout<<temp<<" ";
                n--;
            }
        }

        temp++;
    }
    return 0;
}