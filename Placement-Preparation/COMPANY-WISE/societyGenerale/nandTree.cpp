#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int solve(int h,vector<int>&input)
{
    int temp=h;

    while(temp!=1)
    {
        vector<int>currVec;
        int n=input.size();

        for(int i=0;i<n;i+=2)
        {
            int input1=input[i];
            int input2=input[i+1];

            if(input1==0 || input2==0)
            {
                currVec.push_back(1);
            }
            else{
                currVec.push_back(0);
            }
        }
        input=currVec;
        temp--;
    }

    for(auto it:input)cout<<it<<" ";
    cout<<endl;

    return input[0];
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
         int h;
         cin>>h;
         int noInputs=pow(2,h-1);
         vector<int>input;
         for(int j=0;j<noInputs;j++)
         {
            int a;
            cin>>a;
            input.push_back(a);
         }

         int res=solve(h,input);
         cout<<res<<endl;
    }
    return 0;
}