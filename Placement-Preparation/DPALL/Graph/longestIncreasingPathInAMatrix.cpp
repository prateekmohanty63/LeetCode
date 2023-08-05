#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// T(N)=O(n*m)
// S(N)=)(n*m)

class Solution {
public:
    int solve(vector<vector<int>>&mat,int x,int y,int prevVal,vector<vector<int>>&dp)
    {
        // base case
        int n=mat.size();
        int m=mat[0].size();

        if(x<0 || x>=n)return 0;

        if(y<0 || y>=m)return 0;

        if(dp[x][y]!=-1)return dp[x][y];

        int currVal=mat[x][y];

        int left=0;
        int right=0;
        int up=0;
        int down=0;

        if(y-1>=0 && mat[x][y-1]>currVal)
        left=1+solve(mat,x,y-1,currVal,dp);

        if(y+1<m && mat[x][y+1]>currVal)
        right=1+solve(mat,x,y+1,currVal,dp);

        if(x-1>=0 && mat[x-1][y]>currVal)
        up=1+solve(mat,x-1,y,currVal,dp);

        if(x+1<n && mat[x+1][y]>currVal)
        down=1+solve(mat,x+1,y,currVal,dp);

        return dp[x][y]=max({left,right,up,down});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int res=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=max(res,solve(matrix,i,j,matrix[i][j],dp));
            }
        }
        return res+1;
    }
};

int main()
{
    
    return 0;
}