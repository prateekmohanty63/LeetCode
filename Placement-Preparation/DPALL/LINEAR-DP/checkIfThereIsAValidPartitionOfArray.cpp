#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool solve(vector<int>&nums,int ind,vector<int>&dp)
    {
        int n=nums.size();

        // we can take 2 elements or 3 elements
        if(ind>=n)return true;

        if(ind>=n-1)return false;

        if(dp[ind]!=-1)return dp[ind];

        bool ans=false;

        if(nums[ind]==nums[ind+1])
        ans=(ans || (solve(nums,ind+2,dp)));

        if(ind+1<n && ind+2<n)
        {
            int a=nums[ind];
            int b=nums[ind+1];
            int c=nums[ind+2];

            if(a==b && b==c)
            ans=(ans || (solve(nums,ind+3,dp)));

            if((b-a)==1 && (c-b)==1)
            ans=(ans || (solve(nums,ind+3,dp)));

        }
      return dp[ind]=ans;

    }
    bool validPartition(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        bool res=solve(nums,0,dp);
        return res;
    }
};

int main()
{
    
    return 0;
}