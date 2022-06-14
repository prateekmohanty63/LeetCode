#include<iostream>
#include<vector>
using namespace std;

// Runtime: 7 ms, faster than 75.60% of C++ online submissions for Triangle.
// Memory Usage: 9.1 MB, less than 26.05% of C++ online submissions for Triangle.

// memoization
// note that here we are using O(N^2) space complexity

class Solution {
public:
    int minSum(vector<vector<int>>&triangle,int row,int col,int n,vector<vector<int>>&dp)
    {
       // base case
        
        if(row==n-1)return triangle[row][col];
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int sameRow=triangle[row][col]+minSum(triangle,row+1,col,n,dp);
        int nextRow=triangle[row][col]+minSum(triangle,row+1,col+1,n,dp);
        
        return dp[row][col]=min(sameRow,nextRow);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int res=minSum(triangle,0,0,n,dp);
        
        return res;
        
    }
};

// NOTE RECURSION GIVES TLE


class Solution {
public:
    int minSum(vector<vector<int>>&triangle,int row,int col,int n)
    {
       // base case
        
        if(row==n-1)return triangle[row][col];
        
        int sameRow=triangle[row][col]+minSum(triangle,row+1,col,n);
        int nextRow=triangle[row][col]+minSum(triangle,row+1,col+1,n);
        
        return min(sameRow,nextRow);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int res=minSum(triangle,0,0,n);
        
        return res;
    }
};

int main()
{
    
    return 0;
}