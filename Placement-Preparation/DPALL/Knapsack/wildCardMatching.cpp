#include<iostream>
#include<vector>
using namespace std;

// BOTTOM UP SOLUTION
// T(N)=O(n*m)
// S(n)=O(n*m)

class Solution {
public:
   bool solve(string& s,string& p,int i,int j,vector<vector<int>>&dp)
   {
       // base case
      

       if(i==0 && j==0)return true;
       if(j==0)return false;

       if(i==0)
       {
           for(int k=1;k<=j;k++)if(p[k-1]!='*')return false;

           return true;
       }

       

       if(dp[i][j]!=-1)return dp[i][j];

       bool match=((s[i-1]==p[j-1] || p[j-1]=='?'));

       if(match)return dp[i][j]=solve(s,p,i-1,j-1,dp);

       if(p[j-1]=='*')
        {
            // if we consider * to be a empty string
            bool emptyRep=solve(s,p,i,j-1,dp);

            // matching single current char
            bool singleRep=solve(s,p,i-1,j,dp);

               return dp[i][j]=emptyRep || singleRep;
        }

      

       else return dp[i][j]=false;


   }

   bool bottomUp(string s,string p)
   {
       int n=s.length();
       int m=p.length();

       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
       dp[0][0]=true;

      for(int j=1;j<=m;j++)
      {
          bool flag=true;

          for(int k=1;k<=j;k++){
              if(p[k-1]!='*'){
                  flag=false;
                  break;
              }
          }
          dp[0][j]=flag;
      }

      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
               if(s[i-1]==p[j-1] || p[j-1]=='?')
               dp[i][j]=dp[i-1][j-1];

               else if(p[j-1]=='*')
               dp[i][j]=dp[i-1][j] || dp[i][j-1];

               else dp[i][j]=false;
          }
      }
    return dp[n][m];
   }
    bool isMatch(string s, string p) {
        
        int n=s.length();
        int m=p.length();

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        // return solve(s,p,n,m,dp);

        return bottomUp(s,p);
    }
};

// T(N)=O(n*m)
// S(N)=O(n*m)

class Solution {
public:
   bool solve(string& s,string& p,int i,int j,vector<vector<int>>&dp)
   {
       // base case
      

       if(i==0 && j==0)return true;
       if(j==0)return false;

       if(i==0)
       {
           for(int k=1;k<=j;k++)if(p[k-1]!='*')return false;

           return true;
       }

       

       if(dp[i][j]!=-1)return dp[i][j];

       bool match=((s[i-1]==p[j-1] || p[j-1]=='?'));

       if(match)return dp[i][j]=solve(s,p,i-1,j-1,dp);

       if(p[j-1]=='*')
        {
            // if we consider * to be a empty string
            bool emptyRep=solve(s,p,i,j-1,dp);

            // matching single current char
            bool singleRep=solve(s,p,i-1,j,dp);

               return dp[i][j]=emptyRep || singleRep;
        }

      

       else return dp[i][j]=false;


   }

    bool isMatch(string s, string p) {
        
        int n=s.length();
        int m=p.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(s,p,n,m,dp);
    }
};

int main()
{
    
    return 0;
}