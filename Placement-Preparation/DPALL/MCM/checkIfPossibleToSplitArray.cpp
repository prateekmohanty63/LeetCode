#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool solve(vector<int>&nums,int &m,vector<int>&preFixSum,int start,int end,vector<vector<int>>&dp)
    {
        if(start==end)return true;
        
        //if(start>end)return true;

        int sum=0;
        if(start==0)sum=preFixSum[end];
        else sum=preFixSum[end]-preFixSum[start-1];

        if(end-start==1 && sum>=m)return dp[start][end]=true;
        if(sum<m)return dp[start][end]=false;

        if(dp[start][end]!=-1)return dp[start][end];


        bool ans=false;

        for(int k=start;k<end;k++)
        {
            // we will check if we can split at the current position
           
           ans=(ans || (solve(nums,m,preFixSum,start,k,dp) && solve(nums,m,preFixSum,k+1,end,dp)));
          
        }
        return dp[start][end]=ans;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==2)return true;
        vector<int>preFixSum(n,0);
        preFixSum[0]=nums[0];

        for(int i=1;i<n;i++)
        preFixSum[i]=preFixSum[i-1]+nums[i];

        bool res=solve(nums,m,preFixSum,0,n-1,dp);

        return res;
    }

};

int main()
{
    
    return 0;
}