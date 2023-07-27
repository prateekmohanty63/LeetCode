#include<iostream>
#include<climits>

using namespace std;

int solve(string a)
{
    int countW=0;
    int countM=0;
    int maxim=INT_MIN;

    for(int i=0;i<a.length();i++)
    {
        while(i<a.length() && a[i]=='W')
        {
            countW++;
            i++;
        }

        while(i<a.length() && a[i]=='M')
        {
            countM++;
            i++;
        }

        if(countM>=countW)
        {
            maxim=max(maxim,countW);
        }
        countM=0;
        countW=0;

        i--;
    }
    return maxim*2;
}

int main()
{
    int r;
    cin>>r;

    for(int i=0;i<r;i++)
    {
        string a;
        cin>>a;
        int res=solve(a);
        if(res==0)cout<<-1;
        else cout<<res;
    }
    return 0;
}