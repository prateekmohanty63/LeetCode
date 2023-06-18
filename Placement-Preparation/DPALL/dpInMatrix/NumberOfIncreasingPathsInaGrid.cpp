#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    vector<int> dirs={0,1,0,-1,0};
    
    long solve(vector<vector<int>>&grid,int x,int y,vector<vector<long>>&dp)
    {
       int n=grid.size();
       int m=grid[0].size();

       long result=1;

       if(dp[x][y]!=-1)return dp[x][y];

       for(int d=0;d<4;d++)
       {
           int i=x+dirs[d];
           int j=y+dirs[d+1];

           if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]>grid[x][y])
           result=(result+solve(grid,i,j,dp))%mod;
       }
       return dp[x][y]=result%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

       vector<vector<long>>dp(n+1,vector<long>(m+1,-1));
      
        long res=0;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        res+=solve(grid,i,j,dp)%mod;
         }
        }
        return res%mod;
    }
};

int main()
{
    
    return 0;
}