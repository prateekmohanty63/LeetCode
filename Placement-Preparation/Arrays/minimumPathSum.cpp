#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
   
   long long minPathCost(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
   {
       // base case

       int n=grid.size();
       int m=grid[0].size();


       if(dp[i][j]!=-1)return dp[i][j];

       if(i==n-1 && j==m-1)return grid[i][j];



       if(i<0 || i>=n)return INT_MAX;

       if(j<0 || j>=m)return INT_MAX;

       return dp[i][j]=min(grid[i][j]+minPathCost(grid,i+1,j,dp),grid[i][j]+minPathCost(grid,i,j+1,dp));
   }

    int minPathSum(vector<vector<int>>& grid) {
         
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         return minPathCost(grid,0,0,dp);
    }
};

int main()
{
    
    return 0;
}