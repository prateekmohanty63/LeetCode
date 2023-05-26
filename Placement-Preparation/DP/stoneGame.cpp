#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

  int aliceCollection(vector<int>&piles,int start,int end,int turn,vector<vector<int>>&dp)
  {
      // base case

      // no piles of stone left
      if(start>end)return 0;

      if(dp[start][end]!=-1)return dp[start][end];

      // if the turn is even it is the chance of alice 
      if(turn%2==0)
      {
          return dp[start][end]=max(piles[start]+aliceCollection(piles,start+1,end,turn+1,dp),piles[end]+aliceCollection(piles,start,end-1,turn+1,dp));
      }
      else{
          // bob's turn 
          return dp[start][end]=min(aliceCollection(piles,start+1,end,turn+1,dp),aliceCollection(piles,start,end-1,turn+1,dp));
      }

  } 
   
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        int totalScore=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(auto it:piles)totalScore+=it;

        int aliceScore=aliceCollection(piles,0,n-1,0,dp);
        int bobScore=totalScore-aliceScore;

        cout<<aliceScore<<" "<<bobScore<<endl;

        return aliceScore>bobScore;

    }
};

int main()
{
    
    return 0;
}