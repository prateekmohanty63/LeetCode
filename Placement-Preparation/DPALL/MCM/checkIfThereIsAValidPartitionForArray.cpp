#include<iostream>
#include<vector>
using namespace std;


// TLE

class Solution {
public:
    bool solve(vector<int>&nums,int start,int end,vector<vector<int>>&dp)
    {
        // base case
        int n=nums.size();
        if(start>=end)return false;
        if(end-start==1)
        {
            if(nums[start]!=nums[end])return false;

            return true;
        }
       else if(end-start==2)
        {
            int flag=0;
            int num=nums[start];
            for(int i=start+1;i<=end;i++)
            {
                if(nums[i]!=num)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)return true;

            for(int i=start;i<=end;i++)
            {
                if(i+1<n && nums[start+1]-nums[start]!=1)return false;
            }
            return true;
        }

        if(dp[start][end]!=-1)return dp[start][end];
        bool ans=false;

        for(int k=start;k<end;k++)
        {
             ans=(ans || (solve(nums,start,k,dp) && solve(nums,k+1,end,dp)));
        }
        return dp[start][end]=ans;
    }
    bool validPartition(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        bool res=solve(nums,0,n-1,dp);
        return res;
    }
};

int main()
{
    
    return 0;
}