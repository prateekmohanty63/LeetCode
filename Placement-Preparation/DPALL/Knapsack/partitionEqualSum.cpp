#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   bool isPresent(vector<int>&nums,int i,int sum,vector<vector<int>>&dp)
   {
       // base case
       int n=nums.size();

       if(i>=n)return false;

       if(sum==0)return true;

       if(dp[sum][i]!=-1)return dp[sum][i];

       if(nums[i]<=sum)
       return dp[sum][i]=isPresent(nums,i+1,sum-nums[i],dp) || isPresent(nums,i+1,sum,dp);

       else return dp[sum][i]=isPresent(nums,i+1,sum,dp);
   }
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)sum+=nums[i];

        if(sum%2!=0)return false;

        vector<vector<int>>dp(sum,vector<int>(n,-1));

        return isPresent(nums,0,sum/2,dp);

    }
};

int main()
{
    
    return 0;
}