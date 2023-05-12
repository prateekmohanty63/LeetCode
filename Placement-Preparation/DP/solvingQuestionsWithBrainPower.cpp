#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
  long long maxPoints(vector<vector<int>>&questions,int i,vector<long long>&dp)
  {
      // base case
      int n=questions.size();
      if(i>=n)return 0;

      if(dp[i]!=-1)return dp[i];

       // we have the option of either doing the question or skipping it 

       return dp[i]=max(questions[i][0]+maxPoints(questions,i+(questions[i][1])+1,dp),maxPoints(questions,i+1,dp));
  }

    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        vector<long long>dp(n,-1);
        long long ans=maxPoints(questions,0,dp);
        

        return ans;
    }
};

int main()
{
    
    return 0;
}