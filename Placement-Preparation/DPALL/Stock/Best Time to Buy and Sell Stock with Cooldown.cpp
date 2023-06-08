#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int solve(vector<int>&prices,int i,vector<int>&dp)
  {
      // base case
      int n=prices.size();

      if(i>=n)return 0;

      if(dp[i]!=-1)return dp[i];
      
      int buyPrice=prices[i];

      int maxProfit=0;

      for(int j=i+1;j<n;j++)
      {
          int sellPrice=prices[j];

          maxProfit=max(maxProfit,max((sellPrice-buyPrice)+solve(prices,j+2,dp),solve(prices,i+1,dp)));
      }
     return dp[i]=maxProfit;
  }

    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        vector<int>dp(n+1,-1);

        int res=solve(prices,0,dp);

        if(res<=0)return 0;

        return res;

    }
};

int main()
{
    
    return 0;
}