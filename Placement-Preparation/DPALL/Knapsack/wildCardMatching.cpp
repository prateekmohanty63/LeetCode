#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(n*m)
// S(N)=O(n*m)

class Solution {
public:
   bool solve(string& s,string& p,int i,int j,vector<vector<int>>&dp)
   {
       // base case
       int n=s.length();
       int m=p.length();

       if(i>=n && j>=m)return true;
       if(j>=m)return false;

       if(i==n)
       {
           for(int k=j;k<m;k++)if(p[k]!='*')return false;

           return true;
       }

       

       if(dp[i][j]!=-1)return dp[i][j];

       bool match=(i<n && (s[i]==p[j] || p[j]=='?'));

       if(match)return dp[i][j]=solve(s,p,i+1,j+1,dp);
       if(p[j]=='*')
        {
            // if we consider * to be a empty string
            bool emptyRep=solve(s,p,i,j+1,dp);

            // matching single current char
            bool singleRep=solve(s,p,i+1,j,dp);

               return dp[i][j]=emptyRep || singleRep;
        }

      

       else return dp[i][j]=false;


   }
    bool isMatch(string s, string p) {
        
        int n=s.length();
        int m=p.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(s,p,0,0,dp);
    }
};

int main()
{
    
    return 0;
}