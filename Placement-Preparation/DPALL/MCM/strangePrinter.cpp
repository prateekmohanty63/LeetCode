#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int n;

    int solve(int l,int r,string &s,vector<vector<int>>&dp)
    {
        if(l==r)return 1;

        if(l>r)return 0;

        if(dp[l][r]!=-1)return dp[l][r];

        int i=l+1;

        while(i<=r && s[i]==s[l])i++;

         // all characters are same
        if(i==r+1)return 1;

       // basic approach
        int basic=1+solve(i,r,s,dp);

        int lalach=INT_MAX;
        
        // lalach approach where we are printing all the 
        // elements matching the current starting elements together
        for(int j=i;j<=r;j++)
        {
            if(s[j]==s[l])
            {
                int ans=solve(i,j-1,s,dp)+solve(j,r,s,dp);
                lalach=min(lalach,ans);
            }
        }
        return dp[l][r]=min(basic,lalach);
    }
    int strangePrinter(string s) {
         n=s.length();
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         return solve(0,n-1,s,dp);        
    }
};

int main()
{
    
    return 0;
}