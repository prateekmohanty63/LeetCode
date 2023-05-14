#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int maxMoves1(vector<vector<int>>&grid,int i,int j,int prevVal,vector<vector<int>>&dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || i>=n)return 0;
        
        if(j<0 || j>=m)return 0;
        
        if(grid[i][j]<=prevVal)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int a=grid[i][j];
        
        return dp[i][j]=max(1+maxMoves1(grid,i-1,j+1,a,dp),max(1+maxMoves1(grid,i,j+1,a,dp),1+maxMoves1(grid,i+1,j+1,a,dp)));
        
        
        
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int maximMoves=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        int  prevVal=-1;
        for(int i=0;i<m;i++)
        {
            maximMoves=max(maximMoves,maxMoves1(grid,i,0,prevVal,dp));
        }
        //cout<<maximMoves;
        
        return maximMoves-1;
    }
};

int main()
{
    
    return 0;
}