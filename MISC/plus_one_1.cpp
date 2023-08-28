#include<iostream>

using namespace std;


int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int count=0;
    if(arr[n-1]<9)
        arr[n-1]++;

    else if(arr[n-1]==9)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==9)
            {
                arr[i]=0;
                count++;
            }
            else
                break;
        }
    }

    if(count==n)


}
