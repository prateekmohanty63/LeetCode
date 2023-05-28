#include<iostream>
using namespace std;

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