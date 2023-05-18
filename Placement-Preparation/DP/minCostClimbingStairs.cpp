#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int minCost(vector<int>&cost,int i,vector<int>&dp)
   {
       // base case
       if(i==cost.size())return 0;

       if(i>cost.size())return 1000;
       
       if(dp[i]!=-1)return dp[i];

       return dp[i]=min(cost[i]+minCost(cost,i+2,dp),cost[i]+minCost(cost,i+1,dp));
   }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        vector<int>dp1(cost.size()+1,-1);
        
        
        vector<int>dp(n+2);       
        
        dp[n]=dp[n+1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
      //  return min(dp[0],dp[1]);

      return min(minCost(cost,0,dp1),minCost(cost,1,dp1));
    }
};

int main()
{
    
    return 0;
}