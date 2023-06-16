#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    long long solve(int n,int m,int maxMove,int x,int y,vector<vector<vector<long long>>>&dp)
    {
        // base case
        if(x<0 || x>=n)return 1;

        if(y<0 || y>=m)return 1;

        if(maxMove==0)return 0;

        if(dp[x][y][maxMove]!=-1)return dp[x][y][maxMove];

        long long left=(long long)solve(n,m,maxMove-1,x,y-1,dp)%mod;
        long long right=(long long)solve(n,m,maxMove-1,x,y+1,dp)%mod;
        long long up=(long long)solve(n,m,maxMove-1,x-1,y,dp)%mod;
        long long down=(long long)solve(n,m,maxMove-1,x+1,y,dp)%mod;

        return dp[x][y][maxMove]=(long long)(left+right+up+down)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<long long>>>dp(m+1,vector<vector<long long>>(n+1,vector<long long>(maxMove+1,-1)));
        long long res=solve(m,n,maxMove,startRow,startColumn,dp);

        return res%mod;
    }
};

int main()
{
    
    return 0;
}