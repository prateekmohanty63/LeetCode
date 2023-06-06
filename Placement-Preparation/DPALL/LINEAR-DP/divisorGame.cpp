#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   bool isWinner(int n,int m,int turn,vector<int>&dp)
   {
      // base case
      if(n<=1 && turn%2==0)return false;

      if(n<=1 && turn%2==1)return true;

      if(dp[n]!=-1)return dp[n];

      for(int i=1;i<n;i++)
      {
          if(m%i==0)
          {
              if(isWinner(n-i,m,turn+1,dp))return dp[n]=true;
          }
      }
      return dp[n]=false;
   }
    bool divisorGame(int n) {

        vector<int>dp(n+1,-1);
        return isWinner(n,n,0,dp);
    }
};

int main()
{
    
    return 0;
}