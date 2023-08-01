#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int solve(int k,vector<int>&prices,int ind,int flag,vector<vector<vector<int>>>&dp)
    {
        // base case
        if(k==0)return 0;

        int n=prices.size();

        if(ind>=n)return 0;

        if(dp[ind][k][flag]!=-1)return dp[ind][k][flag];

        if(flag==0)
        {
            // we have not bought till now , first we have to buy before selling
            // we have the option of buying or not buying the current stock

            return dp[ind][k][flag]=max(-prices[ind]+solve(k,prices,ind+1,1,dp),solve(k,prices,ind+1,0,dp));
        }
        else{
            // we have bought a stock , we have to sell the stock before buying again
            // we have the option to sell the stock now or later 
            return dp[ind][k][flag]=max(prices[ind]+solve(k-1,prices,ind+1,0,dp),solve(k,prices,ind+1,1,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
          
          int n=prices.size();
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
          int res=solve(k,prices,0,0,dp);

          return res;
    }
};

int main()
{
    
    return 0;
}