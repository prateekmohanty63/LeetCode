#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long solve(int n,vector<int>&vec,int i,vector<vector<int>>&dp)
    {
        // base case
        if(n==0)return 0;

        if(i>=vec.size())return INT_MAX;

        if(dp[n][i]!=-1)return dp[n][i];

      
        if(vec[i]<=n)
        {
            // we have the option of taking 
            // or not taking the element
            return dp[n][i]=min(1+solve(n-vec[i],vec,i,dp),solve(n,vec,i+1,dp));
        }
        else return dp[n][i]=solve(n,vec,i+1,dp);

    }

    int numSquares(int n) {
        
        int a=sqrt(n);
        
        vector<int>vec;
       

        for(int i=1;i<=a;i++)
        vec.push_back(i*i);

        int m=vec.size();

         vector<vector<int>>dp(n+1,vector<int>(m,-1));

        long long res=solve(n,vec,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}