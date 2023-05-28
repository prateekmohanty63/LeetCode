#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
  
  int longestCommonSubSequence(string s,string srev)
  {
      int n=s.length();
    
      vector<vector<int>>bottomUp(n+1,vector<int>(n+1));

      // initilization 
      for(int i=0;i<n;i++)
      {
          bottomUp[0][i]=0;
          bottomUp[i][0]=0;
      }

      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(s[i-1]==srev[j-1])
              {
                  bottomUp[i][j]=1+bottomUp[i-1][j-1];
              }
              else{
                  bottomUp[i][j]=max(bottomUp[i-1][j],bottomUp[i][j-1]);
              }
          }
      }
      return bottomUp[n][n];
      
  }

    int minInsertions(string s) {
        
        string a=s;
        reverse(a.begin(),a.end());
        int n=s.length();
       

        int longestSubSeq=longestCommonSubSequence(s,a);
        cout<<longestSubSeq<<" ";

        return a.length()-longestSubSeq;
    }
};

class Solution {
public:
  
  int longestCommonSubSequence(string s,string srev,int i,int j,unordered_map<string,int>&dp)
  {
      // base case
      if(i<0 || j<0)return 0;
      
      string r=to_string(i)+"*"+to_string(j);
      if(dp.find(r)!=dp.end())return dp[r];

      if(s[i]==srev[j])
      {
          return dp[r]=1+longestCommonSubSequence(s,srev,i-1,j-1,dp);
      }
      else{
          return dp[r]=max(longestCommonSubSequence(s,srev,i-1,j,dp),longestCommonSubSequence(s,srev,i,j-1,dp));
      }
  }

    int minInsertions(string s) {
        
        string a=s;
        reverse(a.begin(),a.end());
        int n=s.length();
        unordered_map<string,int>dp;

        int longestSubSeq=longestCommonSubSequence(s,a,s.length()-1,s.length()-1,dp);

        return a.length()-longestSubSeq;
    }
};

int main()
{
    
    return 0;
}