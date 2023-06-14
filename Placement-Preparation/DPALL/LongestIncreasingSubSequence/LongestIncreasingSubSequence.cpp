#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   
   int solve(vector<int>&nums,int index,vector<int>&dp)
   {
       // base case
       if(index<0)return 0;
       if(dp[index]!=-1)return dp[index];
       int ans=0;

       for(int i=index-1;i>=0;i--)
       {
           if(nums[index]>nums[i])
           ans=max(ans,1+solve(nums,i,dp));
       }
       return dp[index]=ans;
   }

    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        int maxim=INT_MIN;
        
        for(int i=0;i<n;i++)
        maxim=max(maxim,solve(nums,i,dp)+1);

        return maxim;
    }
};

int main()
{
    
    return 0;
}