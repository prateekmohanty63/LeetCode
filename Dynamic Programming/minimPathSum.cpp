#include<iostream>
#include<vector>
using namespace std;

// tabulation method

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else{
                    int a=10e7;
                    int b=10e7;

                    if(i>0)
                    a=dp[i-1][j];

                    if(j>0)b=dp[i][j-1];

                    dp[i][j]=grid[i][j]+min(a,b);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// memoization solution 

class Solution {
public:
   
   int minSum(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
   {
       // base case

       if(i>=grid.size())return 1e8;

       if(j>=grid[0].size())return 1e8;

       if(i==grid.size()-1 && j==grid[0].size()-1)return grid[i][j];
      
      if(dp[i][j]!=-1)return dp[i][j];

      

       // minimum of move down or right

      return dp[i][j]=grid[i][j]+min(minSum(grid,i+1,j,dp),minSum(grid,i,j+1,dp));
   }

    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();   
       vector<vector<int>>dp(n,vector<int>(m,-1));
     
        cout<<n<<" "<<m;
        int res=minSum(grid,0,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}