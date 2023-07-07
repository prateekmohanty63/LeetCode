#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(n^2)
// S(N)=O(n*m)

class Solution {
public:
    bool solve(string s,string p,int i,int j,vector<vector<int>>&dp)
    {
        // base case
        int n=s.length();
        int m=p.length();
       
       // it is said that both patterns should exactly match
        if(i>=n && j>=m)return true;
       
       // if j goes out of bound  (we have not found exact match)
        if(j>=m)return false;

        if(dp[i][j]!=-1)return dp[i][j];

       // bool ans=false;

        bool match=(i<n && (s[i]==p[j] || p[j]=='.'));
       
       // NOTE we are checking for * first , because * has the highest precedence
        if(j+1<m && p[j+1]=='*')
        {
             // we have 2 choices here
             // either we use the * or dont use it

             // dont use star
             //ans|=solve(s,p,i,j+2);

             // we can only use the star it current element of s
             // matches the current element of p
            //  if(match)
            //  ans|=solve(s,p,i+1,j);

            return dp[i][j]=solve(s,p,i,j+2,dp) || (match && solve(s,p,i+1,j,dp));
        }
        if(match)
        return dp[i][j]=solve(s,p,i+1,j+1,dp);

        else return dp[i][j]= false;

       // return ans;
    }
    bool isMatch(string s, string p) {
        
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int res=solve(s,p,0,0,dp);

        return res; 
    }
};

// T(N)=O(2^n)
// S(N)=O(N)

class Solution {
public:
    bool solve(string s,string p,int i,int j)
    {
        // base case
        int n=s.length();
        int m=p.length();
       
       // it is said that both patterns should exactly match
        if(i>=n && j>=m)return true;
       
       // if j goes out of bound  (we have not found exact match)
        if(j>=m)return false;

       // bool ans=false;

        bool match=(i<n && (s[i]==p[j] || p[j]=='.'));

        if(j+1<m && p[j+1]=='*')
        {
             // we have 2 choices here
             // either we use the * or dont use it

             // dont use star
             //ans|=solve(s,p,i,j+2);

             // we can only use the star it current element of s
             // matches the current element of p
            //  if(match)
            //  ans|=solve(s,p,i+1,j);

            return solve(s,p,i,j+2) || (match && solve(s,p,i+1,j));
        }
        if(match)
        return solve(s,p,i+1,j+1);

        else return false;

       // return ans;
    }
    bool isMatch(string s, string p) {
        
        int res=solve(s,p,0,0);

        return res; 
    }
};

int main()
{
    
    return 0;
}