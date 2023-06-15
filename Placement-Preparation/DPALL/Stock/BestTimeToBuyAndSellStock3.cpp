#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int solve(vector<int>&prices,int index,int buy,int transLeft,vector<vector<vector<int>>>&dp)
    {
        // base case
        int n=prices.size();

        if(index>=n)return 0;

        if(transLeft==0)return 0;

        if(dp[index][buy][transLeft]!=-1)return dp[index][buy][transLeft];

        if(buy==1){
            // we have the option of buying the stock 
            // or not buying it
            int buyPrice=prices[index];

            return dp[index][buy][transLeft]=max(-buyPrice+solve(prices,index+1,0,transLeft,dp),solve(prices,index+1,1,transLeft,dp));
        }
        else{
            // we have to sell before buying

            int sellPrice=prices[index];

            return dp[index][buy][transLeft]=max(sellPrice+solve(prices,index+1,1,transLeft-1,dp),solve(prices,index+1,0,transLeft,dp));
        }
    }
     
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
   // vector<vector<vector<int> > > v(2, vector<vector<int> >(3, vector<int>(4)));
 
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        int res=solve(prices,0,1,2,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}