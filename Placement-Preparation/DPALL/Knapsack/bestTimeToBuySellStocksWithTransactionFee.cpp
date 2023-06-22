#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   int solve(vector<int>&prices,int index,int &fee,int buy,vector<vector<int>>&dp)
   {
       // base case
       int n=prices.size();

       if(index>=n)return 0;

       if(dp[index][buy]!=-1)return dp[index][buy];

       if(buy==0)
       {
          // we have not bought , we have the option of buying
          // either we will buy or we will not buy

          return dp[index][buy]=max(-prices[index]+solve(prices,index+1,fee,1,dp),solve(prices,index+1,fee,0,dp));
       }
       else{
          // we already have a stock , hence we need to sell before buying
          return dp[index][buy]=max((prices[index]-fee)+solve(prices,index+1,fee,0,dp),solve(prices,index+1,fee,1,dp));
       }
   }
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans=solve(prices,0,fee,0,dp);

        return ans;
    }
};

int main()
{
    
    return 0;
}