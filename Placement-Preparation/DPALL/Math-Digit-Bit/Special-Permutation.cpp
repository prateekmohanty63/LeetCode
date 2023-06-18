#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int mod=1000000007;
    
    int solve(vector<int>&nums,int prevIndex,int currIndex,int mask,vector<vector<int>>&dp)
    {
        // base case
        int n=nums.size();
        
        if(currIndex==n)
        {
            return 1;
        }
        
        if(dp[prevIndex+1][mask]!=-1)return dp[prevIndex+1][mask];
        
        int ans=0;
        
        for(int j=0;j<n;j++)
        {
            // check if the element at the current index is already included
            if((mask & (1<<j))>0)
            {
                // then bit at that position is set , hence the number is already used
                continue;
            }
            else{
                if(prevIndex==-1 || nums[j]%nums[prevIndex]==0 || nums[prevIndex]%nums[j]==0)
                {
                    ans=(ans+solve(nums,j,currIndex+1,mask|(1<<j),dp))%mod; // mask | (1<<j) is to make that bit set
                }
            }
        }
       
        return dp[prevIndex+1][mask]=ans%mod;
          
    }
    int specialPerm(vector<int>& nums) {
         
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>((1<<14)+1,-1));
        
        int res=solve(nums,-1,0,0,dp)%mod;
        
        return res%mod;
    }
};

int main()
{
    
    return 0;
}