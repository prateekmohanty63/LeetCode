#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

bool isPrime(int num)
{
    for(int i=2;i<=(num/2);i++)
    {
        if(num%i==0)return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    sort(vec.begin(),vec.end());

    int maxim=INT_MIN;

    for(int i=n-1;i>=0;i--)
    {
        if(vec[i]==0)
        {
            maxim=max(maxim,0);
            continue;
        }
        for(int j=n-1;j>=0;j--)
        {
            if(vec[i]%vec[j]==0)
            {
                if(isPrime(vec[j]))
                maxim=max(maxim,vec[j]);
            }
        }
    }

    cout<<maxim;
    
    return 0;
}