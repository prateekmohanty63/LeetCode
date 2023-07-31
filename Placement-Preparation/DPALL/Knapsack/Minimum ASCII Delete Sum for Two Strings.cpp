#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {
        // base case
        int n=s1.length();
        int m=s2.length();

        if(i>=n && j>=m)return 0;


        if(i>=n)
        {
            int sum=0;
            while(j<m)
            {
                sum+=(int)s2[j];
                j++;
            }
            return sum;
        }

        if(j>=m)
        {
            int sum=0;
            while(i<n)
            {
                sum+=(int)s1[i];
                i++;
            }
            return sum;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        // if both characters are equal we move forward

        if(s1[i]==s2[j])
        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);

        else{
            // we have the option of deleting the first charater or deleting the second 
            // character
            return dp[i][j]=min((int)s1[i]+solve(s1,s2,i+1,j,dp),(int)s2[j]+solve(s1,s2,i,j+1,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.length();
        int m=s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int sum=solve(s1,s2,0,0,dp);
        return sum;
    }
};

int main()
{
    
    return 0;
}