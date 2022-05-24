#include<iostream>
#include<vector>
using namespace std;

// 1st approach
// this solution gives TLE ( time limited exceeded)

class Solution {
public:
    
    int recur(int m,int n,int i,int j)
    {
        if(i==m || j==n)return 0;
        
        if(i==m-1 && j==n-1)return 1;
        
        // move right
        
        int right=recur(m,n,i,j+1);
        int down=recur(m,n,i+1,j);
        
        return right+down;
    }
    int uniquePaths(int m, int n) {
        
        return recur(m,n,0,0);
    }
};

// 2nd approach
// using dynamic programming (memoization)

//Runtime: 3 ms, faster than 39.81% of C++ online submissions for Unique Paths.
//Memory Usage: 6.5 MB, less than 44.66% of C++ online submissions for Unique Paths.

class Solution {
public:
    
    int recur(int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i==m || j==n)return 0;
        
        if(i==m-1 && j==n-1)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        // move right
        
        int right=recur(m,n,i,j+1,dp);
        int down=recur(m,n,i+1,j,dp);
        
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recur(m,n,0,0,dp);
    }
};

// tabulation method
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6.5 MB, less than 44.66% of C++ online submissions for Unique Paths.
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        
        // make the last column and last row as 1 , as we only have 1 option of going from there
        
        for(int i=0;i<m;i++)
        {
            dp[i][n-1]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            dp[m-1][i]=1;
        }
        
        // now our result at each point would be sum of left and right directions
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};

int main()
{
    
    return 0;
}