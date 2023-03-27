#include<iostream>
#include<vector>
using namespace std;


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