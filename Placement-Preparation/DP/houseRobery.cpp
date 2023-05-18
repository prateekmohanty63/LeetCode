#include<iostream>
#include<vector>
using namespace std;


// bottom-up 
// T(n)=O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        
      
      int n=nums.size();
      if(n==0)return 0;

      vector<int>memo(n+1);
      
      memo[0]=0;
      memo[1]=nums[0];

      for(int i=1;i<n;i++)
      {
          int val=nums[i];
          memo[i+1]=max(memo[i],memo[i-1]+val);
      }
      return memo[n];

    }
};

// memoized (top-down)
// Time complexity: O(n)

class Solution {
public:
   
   int maxRobery(vector<int>&nums,int i,vector<int>&dp)
   {
       // base case
       if(i>=nums.size())return 0;

       if(dp[i]!=-1)return dp[i];

       // we have the option of robbing the house or not robbing the house 
       // if we rob the house we cannot rob the adjacent house , if we dont we have the option of robbing the adjacent house 

       return dp[i]=max(nums[i]+maxRobery(nums,i+2,dp),maxRobery(nums,i+1,dp));
   }
   
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return maxRobery(nums,0,dp);
    }
};

int main()
{
    
    return 0;
}