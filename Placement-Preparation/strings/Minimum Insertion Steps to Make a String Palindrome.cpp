#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

   int lcs(string a,string b,int i,int j,vector<vector<int>>&dp)
   {
     int n=a.length();
     int m=b.length();
    
    if(i==0 || j==0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(a[i-1]==b[j-1])return dp[i][j]=1+lcs(a,b,i-1,j-1,dp);

    return dp[i][j]=max(lcs(a,b,i-1,j,dp),lcs(a,b,i,j-1,dp));

   }
    int minInsertions(string s) {
        
        string a=s;
        int m=a.length();
        reverse(a.begin(),a.end());

       // cout<<lcs(s,a,m,m);
      vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return m-lcs(s,a,m,m,dp);
    }
};

int main()
{
    
    return 0;
}