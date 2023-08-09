#include<iostream>
#include<vector>
using namespace std;


int solve(int n,vector<int>&vec)
{
      int firstHalf0s=0;
      int firstHalf1s=0;

      int secondHalf0s=0;
      int secondHalf1s=0;

    if(n%2==0)
    {
     
       for(int i=0;i<=(n/2)-1;i++)
       {
         if(vec[i]==0)firstHalf0s++;

         else firstHalf1s++;
       }
       for(int i=n/2;i<n;i++)
       {
         if(vec[i]==0)secondHalf0s++;
         else secondHalf1s++;
       }
    }
    else{
         for(int i=0;i<(n/2);i++)
         {
             if(vec[i]==0)firstHalf0s++;

            else firstHalf1s++;
         }
         for(int i=(n/2);i<n;i++)
         {
            if(vec[i]==0)secondHalf0s++;
           else secondHalf1s++;
         }
    }

    if(firstHalf0s==0)return 0;
    if(firstHalf1s==0)return 0;

    if(secondHalf0s==0)return 0;
    if(secondHalf1s==0)return 0;
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

            solve(n,vec);
        }

    }
    return 0;
}