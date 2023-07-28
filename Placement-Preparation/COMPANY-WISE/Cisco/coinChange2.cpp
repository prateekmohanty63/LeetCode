#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solve(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp)
    {
        // base case
        int n=coins.size();
        if(amount==0)return 1;

        if(ind>=n)return 0;

        if(dp[ind][amount]!=-1)return dp[ind][amount];

        if(coins[ind]<=amount)
        return dp[ind][amount]=solve(amount-coins[ind],coins,ind,dp)+solve(amount,coins,ind+1,dp);


        else return dp[ind][amount]=solve(amount,coins,ind+1,dp);
    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(5001,-1));
        int res=solve(amount,coins,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}