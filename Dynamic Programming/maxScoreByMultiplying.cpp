#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    
    int maxScore(vector<int>&nums,vector<int>&mult,int start,int end,int m,int i,vector<vector<int>>&dp)
    {
        // base case
        
        if(m==0)return 0;
        
        if(dp[start][i]!=INT_MIN)return dp[start][i];
        
         // int a=nums[start]*mult[i];
         // int b=nums[end]*mult[i];
        
        int score=0;
        
        int a=nums[start]*mult[i]+maxScore(nums,mult,start+1,end,m-1,i+1,dp);
        int b=nums[end]*mult[i]+maxScore(nums,mult,start,end-1,m-1,i+1,dp);
       
       score=score+max(a,b);
        
        return dp[start][i]=score;
       
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n=nums.size();
        int m=multipliers.size();
        int start=0;
        int end=n-1;
        int i=0;
        int score=0;
        
      //  unordered_map<string,int>dp;
        
        vector<vector<int>>dp(1001,vector<int>(1001,INT_MIN));
    
        
        int res=maxScore(nums,multipliers,start,end,m,i,dp);
        
        return res;
    }
};

int main()
{
    
    return 0;
}