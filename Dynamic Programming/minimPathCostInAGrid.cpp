#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    
    int minSum(vector<vector<int>>&grid,vector<vector<int>>&moveCost,int i,int j,vector<vector<int>>&dp)
    {
        // base case

        int n=grid.size();
        int m=grid[0].size();

        if(i>=n)return 10e7;

        if(j>=m)return 10e7;

        if(i==n-1)return grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int minim=INT_MAX;

        for(int k=0;k<grid[0].size();k++)
        {
            minim=min(minim,grid[i][j]+moveCost[grid[i][j]][k]+minSum(grid,moveCost,i+1,k,dp));
        }
        return dp[i][j]=minim;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int res=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<grid[0].size();i++){
             
        res=min(res,minSum(grid,moveCost,0,i,dp));
        }

        return res;
    }
};

int main()
{
    
    return 0;
}