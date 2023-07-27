#include<iostream>
using namespace std;

int digitSum(int range,int k)
{
    int res=0;

    for(int i=1;i<=range;i++)
    {
        int temp=i;
        int count=0;

        while(temp>0)
        {
            count+=temp%10;
            temp/=10;
        }

        if(count==k){
            cout<<i<<" ";
            res++;
        }
    }
    return res;
}

int main()
{
    int res=digitSum(123,6);
    cout<<res;
    return 0;
}