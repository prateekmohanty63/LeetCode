#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>&obstacle,int i,int j,vector<vector<int>>&dp)
    {
        // base case

        int n=obstacle.size();
        int m=obstacle[0].size();

        if(obstacle[n-1][m-1]==1 || obstacle[0][0]==1)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(i==n-1 && j==m-1)return 1;

        if(i<0 || j<0)return 0;

        if(i>n || j>m)return 0;

        int right,down;

      // move right
        if(j+1<m && obstacle[i][j+1]!=1)
        {
            right=uniquePaths(obstacle,i,j+1,dp);
        }
        else right=0;

        if(i+1<n && obstacle[i+1][j]!=1)
        {
            down=uniquePaths(obstacle,i+1,j,dp);
        }
        else down=0;

        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=uniquePaths(obstacleGrid,0,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}