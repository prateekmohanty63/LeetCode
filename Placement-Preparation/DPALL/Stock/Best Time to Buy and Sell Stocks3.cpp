#include<iostream>
#include<vector>
using namespace std;


// TLE 
// T(N)=O(N^2)
class Solution {
public:
    
    int maxSell(vector<int>&prices,int i,int transLeft,vector<vector<int>>&dp)
    {
        // base case
        int n=prices.size();

        if(i>=n)return 0;

        if(transLeft==0)return 0;

        if(dp[i][transLeft]!=-1)return dp[i][transLeft];

        int maxProfit=0;

        int buyPrice=prices[i];

        for(int j=i+1;j<n;j++){
            int sellPrice=prices[j];

            maxProfit=max(maxProfit,sellPrice-buyPrice+maxSell(prices,j+1,transLeft-1,dp));
        }
        maxProfit=max(maxProfit,maxSell(prices,i+1,transLeft,dp));
        return dp[i][transLeft]=maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(3,-1));

        int res=maxSell(prices,0,2,dp);

        return res;
    }
};

class Solution {
public:
    
    int maxSell(vector<int>&prices,int i,int transLeft)
    {
        // base case
        int n=prices.size();

        if(i>=n)return 0;

        if(transLeft==0)return 0;

        int maxProfit=0;

        int buyPrice=prices[i];

        for(int j=i+1;j<n;j++){
            int sellPrice=prices[j];

            maxProfit=max(maxProfit,sellPrice-buyPrice+maxSell(prices,j+1,transLeft-1));
        }
        maxProfit=max(maxProfit,maxSell(prices,i+1,transLeft));
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        int res=maxSell(prices,0,2);

        return res;
    }
};

int main()
{
    
    return 0;
}