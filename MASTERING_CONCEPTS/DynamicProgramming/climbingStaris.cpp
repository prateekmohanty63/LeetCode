#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int climbWays(int n,vector<int>&dp)
   {
       // base case

       if(n==0)return 1;

       if(n<0)return 0;

       if(dp[n]!=-1)return dp[n];

       return dp[n]=climbWays(n-1,dp)+climbWays(n-2,dp);
   }

    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        int res=climbWays(n,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}