#include<iostream>
#include<vector>
using namespace std;

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