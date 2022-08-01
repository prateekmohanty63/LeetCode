#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// my solutions

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




int main()
{
    
    return 0;
}