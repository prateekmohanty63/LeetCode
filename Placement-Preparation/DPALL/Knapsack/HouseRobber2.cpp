#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int maxMoney(vector<int>&nums,int i,int taken,vector<vector<int>>&dp)
   {
       int n=nums.size();
       // base case
       if(i>=n)return 0;

       if(dp[i][taken]!=-1)return dp[i][taken];

       if(i==0)
       {
           // check if first house is robbed
           return dp[i][taken]=max(nums[i]+maxMoney(nums,i+2,1,dp),maxMoney(nums,i+1,taken,dp));
       }
       else{
           // we have the option of taking the element or not taking it
           if(i==n-1)
           {
                if(taken)return dp[i][taken]=0;

                else return nums[i];
           }
           else{
               return dp[i][taken]=max(nums[i]+maxMoney(nums,i+2,taken,dp),maxMoney(nums,i+1,taken,dp));
           }
       }
   }

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maxMoney(nums,0,0,dp);
    }
};

int main()
{
    
    return 0;
}