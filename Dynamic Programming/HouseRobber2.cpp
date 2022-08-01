#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// my solutions
// memoization

class Solution {
public:
    
    int maxMoney(vector<int>&nums,int i,bool robFirst,unordered_map<string,int>&dp)
    {
        // base case
        // if i is greater than n return 0
        // if we have choosen the first element then we cannot chose the last element 
        if(i>=nums.size() || (i==nums.size()-1 && robFirst))return 0;
        
        int r=int(robFirst);
        string res=to_string(i)+"*"+to_string(r);
        
        if(dp.find(res)!=dp.end())return dp[res];
            
        // recursion
        
        int rob1=0,notRob=0;
        // if at first position and taken the first position
        if(i==0)
        rob1=maxMoney(nums,i+2,1,dp)+nums[0];
        
        else rob1=maxMoney(nums,i+2,robFirst,dp)+nums[i];
        
        notRob=maxMoney(nums,i+1,robFirst,dp);
        
        return dp[res]=max(rob1,notRob);
        
        
        
        
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
        bool rob=false;
        unordered_map<string,int>dp;
        return maxMoney(nums,0,rob,dp);
    }
};


// other optimized solutions
// top-down approach

class Solution {
public:
    
    int maxMoney(vector<int>nums)
    {
        vector<int>dp(nums.size()+1,0);
        
        // if there is only 1 house
        dp[0]=nums[0];
        
        // if there are 2 houses
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        
         if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int>vec1(nums.begin()+1,nums.end());
        vector<int>vec2(nums.begin(),nums.end()-1);
        
        return max(maxMoney(vec1),maxMoney(vec2));
    }
};




int main()
{
    
    return 0;
}