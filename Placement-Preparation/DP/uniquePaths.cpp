#include<iostream>
using namespace std;

class Solution {
public:
   
   int paths(int i,int j,int m,int n,vector<vector<int>>&dp)
  {
       // base case
       if(i<0 || i>=m)return 0;

       if(j<0 || j>=n)return 0;

       if(i==m-1 && j==n-1)return 1;

      if(dp[i][j]!=-1)return dp[i][j];

     return dp[i][j]=paths(i+1,j,m,n,dp) + paths(i,j+1,m,n,dp);
  }
    int uniquePaths(int m, int n) {
         
         vector<vector<int>>vis(m,vector<int>(n,-1));
         int res=paths(0,0,m,n,vis);

         return res;
    }
};

int main()
{
    
    return 0;
}