#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>&vec)
{
    int noOnes=0;
    int noZeros=0;

    for(auto it:vec)
    {
        if(it==0)noZeros++;
        else noOnes++;
    }

    // we either put 1s on fiirst 
    // or we put 0s first 

    int startOnes=0;
    int endOnes=0;

    for(int i=0;i<noOnes;i++)
    {
        if(vec[i]==1)startOnes++;
    }  
    int k=n-1;
    int count=0;
    while(count!=noOnes)
    {
        if(vec[k]==1)endOnes++;
        count++;
        k--;
    }

    int res=min(noOnes-startOnes,noOnes-endOnes);

    return res;
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>vec;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
        }
        int res=solve(n,vec);
        cout<<res<<endl;
    }
    return 0;
}