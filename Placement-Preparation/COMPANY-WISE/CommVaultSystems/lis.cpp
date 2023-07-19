#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   int solve(vector<int>&nums,int index,vector<int>&dp)
   {
       // base case
       int n=nums.size();
       if(index>=n)return 0;

       if(dp[index]!=-1)return dp[index];

       int ans=0;

       for(int i=index+1;i<n;i++)
       {
           if(nums[i]>nums[index])
           {
               ans=max(ans,1+solve(nums,i,dp));
           }

       }
       return dp[index]=ans;
   }
    int lengthOfLIS(vector<int>& nums) {
        
        int res=INT_MIN;
        int n=nums.size();
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++)
        {
            res=max(res,solve(nums,i,dp));
        }
        return res+1;
    }
};

int main()
{
    
    return 0;
}