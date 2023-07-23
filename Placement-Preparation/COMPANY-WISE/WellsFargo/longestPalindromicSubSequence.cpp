#include<iostream>
#include<vector>
using namespace std;


class Solution{
  public:
    
    int solve(string A,int start,int end,vector<vector<int>>&dp)
    {
        // base case
        if(start==end)return 1;
        
        if(start>end)return 0;
        
        if(dp[start][end]!=-1)return dp[start][end];
        
        if(A[start]==A[end])
        {
            return dp[start][end]=2+solve(A,start+1,end-1,dp);
        }
        else{
            // we have the option of either moving start ahead or moving end backwards
            return dp[start][end]=max(solve(A,start+1,end,dp),solve(A,start,end-1,dp));
        }
    }
    int longestPalinSubseq(string A) {
        //code here
      
        int n=A.length();
          vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int res=solve(A,0,n-1,dp);
        
        return res;
    }
};

int main()
{
    
    return 0;
}